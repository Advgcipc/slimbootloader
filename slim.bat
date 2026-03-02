::
::  Platform Setting
::
@set PROJECT_NAME=6884
@set PROJECT_EXTNAME=00
@set PROJECT_PD=S

@set PROJECT_CHIPSET_TYPE=0
@set PROJECT_FW_TYPE=1
@set PROJECT_BUILD_TYPE=8

@set PROJECT_TYPE_VER=0V
@set PROJECT_MAJOR_VER=1
@set PROJECT_MINOR_VER=10

@set BIOS_NAME=%PROJECT_NAME%%PROJECT_EXTNAME%%PROJECT_PD%
@set BIOS_FEATURE=%PROJECT_CHIPSET_TYPE%%PROJECT_FW_TYPE%%PROJECT_BUILD_TYPE%
@set BIOS_VERSION=%PROJECT_TYPE_VER%%PROJECT_MAJOR_VER%%PROJECT_MINOR_VER%

::@set PAYLOAD_BINFILE="OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_DEBUG.fd:UEFI:Lzma"
@set PAYLOAD_BINFILE="OsLoader.efi:LLDR:Lz4;UniversalPayload_DEBUG.elf:UEFI:Lzma"

@set STITCH_BIOS_IMAGE=Outputs/%PLATFORM_TYPE%/%BIOS_IMAGE%
::struct {UINT8 PlatformId : 5;UINT8  Reserved1  : 3;UINT8  DebugUart;UINT8 Reserved3;UINT8 Marker;} STITCH_DATA;
:: PlatformId ==> SOM-6884A2:0x1E;SOM-6884:0x1D ;; DebugUart ==> SOC UART0:0; SIO UART0:0xFF;SIO UART1:0xFE      
@set PLATFORM_ID_DEBUGUART=AA00FE1E
@set PLATFORM_TYPE=rplp
@set PLATFORM_PACKAGE=RaptorlakeBoardPkg
@set PLATFORM_BUILDMODE=IA32
@set PLATFORM_OPTION=-p
::  wait for SBL64 for CsmeUpdateDriver
::@set PLATFORM_OPTION= -a x64 %PLATFORM_OPTION%
@set INPUT_BIOS_BINFILE=Platform/%PLATFORM_PACKAGE%/Binaries/BiosBin/6884A200060V110_TS512.bin

@set STITCHIFWI_TEMP=
@set TARGE=DEBUG
@IF "%2"=="-r" (
@set TARGE=RELEASE
@set PROJECT_FW_TYPE=0
@set PLATFORM_OPTION= -r %PLATFORM_OPTION%
@set PAYLOAD_BINFILE="OsLoader.efi:LLDR:Lz4;UniversalPayload_RELEASE.elf:UEFI:Lzma"
@set STITCHIFWI_TEMP=-r
)

@set BUILD_PY_FILE=BuildLoader.py
@set STITCH_PY_FILE=Platform/%PLATFORM_PACKAGE%/Script/StitchLoader.py
@set STITCH_PY_FILE1=Platform/%PLATFORM_PACKAGE%/Script/StitchLoader1.py
@set SBL_SOURCE_BINFILE=Outputs/%PLATFORM_TYPE%/SlimBootloader.bin
@set SBL_STITCH_BINFILE=Outputs/%PLATFORM_TYPE%/SlimBootloaderStitch.bin

@set BASE_PY_FILE=BootloaderCorePkg\Tools\GenCapsuleFirmware.py
@set FWU_BIOS_FILE=%SBL_STITCH_BINFILE%
@set FWU_CSME_FILE=Platform\%PLATFORM_PACKAGE%\Binaries\StitchTools\Input\MeRegionFile.bin
@set FWU_KEY=%SBL_KEY_DIR%\FirmwareUpdateTestKey_Priv_RSA3072.pem 

@set STITCHIFWI_PY_FILE=Platform/%PLATFORM_PACKAGE%/Script/StitchIfwi.py
@set SOURCE_BIN_FILE=Outputs/%PLATFORM_TYPE%/Stitch_Components.zip
@set CONFIG_PY_FILE=Platform/%PLATFORM_PACKAGE%/Script/StitchIfwiConfig_rplp_688400S.py
@set WORK_PATH=Platform/%PLATFORM_PACKAGE%/Binaries/StitchTools
@set STITCHIFWI_OUTPUTPATH=Outputs\%PLATFORM_TYPE%
:: Boot guard profile: legacy,vm,fve,fvme
@set STITCHIFWI_BOOTGUARD_TYPE=legacy
@set STITCHIFWI_TYPE=rplp

