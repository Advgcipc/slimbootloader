/** @file
  ACPI Common Include File for PCIE RP ACPI Objects.

@copyright
  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <PcieRpMacroDefinition.h>


//
// MACRO Definations for Printing PCIE RP Info: Start
// Note: These below MACRO will only work under PCIE RP Scope.
//
#define GET_STRING_PCIE_RP_INDEX_FROM_SLOT_VAR   Concatenate(" And Index : ", ToHexString(SLOT))
#define GET_STRING_PCIE_RP_TYPE_FROM_PRTP_VAR    Concatenate(" Type (2: PCH, 4: CPU) : ", ToHexString(PRTP))
#define GET_STRING_PCIE_RP_INFO_PRTP_SLOT        Concatenate(GET_STRING_PCIE_RP_TYPE_FROM_PRTP_VAR, GET_STRING_PCIE_RP_INDEX_FROM_SLOT_VAR)
#define GET_STRING_PCIE_RP_INFO                  Concatenate("PCIE RP", GET_STRING_PCIE_RP_INFO_PRTP_SLOT)
//
// Note: These above MACRO will only work under PCIE RP Scope.
// MACRO Definations for Printing PCIE RP Info: End
//

External (\_SB.PC00,DeviceObj)
// External Variable for PCIE Rp Device Objects
External (\_SB.PC00.RP01, DeviceObj)
External (\_SB.PC00.RP02, DeviceObj)
External (\_SB.PC00.RP03, DeviceObj)
External (\_SB.PC00.RP04, DeviceObj)
External (\_SB.PC00.RP05, DeviceObj)
External (\_SB.PC00.RP06, DeviceObj)
External (\_SB.PC00.RP07, DeviceObj)
External (\_SB.PC00.RP08, DeviceObj)
External (\_SB.PC00.RP09, DeviceObj)
External (\_SB.PC00.RP10, DeviceObj)
External (\_SB.PC00.RP11, DeviceObj)
External (\_SB.PC00.RP12, DeviceObj)
External (\_SB.PC00.RP13, DeviceObj)
External (\_SB.PC00.RP14, DeviceObj)
External (\_SB.PC00.RP15, DeviceObj)
External (\_SB.PC00.RP16, DeviceObj)
External (\_SB.PC00.RP17, DeviceObj)
External (\_SB.PC00.RP18, DeviceObj)
External (\_SB.PC00.RP19, DeviceObj)
External (\_SB.PC00.RP20, DeviceObj)
External (\_SB.PC00.RP21, DeviceObj)
External (\_SB.PC00.RP22, DeviceObj)
External (\_SB.PC00.RP23, DeviceObj)
External (\_SB.PC00.RP24, DeviceObj)
External (\_SB.PC00.RP25, DeviceObj)
External (\_SB.PC00.RP26, DeviceObj)
External (\_SB.PC00.RP27, DeviceObj)
External (\_SB.PC00.RP28, DeviceObj)

External (\_SB.PC00.PEG0, DeviceObj)
External (\_SB.PC00.PEG1, DeviceObj)
External (\_SB.PC00.PEG2, DeviceObj)

// External Variable holding PCIE Rp Mapped under VMD status
External (\_SB.PC00.RP01.PRMV, IntObj)
External (\_SB.PC00.RP02.PRMV, IntObj)
External (\_SB.PC00.RP03.PRMV, IntObj)
External (\_SB.PC00.RP04.PRMV, IntObj)
External (\_SB.PC00.RP05.PRMV, IntObj)
External (\_SB.PC00.RP06.PRMV, IntObj)
External (\_SB.PC00.RP07.PRMV, IntObj)
External (\_SB.PC00.RP08.PRMV, IntObj)
External (\_SB.PC00.RP09.PRMV, IntObj)
External (\_SB.PC00.RP10.PRMV, IntObj)
External (\_SB.PC00.RP11.PRMV, IntObj)
External (\_SB.PC00.RP12.PRMV, IntObj)
External (\_SB.PC00.RP13.PRMV, IntObj)
External (\_SB.PC00.RP14.PRMV, IntObj)
External (\_SB.PC00.RP15.PRMV, IntObj)
External (\_SB.PC00.RP16.PRMV, IntObj)
External (\_SB.PC00.RP17.PRMV, IntObj)
External (\_SB.PC00.RP18.PRMV, IntObj)
External (\_SB.PC00.RP19.PRMV, IntObj)
External (\_SB.PC00.RP20.PRMV, IntObj)
External (\_SB.PC00.RP21.PRMV, IntObj)
External (\_SB.PC00.RP22.PRMV, IntObj)
External (\_SB.PC00.RP23.PRMV, IntObj)
External (\_SB.PC00.RP24.PRMV, IntObj)
External (\_SB.PC00.RP25.PRMV, IntObj)
External (\_SB.PC00.RP26.PRMV, IntObj)
External (\_SB.PC00.RP27.PRMV, IntObj)
External (\_SB.PC00.RP28.PRMV, IntObj)

External (\_SB.PC00.PEG0.PRMV, IntObj)
External (\_SB.PC00.PEG1.PRMV, IntObj)
External (\_SB.PC00.PEG2.PRMV, IntObj)


// External Variable holding PCIE Rp Index Number
External (\_SB.PC00.RP01.SLOT, IntObj)
External (\_SB.PC00.RP02.SLOT, IntObj)
External (\_SB.PC00.RP03.SLOT, IntObj)
External (\_SB.PC00.RP04.SLOT, IntObj)
External (\_SB.PC00.RP05.SLOT, IntObj)
External (\_SB.PC00.RP06.SLOT, IntObj)
External (\_SB.PC00.RP07.SLOT, IntObj)
External (\_SB.PC00.RP08.SLOT, IntObj)
External (\_SB.PC00.RP09.SLOT, IntObj)
External (\_SB.PC00.RP10.SLOT, IntObj)
External (\_SB.PC00.RP11.SLOT, IntObj)
External (\_SB.PC00.RP12.SLOT, IntObj)
External (\_SB.PC00.RP13.SLOT, IntObj)
External (\_SB.PC00.RP14.SLOT, IntObj)
External (\_SB.PC00.RP15.SLOT, IntObj)
External (\_SB.PC00.RP16.SLOT, IntObj)
External (\_SB.PC00.RP17.SLOT, IntObj)
External (\_SB.PC00.RP18.SLOT, IntObj)
External (\_SB.PC00.RP19.SLOT, IntObj)
External (\_SB.PC00.RP20.SLOT, IntObj)
External (\_SB.PC00.RP21.SLOT, IntObj)
External (\_SB.PC00.RP22.SLOT, IntObj)
External (\_SB.PC00.RP23.SLOT, IntObj)
External (\_SB.PC00.RP24.SLOT, IntObj)
External (\_SB.PC00.RP25.SLOT, IntObj)
External (\_SB.PC00.RP26.SLOT, IntObj)
External (\_SB.PC00.RP27.SLOT, IntObj)
External (\_SB.PC00.RP28.SLOT, IntObj)

External (\_SB.PC00.PEG0.SLOT, IntObj)
External (\_SB.PC00.PEG1.SLOT, IntObj)
External (\_SB.PC00.PEG2.SLOT, IntObj)

// External Variable holding PCIE Rp Type Information
External (\_SB.PC00.RP01.PRTP, IntObj)
External (\_SB.PC00.RP02.PRTP, IntObj)
External (\_SB.PC00.RP03.PRTP, IntObj)
External (\_SB.PC00.RP04.PRTP, IntObj)
External (\_SB.PC00.RP05.PRTP, IntObj)
External (\_SB.PC00.RP06.PRTP, IntObj)
External (\_SB.PC00.RP07.PRTP, IntObj)
External (\_SB.PC00.RP08.PRTP, IntObj)
External (\_SB.PC00.RP09.PRTP, IntObj)
External (\_SB.PC00.RP10.PRTP, IntObj)
External (\_SB.PC00.RP11.PRTP, IntObj)
External (\_SB.PC00.RP12.PRTP, IntObj)
External (\_SB.PC00.RP13.PRTP, IntObj)
External (\_SB.PC00.RP14.PRTP, IntObj)
External (\_SB.PC00.RP15.PRTP, IntObj)
External (\_SB.PC00.RP16.PRTP, IntObj)
External (\_SB.PC00.RP17.PRTP, IntObj)
External (\_SB.PC00.RP18.PRTP, IntObj)
External (\_SB.PC00.RP19.PRTP, IntObj)
External (\_SB.PC00.RP20.PRTP, IntObj)
External (\_SB.PC00.RP21.PRTP, IntObj)
External (\_SB.PC00.RP22.PRTP, IntObj)
External (\_SB.PC00.RP23.PRTP, IntObj)
External (\_SB.PC00.RP24.PRTP, IntObj)
External (\_SB.PC00.RP25.PRTP, IntObj)
External (\_SB.PC00.RP26.PRTP, IntObj)
External (\_SB.PC00.RP27.PRTP, IntObj)
External (\_SB.PC00.RP28.PRTP, IntObj)

External (\_SB.PC00.PEG0.PRTP, IntObj)
External (\_SB.PC00.PEG1.PRTP, IntObj)
External (\_SB.PC00.PEG2.PRTP, IntObj)

// External Variable holding PCIE Rp RTD3 Cold Capability
External (\_SB.PC00.RP01.RD3C, IntObj)
External (\_SB.PC00.RP02.RD3C, IntObj)
External (\_SB.PC00.RP03.RD3C, IntObj)
External (\_SB.PC00.RP04.RD3C, IntObj)
External (\_SB.PC00.RP05.RD3C, IntObj)
External (\_SB.PC00.RP06.RD3C, IntObj)
External (\_SB.PC00.RP07.RD3C, IntObj)
External (\_SB.PC00.RP08.RD3C, IntObj)
External (\_SB.PC00.RP09.RD3C, IntObj)
External (\_SB.PC00.RP10.RD3C, IntObj)
External (\_SB.PC00.RP11.RD3C, IntObj)
External (\_SB.PC00.RP12.RD3C, IntObj)
External (\_SB.PC00.RP13.RD3C, IntObj)
External (\_SB.PC00.RP14.RD3C, IntObj)
External (\_SB.PC00.RP15.RD3C, IntObj)
External (\_SB.PC00.RP16.RD3C, IntObj)
External (\_SB.PC00.RP17.RD3C, IntObj)
External (\_SB.PC00.RP18.RD3C, IntObj)
External (\_SB.PC00.RP19.RD3C, IntObj)
External (\_SB.PC00.RP20.RD3C, IntObj)
External (\_SB.PC00.RP21.RD3C, IntObj)
External (\_SB.PC00.RP22.RD3C, IntObj)
External (\_SB.PC00.RP23.RD3C, IntObj)
External (\_SB.PC00.RP24.RD3C, IntObj)
External (\_SB.PC00.RP25.RD3C, IntObj)
External (\_SB.PC00.RP26.RD3C, IntObj)
External (\_SB.PC00.RP27.RD3C, IntObj)
External (\_SB.PC00.RP28.RD3C, IntObj)

External (\_SB.PC00.PEG0.RD3C, IntObj)
External (\_SB.PC00.PEG1.RD3C, IntObj)
External (\_SB.PC00.PEG2.RD3C, IntObj)
