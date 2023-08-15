/** @file

  Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "Stage2BoardInitLib.h"

#define VENDOR_NAME         "Intel Corporation"
#define PLATFORM_NAME       "Idaville"
#define BOARD_NAME_LCC_RP   "BrightonCity"
#define BOARD_NAME_HCC_RP   "MoroCity"
#define UNKNOWN_STRING      "Unknown"

/**
  Add a Smbios type string into a buffer

**/
STATIC
EFI_STATUS
AddSmbiosTypeString (
  SMBIOS_TYPE_STRINGS  *Dest,
  UINT8                 Type,
  UINT8                 Index,
  CHAR8                *String
  )
{
  UINTN   Length;

  Dest->Type    = Type;
  Dest->Idx     = Index;
  if (String != NULL) {
    Length = AsciiStrLen (String);

    Dest->String  = (CHAR8 *)AllocateZeroPool (Length + 1);
    if (Dest->String == NULL) {
      return EFI_OUT_OF_RESOURCES;
    }
    CopyMem (Dest->String, String, Length);
  }

  return EFI_SUCCESS;
}
//D580X001_1
#define TYPE_TERMINATOR_SIZE          2     // Each Type is terminated by 0000 - 2 bytes

void *
GetSmbiosTypePtr (
  IN  SMBIOS_TYPE_STRINGS  *Dest,
  IN  UINT8   Type
  )
{
  SMBIOS_STRUCTURE              *TypeHdr;
  SMBIOS_STRUCTURE              *LastTypeHdr;
  SMBIOS_TABLE_ENTRY_POINT      *SmbiosEntry;
  UINT8                         *StringPtr;
  UINT32                         CurLimit;

  LastTypeHdr = NULL;
  SmbiosEntry = (SMBIOS_TABLE_ENTRY_POINT *)Dest;
  if (SmbiosEntry == NULL) {
    return NULL;
  }

  TypeHdr  = (SMBIOS_STRUCTURE *) (UINTN) SmbiosEntry->TableAddress;
  CurLimit = (UINT32) (UINTN) ((UINT8 *) SmbiosEntry + SmbiosEntry->EntryPointLength + sizeof (UINT8) + SmbiosEntry->TableLength);

  while ( (UINT32)(UINTN)TypeHdr < CurLimit ) {
    if (TypeHdr->Type == Type) {
      LastTypeHdr = TypeHdr;
    }
    //
    // Go to the end of strings to find next Type header
    //
    StringPtr = (UINT8 *) TypeHdr + TypeHdr->Length;
    while ( !(StringPtr[0] == 0 && StringPtr[1] == 0) ) {
      StringPtr++;
    }
    TypeHdr = (SMBIOS_STRUCTURE *)(StringPtr + TYPE_TERMINATOR_SIZE);
  }

  return LastTypeHdr;
}


EFI_STATUS
UpdateSmbiosTypeData (
  SMBIOS_TYPE_STRINGS  *Dest,
  IN  UINT8     Type,
  IN  UINT16    Offset,
  IN  UINT8     Width,
  IN  UINT8     *Value
  )
{
  UINT8             *TypeHdr;
  //
  // Find the header to append a string
  //
  TypeHdr = (UINT8 *) GetSmbiosTypePtr (Dest, Type);
  if (TypeHdr == NULL) {
    return EFI_DEVICE_ERROR;
  }

  if (Width != 0)
    CopyMem ((TypeHdr + Offset), Value, Width);

  
  return EFI_SUCCESS;
}
//D580X001_1 >>

/**
  Initialize necessary information for Smbios

  @retval EFI_SUCCESS             Initialized necessary information successfully
  @retval EFI_OUT_OF_RESOURCES    Failed to allocate memory for Smbios info

**/
EFI_STATUS
InitializeSmbiosInfo (
  VOID
  )
{
  UINT16                Index;
  UINTN                 Length;
  SMBIOS_TYPE_STRINGS  *TempSmbiosStrTbl;
  VOID                 *SmbiosStringsPtr;
  VOID                 *TempStrPtr;
  BOOT_LOADER_VERSION  *VerInfoTbl;
  CHAR8                 TempStrBuf[SMBIOS_STRING_MAX_LENGTH];
  CHAR8                 ImageId[9];

  if (FeaturePcdGet (PcdSmbiosEnabled)) {
    Index            = 0;
    TempSmbiosStrTbl = (SMBIOS_TYPE_STRINGS *) AllocateTemporaryMemory (0);
    VerInfoTbl       = GetVerInfoPtr ();

    //
    // SMBIOS_TYPE_BIOS_INFORMATION
    //

//D580X001_1  >>
  switch (GetPlatformId ()) {
    case PLATFORM_ID_LCC_SOMD580:
    {
      CHAR8 PlatformName[10]= {0};
      UINT8             MajorVer;
      UINT8             MinorVer;

      if (VerInfoTbl != NULL) {
        CopyMem (PlatformName, GetPlatformName (), 8);
      } else {
        AsciiSPrint (PlatformName, 10, "%a\0", "Unknown");
      }

      AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BIOS_INFORMATION,
        1, "Advantech Corp.");

        AsciiSPrint (TempStrBuf, sizeof (TempStrBuf),
          "%a00%cS060%c%d%02d\0",
          PlatformName,
          VerInfoTbl->ImageVersion.BldDebug ? '1' : '0',
          VerInfoTbl->ImageVersion.ProjMajorVersion ? 'V' : 'X',
          VerInfoTbl->ImageVersion.ProjMajorVersion,
          VerInfoTbl->ImageVersion.ProjMinorVersion);

      AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BIOS_INFORMATION,
        2, TempStrBuf);
      
      AsciiSPrint (TempStrBuf, sizeof (TempStrBuf), 
        "%a",PcdGetPtr (PcdVerInfoBuildDate));
      AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BIOS_INFORMATION,
        3, TempStrBuf);

      MajorVer = 2;
      MinorVer = 0;
      UpdateSmbiosTypeData (TempSmbiosStrTbl, SMBIOS_TYPE_BIOS_INFORMATION, OFFSET_OF(SMBIOS_TABLE_TYPE0, EmbeddedControllerFirmwareMajorRelease), 1, &MajorVer);
      UpdateSmbiosTypeData (TempSmbiosStrTbl, SMBIOS_TYPE_BIOS_INFORMATION, OFFSET_OF(SMBIOS_TABLE_TYPE0, EmbeddedControllerFirmwareMinorRelease), 1, &MinorVer);

  //
  // SMBIOS_TYPE_BASEBOARD_INFORMATION
  //
      AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BASEBOARD_INFORMATION,
        1, "Advantech Corp.");
      AsciiSPrint (TempStrBuf, sizeof (TempStrBuf),"%a\0", PlatformName);
      AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BASEBOARD_INFORMATION,
        2, TempStrBuf);
      AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BASEBOARD_INFORMATION,
        3, "A201-1");
      AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BASEBOARD_INFORMATION,
        4, "1234567");
      }

      break;
    default:
