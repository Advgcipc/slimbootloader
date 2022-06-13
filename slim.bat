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
@IF "%2"=="apl" goto Buildapl
@IF "%2"=="tgl" goto Buildtgl
@IF "%2"=="tglh" goto Buildtglh
@IF "%2"=="cfl" goto Buildcfl
@IF "%2"=="ehl" goto Buildehl
@goto BuildEnd

:Buildapl
@title Slim Boot Loader - Buildapl
@IF "%3"=="-r" goto Buildaplr
python BuildLoader.py build apl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADDbg.fd:UEFI:Lzma"
@goto Stitchapl
:Buildaplr
python BuildLoader.py build apl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADRel.fd:UEFI:Lzma"
@goto Stitchapl

:Buildtgl
@title Slim Boot Loader - Buildtgl
@IF "%3"=="-r" goto Buildtglr
python BuildLoader.py build tgl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADDbg.fd:UEFI:Lzma"
@goto Stitchtgl
:Buildtglr
python BuildLoader.py build tgl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADRel.fd:UEFI:Lzma"
@goto Stitchtgl
::@goto BuildEnd

:Buildtglh
@title Slim Boot Loader - Buildtglh
python BuildLoader.py build tgl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD.fd:UEFI:Lzma"
@goto Stitchtglh

:Buildcfl
@title Slim Boot Loader - Buildcfl
@IF "%3"=="-r" goto Buildcflr
python BuildLoader.py build cfl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADDbg.fd:UEFI:Lzma"
@goto Stitchcfl
:Buildcflr
python BuildLoader.py build cfl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADRel.fd:UEFI:Lzma"
@goto Stitchcfl

:Buildehl
@title Slim Boot Loader - Buildehl
@IF "%3"=="-r" goto Buildehlr
python BuildLoader.py build ehl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADDbg.fd:UEFI:Lzma" -fp Platform/ElkhartlakeBoardPkg/BiosBin 
@goto Stitchehl
:Buildehlr
python BuildLoader.py build ehl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADRel.fd:UEFI:Lzma" -fp Platform/ElkhartlakeBoardPkg/BiosBin
@goto Stitchehl

:Buildcml
@title Slim Boot Loader - Buildcml
@IF "%3"=="-r" goto Buildcmlr
python BuildLoader.py build cml -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADDbg.fd:UEFI:Lzma"
@goto BuildEnd
:Buildcmlr
python BuildLoader.py build cml -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADRel.fd:UEFI:Lzma"
@goto BuildEnd

:Buildcmlv
@title Slim Boot Loader - Buildcmlv
@IF "%3"=="-r" goto Buildcmlvr
python BuildLoader.py build cmlv -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADDbg.fd:UEFI:Lzma"
@goto BuildEnd
:Buildcmlvr
python BuildLoader.py build cmlv -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOADRel.fd:UEFI:Lzma"
@goto BuildEnd

:BuildEnd
@goto Exit

:BuildStitch
@title Slim Boot Loader - BuildStitch
@IF "%2"=="apl" goto Stitchapl
@IF "%2"=="tgl" goto Stitchtgl
@IF "%2"=="cfl" goto Stitchcfl
@IF "%2"=="tglh" goto Stitchtglh
@IF "%2"=="ehl" goto Stitchehl
@IF "%2"=="cml" goto Stitchcml
@IF "%2"=="cmlv" goto Stitchcmlv
@goto StitchEnd

:Stitchapl
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/25690000I60V111.bin -s Outputs/apl/Stitch_Components.zip -o Build/2569000SI60V111.bin -p AA000210
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/35690000I60V400.bin -s Outputs/apl/Stitch_Components.zip -o Build/3569000SI60V400.bin -p AA000311
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/68690000I60V300.bin -s Outputs/apl/Stitch_Components.zip -o Build/6869000SI60V300.bin -p AA000212
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/75690000I60V300.bin -s Outputs/apl/Stitch_Components.zip -o Build/7569000SI60V300.bin -p AA000313
@goto StitchEnd

:Stitchcfl
::python Platform/CoffeelakeBoardPkg/Script/StitchLoader.py -i Platform/CoffeelakeBoardPkg/BiosBin/6882000U160V110.BIN -s Outputs/cfl/SlimBootloader.bin -o Build/6882000S160X001.BIN -p AA000201
python Platform/CoffeelakeBoardPkg/Script/StitchLoader.py -i Platform/CoffeelakeBoardPkg/BiosBin/A586000Q060V201.BIN -s Outputs/cfl/SlimBootloader.bin -o Build/A586000Q060X001.BIN -p AA000302
@goto StitchEnd

:Stitchtgl
python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/7583000U060V110.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/7583000S060X001.BIN -p AA000201
::python Platform/TigerlakeBoardPkg/Script/StitchIfwi.py -b vm -w %CD%\..\Download\TigerlakeStitch -c Platform/TigerlakeBoardPkg/Script/StitchIfwiConfig_tglu.py -s Outputs/tgl/Stitch_Components.zip -p tglu_b0

@goto StitchEnd

:Stitchtglh
python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/AmiTglHCfg1.bin -s Outputs/tgl/SlimBootloader.bin -o Build/AmiTglHCfg1S.bin

@goto StitchEnd

:Stitchehl
python Platform/ElkhartlakeBoardPkg/Script/StitchLoader.py -i Platform/ElkhartlakeBoardPkg/BiosBin/25320000060V110.BIN -s Outputs/ehl/SlimBootloader.bin -o Build/25320000060X001.BIN -p AA000210
::python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/AmiTglHCfg1.bin -s Outputs/tgl/SlimBootloader.bin -o Build/AmiTglHCfg1S.bin

@goto StitchEnd

:Stitchcml
::python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/AmiTglHCfg1.bin -s Outputs/tgl/SlimBootloader.bin -o Build/AmiTglHCfg1S.bin

@goto StitchEnd

:Stitchcmlv
::python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/BiosBin/AmiTglHCfg1.bin -s Outputs/tgl/SlimBootloader.bin -o Build/AmiTglHCfg1S.bin

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
