//**********************************************************************
//
// Name:  <A9610ECAsl.asl>
//
// Description: Define ACPI method or namespce for A9610 EC.
//
//**********************************************************************
//Scope(\_SB.PC00.LPCB)
//{
	Device(EC0)
	{
		// PnP ID
		Name(_HID,  EISAID("PNP0C09"))

        Name(_UID,0)
	        // EC resources
        Name(_CRS,ResourceTemplate() {
          IO(Decode16,0x62,0x62,0,1)
          IO(Decode16,0x66,0x66,0,1)
        })

Name(_GPE, 0x44) // #GPP_E4  <- EC_SCI# @GPE_DW2
                 // mapped to GPE[95:64]
		/* ----------------------------------------------------------------*/
		// EC RAM fields
		/* ----------------------------------------------------------------*/
		OperationRegion(ERAM,EmbeddedControl, 0, 0x100)
		Field(ERAM, ByteAcc, Lock, Preserve)
		{
			Offset(0x28),
			BCNT, 32,	// Boot Count                 0x28   (4 Bytes)
			RHUR, 32,	// Running Hours              0x2C   (4 Bytes)
			PC0S, 8,	// PMC0 Status                0x30   (1 Bytes)
			PC1S, 8,	// PMC1 Status                0x31   (1 Bytes)
			SFLG, 8,	// System Flag                0x32   (1 Bytes)
			COPR, 8,	// Case Open Register         0x33   (1 Bytes)
			Offset(0x40),                           
			P0DC, 8,	// PWM0 Duty Cycle            0x40   (1 Bytes)
			P1DC, 8,	// PWM1 Duty Cycle            0x41   (1 Bytes)
			P2DC, 8,	// PWM2 Duty Cycle            0x42   (1 Bytes)
			Offset(0x44),                           
			P0FQ, 32,	// PWM0 Frequency             0x44   (4 Bytes)  
			P1FQ, 32,	// PWM1 Frequency             0x48   (4 Bytes)  
			P2FQ, 32,	// PWM2 Frequency             0x4C   (4 Bytes)
			TA0P, 8,	// TACH0 Pulse                0x50   (1 Bytes)
			TA1P, 8,	// TACH1 Pulse                0x51   (1 Bytes)
			Offset(0x54),                           
			TA0R, 32,	// TACH0 RPM                  0x54   (4 Bytes)
			TA1R, 32,	// TACH1 RPM                  0x58   (4 Bytes)
			Offset(0x60),                           
			ADC0, 16,	// ADC0 Real Value            0x60   (2 Bytes)  
			ADC1, 16,	// ADC1 Real Value            0x62   (2 Bytes) 
			ADC2, 16,	// ADC2 Real Value            0x64   (2 Bytes)
			ADC3, 16,	// ADC3 Real Value            0x66   (2 Bytes)
			ADC4, 16,	// ADC4 Real Value            0x68   (2 Bytes)
			Offset(0x70),                          
      CTMP, 16, // EC CPU Temperature         0x70   (2 Bytes)
      STMP, 16, // EC System Temperature      0x72   (2 Bytes)
			Offset(0x80),
			GDV0, 8,	// GPIO Data Registers (GP00) 0x80   (1 Bytes)
			GDV1, 8,	// GPIO Data Registers (GP01) 0x81   (1 Bytes)
			GDV2, 8,	// GPIO Data Registers (GP20) 0x82   (1 Bytes)
			GDV3, 8,	// GPIO Data Registers (GP21) 0x83   (1 Bytes)
			GDV4, 8,	// GPIO Data Registers (GP30) 0x84   (1 Bytes)
			GDV5, 8,	// GPIO Data Registers (GP31) 0x85   (1 Bytes)
			GDV6, 8,	// GPIO Data Registers (GP32) 0x86   (1 Bytes)
			GDV7, 8,	// GPIO Data Registers (GP33) 0x87   (1 Bytes)
			GDV8, 8,	// GPIO Data Registers (GP34) 0x88   (1 Bytes)
			GDV9, 8,	// GPIO Data Registers (GP35) 0x89   (1 Bytes)
			GDVA, 8,	// GPIO Data Registers (GP36) 0x8A   (1 Bytes)
			GDVB, 8,	// GPIO Data Registers (GP37) 0x8B   (1 Bytes)
			Offset(0x90),
			GDR0, 8,	// GPIO Direction Registers (GP00) 0x90   (1 Bytes)
			GDR1, 8,	// GPIO Direction Registers (GP01) 0x91   (1 Bytes)
			GDR2, 8,	// GPIO Direction Registers (GP20) 0x92   (1 Bytes)
			GDR3, 8,	// GPIO Direction Registers (GP21) 0x93   (1 Bytes)
			GDR4, 8,	// GPIO Direction Registers (GP30) 0x94   (1 Bytes)
			GDR5, 8,	// GPIO Direction Registers (GP31) 0x95   (1 Bytes)
			GDR6, 8,	// GPIO Direction Registers (GP32) 0x96   (1 Bytes)
			GDR7, 8,	// GPIO Direction Registers (GP33) 0x97   (1 Bytes)
			GDR8, 8,	// GPIO Direction Registers (GP34) 0x98   (1 Bytes)
			GDR9, 8,	// GPIO Direction Registers (GP35) 0x99   (1 Bytes)
			GDRA, 8,	// GPIO Direction Registers (GP36) 0x9A   (1 Bytes)
			GDRB, 8,	// GPIO Direction Registers (GP37) 0x9B   (1 Bytes)
			Offset(0xC0),
			WDGC, 8,	// Watch dog Control Register 0xC0   (1 Bytes)
			Offset(0xC8),
			WDDT, 32,	// Watch dog Delay Time       0xC8   (4 Bytes)
			WPCT, 32,	// Watch dog Power Cycle Time 0xCC   (4 Bytes)
			WDIT, 32,	// Watch dog IRQ Time         0xD0   (4 Bytes)
			WDST, 32,	// Watch dog SCI Time         0xD4   (4 Bytes)
			WDOT, 32,	// Watch dog Pin Output Time  0xD8   (4 Bytes)
			WDRT, 32,	// Watch dog Reset Time       0xDD   (4 Bytes)
			BNSS, 32,	// Board Name String          0xE0   (16 Bytes)
			FMAJ, 8,	// F/W Major Version          0xF0   (1 Bytes)
			FMIN, 8,	// F/W Minor Version          0xF1   (1 Bytes)
			FREV, 16,	// F/W Revision Number        0xF2   (2 Bytes)
			Offset(0xF8),
			FPID, 16,	// Project ID                 0xF8   (2 Bytes)
			FICV, 8,	// IC Vendor                  0xFA   (1 Bytes)
			FICC, 8,	// IC Code                    0xFB   (1 Bytes)
			FWCB, 8,	// F/W Code Base              0xFC   (1 Bytes)
			FWTP, 8,	// F/W Type                   0xFD   (1 Bytes)
		}

		Method(_REG, 2) {
			If(LEqual(Arg0, 0x3)) {
				Store(Arg1, ECF)
			}
		}
		
		Device(LID1) {
			Name(_HID,EISAID("PNP0C0D"))
			Method(_STA) {
				Return(0x0F)
			}
			Method(_LID,0) {
				// 0 = Closed, 1 = Open.
				Return(1)
			}
		}

		Device(SLPB) {
      Name(_HID,EISAID("PNP0C0E"))
      Method(_STA,0,NotSerialized){
        Return(0x0F)
      }
		}

		Method(_Q21) {          	// ACPI LID make event
			store(0x51,DBG1)
		}

		Method(_Q22) {          	// ACPI LID break event
			store(0x22,DBG1)
		}

		Method(_Q23) {          	// ACPI Sleep button event
			store(0x50,DBG1)
		}

		Method(_Q30) {                  // WDIN button event
			store(0x30,DBG1)
		}

		Method(_Q50) {          	// Adapter event
		}

		Method(_Q51) {          	// Battery event
			store(0x52,DBG1)
		}

		Method(_Q52) {                  // power button event
			Notify(\_SB.PWRB,0x80)
		}

		Method(_Q53) {          	// Battery status event
		}

		Method(_Q60) {          	// Warn temperature event
			store(0x60,DBG1)
		}

	} // end of Device(EC0)

			Device(UAR1) {
				Name(_UID, 0x00)	// Unique ID.
				Name(LDN, 0x03)	// Logical Device Number
			
	      Name(_CID, EISAID("PNP0501"))                   //PnP Device ID 16550 Type
	      Name(_HID, EISAID("AHC0501"))                   //Advantech Device ID for RDC UART 16550
	      Name(_DDN, "COM1")
        Name(_STA, 0xF)

        Name(CRS1, ResourceTemplate(){
		    	IO(Decode16, 0x3F8, 0x3F8, 1, 8)
		    	IRQNoFlags() {4}
		    	DMA(Compatibility, NotBusMaster, Transfer8) {}
        })
	      Method(_CRS, 0) {Return(CRS1)}	//Get UART current resources

			}	//End of UAR1

			Device(UAR2) {
				Name(_UID, 0x01)	// Unique ID.
				Name(LDN, 0x03)	// Logical Device Number
	      Name(_CID, EISAID("PNP0501"))                   //PnP Device ID 16550 Type
	      Name(_HID, EISAID("AHC0501"))                   //Advantech Device ID for RDC UART 16550
	      Name(_DDN, "COM2")
        Name(_STA, 0xF)

        Name(CRS2, ResourceTemplate(){
		    	IO(Decode16, 0x2F8, 0x2F8, 1, 8)
		    	IRQNoFlags() {3}
		    	DMA(Compatibility, NotBusMaster, Transfer8) {}
        })
	      Method(_CRS, 0) {
//	      \SDBM("SBL UART2 CRS")
 
	      Return(CRS2)}	//Get UART current resources
			}	//End of UAR2

