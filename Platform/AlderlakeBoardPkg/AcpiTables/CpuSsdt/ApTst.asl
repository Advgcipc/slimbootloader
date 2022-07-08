/** @file

  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#define AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(INDEX, DOMAIN) \
  External(\_SB.PR##INDEX, DeviceObj) \
  If (CondRefOf (\_SB.PR##INDEX)) { \
    Scope(\_SB.PR##INDEX) \
    { \
      Method(_TPC, 0) \
      { \
        Return(\_SB.PR00._TPC) \
      } \
      Method(_PTC, 0) \
      { \
        Return(\_SB.PR00._PTC) \
      } \
      Method(_TSS, 0) \
      { \
        Return(\_SB.PR00._TSS) \
      } \
      Method(_TSD, 0) \
      { \
        Return(\_SB.PR00.GTSD(DOMAIN)) \
      } \
    } \
  }


DefinitionBlock(
  "APTST.aml",
  "SSDT",
  0x02,
  "PmRef",
  "ApTst",
  0x3000
  )
{
  External(\_SB.PR00._TPC, MethodObj)
  External(\_SB.PR00._PTC, MethodObj)
  External(\_SB.PR00._TSS, MethodObj)
  External(\_SB.PR00.GTSD, MethodObj)

  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(01, 1)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(02, 2)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(03, 3)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(04, 4)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(05, 5)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(06, 6)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(07, 7)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(08, 8)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(09, 9)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(10, 10)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(11, 11)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(12, 12)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(13, 13)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(14, 14)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(15, 15)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(16, 16)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(17, 17)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(18, 18)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(19, 19)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(20, 20)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(21, 21)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(22, 22)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(23, 23)

  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(24, 24)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(25, 25)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(26, 26)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(27, 27)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(28, 28)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(29, 29)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(30, 30)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(31, 31)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(32, 32)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(33, 33)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(34, 34)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(35, 35)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(36, 36)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(37, 37)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(38, 38)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(39, 39)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(40, 40)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(41, 41)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(42, 42)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(43, 43)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(44, 44)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(45, 45)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(46, 46)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(47, 47)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(48, 48)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(49, 49)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(50, 50)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(51, 51)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(52, 52)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(53, 53)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(54, 54)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(55, 55)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(56, 56)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(57, 57)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(58, 58)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(59, 59)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(60, 60)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(61, 61)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(62, 62)
  AP_SCOPE_TPC_PTC_TSS_TSD_METHOD(63, 63)


} // End of Definition Block

#undef AP_SCOPE_TPC_PTC_TSS_TSD_METHOD
