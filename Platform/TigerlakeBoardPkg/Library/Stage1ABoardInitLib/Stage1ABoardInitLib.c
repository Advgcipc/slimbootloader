/** @file

  Copyright (c) 2008 - 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <PiPei.h>
#include <Library/BaseLib.h>
#include <Library/BoardInitLib.h>
#include <FsptUpd.h>
#include <Library/BootloaderCoreLib.h>
#include <Library/SerialPortLib.h>
#include <Library/PlatformHookLib.h>
#include <Library/DebugPrintErrorLevelLib.h>
#include <PlatformData.h>
#include <CpuRegs.h>
#include <PchAccess.h>
#include <Library/GpioLib.h>
#include <GpioConfig.h>
#include <GpioPinsVer2Lp.h>
#include <Library/ConfigDataLib.h>
//7583X003_1
#include <PchAccess.h>
#include <Library/PchPcrLib.h>
//7583X003_1

#define UCODE_REGION_BASE   FixedPcdGet32(PcdUcodeBase)
#define UCODE_REGION_SIZE   FixedPcdGet32(PcdUcodeSize)
#define CODE_REGION_BASE    0xFFD00000
#define CODE_REGION_SIZE    0x00300000

const
FSPT_UPD TempRamInitParams = {
  .FspUpdHeader = {
    .Signature = FSPT_UPD_SIGNATURE,
    .Revision  = 1,
    .Reserved  = {0},
  },
  .FsptCoreUpd = {
    .MicrocodeRegionBase   = UCODE_REGION_BASE,
    .MicrocodeRegionSize   = UCODE_REGION_SIZE,
    .CodeRegionBase        = CODE_REGION_BASE,
    .CodeRegionSize        = CODE_REGION_SIZE,
    .Reserved              = {0},
  },
  .FsptConfig = {
    .PcdSerialIoUartDebugEnable = 1,
    .PcdSerialIoUartNumber      = FixedPcdGet32 (PcdDebugPortNumber) < PCH_MAX_SERIALIO_UART_CONTROLLERS ? \
                                    FixedPcdGet32 (PcdDebugPortNumber) : 2,
    .PcdSerialIoUartMode        = 4, // SerialIoUartSkipInit, let SBL init UART
    .PcdSerialIoUartBaudRate    = 115200,
    .PcdPciExpressBaseAddress   = FixedPcdGet32 (PcdPciMmcfgBase),
    .PcdPciExpressRegionLength  = 0x10000000,
    .PcdSerialIoUartParity      = 1, // NoParity
    .PcdSerialIoUartDataBits    = 8,
    .PcdSerialIoUartStopBits    = 1,
    .PcdSerialIoUartAutoFlow    = 0,
    .PcdSerialIoUartRxPinMux    = 0,
    .PcdSerialIoUartTxPinMux    = 0,
    .PcdSerialIoUartRtsPinMux   = 0,
    .PcdSerialIoUartCtsPinMux   = 0,
    .PcdLpcUartDebugEnable      = 1,
  },
  .UpdTerminator = 0x55AA,
};

CONST GPIO_INIT_CONFIG mUartGpioTable[] = {
  {GPIO_VER2_LP_GPP_C8,  {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//SERIALIO_UART0_RXD
  {GPIO_VER2_LP_GPP_C9,  {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//SERIALIO_UART0_TXD
  {GPIO_VER2_LP_GPP_C12, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//SERIALIO_UART1_RXD
  {GPIO_VER2_LP_GPP_C13, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//SERIALIO_UART1_TXD
  {GPIO_VER2_LP_GPP_C20, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//SERIALIO_UART2_RXD
  {GPIO_VER2_LP_GPP_C21, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//SERIALIO_UART2_TXD
};

//7583X003_1
typedef struct _SIO_INIT_TABLE{
    UINT16      Index16;
    UINT8       Value8;
    UINT16      Data16;
    UINT8       Data8;
} SIO_INIT_TABLE;

#define SIO_LDN_PMC0	      0xc
#define SIO_LDN_PMC1	      0xd
#define SIO_LDN_CAN0	      0x18
#define SIO_LDN_CAN1	      0x19
#define SIO_LDN_I2C0	      0x20
#define SIO_LDN_I2C1	      0x21
#define SIO_LDN_SMBUS0	    0x22
#define SIO_LDN_SMBUS1	    0x23
//7583V111 >>
#define SIO_LDN_GPIO0	      0x24
//7583V111 >>
#define SIO_LDN_PMCMB	      0xe
#define SIO_LDN_EC	        0xf
#define SIO_LDN_UART1	      0x2
#define SIO_LDN_UART2	      0x3


#define SIO_CONFIG_INDEX	  0x299
#define SIO_CONFIG_DATA	    0x29A
#define SIO_CONFIG_ENTER	  0x87
#define SIO_CONFIG_EXIT	    0xAA
#define SIO_LDN_ACTIVATE	  0x1
#define SIO_LDN_DEACTIVATE  0x0
#define SIO_LDN_SELECT	    0x7
#define SIO_ACTIVATE_REG    0x30
#define SIO_BASE1_HI_REG    0x60
#define SIO_BASE1_LO_REG    0x61
#define SIO_BASE2_HI_REG    0x62
#define SIO_BASE2_LO_REG    0x63
#define SIO_IRQ1_REG      	0x70
#define SIO_IRQ2_REG      	0x72
#define SIO_DMA1_REG      	0x74
#define SIO_DMA2_REG      	0x75 
#define SIO_PMC1_INDEX     	0x2F2
#define SIO_PMC1_DATA     	0x2F6
#define SIO_UART1_BASE     	0x3F8
#define SIO_UART2_BASE     	0x2F8

//7583V111 >>
#define SIO_I2C0_IRQ      	6
#define SIO_I2C0_BASE     	0x280
#define SIO_GPIO0_BASE     	0x2C0
//7583V111 >>

#define ECE1200_SIO_CONFIG_INDEX      0x8c
#define ECE1200_SIO_CONFIG_DATA      0x8d
#define ECE1200_LDN_ESPI	        0x0
#define ECE1200_LDN_LPC	          0x1
#define ECE1200_SIO_CONFIG_ENTER	0x55
#define ECE1200_SIO_CONFIG_EXIT	  0xaa 

// eSPI Register Set, Logical Device 00h
#define ECE1200_IOBAR_LS_REG  0x36
#define ECE1200_IOBAR_MS_REG  0x37

// LPC Register Set, Logical Device 01h
#define ECE1200_SIRQ_REG      0x40


SIO_INIT_TABLE SioInitTable[]= {
  {SIO_CONFIG_INDEX, SIO_CONFIG_ENTER,  SIO_CONFIG_INDEX, SIO_CONFIG_ENTER},
  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_PMC0},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},

  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_PMC1},
  {SIO_CONFIG_INDEX, SIO_BASE1_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_INDEX & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE1_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_INDEX >> 8)},
  {SIO_CONFIG_INDEX, SIO_BASE2_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_DATA & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE2_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_DATA >> 8)},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},

  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_UART1},
  {SIO_CONFIG_INDEX, SIO_BASE1_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_UART1_BASE & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE1_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_UART1_BASE >> 8)},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},

  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_UART2},
  {SIO_CONFIG_INDEX, SIO_BASE1_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_UART2_BASE & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE1_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_UART2_BASE >> 8)},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},
//7583V111 >>
  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_I2C0},
  {SIO_CONFIG_INDEX, SIO_BASE1_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_I2C0_BASE & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE1_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_I2C0_BASE >> 8)},
  {SIO_CONFIG_INDEX, SIO_IRQ1_REG,      SIO_CONFIG_DATA,  SIO_I2C0_IRQ},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},


  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_GPIO0},
  {SIO_CONFIG_INDEX, SIO_BASE1_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_GPIO0_BASE & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE1_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_GPIO0_BASE >> 8)},
  {SIO_CONFIG_INDEX, SIO_IRQ1_REG,      SIO_CONFIG_DATA,  SIO_I2C0_IRQ},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},

//7583V111 >>
  {SIO_CONFIG_INDEX, SIO_CONFIG_EXIT,   SIO_CONFIG_INDEX, SIO_CONFIG_EXIT},

  {ECE1200_SIO_CONFIG_INDEX, ECE1200_SIO_CONFIG_ENTER,  ECE1200_SIO_CONFIG_INDEX, ECE1200_SIO_CONFIG_ENTER},
  {ECE1200_SIO_CONFIG_INDEX, SIO_LDN_SELECT,    ECE1200_SIO_CONFIG_DATA,  ECE1200_LDN_LPC},
  {ECE1200_SIO_CONFIG_INDEX, ECE1200_SIRQ_REG,  ECE1200_SIO_CONFIG_DATA, 0x90},
  {ECE1200_SIO_CONFIG_INDEX, ECE1200_SIO_CONFIG_EXIT,   ECE1200_SIO_CONFIG_INDEX, ECE1200_SIO_CONFIG_EXIT},

};

#define R_PCH_DMI_PCR_LPCLGIR1                   0x2730                       ///< LPC Generic I/O Range 2
#define R_PCH_DMI_PCR_LPCLGIR2                   0x2734                       ///< LPC Generic I/O Range 2
#define R_PCH_DMI_PCR_LPCLGIR3                   0x2738                       ///< LPC Generic I/O Range 3
#define R_PCH_DMI_PCR_LPCLGIR4                   0x273C                       ///< LPC Generic I/O Range 2

/**
  Enable UART in SIO chip.

**/
VOID
EarlySioInit (
  VOID
)
{
    UINT8                 Idx;
    UINT32                LpcBaseAddr;
    SIO_INIT_TABLE        *pSioTbl = SioInitTable;
    UINT32            PciData32;

    // Enable SIO decoding
    LpcBaseAddr = MM_PCI_ADDRESS (0, 31, 0, 0);

    PciData32 = MmioRead32 (LpcBaseAddr+0x80);
    PciData32 = 0x3F030010;
    MmioWrite32 (LpcBaseAddr+0x80,  PciData32);

    MmioWrite16 (PCH_PCR_ADDRESS (PID_DMI, R_PCH_DMI_PCR_LPCIOD),(UINT16) PciData32);
    MmioWrite16 (PCH_PCR_ADDRESS (PID_DMI, R_PCH_DMI_PCR_LPCIOE), (UINT16) (PciData32>> 16));

    
    PciData32 = MmioRead32 (LpcBaseAddr+0x80);
    
    PciData32 = MmioRead32 (LpcBaseAddr+0x84);
    PciData32 = 0x00FC0201;
//  MmioWrite32 (PCH_PCR_ADDRESS (PID_DMI, R_PCH_DMI_PCR_LPCLGIR3), PciData32);
    PchPcrWrite32 (PID_DMI, R_PCH_DMI_PCR_LPCLGIR1, PciData32);

    MmioWrite32 (LpcBaseAddr+0x84,  PciData32);
    

    for  (Idx = 0; Idx < sizeof(SioInitTable)/sizeof(SIO_INIT_TABLE); Idx ++) {
      IoWrite8 (pSioTbl->Index16, pSioTbl->Value8 );
      IoWrite8 (pSioTbl->Data16, pSioTbl->Data8 );
      pSioTbl = pSioTbl+1;
    }

}
//7583X003_1

