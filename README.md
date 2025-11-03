![Alt text](https://www.advantech.tw/css/css-img/advantech-logo-notagl.svg "Advantech sbl")

# Slim Boot Loader support 

#  Project Name : SOM-6884 

### Slim BootLoader Commit ID
    1397f56093238ad67b9fb3391242005a39f10b33

### Intel FSP Commit ID
    54792daf438471c724e993d774194c1680e08846    

#  Hardware Configuration
    CPU         : RaptorLake_P
    Chipset     : RaptorLake_P
    ClockGEN    : RaptorLake_P ICC
    SuperI/O    : EIO-211
    Flash ROM   : Winbond W25Q256FV

### Revision History
* BIOS Name     : 688400S0080V101.bin
* BIOS Checksum : 259F
* BIOS String   : **** SOM-6884 BIOS V1.01 (10/21/2025) ****
* Release Date  : 2025/11/3
* Owner         : Lawrence.Guan
* Requester     : 
* Customer      : Advantech-SOM

### Release Description
* 6884V101_1      Add Platform ID 0x1D for SOM-6884 and Add CSME_UPDATE_DRIVER support for Firmware Update.
 
### Implement Feature List
- [ ] GPIO setting
- [x] VBT setting
- [ ] ClockGen setting
- [ ] BIOSString support
- [ ] SMBIOS support
- [ ] EC and SCI porting
- [x] Firmware Update function 
- [ ] Secure Boot with Boot Guard
 