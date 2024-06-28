@set BIOS_NAME=6884000
@set BIOS_DEBUG=1
@set BIOS_FEATURE=08
@set BIOS_VERSION=0X001
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin
@set PLATFORM_ID_DEBUGUART=AA00FF1F
@set PLATFORM_TYPE=rplp
@set PLATFORM_PACKAGE=RaptorlakeBoardPkg
@set BUILD_PY_FILE=BuildLoader.py
@set STITCH_PY_FILE=Platform/%PLATFORM_PACKAGE%/Script/StitchLoader.py
@set SBL_SOURCE_BINFILE=Outputs/%PLATFORM_TYPE%/SlimBootloader.bin
@set INPUT_BIOS_BINFILE=Platform/%PLATFORM_PACKAGE%/Binaries/BiosBin/68840000060V201.bin


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
@set SBL_KEY_DIR=%CD%\..\sblKeys\
@set IASL_PREFIX=C:\ASL\
@set BASE_TOOLS_PATH=%CD%\BaseTools


@call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"

@goto Exit

:BuildKey
python BootloaderCorePkg\Tools\GenerateKeys.py -k ..\sblKeys
@goto Exit

:BuildSource
git clone git@github.com:Advgcipc/slimbootloader.git
@goto Exit

:BuildStitchSlim
@goto BuildSlim
:BuildSlimend
@goto BuildStitch


:BuildSlim
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
@IF "%2"=="-r" set BIOS_DEBUG=0
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin

@title Stitch Boot Loader - Build %BIOS_IMAGE%

@IF "%2"=="-r" goto BuildStitchR
python %STITCH_PY_FILE% -i %INPUT_BIOS_BINFILE% -s %SBL_SOURCE_BINFILE% -o Build/%BIOS_IMAGE%  -p %PLATFORM_ID_DEBUGUART%

@goto StitchEnd

:BuildStitchR
python %STITCH_PY_FILE% -i %INPUT_BIOS_BINFILE% -s %SBL_SOURCE_BINFILE% -o Build/%BIOS_IMAGE%  -p %PLATFORM_ID_DEBUGUART%

@goto StitchEnd

:BuildStitchBootGuard
@echo BuildStitchBootGuard todo

@goto StitchEnd

:StitchEnd
@goto Exit


:BuildFirmwareUpdate
@echo BuildFirmwareUpdate todo

::@title Build Firmware Update Image
::
::@set BASE_PY_FILE=BootloaderCorePkg\Tools\GenCapsuleFirmware.py
::@set PAYLOAD_FILE0=Platform\TigerlakeBoardPkg\Binaries\StitchTools\Temp\BiosRegion.bin
::@set PAYLOAD_FILE1=Platform\TigerlakeBoardPkg\Binaries\StitchTools\Temp\MeRegionFile.bin
::@set PAYLOAD_FILE2=Platform\TigerlakeBoardPkg\Binaries\Sbl32\CsmeUpdateDriver.efi
::@set FWU_KEY=%SBL_KEY_DIR%\FirmwareUpdateTestKey_Priv_RSA3072.pem 
::@set FWU_OUTPUTFILE=Build\FwuImage.bin

::python %BASE_PY_FILE% -p BIOS %PAYLOAD_FILE0% -p CSME %PAYLOAD_FILE1% -p CSMD %PAYLOAD_FILE2% -k %FWU_KEY% -o %FWU_OUTPUTFILE% -v
@goto Exit


:StitchEnd
@goto Exit


:BuildClean
python BuildLoader.py clean
@goto Exit

:HelpMsg
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
