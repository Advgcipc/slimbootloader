/** @file
  This file defines the hob structure for Bios String.

  Copyright (c) 2014 - 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef BIOS_STRING_HOB_H_
#define BIOS_STRING_HOB_H_

///
/// Ahc Bios String GUID
///
extern EFI_GUID  gAhcBiosStringGuid;

typedef struct {
  UINT8 BIOSMajorVersion;
  UINT8 BIOSMinorVersion;
  CHAR8 BIOSFormalVersion;
  CHAR8 ProjectBuildDate[16];
//  CHAR8 ProjectDep[8];
  CHAR8 ProjectName[16];
} EFI_PEI_BIOS_STRING_HOB;

#endif
