//**********************************************************************
//
// Name:  <A9610ECAsl.asl>
//
// Description: Define ACPI method or namespce for A9610 EC.
//
//**********************************************************************
Scope(\_SB.PC00.LPCB)
{
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

// EC SCI is connected to external GPE
//6883X005_5 >>
//Method(_GPE)
//{
//  If (\_SB.PC00.LPCB.ESPI)
//  {
//    Store (0x6E,  Local0)   // GPI6E for eSPI
//  }
//  return (Local0)
//}
//Name(_GPE, 0x44) // #GPP_E4  <- EC_SCI# @GPE_DW2
//                 // mapped to GPE[95:64]
//6883X005_5 <<
//7532X001_3    Name(_GPE, 0x01)  //6832X001_1  GP_D01, GPP_D to GPE_DW0 mapping to GPE[31:0]
  Name(_GPE, 0x6E)      //7532X001_3 ESPI_SCI
		/* ----------------------------------------------------------------*/
		// EC RAM fields
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
//6832X015_1                        CTMP, 16,       // EC CPU Temperature         0x70   (2 Bytes)
//6832X015_1                        STMP, 16,       // EC System Temperature      0x72   (2 Bytes)
//6832X015_1 - start
			TRM0, 16,   // THERM0 Temperature         0x70   (2 Bytes)
			TRM1, 16,   // THERM1 Temperature         0x72   (2 Bytes)
			TRM2, 16,   // THERM2 Temperature         0x74   (2 Bytes)
			TRM3, 16,   // THERM3 Temperature         0x76   (2 Bytes)
			TCT0, 16,   // THERM0 Critical Temp       0x78   (2 Bytes)
			TCT1, 16,   // THERM1 Critical Temp       0x7A   (2 Bytes)
			TCT2, 16,   // THERM2 Critical Temp       0x7C   (2 Bytes)
			TCT3, 16,   // THERM3 Critical Temp       0x7E   (2 Bytes)
//6832X015_1 - end
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
			Offset(0xE0),
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

//6832X015_1		Method(_REG, 2) {
//6832X015_1			If(LEqual(Arg0, 0x3)) {
//6832X015_1				Store(Arg1, ECF)
//6832X015_1			}
//6832X015_1		}
//6832X015_1 - start
		Name(ECAV, Zero)   // OS Bug Checks if EC OpRegion accessed before Embedded Controller Driver loaded
		Method(_REG, 2)
		{
			// When OS runs _REG control method with Arg0 = 3 (Embedded Controller Operation Region) and Arg1 = 1 (connect the handler)
			If (LAnd(LEqual(Arg0,3),LEqual(Arg1,1)))
			{
				// Must be running NT 5.0 OS or newer.
				EREG()
			}
		}

		// The _REG Method will not evaluated if ECDT is loaded by OS with ECDT support
		// Uising _INI Method to cover EC initialization done in _REG
		Method(_INI)
		{
		    EREG()
		}

		// EREG method will be used in _REG (evaluated by OS without ECDT support) or _INI (for OS with ECDT support)
		Method(EREG)
		{
		  // Update ECAV Object. ASL should check for this value to be One before accessing EC OpRegion.
		  Store(One, ECAV)
		  Notify(\_TZ.TZ02, 0x81)
		}
//6832X015_1 - end
		
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
//			Notify(\_SB.PC00.LPCB.EC0.LID1,0x80)
		}
		Method(_Q22) {          	// ACPI LID break event
			store(0x22,DBG1)
//			Notify(\_SB.PC00.LPCB.EC0.LID1,0x80)
		}
		Method(_Q23) {          	// ACPI Sleep button event
			store(0x50,DBG1)
//			Notify(\_SB.PC00.LPCB.EC0.SLPB,0x80)
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
//6832X015_1		Method(_Q60) {          	// Warn temperature event
//6832X015_1			store(0x60,DBG1)
//6832X015_1		}
//6832X015_1 - start
    Method(_Q60) {              // Thermal Critial event
      store(0x60,DBG1)
      Notify(\_TZ.TZ02, 0x81)
    }
    Method(_Q61) {              // Thermal Status changed
//      store(0x61,DBG1)
      Notify(\_TZ.TZ02, 0x80)
    }
//6832X015_1 - end
	} // end of Device(EC0)
} // end of Scope(\_SB.PC00.LPCB)

Scope(\){
	Name(ECF,Zero)
	Name(ECCT, 5)

        OperationRegion(\DEBG, SystemIO, 0x80, 0x1)
	Field(\DEBG, ByteAcc, NoLock, Preserve) {
		DBG1, 8,
	}
}

//6832X001_1 - start
Scope(\_GPE) {                  // System Bus scope

  Method(_L42, 0) {             //SMB_ALT1 SMB_ALT1/GPP_C2, GPP_C to GPE_DW2 mapping to GPE[95:64]
	store(0x53, DBG1)
//    Notify(\_SB.PWRB, 0x80)
  }

} // end _GPE scope
//6832X001_1 - end
//6832X015_1 - start
Scope(\_TZ)
{
    ThermalZone(TZ02)
    {
        // Notifies ASL Code the current cooling mode.
        //	0 - Active cooling
        //	1 - Passive cooling
        Method(_SCP, 1, Serialized)
        {
            //Store(Arg0,\CTYP)
        }

        Method(_TMP, 0, Serialized)
        {
            Return(\_SB.PC00.LPCB.EC0.TRM0)
        }

        // Return the temperature at which the OS performs Critical Shutdown
        Method(_CRT, 0, Serialized)
        {
            Store(\_SB.PC00.LPCB.EC0.TCT0, Local0)
            Return(Local0)
        }
    } // ThermalZone(TZ02)
} // Scope(\_TZ)
//6832X015_1 - end
