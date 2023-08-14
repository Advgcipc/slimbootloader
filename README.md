![Alt text](https://www.advantech.tw/css/css-img/advantech-logo-notagl.svg "Advantech sbl")

# Slim Boot Loader support 

#  Project Name : SOM-7583 

#  Hardware Configuration
    CPU         : TigerLake-UP3
    Chipset     : TigerLake-UP3
    ClockGEN    : ICC
    SuperI/O    : RDC-IS211
    Flash ROM   : Winbond W25R256JVEIQ

#  Revision History
    BIOS Name     : 7583000S060V111.bin;7583000S160V111.bin
    BIOS Checksum : C655;DE74
    BIOS String   : **** SOM-7583 BIOS V1.11 (06/08/2022) ****
    Release Date  : 2022/06/08
    Owner         : Mike.Fan
    Requester     : Lauryn.Hsu
    Customer      : Advantech-SOM

#  Release Description
    7583V111      Add I2C and Gpio function of EC.

#  Hardware Configuration
    CPU         : TigerLake-UP3
    Chipset     : TigerLake-UP3
    ClockGEN    : ICC
    SuperI/O    : RDC-IS211
    Flash ROM   : Winbond W25R256JVEIQ

#  Revision History
    BIOS Name     : 7583000S060V110.bin;7583000S160V110.bin
    BIOS Checksum : C655;DE74
    BIOS String   : **** SOM-7583 BIOS V1.10 (06/08/2022) ****
    Release Date  : 2022/06/08
    Owner         : Mike.Fan
    Requester     : Lauryn.Hsu
    Customer      : Advantech-SOM

#  Release Description
    7583V110      Update EC SCI setting.

#  Release BIOS Information
    Source Path https://github.com/Advgcipc/slimbootloader.git (Branch:SOM-7583)
    7583000S060V110.bin  Release mode BIOS
    7583000S160V110.bin  Release mode BIOS with Boot Guard 
    FwuImage.bin         Firmware update Image put into USB Root.
      Window command line : "cscript fmu.vbs" then reboot
      Linux : "echo 1 > /sys/bus/wmi/devices/44FADEB1-B204-40F2-8581-394BBDC1B651/firmware_update_request" then reboot

#  Revision History
    BIOS Name     : 7583000S060V109.bin;7583000S160V109.bin
    BIOS Checksum : A835;DE74
    BIOS String   : **** SOM-7583 BIOS V1.09 (06/07/2022) ****
    Release Date  : 2022/06/07
    Owner         : Mike.Fan
    Requester     : Lauryn.Hsu
    Customer      : Advantech-SOM

#  Release Description
    7583V109      Update PepGbe to 0 to fix blocked postcode 0x05 during rebooting.

#  Release BIOS Information
    SourceVersion        09c7060994d7b900
    7583000S060V109.bin  Release mode BIOS
    7583000S160V109.bin  Release mode BIOS with Boot Guard 
    FwuImage.bin         Firmware update Image put into USB Root.
      Window command line : "cscript fmu.vbs" then reboot
      Linux : "echo 1 > /sys/bus/wmi/devices/44FADEB1-B204-40F2-8581-394BBDC1B651/firmware_update_request" then reboot

#  Revision History
    BIOS Name     : 7583000S060V108.bin
    BIOS Checksum : 78AD
    BIOS String   : **** SOM-7583 BIOS V1.08 (05/31/2022) ****
    Release Date  : 2022/05/26
    Owner         : Mike.Fan
    Requester     : Lauryn.Hsu
    Customer      : Advantech-SOM

#  Release Description
    7583V108      Update Firmware update support.
 
#  Release BIOS Information
    7583000S060V108.bin  Release mode BIOS
    7583001S060V108.bin  Debug mode BIOS
    7583000S160V108.bin  Release mode BIOS with Boot Guard 
    7583001S160V108.bin  Debug mode BIOS  with Boot Guard 
    FwuImage.bin         Firmware update Image put into USB Root.
      Window command line : "cscript fmu.vbs" then reboot
      Linux : "echo 1 > /sys/bus/wmi/devices/44FADEB1-B204-40F2-8581-394BBDC1B651/firmware_update_request" then reboot
          
#  Revision History
    BIOS Name     : 7583000S060V107.bin;7583001S060V107.bin
    BIOS Checksum : 6A3A;3EEE
    BIOS String   : 
    Release Date  : 2022/05/26
    Owner         : Mike.Fan
    Requester     : Lauryn.Hsu
    Customer      : Advantech-SOM

#  Release Description
    7583X007_1    Merge 10a9e53b [ADLN] Add GPIO configuration from Cfg Data (#1566).
 
#  Release BIOS Information
    7583000S060V107.bin  Release mode BIOS
    7583001S060V107.bin  Debug mode BIOS

#  Revision History
    BIOS Name     : 7583000S060V106.bin;7583001S060V106.bin
    BIOS Checksum : E3AA;C21B
    BIOS String   : 
    Release Date  : 2022/05/020
    Owner         : Mike.Fan
    Requester     : Lauryn.Hsu
    Customer      : Advantech-SOM

#  Release Description
    7583X006_1    Add BIOS string support and update UEFI payload image.
 
#  Release BIOS Information
    7583000S060V106.bin  Release mode BIOS
    7583001S060V106.bin  Debug mode BIOS

#  Revision History
    BIOS Name     : 7583000S060X005.bin;7583001S060X005.bin
    BIOS Checksum : 26CA;03F9
    BIOS String   : 
    Release Date  : 2022/05/04
    Owner         : Mike.Fan
    Requester     : Lauryn.Hsu
    Customer      : Advantech-SOM

#  Release Description
    7583X005_1  Add BootGuard stitch support.
 
#  Release BIOS Information
    7583000S060X005.bin  Release mode BIOS
    7583001S060X005.bin  Debug mode BIOS

#  Revision History
    BIOS Name     : 7583000S060X004.bin;7583001S060X004.bin
    BIOS Checksum : 0BAC;5AD2
    BIOS String   : 
    Release Date  : 2022/05/04
    Owner         : Mike.Fan
    Requester     : Lauryn.Hsu
    Customer      : Advantech-SOM

#  Release Description
    7583X004_1 Seperated SOM-7583 branch in github.
 
#  Release BIOS Information
    7583000S060X004.bin  Release mode BIOS
    7583001S060X004.bin  Debug mode BIOS
 