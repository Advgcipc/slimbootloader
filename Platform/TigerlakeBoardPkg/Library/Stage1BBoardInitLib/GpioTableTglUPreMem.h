/** @file
  Tigerlake U RVP GPIO definition table for Pre-Memory Initialization

  Copyright (c) 2018 Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#ifndef _TIGERLAKE_U_PREMEM_GPIO_TABLE_H_
#define _TIGERLAKE_U_PREMEM_GPIO_TABLE_H_

#include <GpioPinsVer2Lp.h>
#include <Library/GpioLib.h>

static GPIO_INIT_CONFIG mGpioTablePreMemTglUDdr4[] =
{
  { GPIO_VER2_LP_GPP_A14, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut, GpioOutLow, GpioIntDis, GpioPlatformReset, GpioTermNone } },  //ONBOARD_X4_PCIE_SLOT1_PWREN_N
  { GPIO_VER2_LP_GPP_C13, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut, GpioOutHigh, GpioIntDis, GpioPlatformReset, GpioTermNone } },  //ONBOARD_X4_PCIE_SLOT1_RESET_N
  // CPU M.2 SSD
  { GPIO_VER2_LP_GPP_D16, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut, GpioOutHigh, GpioIntDis, GpioPlatformReset, GpioTermNone } },  //CPU SSD PWREN
  { GPIO_VER2_LP_GPP_A11, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut, GpioOutHigh, GpioIntDis, GpioPlatformReset, GpioTermNone } },  //CPU SSD RESET
  // X1 Pcie Slot
  {GPIO_VER2_LP_GPP_F9,   { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut, GpioOutHigh, GpioIntDis,GpioPlatformReset,  GpioTermNone}},  //X1 Slot PWREN
  {GPIO_VER2_LP_GPP_A23,  { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirOut, GpioOutLow,  GpioIntDis,GpioPlatformReset,  GpioTermNone}},  //TC_RETIMER_FORCE_PWR
};





static GPIO_INIT_CONFIG mGpioTablePreMemSOM7583[] =
{
    {GPIO_VER2_LP_GPD2,    {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv,  GpioOutDefault,GpioIntLevel|GpioIntSci,GpioHostDeepReset,  GpioTermNone, GpioPadConfigUnlock}},  //LAN_WAKE#
    {GPIO_VER2_LP_GPD9,    {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutHigh,  GpioIntDis,GpioDswReset,  GpioTermNone}},  //to gate I225's Power
    {GPIO_VER2_LP_GPD11,   {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutHigh,  GpioIntDis,GpioDswReset,  GpioTermNone}},  //LAN_DISABLE_N
    {GPIO_VER2_LP_GPP_E7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutHigh,  GpioIntDis,GpioPlatformReset,  GpioTermNone, GpioOutputStateUnlock}},  //SYSTEM_OK_N
    {GPIO_VER2_LP_GPP_B14,  {GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone,  GpioOutDefault,   GpioIntDis, GpioResetDefault,  GpioTermNone}},  //SPKR
    {GPIO_VER2_LP_GPP_E5, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv,  GpioOutDefault,  GpioIntLevel | GpioIntSmi,  GpioPlatformReset,  GpioTermNone, GpioPadConfigUnlock}},  //EC_SMI#
    {GPIO_VER2_LP_GPP_E4, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv,  GpioOutDefault,  GpioIntLevel | GpioIntSci,  GpioPlatformReset,  GpioTermNone, GpioPadConfigUnlock}},  //EC_SCI#
    {GPIO_VER2_LP_GPP_C2,  {GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv,  GpioOutDefault,  GpioIntLevel | GpioIntSci,  GpioPlatformReset,  GpioTermNone, GpioPadConfigUnlock}},  //SMB_ALT_PCH#
    {GPIO_VER2_LP_GPP_U4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,  GpioOutDefault,  GpioIntDis,  GpioPlatformReset,  GpioTermNone}},  //Bios New Feature
    {GPIO_VER2_LP_GPP_U5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,  GpioOutDefault,  GpioIntDis,  GpioPlatformReset,  GpioTermNone}},  //Bios New Feature
    {GPIO_VER2_LP_GPP_A7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A10,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A11,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A12,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A13,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A17,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A18,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A20,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A21,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A22,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_A23,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used

    {GPIO_VER2_LP_GPP_B3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B10,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
//    {GPIO_VER2_LP_GPP_B15,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B16,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B17,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B19,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B20,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B21,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_B22,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C10,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C11,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C12,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C13,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C14,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C15,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C18,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C19,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C22,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_C23,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used

    {GPIO_VER2_LP_GPP_D0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D13,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D14,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D15,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D16,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D17,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D18,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_D19,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used

    {GPIO_VER2_LP_GPP_E0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E10,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E11,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E12,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E13,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E15,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E16,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E17,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E22,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_E23,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used

    {GPIO_VER2_LP_GPP_F0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F10,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F11,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F12,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F13,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F14,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F15,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F16,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F17,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_F18,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H8,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H9,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H12,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H13,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H14,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H15,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H16,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H17,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H18,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H19,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H20,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H21,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H22,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_H23,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_R6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_R7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_S0,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_S1,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_S2,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_S3,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_S4,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_S5,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_S6,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
    {GPIO_VER2_LP_GPP_S7,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,  GpioOutLow ,  GpioIntDis,GpioHostDeepReset,  GpioTermNone}},  //Not Used
};

#endif // _TIGERLAKE_U_PREMEM_GPIO_TABLE_H_
