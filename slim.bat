@set BIOS_NAME=688400S
@set BIOS_DEBUG=0
@set BIOS_FEATURE=08
@set BUILD_NUMBER=22
::self.VERINFO_PROJ_MAJOR_VER;self.VERINFO_PROJ_MINOR_VER;
@set PROJ_MAJOR_VER=1
@set PROJ_MINOR_VER=5
@set BIOS_VERSION=0V%PROJ_MAJOR_VER%0%PROJ_MINOR_VER%
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin
::struct {UINT8 PlatformId : 5;UINT8  Reserved1  : 3;UINT8  DebugUart;UINT8 Reserved3;UINT8 Marker;} STITCH_DATA;
:: PlatformId ==> SOM-6884A2:0x1E;SOM-6884:0x1D ;; DebugUart ==> SOC UART0:0; SIO UART0:0xFF;SIO UART1:0xFE      
@set PLATFORM_ID_DEBUGUART=AA00FF1E
@set PLATFORM_TYPE=rplp
@set PLATFORM_PACKAGE=RaptorlakeBoardPkg
@set BUILD_PY_FILE=BuildLoader.py
@set STITCH_PY_FILE=Platform/%PLATFORM_PACKAGE%/Script/StitchLoader.py
@set STITCH_PY_FILE1=Platform/%PLATFORM_PACKAGE%/Script/StitchLoader1.py
@set SBL_SOURCE_BINFILE=Outputs/%PLATFORM_TYPE%/SlimBootloader.bin
@set SBL_STITCH_BINFILE=Outputs/%PLATFORM_TYPE%/SlimBootloaderStitch.bin
::@set INPUT_BIOS_BINFILE=Platform/%PLATFORM_PACKAGE%/Binaries/BiosBin/68840000060V201.bin
::@set INPUT_BIOS_BINFILE=Platform/%PLATFORM_PACKAGE%/Binaries/BiosBin/68840000060V201_TS512.bin
@set INPUT_BIOS_BINFILE=Platform/%PLATFORM_PACKAGE%/Binaries/BiosBin/6884A200060V110_TS512.bin


@IF "%1"=="" goto EnvSet
@IF "%1"=="-a" goto BuildStitchSlim
@IF "%1"=="-b" goto BuildSlim
@IF "%1"=="-g" goto BuildSource
@IF "%1"=="-s" goto BuildStitch
@IF "%1"=="-ss" goto BuildStitchBootGuard
@IF "%1"=="-fwu" goto BuildFirmwareUpdate
@IF "%1"=="-c" goto BuildClean
@IF "%1"=="-k" goto BuildKey
@IF "%1"=="-?" goto HelpMsg
@IF "%1"=="-h" goto HelpMsg
@goto Exit

:EnvSet
@title Slim Boot Loader Setting environment
@IF "OPENSSL_PATH"=="" goto HelpMsg

@set PATH=C:\Python36;C:\envs;%ProgramFiles%\Dediprog\SF100;C:\Program Files\Git\cmd;%PATH%
@set OPENSSL_PATH=C:\Openssl
@set PYTHON_HOME=C:\Python36
@set NASM_PREFIX=C:\Nasm\
@set SBL_KEY_DIR=%CD%\sblKeys
@set IASL_PREFIX=C:\ASL\
@set BASE_TOOLS_PATH=%CD%\BaseTools
::change windows page code 
:: 0x80E2 at 5736,5737,5738,5759 $(SBL_DIR)\MdePkg\Include\Register\Intel\ArchitecturalMsr.h
@chcp 65001

@call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"

@goto Exit

:BuildKey
python BootloaderCorePkg\Tools\GenerateKeys.py -k %SBL_KEY_DIR%
@goto Exit

:BuildSource
cd..
::git clone git@github.com:Advgcipc/slimbootloader.git
git clone https://github.com/slimbootloader/slimbootloader.git
cd slimbootloader
git checkout e9f9845d

:: robocopy /s %CD%\..\AdvantechSBL\ %CD%\
@goto Exit

:BuildStitchSlim
@goto BuildSlim
:BuildSlimend
@goto BuildStitch
:BuildStitchend
@goto BuildFirmwareUpdate


:BuildSlim
:: @robocopy /s %CD%\..\AdvantechSBL\ %CD%\

@IF "%2"=="-r" set BIOS_DEBUG=0
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin
@IF "%2"=="-r" goto BuildSlimR
python %BUILD_PY_FILE% build %PLATFORM_TYPE% -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_DEBUG.fd:UEFI:Lzma"

@IF "%1"=="-a" goto BuildSlimend

