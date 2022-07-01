/** @file
  Tigerlake U RVP GPIO definition table for Pre-Memory Initialization

 Copyright (c) 2018 - 2019, Intel Corporation. All rights reserved.<BR>
 SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#ifndef _ELKHARTLAKE_PREMEM_GPIO_TABLE_H_
#define _ELKHARTLAKE_PREMEM_GPIO_TABLE_H_

#include <Register/GpioPinsVer3.h>
#include <GpioConfig.h>

//DS202_SBL_X001_05// >>
GLOBAL_REMOVE_IF_UNREFERENCED GPIO_INIT_CONFIG mGpioTablePreMemEhlDS202[] =
{
  {GPIO_VER3_GPP_A0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A10, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A11, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A16, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A17, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A18, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A19, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A20, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A21, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A22, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_A23, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC

  {GPIO_VER3_GPP_B5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_B6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_B7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_B8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_B9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_B10, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_B11, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_B14, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,  GpioOutDefault, GpioIntDefault,             GpioHostDeepReset,  GpioTermNone }}, // SOC_SPKR
  {GPIO_VER3_GPP_B15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_B16, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_B17, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC 
  {GPIO_VER3_GPP_B18, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_B19, {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //SIO_SPI1_CS0_N
  {GPIO_VER3_GPP_B20, {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //SIO_SPI1_CLK
  {GPIO_VER3_GPP_B21, {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //SIO_SPI1_MISO
  {GPIO_VER3_GPP_B22, {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //SIO_SPI1_MOSI
  {GPIO_VER3_GPP_B23, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  
  {GPIO_VER3_GPP_C2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C10, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C11, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C16, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C17, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C18, {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //SML_DATA0
  {GPIO_VER3_GPP_C19, {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //SML_CLK0
  {GPIO_VER3_GPP_C20, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C21, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//ATX_AT#_SEL
  {GPIO_VER3_GPP_C22, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_C23, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
 
  {GPIO_VER3_GPP_D0,  {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv,  GpioOutDefault,  GpioIntLevel|GpioIntSmi,   GpioPlatformReset,  GpioTermNone,  GpioPadConfigUnlock}}, //EC_SMI#
  {GPIO_VER3_GPP_D1,  {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirIn,  GpioOutDefault, GpioIntEdge | GpioIntSci, GpioPlatformReset,  GpioTermNone, GpioPadConfigUnlock}}, //EC_PME#
  {GPIO_VER3_GPP_D2,  {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirIn,  GpioOutDefault, GpioIntEdge | GpioIntSci, GpioPlatformReset,  GpioTermNone, GpioPadConfigUnlock}}, //EC_SCI#
  {GPIO_VER3_GPP_D3,  {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirIn,  GpioOutDefault, GpioIntEdge | GpioIntNmi, GpioPlatformReset,  GpioTermNone, GpioPadConfigUnlock}}, //EC_NMI#
  {GPIO_VER3_GPP_D4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_D9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_D10, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDis, GpioResumeReset, GpioTermNone, GpioPadConfigUnlock}}, //LAN2PWR_CTL
  {GPIO_VER3_GPP_D11, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDis, GpioResumeReset, GpioTermNone, GpioPadConfigUnlock}}, //PCH_LAN2_DIS_DASH
  {GPIO_VER3_GPP_D12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow,  GpioIntDis, GpioResumeReset, GpioTermNone, GpioPadConfigUnlock}}, //LAN2_SMBUS_SW_CNTL
  {GPIO_VER3_GPP_D13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_D14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_D15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_D16, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_D17, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_D18, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_D19, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //DP1_CONFIG1

  {GPIO_VER3_GPP_E1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,  GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //PCIEX1_SLOT_WAKE#
  {GPIO_VER3_GPP_E4,  {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //M2M1_SATA0_DEVSLP
  {GPIO_VER3_GPP_E8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E9,  {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermDefault}},//USB_OC#12
  {GPIO_VER3_GPP_E10, {GpioPadModeGpio, GpioHostOwnDefault, GpioDirOut,  GpioOutHigh,  GpioIntDis, GpioHostDeepReset, GpioTermNone,  GpioOutputStateUnlock}},  //M2E1_WIFI_OFF#
  {GPIO_VER3_GPP_E11, {GpioPadModeGpio, GpioHostOwnDefault, GpioDirOut,  GpioOutHigh,  GpioIntDis, GpioHostDeepReset, GpioTermNone,  GpioOutputStateUnlock}},  //M2E1_BT_DISABLE#
  {GPIO_VER3_GPP_E12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E16, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E17, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E18, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E20, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E21, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E22, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_E23, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC

  {GPIO_VER3_GPP_F0,  {GpioPadModeNative2, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermDefault}},//CPU_UART0_RTS# 
  {GPIO_VER3_GPP_F1,  {GpioPadModeNative2, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermDefault}},//CPU_UART0_RXD 
  {GPIO_VER3_GPP_F2,  {GpioPadModeNative2, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermDefault}},//CPU_UART0_TXD 
  {GPIO_VER3_GPP_F3,  {GpioPadModeNative2, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermDefault}},//CPU_UART0_CTS# 
  {GPIO_VER3_GPP_F4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F11, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F16, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F17, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F18, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F19, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F20, {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv, GpioOutDefault,GpioIntLevel|GpioIntSci, GpioHostDeepReset,  GpioTermNone,  GpioPadConfigUnlock  }},  //UART_BT_WAKE# 
  {GPIO_VER3_GPP_F21, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_F22, {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //PMC_+VNN_CTRL
  {GPIO_VER3_GPP_F23, {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //PMC_+V1.05_CTRL
  
  {GPIO_VER3_GPP_G0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G11, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_G19, {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirIn, GpioOutDefault, GpioIntLevel|GpioIntApic, GpioHostDeepReset, GpioTermNone, GpioPadConfigUnlock}},  //SPI_TPM_INT_N
  {GPIO_VER3_GPP_G23, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC

  {GPIO_VER3_GPP_H0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H4,  {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //SIO_I2C2_SDA
  {GPIO_VER3_GPP_H5,  {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault,  GpioOutDefault, GpioIntDefault, GpioPlatformReset,  GpioTermNone}}, //SIO_I2C2_SCL
  {GPIO_VER3_GPP_H6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H17, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H21, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H22, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_H23, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC

  {GPIO_VER3_GPP_R5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_R6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_R7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC

  {GPIO_VER3_GPP_S0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_S1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  
  {GPIO_VER3_GPP_T4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_T5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_T6,  {GpioPadModeNative2, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermDefault}},//USB_OC#56
  {GPIO_VER3_GPP_T7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_T8,  {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermDefault}},//USB_OC#34
  {GPIO_VER3_GPP_T9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_T10, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_T11, {GpioPadModeNative1, GpioHostOwnDefault, GpioDirDefault, GpioOutDefault, GpioIntDefault, GpioResumeReset, GpioTermDefault}},//USB_OC#78
  {GPIO_VER3_GPP_T12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_T13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_T14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_T15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC

  {GPIO_VER3_GPP_U0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}}, //MB_ID0
  {GPIO_VER3_GPP_U5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}}, //MB_ID1
  {GPIO_VER3_GPP_U6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U10, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U11, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U16, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U17, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U18, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_U19, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC

  {GPIO_VER3_GPP_V0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V10, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V11, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC
  {GPIO_VER3_GPP_V15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC  

  {GPIO_VER3_GPD1,    {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioPlatformReset, GpioTermNone, GpioPadConfigUnlock}},  //ACPRESENT
  {GPIO_VER3_GPD2,    {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv, GpioOutDefault, GpioIntBothEdge | GpioIntSci, GpioHostDeepReset,  GpioTermNone, GpioPadConfigUnlock}}, // Power Button
  {GPIO_VER3_GPD7,    {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioHostDeepReset, GpioTermNone}}, //NC  
  {GPIO_VER3_GPD9,    {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut,  GpioOutHigh,    GpioIntDis, GpioPlatformReset, GpioTermNone}}, //SLP_WLAN#
};
//DS202_SBL_X001_05// <<

GLOBAL_REMOVE_IF_UNREFERENCED GPIO_INIT_CONFIG mGpioTablePreMemEhl[] =
{
  {GPIO_VER3_GPP_E0,  {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut,   GpioOutHigh,    GpioIntDis,                   GpioPlatformReset,  GpioTermNone}},  //WWAN_FCP_OFF_N
  {GPIO_VER3_GPP_F21, {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut,   GpioOutHigh,    GpioIntDis,                   GpioPlatformReset,  GpioTermNone}},  //WWAN_PWREN
  {GPIO_VER3_GPP_B14, {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut,   GpioOutLow,     GpioIntDis,                   GpioPlatformReset,  GpioTermNone}},  //WWAN_PERST_N
  {GPIO_VER3_GPP_B17, {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv, GpioOutDefault, GpioIntLevel | GpioIntSci,    GpioHostDeepReset,  GpioTermNone,  GpioPadConfigUnlock}},  //WWAN_WAKE_N
  {GPIO_VER3_GPP_V13, {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut,   GpioOutLow,     GpioIntDis,                   GpioPlatformReset,  GpioTermNone}},  //WWAN_RST_N
  {GPIO_VER3_GPD2,    {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv, GpioOutDefault, GpioIntDis,                   GpioHostDeepReset,  GpioTermNone, GpioPadConfigUnlock}}, // LAN_WAKEB
  {GPIO_VER3_UFS_RESETB, {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut,   GpioOutHigh,    GpioIntDis,                   GpioPlatformReset,  GpioTermNone}},  // UFS_RESETB
};

/**
GLOBAL_REMOVE_IF_UNREFERENCED GPIO_INIT_CONFIG mGpioTableEhlWwanOnEarlyPreMem[] =
{
  {GPIO_VER3_GPP_F21,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,    GpioOutHigh,     GpioIntDis,               GpioResumeReset,    GpioTermNone,  GpioOutputStateUnlock}},  //WWAN_PWREN
  {GPIO_VER3_GPP_E0,   { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,    GpioOutHigh,     GpioIntDis,               GpioResumeReset,    GpioTermNone}},                          //WWAN_FCP_OFF_N
  {GPIO_VER3_GPP_V13,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,    GpioOutHigh,     GpioIntDis,               GpioResumeReset,    GpioTermNone}},                          //WWAN_RST_N
  {GPIO_VER3_GPP_B14,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,    GpioOutHigh,     GpioIntDis,               GpioResumeReset,    GpioTermNone}},                          //WWAN_PERST_N
  {GPIO_VER3_GPP_B17,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirInInv,  GpioOutDefault,  GpioIntLevel|GpioIntSci,  GpioHostDeepReset,  GpioTermNone,  GpioPadConfigUnlock}},    //WWAN_WAKE_N
};

GLOBAL_REMOVE_IF_UNREFERENCED GPIO_INIT_CONFIG mGpioTableEhlWwanOffEarlyPreMem[] =
{
  {GPIO_VER3_GPP_V13,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,    GpioOutLow,      GpioIntDis,                GpioResumeReset,    GpioTermNone}},                          //WWAN_RST_N
  {GPIO_VER3_GPP_B14,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,    GpioOutLow,      GpioIntDis,                GpioResumeReset,    GpioTermNone}},                          //WWAN_PERST_N
  {GPIO_VER3_GPP_B17,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirInInv,  GpioOutDefault,  GpioIntLevel | GpioIntSci, GpioHostDeepReset,  GpioTermNone,  GpioPadConfigUnlock}},    //WWAN_WAKE_N
  {GPIO_VER3_GPP_E0,   { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,    GpioOutLow,      GpioIntDis,                GpioResumeReset,    GpioTermNone}},                          //WWAN_FCP_OFF_N
};
**/
#endif // _ELKHARTLAKE_U_PREMEM_GPIO_TABLE_H_
