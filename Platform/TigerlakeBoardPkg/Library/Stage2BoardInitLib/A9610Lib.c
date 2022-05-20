//*************************************************************************
//
// Name:  <A9610Lib.C>
//
// Description: 
//
//*************************************************************************
//-------------------------------------------------------------------------
// Include Files
//-------------------------------------------------------------------------
#include "A9610Lib.h"

//----------------------------------------------------------------------------
// Procedure:	EcIbFree
//
// Description: Wait till EC I/P buffer is free.
//
// Input:       None
//              
// Output:      None
//
//----------------------------------------------------------------------------
EFI_STATUS
EcIbFree ()
{
	UINTN   Status;
	UINTN   Timeout=100000;
    
	do {
		Status = IoRead8(A9610_PMC_CMD_PORT);
		Timeout--;
		if(Timeout==0) return EFI_TIMEOUT;
	} while (Status & Ibf); 
	
	return EFI_SUCCESS;
}

//----------------------------------------------------------------------------
// Procedure:	EcObFull
//
// Description: Wait till EC O/P buffer is full
//
// Input:       None
//              
// Output:      None
//
//----------------------------------------------------------------------------
EFI_STATUS
EcObFull ()
{
	UINTN    Status;
	UINTN   Timeout=100000;
    
	do {
		Status = IoRead8(A9610_PMC_CMD_PORT);
		Timeout--;
		if(Timeout==0) return EFI_TIMEOUT;
	} while (!(Status & Obf));
	
	return EFI_SUCCESS;
}

// read data if obf
EFI_STATUS
CheckEcObf ()
{
	UINTN   Status;
	UINTN   Timeout=100000;
	UINT8   temp;
	do {
		Status = IoRead8(A9610_PMC_CMD_PORT);
		if(Status & Obf) temp = IoRead8(A9610_PMC_DATA_PORT);

		Timeout--;
		if(Timeout==0) return EFI_TIMEOUT;
	} while (Status & Obf);

	return EFI_SUCCESS;
}

//----------------------------------------------------------------------------
// Procedure:	EcPmcWriteCmd
//
// Description: Send EC command
//
// Input:       None
//              
// Output:      None
//
//----------------------------------------------------------------------------
EFI_STATUS
EcPmcWriteCmd (UINT8	cmd)
{
	EFI_STATUS      Status;

	Status = CheckEcObf();
	if(EFI_ERROR(Status)) return Status;

	Status = EcIbFree();
	if(!EFI_ERROR(Status)) IoWrite8(A9610_PMC_CMD_PORT, (UINT8)cmd);

	return Status;
}

//----------------------------------------------------------------------------
// Procedure:	EcPmcWriteData
//
// Description: Write Data from EC data port
//
// Input:       None
//              
// Output:      None
//
//----------------------------------------------------------------------------
EFI_STATUS
EcPmcWriteData (UINT8	data)
{
	EFI_STATUS      Status;

	Status = EcIbFree();
	if(!EFI_ERROR(Status)) IoWrite8(A9610_PMC_DATA_PORT, (UINT8)data);
	
	return Status;
}

//----------------------------------------------------------------------------
// Procedure:	EcPmcReadData
//
// Description: Read Data from EC data Port.
//
// Input:       None
//              
// Output:      None
//
//----------------------------------------------------------------------------
EFI_STATUS
EcPmcReadData (UINT8 *pData)
{
	EFI_STATUS      Status;

	Status = EcObFull();
    
	if(!EFI_ERROR(Status)) *pData = IoRead8(A9610_PMC_DATA_PORT);
	return Status;
}

//----------------------------------------------------------------------------
// Procedure:	EcPmcWrite_Protocol
//----------------------------------------------------------------------------
EFI_STATUS
EcPmcWrite_Protocol (UINT8 CommandByte, UINT8 ControlByte, UINT8 DeviceByte, UINT8 PayloadSizeByte, UINT8 *PayloadByte)
{
	EFI_STATUS   Status = EFI_SUCCESS;
	UINT8   i = 1;
	
	Status=EcPmcWriteCmd(CommandByte);
	if(EFI_ERROR(Status)) return Status;
	Status=EcPmcWriteData(ControlByte);
	if(EFI_ERROR(Status)) return Status;
	Status=EcPmcWriteData(DeviceByte);
	if(EFI_ERROR(Status)) return Status;
	Status=EcPmcWriteData(PayloadSizeByte);
	if(EFI_ERROR(Status)) return Status;
	for(i=0; i<PayloadSizeByte; i++) {
		Status=EcPmcWriteData(PayloadByte[i]);
		if(EFI_ERROR(Status)) return Status;
	}
        
	return Status;
}

//----------------------------------------------------------------------------
// Procedure:	EcPmcRead_Protocol
//----------------------------------------------------------------------------
EFI_STATUS
EcPmcRead_Protocol (UINT8 CommandByte, UINT8 ControlByte, UINT8 DeviceByte, UINT8 PayloadSizeByte, UINT8 *PayloadByte)
{
	EFI_STATUS      Status;
	UINT8           i;

	Status=EcPmcWriteCmd(CommandByte);
	if(EFI_ERROR(Status)) return Status;
	Status=EcPmcWriteData(ControlByte);
	if(EFI_ERROR(Status)) return Status;
	Status=EcPmcWriteData(DeviceByte);
	if(EFI_ERROR(Status)) return Status;
	Status=EcPmcWriteData(PayloadSizeByte);
	if(EFI_ERROR(Status)) return Status;
	for(i=0; i<PayloadSizeByte; i++) {
		Status=EcPmcReadData(&PayloadByte[i]);
		if(EFI_ERROR(Status)) return Status;
	}

	return Status;
}

EFI_STATUS
A9610Read_FW_Version (
	OUT UINT8 *MajorVersion,
	OUT UINT8 *MinorVersion
)
{
  EFI_STATUS   Status;
	UINT8	Major, Minor;

	Status = EcPmcWriteCmd(0x31);	// Read ACPI RAM ~ iManager
	if(EFI_ERROR(Status)) return Status;
	
	// Offset=F0h : Major Version 
	// Offset=F1h : Minor Version
	Status = EcPmcWriteData(0xF0);
	if(EFI_ERROR(Status)) return Status;

	// Size = 2 : Major + Minor
	Status = EcPmcWriteData(0x02);
	if(EFI_ERROR(Status)) return Status;

	Status = EcPmcReadData(&Major);
	if(EFI_ERROR(Status)) return Status;

	Status = EcPmcReadData(&Minor);
	if(EFI_ERROR(Status)) return Status;	

	*MajorVersion = Major;
	*MinorVersion = Minor;

  return Status;
}
