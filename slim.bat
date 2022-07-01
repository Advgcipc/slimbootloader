@IF "%1"=="" goto EnvSet
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

:BuildSlim

@IF "%2"=="ehl" goto Buildehl
@goto BuildEnd



:Buildehl
@title Slim Boot Loader - Buildehl
@IF "%3"=="-r" goto Buildehlr
python BuildLoader.py build ehl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADDbg.fd:UEFI:Lzma"
@goto Stitchehl
:Buildehlr
python BuildLoader.py build ehl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADRel.fd:UEFI:Lzma"
@goto Stitchehlr


:BuildEnd
@goto Exit

:BuildStitch
@title Slim Boot Loader - BuildStitch

@IF "%2"=="ehl" goto Stitchehl

@goto StitchEnd



:://DS202_SBL_X001_01// >>
:Stitchehl
python Platform/ElkhartlakeBoardPkg/Script/StitchLoader.py -i Platform/ElkhartlakeBoardPkg/BiosBin/D2020000060V110.BIN -s Outputs/ehl/SlimBootloader.bin -o D20200S0D60X001.BIN -p AA00FF11
::python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/AmiTglHCfg1.bin -s Outputs/tgl/SlimBootloader.bin -o Build/AmiTglHCfg1S.bin

@goto StitchEnd

:Stitchehlr
python Platform/ElkhartlakeBoardPkg/Script/StitchLoader.py -i Platform/ElkhartlakeBoardPkg/BiosBin/D2020000060V110.BIN -s Outputs/ehl/SlimBootloader.bin -o D20200S0060X001.BIN -p AA00FF11
@goto StitchEnd
:://DS202_SBL_X001_01// <<


:StitchEnd
@goto Exit

:BuildClean
python BuildLoader.py clean
@goto Exit

:HelpMsg
@echo Slim Boot Loader Setup & Build Environment
@echo       -g      Get Slim Boot Loader Source
@echo       -c      Clean Slim Boot Loader
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
@echo Example: Slim -s apl/cfl/tgl/tglh/ehl/cml/cmlv
@goto Exit

:Exit
@title Slim Boot Loader Setting environment
