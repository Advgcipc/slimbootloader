#!/bin/bash

BIOS_NAME="758300"
BIOS_DEBUG="1"
BIOS_FEATURE="S06"
BIOS_VERSION="0V107"
BIOS_IMAGE=$BIOS_NAME$BIOS_DEBUG$BIOS_FEATURE$BIOS_VERSION".bin"
PLATFORM_ID_DEBUGUART="AA00FE10"


if [ "$1" == "" ]; then
	echo "Usage: slim.sh <arg1> <arg2>"
	exit 1
fi

case "$1" in
	# -b:
	"-b")
		echo "build realease"

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
		echo "build Stitch"
		if [ "$2" == "-r" ]; then
			BIOS_DEBUG="0"
      BIOS_IMAGE=$BIOS_NAME$BIOS_DEBUG$BIOS_FEATURE$BIOS_VERSION".bin"
		fi

		  python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/Binaries/BiosBin/7583000U060V110.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/$BIOS_IMAGE -p $PLATFORM_ID_DEBUGUART
		  echo "python Platform/TigerlakeBoardPkg/Script/StitchLoader.py -i Platform/TigerlakeBoardPkg/Binaries/BiosBin/7583000U060V110.BIN -s Outputs/tgl/SlimBootloader.bin -o Build/$BIOS_IMAGE -p $PLATFORM_ID_DEBUGUART"
		;;
	# -c:
	"-c")
		echo "build clean"
		python BuildLoader.py clean
		echo "python BuildLoader.py clean"
		;;
	*)
		echo "Usage: slim.sh <arg1> <arg2>"
		exit 1
		;;
esac