/**
  Stitching process might pass some specific platform data to be
  consumed pretty early. This will be used to guide the platform initialization
  even before CFGDATA is available.

**/
VOID
EarlyPlatformDataCheck (
  VOID
  )
{
  STITCH_DATA          *StitchData;

  // Stitching process might pass some plafform specific data.
  StitchData = (STITCH_DATA *)(UINTN)0xFFFFFFF4;
  if (StitchData->Marker != 0xAA) {
    // PlatformID will be deferred to be detected
    SetDebugPort ( PcdGet8 (PcdDebugPortNumber));
  } else {
    SetDebugPort  (StitchData->DebugUart);
    if ((StitchData->PlatformId > 0) && (StitchData->PlatformId < 32)) {
      SetPlatformId (StitchData->PlatformId);
    }
  }
}

/**
  Board specific hook points.

  Implement board specific initialization during the boot flow.

  @param[in] InitPhase             Current phase in the boot flow.

**/
VOID
EFIAPI
BoardInit (
  IN  BOARD_INIT_PHASE  InitPhase
)
{
  UINT32                    MsrIdx;
  UINT32                    ImgLen;
  UINT32                    AdjLen;
  UINT64                    MskLen;
  UINT8                     DebugPort;

  switch (InitPhase) {
  case PostTempRamInit:
    DisableWatchDogTimer ();

    EarlyPlatformDataCheck ();
    DebugPort = GetDebugPort ();
    if (DebugPort < PCH_MAX_SERIALIO_UART_CONTROLLERS) {
      ConfigureGpio (CDATA_NO_TAG, 2, (UINT8 *)(mUartGpioTable + DebugPort * 2));
    }

//7583X003_1
    EarlySioInit ();  

    PlatformHookSerialPortInitialize ();
    SerialPortInitialize ();

    // Enlarge the code cache region to cover full flash for non-BootGuard case only
    if ((AsmReadMsr64(MSR_BOOT_GUARD_SACM_INFO) & B_BOOT_GUARD_SACM_INFO_NEM_ENABLED) == 0) {
      // WHL FSP-T does not allow to enable full flash code cache due to cache size restriction.
      // Here, MTRR is patched to enable full flash region cache to avoid performance penalty.
      // However, the SBL code flow should ensure only limited flash regions will be accessed
      // before FSP TempRamExit() is called. The combined DATA and CODE cache size should satisfy
      // the BWG requirement.
      MskLen = (AsmReadMsr64(MSR_CACHE_VARIABLE_MTRR_BASE + 1) | (SIZE_4GB - 1)) + 1;
      MsrIdx = MSR_CACHE_VARIABLE_MTRR_BASE + 1 * 2;
      ImgLen = PcdGet32(PcdFlashSize);
      AdjLen = GetPowerOfTwo32(ImgLen);
      if (ImgLen > AdjLen) {
        AdjLen <<= 1;
      }
      AsmWriteMsr64(MsrIdx, (SIZE_4GB - AdjLen) | CACHE_WRITEPROTECTED);
      AsmWriteMsr64(MsrIdx + 1, (MskLen - AdjLen) | B_CACHE_MTRR_VALID);
    }
    break;
  default:
    break;
  }
}

/**
  Get size of Platform Specific Data

  @param[in] none

  @retval    UINT32     Size of Platform Specific Data

**/
UINT32
EFIAPI
GetPlatformDataSize (
  IN  VOID
  )
{
  return sizeof (PLATFORM_DATA);
}

