@set BIOS_VERSION=0X004
@set BIOS_IMAGE=7583000S00%BIOS_VERSION%.bin
@set BIOS_DEBUG_IMAGE=7583001S000X004.bin
@IF "%1"=="" goto EnvSet
@IF "%1"=="-a" goto BuildStitchSlim
@IF "%1"=="-b" goto BuildSlim
@IF "%1"=="-g" goto BuildSource
@IF "%1"=="-s" goto BuildStitch
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
@title Slim Boot Loader - Build %BIOS_DEBUG_IMAGE%
@IF "%2"=="-r" goto BuildSlimR
python BuildLoader.py build tgl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADDbg.fd:UEFI:Lzma"
@goto BuildEnd

:BuildSlimR
@title Slim Boot Loader - Build %BIOS_IMAGE%
python BuildLoader.py build tgl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADRel.fd:UEFI:Lzma"
@goto BuildEnd


:BuildEnd
@IF "%1"=="-a" goto BuildSlimend
@goto Exit

:BuildStitch
@title Stitch Boot Loader - Build %BIOS_DEBUG_IMAGE%
@IF "%2"=="-r" goto BuildStitchR
:: UART2 of SIO
python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/7583000U060V110.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/%BIOS_DEBUG_IMAGE% -p AA00FE10
:: UART2 of PCH
::python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/7583000U060V110.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/%BIOS_DEBUG_IMAGE% -p AA000210
@goto StitchEnd

:BuildStitchR
@title Stitch Boot Loader - Build %BIOS_IMAGE%
:: UART2 of SIO
python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/7583000U060V110.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/%BIOS_IMAGE% -p AA00FE10
:: UART2 of PCH
::python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/7583000U060V110.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/%BIOS_IMAGE% -p AA000210
::python Platform/TigerlakeBoardPkg/Script/StitchIfwi.py -b vm -w %CD%\..\Download\TigerlakeStitch -c Platform/TigerlakeBoardPkg/Script/StitchIfwiConfig_tglu.py -s Outputs/tgl/Stitch_Components.zip -p tglu_b0
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
