![Alt text](https://www.advantech.tw/css/css-img/advantech-logo-notagl.svg "Advantech sbl")

# Slim Boot Loader support 

#  Project Name : SOM-5993 

##  Hardware Configuration
#### CPU         : IceLake-D LCC
#### Chipset     : IceLake-D LCC
#### ClockGEN    : ICC
#### SuperI/O    : EIO-201
#### Flash ROM   : Macronix MX25L25673GM2I-08G

##  Revision History
#### BIOS Name     : 5993000S060X001.bin
#### BIOS Checksum : 8F1B
#### BIOS String   : 
#### Release Date  : 2023/09/28
#### Owner         : Mike.Fan
#### Requester     : 
#### Customer      : Advantech-SOM

##  Release Description
#### 5993X001_1    Bring up and update Aspeed VGA 800x600 resulotion.
#### 5993X001_2    Update Pcie setting.
#### 5993X001_3    Update default UEFI Payload.

##  Release BIOS Information
#### 5993000S060X001.bin  Release mode BIOS

##  Github Source Branch:SOM-5993
    https://github.com/Advgcipc/slimbootloader.git

**Todo List**
=============

- [x] Boot into OS (Window 10)
- [ ] POST Meesge on UART
- [ ] GPIO setting
- [ ] VBT setting
- [ ] ClockGen setting
- [ ] BIOSString support
- [ ] SMBIOS support
- [ ] EC and SCI 
- [ ] Secure Boot with Boot Guard
- [ ] FWU

 