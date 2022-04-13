/** @file

  Copyright (c) 2017 - 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Library/GpioLib.h>
#include <GpioConfig.h>
#include <GpioPinsCmlH.h>
#include <GpioPinsCmlLp.h>
/*
//
// GPIO_PAD Fileds
//
typedef struct {
  UINT32    PadNum:16;
  UINT32    GrpIdx:8;
  UINT32    ChipsetId:4;
  UINT32    Rsvd:4;
} GPIO_PAD_FIELD;

//
// GPIO_CFG_DATA DW1 fields
//
typedef struct {
  UINT32    Rsvd1:16;
  UINT32    PadNum:8;
  UINT32    GrpIdx:5;
  UINT32    Rsvd2:3;
} GPIO_CFG_DATA_DW1;

#define CNL_LP_CHIPSET_ID   0x4
#define CNL_H_CHIPSET_ID    0x3
*/
//
// CML S 82 UDIMM GPIO TBL
//
static GPIO_INIT_CONFIG mGpioTableCmlS82Ddr4PreMem[] =
{
  // PEG slot
  {GPIO_CNL_H_GPP_F22,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//GPIO_PEG SLOT_RESET
// AIMB-287.X004.a - START
#if 0
// AIMB-287.X004.a - END
  // turn on power in premem after reset asserted
  {GPIO_CNL_H_GPP_F8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//DGPU_PWR_EN_N
  {GPIO_CNL_H_GPP_K22,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_PEGSLOT1_PWREN
  {GPIO_CNL_H_GPP_K10,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//PCH_RST_GPIO for PEG aux power
  // Titan Ridge
  {GPIO_CNL_H_GPP_K1,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioHostDeepReset, GpioTermWpu2K, GpioPadConfigLock }},//PLX_SX_ENTRY_G1_PCH_N
  //Asserting power pin enable in pre-mem phase to solve some NVMe devices cannot be detected.
  {GPIO_CNL_H_GPP_I10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh,    GpioIntDefault, GpioPlatformReset, GpioTermNone }},//GPP_I_10_DDPD_CTRLDATA
// AIMB-287.X004.a - START
#else

  //                            Pmode,        GPI_IS,        GpioDir,   GPIOTxState,  RxEvCfg,      GPIRoutConfig,     PadRstCfg,  Term,
  {GPIO_CNL_H_GPP_A0,  { GpioPadModeNative3, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone }},//ESPI_ALERT1#
  {GPIO_CNL_H_GPP_A1,  { GpioPadModeNative3, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone }},//ESPI_a_IO0
  {GPIO_CNL_H_GPP_A2,  { GpioPadModeNative3, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone }},//ESPI_a_IO1
  {GPIO_CNL_H_GPP_A3,  { GpioPadModeNative3, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone }},//ESPI_a_IO2
  {GPIO_CNL_H_GPP_A4,  { GpioPadModeNative3, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone }},//ESPI_a_IO3
  {GPIO_CNL_H_GPP_A5,  { GpioPadModeNative3, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone }},//ESPI_CS0#  
  {GPIO_CNL_H_GPP_A7,  { GpioPadModeNative3, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone }},//ESPI_ALERT0#
  {GPIO_CNL_H_GPP_A9,  { GpioPadModeNative3, GpioHostOwnDefault, GpioDirOut, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermWpd20K }},//ESPI_a_CLK
  {GPIO_CNL_H_GPP_A11, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermNone }},//PCH_PME#
  {GPIO_CNL_H_GPP_A13, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone }},//PCH_SUSWARN#  
  {GPIO_CNL_H_GPP_A14, { GpioPadModeNative3, GpioHostOwnDefault, GpioDirOut, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone }},//eSPI_RESET#
  {GPIO_CNL_H_GPP_A15, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//PCH_SUSACK#  
  {GPIO_CNL_H_GPP_A17, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirIn, GpioOutDefault, GpioIntEdge | GpioIntSci, GpioHostDeepReset , GpioTermNone, GpioPadConfigUnlock }},//PCH_RI#
  {GPIO_CNL_H_GPP_A18, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioResetDefault, GpioTermDefault }},//MB_ID0
  {GPIO_CNL_H_GPP_A19, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermNone }},//MB_ID1
  {GPIO_CNL_H_GPP_A20, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioResetDefault, GpioTermDefault }},//MB_ID2
  {GPIO_CNL_H_GPP_A21, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermNone }},//MB_ID3
  {GPIO_CNL_H_GPP_A22, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermNone }},//MB_ID4
  {GPIO_CNL_H_GPP_A23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermNone }},//MB_ID5
  {GPIO_CNL_H_GPP_A6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}},//NL
  {GPIO_CNL_H_GPP_A8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDis, GpioPlatformReset, GpioTermNone }},//TP, GPP_A8
  {GPIO_CNL_H_GPP_A10, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}},//NL
  {GPIO_CNL_H_GPP_A16, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetDefault, GpioTermDefault }},//TP_CLK48M_PCH TP30

  {GPIO_CNL_H_GPP_B2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_UART_WAKE#
  {GPIO_CNL_H_GPP_B3,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//M2E1_BT_DISABLE#
  {GPIO_CNL_H_GPP_B12, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault  , GpioPlatformReset , GpioTermNone }},//TP, PCH_SLP_S0#
  {GPIO_CNL_H_GPP_B13, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermNone }},//PLTRST_PCH#
  {GPIO_CNL_H_GPP_B14, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioResetDefault, GpioTermNone }},//SPKR

  {GPIO_CNL_H_GPP_C8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//EN_+USBV2
  {GPIO_CNL_H_GPP_C9,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//EN_+USBV1
  {GPIO_CNL_H_GPP_C10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//EN_+USBV4
  {GPIO_CNL_H_GPP_C11, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//EN_+USBV3
  {GPIO_CNL_H_GPP_C0,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//SMB_CLK_RESUME
  {GPIO_CNL_H_GPP_C1,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//SMB_DAT_RESUME
  {GPIO_CNL_H_GPP_C2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//ME_CRYPTO
  {GPIO_CNL_H_GPP_C3,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//SML0CLK
  {GPIO_CNL_H_GPP_C4,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//SML0DATA
  {GPIO_CNL_H_GPP_C5,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_GPP_C5 //ESPI/LPC SELECT STRAP, HIGH:eSPI (Default)
  {GPIO_CNL_H_GPP_C6,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//SML1CLK
  {GPIO_CNL_H_GPP_C7,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//SML1DATA
  {GPIO_CNL_H_GPP_C12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C16, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C17, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C18, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C19, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C20, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C21, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C22, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL
  {GPIO_CNL_H_GPP_C23, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NL


  {GPIO_CNL_H_GPP_D0,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D1,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D3,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D4,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP_PCH_GPP_D4
  {GPIO_CNL_H_GPP_D5,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D6,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D9,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_D10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_D11, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_GPP_D11
  {GPIO_CNL_H_GPP_D12, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_GPP_D12
  {GPIO_CNL_H_GPP_D13, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_D14, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_D15, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_D16, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_D17, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D18, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D19, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D20, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_D21, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_D22, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_D23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP_PCH_GPP_D23 TP
  
  {GPIO_CNL_H_GPP_E0,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//SATAXPCIE0
  {GPIO_CNL_H_GPP_E1,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//SATAXPCIE1
  {GPIO_CNL_H_GPP_E2,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//SATAXPCIE2
  {GPIO_CNL_H_GPP_E3,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//PCH_GPP_E3
  {GPIO_CNL_H_GPP_E4,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//M.2_M_DEVSLP
  {GPIO_CNL_H_GPP_E5,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_E6,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_E7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_E8,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//SATA_PCH_LED#
  {GPIO_CNL_H_GPP_E9,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//USB2_OC#12
  {GPIO_CNL_H_GPP_E10, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//USB2_OC#34
  {GPIO_CNL_H_GPP_E11, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//USB2_OC#56
  {GPIO_CNL_H_GPP_E12, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//USB2_OC#78
  
  {GPIO_CNL_H_GPP_F0,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//SATAXPCIE3
  {GPIO_CNL_H_GPP_F1,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//SATAXPCIE4
  {GPIO_CNL_H_GPP_F2,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//SATAXPCIE5
  {GPIO_CNL_H_GPP_F3,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//SATAXPCIE6
  {GPIO_CNL_H_GPP_F4,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//SATAXPCIE7
  {GPIO_CNL_H_GPP_F5,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_F6,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//ATX_AT#_SEL
  {GPIO_CNL_H_GPP_F7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_F8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_F9,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_F10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_CONFIG
  {GPIO_CNL_H_GPP_F11, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntLevel, GpioPlatformReset, GpioTermNone }},//PCH_RSVD
  {GPIO_CNL_H_GPP_F12, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntLevel, GpioPlatformReset, GpioTermNone }},//PCH_SV_ADVANCE_GP48 // 1:NORMAL MENU(Default)
  {GPIO_CNL_H_GPP_F13, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_GP39_GFX_CRB_DETECT  
  {GPIO_CNL_H_GPP_F14, { GpioPadModeNative2, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermNone }},//TP, PSON#
  {GPIO_CNL_H_GPP_F15, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},        //USB2_OC#910
  {GPIO_CNL_H_GPP_F16, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_F17, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_F18, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL 
  {GPIO_CNL_H_GPP_F19, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//EDP_VDDEN
  {GPIO_CNL_H_GPP_F20, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//EDP_BKLTEN
  {GPIO_CNL_H_GPP_F21, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//EDP_BKLTCTL
  {GPIO_CNL_H_GPP_F23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//GPIO_WLAN_RST_N
  
  {GPIO_CNL_H_GPP_G0,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_G1,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_G2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_G3,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_G4,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_G5,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_G6,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP
  {GPIO_CNL_H_GPP_G7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//TP

  {GPIO_CNL_H_GPP_H10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_H11, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_H12, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntLevel, GpioPlatformReset, GpioTermNone }},//PCH_GPP_H12  
  {GPIO_CNL_H_GPP_H13, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_GPP_H13 
  {GPIO_CNL_H_GPP_H14, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_H15, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntLevel, GpioPlatformReset, GpioTermNone }},//GPP_H15
  {GPIO_CNL_H_GPP_H16, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_H17, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_H18, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_H19, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_H20, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_H21, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_H22, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_H23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntLevel, GpioPlatformReset, GpioTermNone }},//PCH_GPIO_H23
  
  {GPIO_CNL_H_GPP_I0,  { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//DDPB_HPD
  {GPIO_CNL_H_GPP_I1,  { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//DDPC_HPD
  {GPIO_CNL_H_GPP_I2,  { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//NL, DDPD_HPD
  {GPIO_CNL_H_GPP_I3,  { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//NL, DDPE_HPD
  {GPIO_CNL_H_GPP_I4,  { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//EDP_HPD
  {GPIO_CNL_H_GPP_I5,  { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//DDC_PCH_DDPB_CLK
  {GPIO_CNL_H_GPP_I6,  { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//DDC_PCH_DDPB_DATA
  {GPIO_CNL_H_GPP_I7,  { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//DDC_PCH_DDPC_CLK
  {GPIO_CNL_H_GPP_I8,  { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//DDC_PCH_DDPC_DATA
  {GPIO_CNL_H_GPP_I9,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//M2E1_WIFI_OFF#
  {GPIO_CNL_H_GPP_I10, { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//DDC_PCH_VGA_DATA  
  {GPIO_CNL_H_GPP_I11, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_SKTOCC#
  {GPIO_CNL_H_GPP_I12, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_I13, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_I14, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  
  {GPIO_CNL_H_GPP_J0,  { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioPlatformReset , GpioTermNone }},//CNV_GNSS_PA_BLANKING  
  {GPIO_CNL_H_GPP_J1,  { GpioPadModeNative2, GpioHostOwnGpio, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//TP_PCH_CPU_C10_GATE#
  {GPIO_CNL_H_GPP_J2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_J3,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_J4,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermNone }},//CNV_BRI_DT_R
  {GPIO_CNL_H_GPP_J5,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermNone }},//CNV_BRI_RSP 
  {GPIO_CNL_H_GPP_J6,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermNone }},//CNV_RGI_DT_R
  {GPIO_CNL_H_GPP_J7,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermNone }},//CNV_RGI_RSP
  {GPIO_CNL_H_GPP_J8,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermNone }},//CNV_MFUART2_RXD
  {GPIO_CNL_H_GPP_J9,  { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermNone }},//CNV_MFUART2_TXD
  {GPIO_CNL_H_GPP_J10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_J11, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone}},//PCH_A4WP_PRESENT
  
  {GPIO_CNL_H_GPP_K0,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K1,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K3,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL  
  {GPIO_CNL_H_GPP_K4,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K5,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntLevel, GpioPlatformReset, GpioTermNone }},//PCH_SV_DETECT
  {GPIO_CNL_H_GPP_K6,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntLevel, GpioPlatformReset, GpioTermNone }},//INV_LINEAR_PWM#
  {GPIO_CNL_H_GPP_K8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K9,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K11, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K12,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_GPP_K12
  {GPIO_CNL_H_GPP_K13, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K14, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//NL
  {GPIO_CNL_H_GPP_K15, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//NL
  {GPIO_CNL_H_GPP_K16, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K17, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K18, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn , GpioOutDefault, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//NL
  {GPIO_CNL_H_GPP_K19, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv, GpioOutDefault, GpioIntLevel | GpioIntSci, GpioPlatformReset, GpioTermNone, GpioPadConfigUnlock}}, // AIMB-287.X015.c
  {GPIO_CNL_H_GPP_K20, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntLevel, GpioPlatformReset, GpioTermNone }},//PCH_GPIO_TEST_SETUP_MENU // 1:Disable(Default)
  {GPIO_CNL_H_GPP_K21,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntLevel | GpioIntApic, GpioHostDeepReset, GpioTermNone, GpioPadConfigUnlock }}, //SPI_TPM_INT // AIMB-287.X022.a
  {GPIO_CNL_H_GPP_K22, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone , GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL
  {GPIO_CNL_H_GPP_K23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone , GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//NL

  {GPIO_CNL_H_GPD0,    { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioResumeReset , GpioTermNone }},//PCH_BATLOW#
  {GPIO_CNL_H_GPD1,    { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioResumeReset , GpioTermNone }},//PCH_ACPRESENT#
  {GPIO_CNL_H_GPD2,    { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioResumeReset , GpioTermNone }},//PCH_LAN_WAKE#_LAN1
  {GPIO_CNL_H_GPD3,    { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirIn , GpioOutDefault , GpioIntDefault , GpioResumeReset , GpioTermNone }},//SIO_PWRBTN#
  {GPIO_CNL_H_GPD4,    { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirOut , GpioOutDefault , GpioIntDefault , GpioResumeReset , GpioTermNone }},//PCH_SLP_S3#
  {GPIO_CNL_H_GPD5,    { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirOut , GpioOutDefault , GpioIntDefault , GpioResumeReset , GpioTermNone }},//PCH_SLP_S4#
  {GPIO_CNL_H_GPD7,    { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut , GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermDefault }},//PCH_GPD7 //XTAL INPUT MODE HIGH : XTAL INPUT IS DIFFERENTIAL
  {GPIO_CNL_H_GPD8,    { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirOut , GpioOutDefault , GpioIntDefault , GpioResumeReset , GpioTermNone }},//PCH_SUSCLK
  {GPIO_CNL_H_GPD9,    { GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermDefault }},//PCH_SLP_WLAN# TP
  {GPIO_CNL_H_GPD10,   { GpioPadModeNative1 , GpioHostOwnGpio , GpioDirOut , GpioOutDefault , GpioIntDefault , GpioResumeReset , GpioTermNone }},//TP, TP_PCH_SLP_S5#
  {GPIO_CNL_H_GPD11,   { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutDefault, GpioIntDis, GpioDswReset, GpioTermNone    }},//PCH_LAN1_DISABLE#
#endif
// AIMB-287.X004.a - END
};


GPIO_INIT_CONFIG mGpioTableEMMC[] =
{
  {GPIO_CNL_LP_GPP_F11, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_CMD
  {GPIO_CNL_LP_GPP_F12, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA0
  {GPIO_CNL_LP_GPP_F13, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA1
  {GPIO_CNL_LP_GPP_F14, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA2
  {GPIO_CNL_LP_GPP_F15, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA3
  {GPIO_CNL_LP_GPP_F16, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA4
  {GPIO_CNL_LP_GPP_F17, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA5
  {GPIO_CNL_LP_GPP_F18, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA6
  {GPIO_CNL_LP_GPP_F19, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA7
  {GPIO_CNL_LP_GPP_F20, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_RCLK
  {GPIO_CNL_LP_GPP_F21, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_CLK
  {GPIO_CNL_LP_GPP_F22, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_RESETB
};