Scope(\){
	Name(ECF,Zero)
	Name(ECCT, 5)

  OperationRegion(\DEBG, SystemIO, 0x80, 0x1)
	Field(\DEBG, ByteAcc, NoLock, Preserve) {
		DBG1, 8,
	}

  Method (SDBM, 1, Serialized)
  {
    OperationRegion (S3F8, SystemIO, 0x3f8, 0x10)
    Field (S3F8, ByteAcc, Lock, Preserve)
    {
      TXBF,   8, 
      DLM,    8, 
      FCR,    8, 
      LCR,    8
    }
  
//    If (LEqual(\SDBA,1)) {
      Store (0x83, LCR)
      Store (1, TXBF)
      Store (0, DLM)
      Store (0xE1, FCR)
      Store (0x03, LCR)
      Store (0, DLM)
      
      ToHexString (Arg0, Local3)
      Store (SizeOf (Local3), Local4)
      Store (Zero, Local5)
      While(LLess(Local5, Local4))
      {
        Mid (Local3, Local5, One, TXBF) /* \SDBG.TXBF */
        Stall (100)
        Increment(Local5)
      }
      
      Stall (100)
      Store (0x0D, TXBF)
      Stall (100)
      Store (0x0A, TXBF)
//    }
  } // SDBM method for ACPI debug message

}

Scope(\_GPE) {        // System Bus scope
    Method(_L02, 0) { // GPP_C2  SMB_ALT_PCH# @GPE_DW0
                      // mapped to GPE[31:0]
	  store(0x53,DBG1)
  }
} // end _GPE scope
