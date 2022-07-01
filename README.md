![Alt text](https://www.advantech.tw/css/css-img/advantech-logo-notagl.svg "Advantech sbl")

# Slim Boot Loader support 
#  Project Name : DS-202 
##  Hardware Configuration
    CPU         : ElkhartLake
    Chipset     : ElkhartLake
    ClockGEN    : ElkhartLake
    SuperI/O    : ITE_IT5121VG-I-128/CX (eSPI)
    Flash ROM   : MX25L25673G

	
##  Revision History
    BIOS Name     : D20200S0060X001.BIN ; D20200S0D60X001.BIN
    BIOS Checksum : 3FA5 ; 671E
    Release Date  : 2022/07/01

    Owner         : tony3.cheng
    Requester     : Advantech
    Customer      : Advantech
###  Release Description
    DS202_SBL_X001_01   Bring up.
    DS202_SBL_X001_02   Set PcdFixedDebugPrintErrorLevel to 0x00 during RELEASE mode
    DS202_SBL_X001_03   Add DEBUG_VERBOSE of PcdDebugPrintErrorLevel during DEBUG mode
    DS202_SBL_X001_04   Add HDA verbtable and program PCH HDA SVID/SSID
    DS202_SBL_X001_05   Modify PCH GPIO setting
    DS202_SBL_X001_06   Modfiy Display DDI config 
    DS202_SBL_X001_07   Modify USB overcurrent setting
    DS202_SBL_X001_08   Set GNA, eMMC and SdCard controller to disabled.
    DS202_SBL_X001_09   Support dTPM
###  Release BIOS Information
    - Core        : Slim Boot Loader
                    REPO    = https://github.com/slimbootloader/slimbootloader.git
                    COMMIT  = 8ecaa21054d04245b6b95c42179060590a180422
    - FSP Version : Elkhart Lake MR3 FSP
                    REPO    = https://github.com/intel/FSP.git
                    COMMIT  = 72266f6523286fb3494f5b2553ace612d1dc95c4
    - CSME F/W    : 15.40.15.2416
    - PMC F/W     : EHL_B0_PMC_FW_154.01.10.1024_prod
    - PCHC F/W    : EHL_PCHC_15.40.0.1001_prod
    - ChipsetInit : MCCChipsetInitB0V10
    - uCode       : M0190661_00000015
    - GOP Driver  : 18.0.1040
    D20200S0060X001.BIN --- SlimBootLoader with release mode.
    D20200S0D60X001.BIN --- SlimBootLoader with debug mode.
    +--+-+++++----+
       | ||||||   +-----------  BIOS Version as before.
       | |||||+---------------  Reserved.       : Reserved.
       | ||||+----------------  BIOS Build mode : 6 = 64 bit; 3 = 32 bit.
       | |||+-----------------  Debug mode      : D = Debug Mode Enabled; 0 = Debug Mode Disabled.
       | ||+------------------  Chipset sku type: 0 = EHL; Others are reserved.
       | |+-------------------  SlimBootLoader  : S = SBL supported; 0 = not supported.
       | +--------------------  Project name extension define by PD.
       +----------------------  Project name define by PD.
