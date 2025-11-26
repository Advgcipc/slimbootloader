/** @file

  Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

// LPC Bridge - Device 31, Function 0
scope (\_SB.PC00.LPCB) {

      Include ("LpcDev.asl")
      //Include ("H8S2113Sio.asl")
//6884V105_3      Include ("IteSio.asl")
      Include ("A9610ECAsl.asl")  //6884V105_3
      If (LEqual(\ECON,1)){
            Include ("EC.ASL")

      }
}
