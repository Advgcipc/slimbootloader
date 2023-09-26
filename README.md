![Alt text](https://www.advantech.tw/css/css-img/advantech-logo-notagl.svg "Advantech sbl")

# Slim BootLoader Support 

#  Project Name : SOM-C350 

#  Hardware Configuration
    CPU         : AlderLake-S
    Chipset     : AlderLake-S PCHs (Embedded)
    ClockGEN    : AlderLake-S PCHs (Embedded)
    SuperI/O    : RDC EIO-211
    Flash ROM   : Macronix MX25L25673G

#  Revision History
    BIOS Name     : C3500000S060X001.bin;C3500001S060X001.bin
    BIOS Checksum : D464;F286
    BIOS String   : 
    Release Date  : 2023/09/26
    Owner         : Mike.Fan
    Requester     : 
    Customer      : Advantech-SOM

#  Release Description
    C350X001_1    Bring up only and default loaded UEFI Payload boot to Winodow 10. 
    C350X001_2    Update VBT file as same as X014 BIOS. 

#  Release BIOS Information
    Source Path https://github.com/Advgcipc/slimbootloader.git (Branch:SOM-C350)
    C350000S060X001.bin  Release mode BIOS
    C350001S060X001.bin  Debug message BIOS

#  Todo List
- [ ] GPIO setting
- [x] VBT setting
- [ ] ClockGen setting
- [ ] BIOSString support
- [ ] SMBIOS support
- [ ] EC and SCI porting
- [ ] Secure Boot with Boot Guard
- [ ] FWU

 