//D580X001_1  >>

    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BIOS_INFORMATION,
      1, VENDOR_NAME);
    if (VerInfoTbl != NULL) {
      ZeroMem (ImageId, sizeof (ImageId));
      CopyMem (ImageId, &VerInfoTbl->ImageId, sizeof (UINT64));
      AsciiSPrint (TempStrBuf, sizeof (TempStrBuf),
        "%a.%03d.%03d.%03d.%03d.%03d.%05d.%c-%016lX%a\0",
        ImageId,
        VerInfoTbl->ImageVersion.SecureVerNum,
        VerInfoTbl->ImageVersion.CoreMajorVersion,
        VerInfoTbl->ImageVersion.CoreMinorVersion,
        VerInfoTbl->ImageVersion.ProjMajorVersion,
        VerInfoTbl->ImageVersion.ProjMinorVersion,
        VerInfoTbl->ImageVersion.BuildNumber,
        VerInfoTbl->ImageVersion.BldDebug ? 'D' : 'R',
        VerInfoTbl->SourceVersion,
        VerInfoTbl->ImageVersion.Dirty ? "-dirty" : "");
    } else {
      AsciiSPrint (TempStrBuf, sizeof (TempStrBuf), "%a\0", UNKNOWN_STRING);
    }
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BIOS_INFORMATION,
      2, TempStrBuf);
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BIOS_INFORMATION,
      3, __DATE__);

//D580X001_1  >>
       break;
   }
//D580X001_1  >>
    //
    // SMBIOS_TYPE_SYSTEM_INFORMATION
    //
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_SYSTEM_INFORMATION,
      1, VENDOR_NAME);
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_SYSTEM_INFORMATION,
      2, PLATFORM_NAME);
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_SYSTEM_INFORMATION,
      3, "0.1");
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_SYSTEM_INFORMATION,
      4, UNKNOWN_STRING);
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_SYSTEM_INFORMATION,
      5, UNKNOWN_STRING);
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_SYSTEM_INFORMATION,
      6, PLATFORM_NAME);

    //
    // SMBIOS_TYPE_BASEBOARD_INFORMATION
    //
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BASEBOARD_INFORMATION,
      1, VENDOR_NAME);
    switch (GetPlatformId ()) {
    case PLATFORM_ID_LCC_RP:
      TempStrPtr = BOARD_NAME_LCC_RP;
      break;
    case PLATFORM_ID_HCC_RP:
      TempStrPtr = BOARD_NAME_HCC_RP;
      break;
    default:
      TempStrPtr = UNKNOWN_STRING;
      break;
    }
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BASEBOARD_INFORMATION,
      2, TempStrPtr);
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BASEBOARD_INFORMATION,
      3, "1");
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_BASEBOARD_INFORMATION,
      4, UNKNOWN_STRING);

    //
    // SMBIOS_TYPE_END_OF_TABLE
    //
    AddSmbiosTypeString (&TempSmbiosStrTbl[Index++], SMBIOS_TYPE_END_OF_TABLE,
      0, NULL);

    Length = sizeof (SMBIOS_TYPE_STRINGS) * Index;
    SmbiosStringsPtr = AllocatePool (Length);
    if (SmbiosStringsPtr == NULL) {
      return EFI_OUT_OF_RESOURCES;
    }

    CopyMem (SmbiosStringsPtr, TempSmbiosStrTbl, Length);
    (VOID) PcdSet32S (PcdSmbiosStringsPtr, (UINT32)(UINTN)SmbiosStringsPtr);
    (VOID) PcdSet16S (PcdSmbiosStringsCnt, Index);
  }

  return EFI_SUCCESS;
}
