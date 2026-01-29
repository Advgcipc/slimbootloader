/** @file
  This file defines the hob structure for Bios String.

  Copyright (c) 2014 - 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef BIOS_STRING_HOB_H_
#define BIOS_STRING_HOB_H_

//
//  Ahc Bios String GUID
//
extern EFI_GUID  gAhcBiosStringGuid;
#pragma pack(1)

typedef struct {
  UINT8 BIOSMajorVersion;
  UINT8 BIOSMinorVersion;
  CHAR8 BIOSFormalVersion;
  CHAR8 ProjectBuildDate[16];
  CHAR8 ProjectName[16];
} EFI_PEI_BIOS_STRING_HOB;

//
//  gEfiGlobalVariableGuid
//
typedef struct {
  UINT8   SecureBootKeysMajorVersion;
  UINT8   SecureBootKeysMinorVersion;
  CHAR8   SecureBootKeysFormalVersion;
  UINT8   SecureBootKeysDefaultLoad;
  UINT8   SerialTerminalDefault;
  UINT8   Rsvd0;
  UINT16  PlatformBootDefaultTimeout;
  UINT32  PKKeyAddress;
  UINT32  PKKeySize;
  UINT32  KEKKeyAddress;
  UINT32  KEKKeySize;
  UINT32  DBKeyAddress;
  UINT32  DBKeySize;
  UINT32  DBXKeyAddress;
  UINT32  DBXKeySize;
  UINT32  DBTKeyAddress;
  UINT32  DBTKeySize;
} EFI_SECURE_BOOT_KEYS_HOB;

typedef struct {
  CHAR8 BIOSPD;
  CHAR8 BIOSPDString[16];
} EFI_PEI_BIOS_PD_STRING;


#pragma pack()

#endif
