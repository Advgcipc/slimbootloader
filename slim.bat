@set BIOS_NAME=758300
@set BIOS_DEBUG=1
@set BIOS_FEATURE=S06
@set BIOS_VERSION=0V106
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin
@set PLATFORM_ID_DEBUGUART=AA00FE10
::@set PLATFORM_ID_DEBUGUART=AA000210

@IF "%1"=="" goto EnvSet
@IF "%1"=="-a" goto BuildStitchSlim
@IF "%1"=="-b" goto BuildSlim
@IF "%1"=="-g" goto BuildSource
@IF "%1"=="-s" goto BuildStitch
@IF "%1"=="-ss" goto BuildStitchBootGuard
@IF "%1"=="-c" goto BuildClean
@IF "%1"=="-k" goto BuildKey
@IF "%1"=="-?" goto HelpMsg
@IF "%1"=="-h" goto HelpMsg
@goto Exit

:EnvSet
@title Slim Boot Loader Setting environment
@IF "OPENSSL_PATH"=="" goto HelpMsg

@set PATH=C:\envs;%ProgramFiles%\Dediprog\SF100;C:\Program Files\Git\cmd;%PATH%
@set OPENSSL_PATH=C:\Openssl
@set PYTHON_HOME=C:\Python36
@set NASM_PREFIX=C:\Nasm\
@set SBL_KEY_DIR=%CD%\..\sblKeys\
@set IASL_PREFIX=C:\ASL\
@set WORKSPACE=%CD%
@set PACKAGES_PATH=%CD%
@set EDK_TOOLS_PATH=%CD%\BaseTools
@set BASE_TOOLS_PATH=%CD%\BaseTools


@call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"
  
@goto Exit

:BuildKey
python BootloaderCorePkg\Tools\GenerateKeys.py -k ..\sblKeys
@goto Exit

:BuildSource
::echo git clone --recurse-submodules https://github.com/Advgcipc/slimbootloader.git
git clone --recurse-submodules https://github.com/Advgcipc/slimbootloader.git
@goto Exit

:BuildStitchSlim
@goto BuildSlim
:BuildSlimend
@goto BuildStitch


:BuildSlim
@IF "%2"=="-r" set BIOS_DEBUG=0
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin
@IF "%2"=="-r" goto BuildSlimR
::python BuildLoader.py build tgl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADDbg.fd:UEFI:Lzma"
python BuildLoader.py build tgl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_DEBUG.fd:UEFI:Lzma"
::python BuildLoader.py build tgl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD.fd:UEFI:Lzma"
@goto BuildEnd

:BuildSlimR
@IF "%2"=="-r" set BIOS_DEBUG=0
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin
python BuildLoader.py build tgl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_RELEASE.fd:UEFI:Lzma"
@goto BuildEnd


:BuildEnd
@IF "%1"=="-a" goto BuildSlimend
@goto Exit

:BuildStitch
@IF "%2"=="-r" goto BuildStitchR
@title Stitch Boot Loader - Build %BIOS_IMAGE%

@set BASE_PY_FILE=Platform/TigerlakeBoardPkg/Script/StitchLoader.py
@set SBL_SOURCE_BINFILE=Outputs/tgl/SlimBootloader.bin
@set INPUT_BIOS_BINFILE=Platform/TigerlakeBoardPkg/Binaries/BiosBin/7583000U060V110.BIN

python %BASE_PY_FILE% -i %INPUT_BIOS_BINFILE% -s %SBL_SOURCE_BINFILE% -o Build/%BIOS_IMAGE% -p %PLATFORM_ID_DEBUGUART%
::python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/7583000U060V110.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/%BIOS_IMAGE% -p %PLATFORM_ID_DEBUGUART%
@goto StitchEnd

:BuildStitchR
@IF "%2"=="-r" set BIOS_DEBUG=0
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin
@title Stitch Boot Loader - Build %BIOS_IMAGE%

@set BASE_PY_FILE=Platform/TigerlakeBoardPkg/Script/StitchLoader.py
@set SBL_SOURCE_BINFILE=Outputs/tgl/SlimBootloader.bin
@set INPUT_BIOS_BINFILE=Platform/TigerlakeBoardPkg/Binaries/BiosBin/7583000U060V110.BIN

python %BASE_PY_FILE% -i %INPUT_BIOS_BINFILE% -s %SBL_SOURCE_BINFILE% -o Build/%BIOS_IMAGE% -p %PLATFORM_ID_DEBUGUART%

::python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/7583000U060V110.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/%BIOS_IMAGE% -p %PLATFORM_ID_DEBUGUART%
@goto StitchEnd


:: //7583X005_1
:BuildStitchBootGuard
@set BASE_PY_FILE=Platform/TigerlakeBoardPkg/Script/StitchIfwi.py
@set SOURCE_BIN_FILE=Outputs/tgl/Stitch_Components.zip
@set CONFIG_PY_FILE=Platform/TigerlakeBoardPkg/Binaries/StitchTools/Script/StitchIfwiConfig_SOM7583.py
@set WORK_PATH=Platform/TigerlakeBoardPkg/Binaries/StitchTools

@set BIOS_FEATURE=S10
@IF "%2"=="-r" set BIOS_DEBUG=0
@set BIOS_IMAGE=%BIOS_NAME%%BIOS_DEBUG%%BIOS_FEATURE%%BIOS_VERSION%.bin

@title Stitch Boot Loader - Build %BIOS_IMAGE%
python %BASE_PY_FILE% -b vm -w %WORK_PATH% -c %CONFIG_PY_FILE% -s %SOURCE_BIN_FILE% -p tglu_b0 -d %PLATFORM_ID_DEBUGUART% -op Build -of %BIOS_IMAGE%
@goto StitchEnd

:StitchEnd
@goto Exit

:BuildClean
python BuildLoader.py clean
@goto Exit

:HelpMsg
@echo Slim Boot Loader Setup & Build Environment
@echo       -g      Get Slim Boot Loader Source
@echo       -c      Clean Slim Boot Loader
@echo       -a      Build & Stitch Slim Boot Loader 
@echo       -b      Build Slim Boot Loader 
@echo       -s      Stitch Slim Boot Loader
@echo       -k      Create SBL Keys
@echo       -r      Build Release Mode Slim Boot Loader
@echo       -h      Show Help message  
@echo       -?      Show Help message  
@echo Example: Slim -b apl/cfl/tgl/tglh/ehl/cml/cmlv -r
@echo Recommand before rebuild Slim Boot Loader clean it first..
@echo Example: Slim -c
@echo 
@echo Stitch Slim Boot Loader 
@echo Orignal BIOS Image located at Platform/$(PlatformName)BoardPkg/BiosBin/XXXImage
@echo Example: Slim -a  Build & Stitch Slim Boot Loader 
@goto Exit

:Exit
@title Slim Boot Loader Setting environment
