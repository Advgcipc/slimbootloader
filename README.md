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
