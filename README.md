![Alt text](https://www.advantech.tw/css/css-img/advantech-logo-notagl.svg "Advantech sbl")

# Slim BootLoader support 

## Project Name : SOM-6884A2

### Slim BootLoader Commit ID
    1397f56093238ad67b9fb3391242005a39f10b33

### Intel FSP Commit ID
    54792daf438471c724e993d774194c1680e08846    
    
### Hardware Configuration
* CPU         : RaptorLake_P
* Chipset     : RaptorLake_P
* ClockGEN    : ICC
* SuperI/O    : RDC-IS211
* Flash ROM   : Winbond W25R256JVEIQ

### Implement Feature List
- [x] GPIO setting
- [x] ClockGen setting
- [x] BIOSString support
- [x] SMBIOS support
- [x] EC porting
- [x] Firmware Update function 
- [x] Security function
- [x] ME XML setting
- [x] USB function
- [x] HDA verb table
- [x] Display support
- [x] PCI Express function
- [x] Generic IO decode
- [x] Debug Features

### Revision History
* BIOS Name     : 688400S0080V111.bin
* BIOS Checksum : 
* BIOS String   : **** SOM-6884 BIOS V1.10 (03/02/2026) ****
* Release Date  : 2026/03/02
* Owner         : Lawrence.Guan
* Requester     : Ronny.Tao
* Customer      : Boeing

### Release Description

* 6884V111_1  Set FSP and config default:
  1. P-Core All cores 
  2. E-Core = 4 cores
  3. CPU Turbo Mode Disabled 
  4. Intel SpeedStep Disabled 
  5. Boot performance mode Max Non-Turbo Performance 
  6. configurable CPU TDP PL1=10.5W, PL2=12W 
  7. Enable TCO Timer Enabled 
  
* 6884V111_2  Support StitchIfwiConfig for RPLP.
  
* 6884V111_3  Update PCIe controller 2(Port 5-8)  [2x2]
  
### Firmware Update Trigger step
  
  Prepare Firmware update image:  copy Outputs\rplp\688400S0080V111_FwuImage.bin to usb key \FwuImage.bin
  Prepare Firmware update script: copy Platform\RaptorlakeBoardPkg\Binaries\fwu.nsh to usb key \fwu.nsh
  Trigger Firmware update:        boot to uefishell and execute .\Fwu.nsh 

### Revision History
* BIOS Name     : 688400S0080V110.bin
* BIOS Checksum : 71BB
* BIOS String   : **** SOM-6884 BIOS V1.10 (03/02/2026) ****
* Release Date  : 2026/03/02
* Owner         : Lawrence.Guan
* Requester     : Ronny.Tao
* Customer      : Boeing

### Release Description

* 6884V110_1  Support Windows EMS function by ACPI SPCR table.
  
* 6884V110_2  Set secure boot default as disable.


### Firmware Update Trigger step
  
  Prepare Firmware update image:  copy Outputs\rplp\688400S0080V110_FwuImage.bin to usb key \FwuImage.bin
  Prepare Firmware update script: copy Platform\RaptorlakeBoardPkg\Binaries\fwu.nsh to usb key \fwu.nsh
  Trigger Firmware update:        boot to uefishell and execute .\Fwu.nsh 

### Revision History
* BIOS Name     : 688400S0180V109.bin
* BIOS Checksum : AB2D
* BIOS String   : **** SOM-6884 BIOS V1.09 (02/12/2026) ****
* Release Date  : 2026/02/12
* Owner         : Lawrence.Guan
* Requester     : Ronny.Tao
* Customer      : Boeing

### Release Description

* 6884V109_1  Resolve build fail caused from git merge.

* 6884V109_2  Support UniversalPayload of ELF format.

* 6884V109_3  Support secure boot settings.

* No tag: 
*   Merged SOM-6884A2 V108 into commit 0576ef337442c2ba5758e6117a05ba03b6116a7b, producing the resulting commit 97f53a6963c0b140412b0e847a9725a3c347a3a6. Version V109 was built based on this resulting commit.

### Firmware Update Trigger step
  
  Prepare Firmware update image:  copy Outputs\rplp\688400S0080V109_FwuImage.bin to usb key \FwuImage.bin
  Prepare Firmware update script: copy Platform\RaptorlakeBoardPkg\Binaries\fwu.nsh to usb key \fwu.nsh
  Trigger Firmware update:        boot to uefishell and execute .\Fwu.nsh 


### Revision History
* BIOS Name     : 688400S0080V108.bin ; 688400S0180V108.bin
* BIOS Checksum : BC5E ; A0F5
* BIOS String   : **** SOM-6884 BIOS V1.08 (12/17/2025) ****
* Release Date  : 2025/12/17
* Owner         : Mike.Fan
* Requester     : Ronny.Tao
* Customer      : Boeing

### Release Description

* 6884V108_1  Update slim.bat, batch file and secureboot keys.
* 6884V108_2  Add stitchifwi support.
* 6884V108_3  Update CS1 decode setting for LPC port 80.
* 6884V108_4  Add IT8883 initial table.
* 6884V108_5  Add "Binaries\VbtBin" path to link VBT file.

### Firmware Update Trigger step
  
  Prepare Firmware update image:  copy Outputs\rplp\688400S0080V108_FwuImage.bin to usb key \FwuImage.bin
  Prepare Firmware update script: copy Platform\RaptorlakeBoardPkg\Binaries\fwu.nsh to usb key \fwu.nsh
  Trigger Firmware update:        boot to uefishell and execute .\Fwu.nsh 


### Revision History
* BIOS Name     : 688400S0080V107.bin ; FwuImage.bin
* BIOS Checksum : C8E4 ; 9C9F
* BIOS String   : **** SOM-6884 BIOS V1.07 (12/16/2025) ****
* Release Date  : 2025/12/16
* Owner         : Lawrence.Guan
* Requester     : Ronny.Tao
* Customer      : Boeing

### Release Description

* 6884V107_1  Update PcieClkSrcUsage for SOM-6884A2.

###  Release BIOS Information
    Source Path https://github.com/Advgcipc/slimbootloader.git (Branch:SOM-6884A2)
    688400S0080V107.bin  Release mode BIOS
    FwuImage.bin         Firmware update Image put into USB Root.

### Revision History
* BIOS Name     : 688400S0080V106.bin ; FwuImage.bin
* BIOS Checksum : C7CE ; 9C85
* BIOS String   : **** SOM-6884 BIOS V1.06 (12/01/2025) ****
* Release Date  : 2025/12/1
* Owner         : Lawrence.Guan
* Requester     : Advantech-SOM
* Customer      : Advantech-SOM

### Release Description

* 6884V106_1  Support USB OC pin#0, 3 mapping.

* 6884V106_2  Support IT8883.

* No tag: Update "Implement Feature List".

###  Release BIOS Information
    Source Path https://github.com/Advgcipc/slimbootloader.git (Branch:SOM-6884A2)
    688400S0080V106.bin  Release mode BIOS
    FwuImage.bin         Firmware update Image put into USB Root.

### Revision History
* BIOS Name     : 688400S0080V105.bin ; FwuImage.bin
* BIOS Checksum : 43CB ; 17C5
* BIOS String   : **** SOM-6884 BIOS V1.05 (12/01/2025) ****
* Release Date  : 2025/12/1
* Owner         : Lawrence.Guan
* Requester     : Advantech-SOM
* Customer      : Advantech-SOM

### Release Description

* 6884V105_1  Program GPE configuration in PMC register.
    
* 6884V105_2  Update mRplPDdr5SODimmCrbDisplayDdiConfigSOM6884.
    
* 6884V105_3  Add A9610ECAsl.asl to support EC SCI. 

* No tag: Move the "Implement Feature List" section between "Hardware Configuration" and "Revision History".

###  Release BIOS Information
    Source Path https://github.com/Advgcipc/slimbootloader.git (Branch:SOM-6884A2)
    688400S0080V105.bin  Release mode BIOS
    FwuImage.bin         Firmware update Image put into USB Root.

### Revision History
* BIOS Name     : 688400S0080V104.bin
* BIOS Checksum : F55E
* BIOS String   : **** SOM-6884 BIOS V1.04 (11/20/2025) ****
* Release Date  : 2025/11/20
* Owner         : Lawrence.Guan
* Requester     : Advantech-SOM
* Customer      : Advantech-SOM

### Release Description

* No tag:
    * Remove */VbtBin/* of Platform\.gitignore.
    * Revise BuildFirmwareUpdate path for RELEASE/DEBUG mode.

###  Release BIOS Information
    Source Path https://github.com/Advgcipc/slimbootloader.git (Branch:SOM-6884A2)
    688400S0080V104.bin  Release mode BIOS
    FwuImage.bin         Firmware update Image put into USB Root.

### Revision History
* BIOS Name     : 688400S0080V103.bin
* BIOS Checksum : B46D
* BIOS String   : **** SOM-6884 BIOS V1.03 (11/20/2025) ****
* Release Date  : 2025/11/20
* Owner         : Lawrence.Guan
* Requester     : Advantech-SOM
* Customer      : Advantech-SOM

### Release Description

* No tag:
    * Add Platform\RaptorlakeBoardPkg\VbtBin\VbtAdlP.bin to resolve build fail.

###  Release BIOS Information
    Source Path https://github.com/Advgcipc/slimbootloader.git (Branch:SOM-6884A2)
    688400S0080V103.bin  Release mode BIOS
    FwuImage.bin         Firmware update Image put into USB Root.

### Implement Feature List
- [x] GPIO setting
- [x] ClockGen setting
- [x] BIOSString support
- [x] SMBIOS support
- [ ] EC porting
- [x] Firmware Update function 
- [ ] Secyrity function
- [x] ME XML setting
- [x] USB function
- [ ] HDA function
- [x] Display support
- [ ] PCI Express function
- [ ] Generic IO decode
- [x] Debug Features

### Revision History
* BIOS Name     : 688400S0080V102.bin
* BIOS Checksum : DECB
* BIOS String   : **** SOM-6884 BIOS V1.01 (11/18/2025) ****
* Release Date  : 2025/11/18
* Owner         : Lawrence.Guan
* Requester     : Advantech-SOM
* Customer      : Advantech-SOM

### Release Description

* 6884A2V102_1  Sync Major version and Minor version between slim.bat and BoardConfigRplp.py.

* 6884A2V102_2  Support SYS_OK_LED function.

* 6884A2V102_3  Add mAzaliaVerbTableDataALC0888.

* 6884A2V102_4  Update mRplPDdr5SODimmCrbDisplayDdiConfigSOM6884.

* 6884A2V102_5  Update mGpioTablePreMemAdlPDdr5Rvp_SOM6884.

* No tag:
    * Replace 'INPUT_BIOS_BINFILE' to '6884A200060V110_TS512.bin'.
    * Add 'fwu.vbs' to 'Platform\RaptorlakeBoardPkg\Binaries'.

###  Release BIOS Information
    Source Path https://github.com/Advgcipc/slimbootloader.git (Branch:SOM-6884A2)
    688400S0080V102.bin  Release mode BIOS
    FwuImage.bin         Firmware update Image put into USB Root.

### Implement Feature List
- [ ] GPIO setting
- [x] VBT setting
- [x] ClockGen setting
- [x] BIOSString support
- [x] SMBIOS support
- [ ] EC and SCI porting
- [x] Firmware Update function 
- [ ] Secure Boot with Boot Guard

### Revision History
* BIOS Name     : 688400S0080V101.bin
* BIOS Checksum : C655
* BIOS String   : **** SOM-6884 BIOS V1.01 (10/21/2025) ****
* Release Date  : 2025/10/21
* Owner         : Mike.Fan
* Requester     : 
* Customer      : Advantech-SOM

### Release Description
* 6884V101_1      Add Platform ID 0x1D for SOM-6884 and 0x1E for SOM-6884A2.
* 6884V101_2      Add SIO registers programming.
* 6884V101_3      Add Build Date/Time for BIOS String.
* 6884V101_4      Add mRplPDdr5SODimmCrbDisplayDdiConfigSOM6884 for SOM-6884 IGD.
* 6884V101_5      Preset GPIO table, Acpi and FspConfig as PLATFORM_ID_ADL_P_DDR5_RVP.
* 6884V101_6      Update RDC 9610 and SMBIOS support.
* 6884V101_7      Add CSME_UPDATE_DRIVER support for Firmware Update.
* 6884V101_8      Update SMBIOS info.

### Implement Feature List
- [ ] GPIO setting
- [x] VBT setting
- [ ] ClockGen setting
- [x] BIOSString support
- [x] SMBIOS support
- [ ] EC and SCI porting
- [ ] Firmware Update function 
- [ ] Secure Boot with Boot Guard
