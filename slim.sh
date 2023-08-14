#!/bin/bash

BIOS_NAME="758300"
BIOS_DEBUG="1"
BIOS_FEATURE="S06"
BIOS_VERSION="0V111"
BIOS_IMAGE=$BIOS_NAME$BIOS_DEBUG$BIOS_FEATURE$BIOS_VERSION".bin"
PLATFORM_ID_DEBUGUART="AA00FE10"


if [ "$1" == "" ]; then
	echo "Usage: slim.sh <arg1> <arg2>"
	exit 1
fi

case "$1" in
	# -b:
	"-b")
		echo "Build Slim"

		#echo BIOS_IMAGE=$BIOS_IMAGE

		if [ "$2" == "-r" ]; then
			BIOS_DEBUG="0"
      BIOS_IMAGE=$BIOS_NAME$BIOS_DEBUG$BIOS_FEATURE$BIOS_VERSION".bin"
			python BuildLoader.py build tgl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_DEBUG.fd:UEFI:Lzma"
			echo "python BuildLoader.py build tgl -p \"OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_DEBUG.fd:UEFI:Lzma\""
		else
			python BuildLoader.py build tgl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_RELEASE.fd:UEFI:Lzma"
			echo "python BuildLoader.py build tgl -r -p \"OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_RELEASE.fd:UEFI:Lzma\""
		fi

		;;
	# -s:
	"-s")
		echo "Build Stitch"
		if [ "$2" == "-r" ]; then
			BIOS_DEBUG="0"
      BIOS_IMAGE=$BIOS_NAME$BIOS_DEBUG$BIOS_FEATURE$BIOS_VERSION".bin"
		fi

		  python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/Binaries/BiosBin/7583000U060V11.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/$BIOS_IMAGE -p $PLATFORM_ID_DEBUGUART
		  echo "python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/Binaries/BiosBin/7583000U060V110.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/$BIOS_IMAGE -p $PLATFORM_ID_DEBUGUART"
		;;
	"-ss")
		echo "Build Stitch BootGuard"
		if [ "$2" == "-r" ]; then
			BIOS_DEBUG="0"
      BIOS_IMAGE=$BIOS_NAME$BIOS_DEBUG$BIOS_FEATURE$BIOS_VERSION".bin"
		fi
      BASE_PY_FILE=Platform/TigerlakeBoardPkg/Script/StitchIfwi.py
      SOURCE_BIN_FILE=Outputs/tgl/Stitch_Components.zip
      CONFIG_PY_FILE=Platform/TigerlakeBoardPkg/Binaries/StitchTools/Script/StitchIfwiConfig_SOM7583.py
      WORK_PATH=Platform/TigerlakeBoardPkg/Binaries/StitchTools


      python $BASE_PY_FILE -b vm -w $WORK_PATH -c $CONFIG_PY_FILE -s $SOURCE_BIN_FILE -p tglu_b0 -d $PLATFORM_ID_DEBUGUART -op Build -of $BIOS_IMAGE
		  echo "python $BASE_PY_FILE -b vm -w $WORK_PATH -c $CONFIG_PY_FILE -s $SOURCE_BIN_FILE -p tglu_b0 -d $PLATFORM_ID_DEBUGUART -op Build -of $BIOS_IMAGE"
		;;
	"-fwu")
		echo "Build Firmware Update Image"

      BASE_PY_FILE=BootloaderCorePkg/Tools/GenCapsuleFirmware.py
      PAYLOAD_FILE0=Platform/TigerlakeBoardPkg/Binaries/StitchTools/Temp/BiosRegion.bin
      PAYLOAD_FILE1=Platform/TigerlakeBoardPkg/Binaries/StitchTools/Temp/MeRegionFile.bin
      PAYLOAD_FILE2=Platform/TigerlakeBoardPkg/Binaries/Sbl32/CsmeUpdateDriver.efi
      FWU_KEY=$SBL_KEY_DIR/FirmwareUpdateTestKey_Priv_RSA3072.pem 
      FWU_OUTPUTFILE=Build/FwuImage.bin
      
      python $BASE_PY_FILE -p BIOS $PAYLOAD_FILE0 -p CSME $PAYLOAD_FILE1 -p CSMD $PAYLOAD_FILE2 -k $FWU_KEY -o $FWU_OUTPUTFILE -v
		;;
	# -c:
	"-c")
		echo "build clean"
		python BuildLoader.py clean
		echo "python BuildLoader.py clean"
		;;
	*)
		echo "Slim Boot Loader Setup & Build Environment"
		echo "      -c      Clean Slim Boot Loader"
#		echo "      -a      Build & Stitch Slim Boot Loader"
		echo "      -b      Build Slim Boot Loader"
		echo "      -s      Stitch Slim Boot Loader"
		echo "      -ss     Stitch BootGuard"
		echo "      -fwu    Build FirmwareUpdate Image"
#		echo "      -k      Create SBL Keys"
#		echo "      -r      Build Release Mode Slim Boot Loader"
		echo "      -?      Show Help message"
		echo " Recommand before rebuild Slim Boot Loader clean it first.."
		echo "Usage:"
		echo "    ./slim.sh -c      : Clean Slim Boot Loader" 
		echo "    ./slim.sh -a      : Build & Stitch Slim Boot Loader release mode"
#		echo "    ./slim.sh -a -r   : Stitch Slim Boot Loader with BootGuard feature"
		echo "    ./slim.sh -s      : Build Firmware Update Image"
		echo "    ./slim.sh -ss     : Build Firmware Update Image into Build\FwuImage.bin"
		echo "    ./slim.sh -fwu    : Build FirmwareUpdate Image"
		exit 1
		;;
esac