@set BIOS_FEATURE=%PROJECT_CHIPSET_TYPE%%PROJECT_FW_TYPE%%PROJECT_BUILD_TYPE%
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_FEATURE%%BIOS_VERSION%.bin
@set STITCH_BIOS_IMAGE=Outputs/%PLATFORM_TYPE%/%BIOS_IMAGE%
@set STITCHIFWI_BIOS_IMAGE=%BIOS_NAME%%BIOS_FEATURE%%BIOS_VERSION%_IfwiImage.bin
@set FWU_CSMD_FILE=Build\BootloaderCorePkg\%TARGE%_%TOOL_CHAIN%\%PLATFORM_BUILDMODE%\CsmeUpdateDriver.efi
@set FWU_BIOS_IMAGE=Outputs\%PLATFORM_TYPE%\%BIOS_NAME%%BIOS_FEATURE%%BIOS_VERSION%_FwuImage.bin


@IF "%1"=="" goto EnvSet
@IF "%1"=="-a" goto BuildStitchSlim
@IF "%1"=="-b" goto BuildSlim
@IF "%1"=="-s" goto BuildStitch
@IF "%1"=="-ss" goto BuildStitchBootGuard
@IF "%1"=="-fwu" goto BuildFirmwareUpdate
@IF "%1"=="-f" goto BuildFirmwareUpdate
@IF "%1"=="-c" goto BuildClean
@IF "%1"=="-?" goto HelpMsg
@IF "%1"=="-h" goto HelpMsg
@goto Exit


::
::  Platform Build all
::

:BuildStitchSlim
@goto BuildSlim
:BuildSlimend
@goto BuildStitch
:BuildStitchEnd
@goto BuildFirmwareUpdate
:BuildFirmwareUpdateEnd
@goto BuildStitchBootGuard
:BuildStitchBootGuardEnd
@goto Exit


::
::  Build Slim BootLoader
::
:BuildSlim
@title %BIOS_IMAGE% - Build Slim BootLoader

python %BUILD_PY_FILE% build %PLATFORM_TYPE% %PLATFORM_OPTION% %PAYLOAD_BINFILE%

@IF "%1"=="-a" goto BuildSlimend
@goto Exit


::
::  Build Slim BootLoader
::
:BuildStitch
@title %STITCH_BIOS_IMAGE% - Stitch Slim BootLoader

python %STITCH_PY_FILE% -i %INPUT_BIOS_BINFILE% -s %SBL_SOURCE_BINFILE% -o %STITCH_BIOS_IMAGE% -p %PLATFORM_ID_DEBUGUART%

@IF "%1"=="-a" goto BuildStitchEnd
@goto Exit


::
::  Build Slim BootLoader
::
:BuildStitchBootGuard
@title %STITCHIFWI_BIOS_IMAGE% - Stitch BootGuard Slim BootLoader

python %STITCHIFWI_PY_FILE% -b %STITCHIFWI_BOOTGUARD_TYPE% -w %WORK_PATH% -c %CONFIG_PY_FILE% -s %SOURCE_BIN_FILE% -p %STITCHIFWI_TYPE% -d %PLATFORM_ID_DEBUGUART% -t dtpm -op %STITCHIFWI_OUTPUTPATH% -of %STITCHIFWI_BIOS_IMAGE% %STITCHIFWI_TEMP%

@IF "%1"=="-a" goto BuildStitchBootGuardEnd
@goto Exit


::
::  Build Slim BootLoader
::
:BuildFirmwareUpdate
@title %FWU_BIOS_IMAGE% - Build Slim BootLoader FWU Image

python %STITCH_PY_FILE1% -s %SBL_SOURCE_BINFILE% -o %SBL_STITCH_BINFILE%  -p %PLATFORM_ID_DEBUGUART%
::python %BASE_PY_FILE% -p BIOS %FWU_BIOS_FILE% -p CSME %FWU_CSME_FILE% -p CSMD %FWU_CSMD_FILE% -k %FWU_KEY% -o %FWU_BIOS_IMAGE% -v
::python %BASE_PY_FILE% -p BIOS %FWU_BIOS_FILE% -p CSMD %FWU_CSMD_FILE% -k %FWU_KEY% -o %FWU_BIOS_IMAGE% -v
python %BASE_PY_FILE% -p BIOS %FWU_BIOS_FILE% -k %FWU_KEY% -o %FWU_BIOS_IMAGE% -v