@goto BuildEnd

:BuildSlimR
@IF "%2"=="-r" set BIOS_DEBUG=0
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin
python %BUILD_PY_FILE% build %PLATFORM_TYPE% -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_RELEASE.fd:UEFI:Lzma"

@IF "%1"=="-a" goto BuildSlimend
@goto BuildEnd


:BuildEnd
@goto Exit

:BuildStitch
:: @robocopy /s %CD%\..\AdvantechSBL\ %CD%\
@IF "%2"=="-r" set BIOS_DEBUG=0
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin

@title Stitch Boot Loader - Build %BIOS_IMAGE%

@IF "%2"=="-r" goto BuildStitchR
python %STITCH_PY_FILE% -i %INPUT_BIOS_BINFILE% -s %SBL_SOURCE_BINFILE% -o Build/%BIOS_IMAGE%  -p %PLATFORM_ID_DEBUGUART%
@IF "%1"=="-a" goto BuildFirmwareUpdate
@goto StitchEnd

:BuildStitchR
python %STITCH_PY_FILE% -i %INPUT_BIOS_BINFILE% -s %SBL_SOURCE_BINFILE% -o Build/%BIOS_IMAGE%  -p %PLATFORM_ID_DEBUGUART%

@IF "%1"=="-a" goto BuildFirmwareUpdate
@goto StitchEnd

:BuildStitchBootGuard
@echo BuildStitchBootGuard todo

@goto StitchEnd

:StitchEnd
@goto Exit


:BuildFirmwareUpdate
@title Build Firmware Update Image
@set BASE_PY_FILE=BootloaderCorePkg\Tools\GenCapsuleFirmware.py
@set PAYLOAD_FILE1=Platform\%PLATFORM_PACKAGE%\Binaries\StitchTools\Temp1\MeRegionFile.bin
:@set PAYLOAD_FILE2=Build\BootloaderCorePkg\RELEASE_VS2022\IA32\CsmeUpdateDriver.efi
@set PAYLOAD_FILE2=Build\BootloaderCorePkg\RELEASE_VS2019\IA32\CsmeUpdateDriver.efi
@IF "%2"=="-r" goto BuildFirmwareUpdateRelease
:@set PAYLOAD_FILE2=Build\BootloaderCorePkg\DEBUG_VS2022\IA32\CsmeUpdateDriver.efi
@set PAYLOAD_FILE2=Build\BootloaderCorePkg\RELEASE_VS2019\IA32\CsmeUpdateDriver.efi
:BuildFirmwareUpdateRelease
@set FWU_KEY=%SBL_KEY_DIR%\FirmwareUpdateTestKey_Priv_RSA3072.pem 
@set FWU_OUTPUTFILE=Build\FwuImage.bin
@set PAYLOAD_FILE0=%SBL_STITCH_BINFILE%

python %STITCH_PY_FILE1% -s %SBL_SOURCE_BINFILE% -o %SBL_STITCH_BINFILE%  -p %PLATFORM_ID_DEBUGUART%

python %BASE_PY_FILE% -p BIOS %PAYLOAD_FILE0% -p CSMD %PAYLOAD_FILE2% -k %FWU_KEY% -o %FWU_OUTPUTFILE% -v

@goto Exit


:StitchEnd
@goto Exit


:BuildClean
python BuildLoader.py clean
@goto Exit

:HelpMsg
@echo "%WORKSPACE%"
@echo "Slim Boot Loader Setup & Build Environment
@echo "      -g      Get Slim Boot Loader Source
@echo "      -c      Clean Slim Boot Loader
@echo "      -a      Build & Stitch Slim Boot Loader 
@echo "      -b      Build Slim Boot Loader 
@echo "      -s      Stitch Slim Boot Loader
@echo "      -ss     Stitch BootGuard
@echo "      -fwu    Build FirmwareUpdate Image
@echo "      -k      Create SBL Keys
@echo "      -r      Build Release Mode Slim Boot Loader
@echo "      -h      Show Help message  
@echo "      -?      Show Help message  
@echo " Recommand before rebuild Slim Boot Loader clean it at first.
@echo " Example: Slim -c
@echo " Build & Stitch Slim Boot Loader 
@echo " Example: Slim -a 
@echo " Build & Stitch Slim Boot Loader release mode
@echo " Example: Slim -a -r
@echo " Stitch Slim Boot Loader with BootGuard feature
@echo " Example: Slim -ss
@echo " Build Firmware Update Image into Build\FwuImage.bin
@echo " Example: Slim -fwu

@goto Exit

:Exit
@title Slim Boot Loader Setting environment