::@IF exist "F:\GitHub\20251202\slimbootloader\Build\BootloaderCorePkg\RELEASE_VS2022\IA32\CsmeUpdateDriver.efi (
::python %BASE_PY_FILE% -p BIOS %FWU_BIOS_FILE% -p CSME %FWU_CSME_FILE% -p CSMD %FWU_CSMD_FILE% -k %FWU_KEY% -o %FWU_BIOS_IMAGE% -v
::) else if exist %FWU_CSME_FILE% (
::python %BASE_PY_FILE% -p BIOS %FWU_BIOS_FILE% -p CSMD %FWU_CSMD_FILE% -k %FWU_KEY% -o %FWU_BIOS_IMAGE% -v
::) else (
::python %BASE_PY_FILE% -p BIOS %FWU_BIOS_FILE% -k %FWU_KEY% -o %FWU_BIOS_IMAGE% -v
::)

@IF "%1"=="-a" goto BuildFirmwareUpdateEnd
@goto Exit

::
::  Clean Slim BootLoader
::
:BuildClean
python BuildLoader.py clean
@goto Exit

::
::  Setup Platform environment
::
:EnvSet
@title Slim Boot Loader Setting environment
@set PATH=C:\envs;C:\Program Files\Git\cmd;%PATH%

@set OPENSSL_PATH=C:\Program Files\OpenSSL-Win64\bin
@set PYTHON_HOME=C:\Python39
@set PYTHONIOENCODING=utf8
@set NASM_PREFIX=C:\Nasm\
@set SBL_KEY_DIR=%CD%\Platform\%PLATFORM_PACKAGE%\Binaries\Keys\sblKeys
@set IASL_PREFIX=C:\ASL\
@set WORKSPACE=%CD%
@set PACKAGES_PATH=%CD%
@set EDK_TOOLS_PATH=%CD%\BaseTools
@set BASE_TOOLS_PATH=%CD%\BaseTools

@IF exist "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat" (
@call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"
) else if exist "C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat" (
@call "C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat"
) else if exist "C:\Program Files\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat" (
@call "C:\Program Files\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"
) else if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat" (
@call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"
) else if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat" (
@set VSCMD_DEBUG=1
@call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"
) else (
@echo Visual Studio Community 2022, 2019, 2017
@goto Exit
)
:: SBL only support VS2019 
@IF %VisualStudioVersion% == 17.0 (@set TOOL_CHAIN=VS2022)
::@IF %VisualStudioVersion% == 17.0 (@set TOOL_CHAIN=VS2019)
@IF %VisualStudioVersion% == 16.0 (@set TOOL_CHAIN=VS2019)
@IF %VisualStudioVersion% == 15.0 (@set TOOL_CHAIN=VS2017)
@IF %VisualStudioVersion% == 14.0 (@set TOOL_CHAIN=VS2015)  

@chcp 65001
  
@goto Exit

::
::  Display Help information
::
:HelpMsg
@echo Slim Boot Loader Setup & Build Environment
@echo       -c      Clean Slim Boot Loader
@echo       -a      Build & Stitch Slim Boot Loader 
@echo       -b      Build Slim Boot Loader 
@echo       -s      Stitch Slim Boot Loader
@echo       -ss     Stitch BootGuard
@echo       -fwu    Build FirmwareUpdate Image
@echo       -f      Build FirmwareUpdate Image
@echo       -k      Create SBL Keys
@echo       -r      Build Release Mode Slim Boot Loader
@echo       -h      Show Help message  
@echo       -?      Show Help message  
@echo  Recommand before rebuild Slim Boot Loader clean it first..
@echo  Example: Slim -c
@echo  Build & Stitch Slim Boot Loader 
@echo  Example: Slim -a 
@echo  Build & Stitch Slim Boot Loader release mode
@echo  Example: Slim -a -r
@echo  Stitch Slim Boot Loader with BootGuard feature
@echo  Example: Slim -ss
@echo  Build Firmware Update Image into FwuImage.bin
@echo  Example: Slim -fwu

@goto Exit

:Exit


