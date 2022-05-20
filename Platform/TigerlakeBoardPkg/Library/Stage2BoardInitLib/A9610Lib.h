//**********************************************************************
//
// Name:  <A9610Setup.H>
//
// Description: GUID or structure Of Setup related Routines.
//
//**********************************************************************

#ifndef _A9610_LIB_H_
#define _A9610_LIB_H_

//#ifdef __cplusplus
//extern "C" {
//#endif

#define	  Obf		                0x01
#define   Ibf		                0x02

// PMC Command Byte List
#define	  A9610_CMD_READ_TEMPERATURE  		0x11
#define	  A9610_CMD_WRITE_TEMPERATURE 		0x10

#define	  A9610_CMD_READ_VOLTAGE      		0x13
#define	  A9610_CMD_WRITE_VOLTAGE     		0x12

#define	  A9610_CMD_READ_TACHOMETER   		0x17
#define	  A9610_CMD_WRITE_TACHOMETER  		0x16

#define	  A9610_CMD_READ_CURRENT	  	0x1B
#define	  A9610_CMD_WRITE_CURRENT	  	0x1A

#define	  A9610_CMD_READ_PANEL        		0x21
#define	  A9610_CMD_WRITE_PANEL       		0x20

#define	  A9610_CMD_READ_FAN  		        0x25
#define	  A9610_CMD_WRITE_FAN		        0x24

#define	  A9610_CMD_READ_CASEOPEN      		0x29
#define	  A9610_CMD_WRITE_CASEOPEN     		0x28

#define	  A9610_CMD_READ_WATCHDOG      		0x2B
#define	  A9610_CMD_WRITE_WATCHDOG     		0x2A

#define	  A9610_CMD_READ_BOARD_INFO   		0x53
#define	  A9610_CMD_WRITE_BOARD_INFO  		0x52

#define	  A9610_CMD_READ_SYSTEM       		0x55
#define	  A9610_CMD_WRITE_SYSTEM      		0x54

#define	  A9610_CMD_READ_CONFIGURATION 		0x71
#define	  A9610_CMD_WRITE_CONFIGURATION		0x70

// PMC Control Byte List
#define	  A9610_CTRL_TEMPERATURE_MODULE_STATUS	0x00
#define	  A9610_CTRL_TEMPERATURE_TYPE		0x01
#define	  A9610_CTRL_TEMPERATURE_VALUE		0x10
#define	  A9610_CTRL_TEMPERATURE_MAX_VALUE	0x11
#define	  A9610_CTRL_TEMPERATURE_MIN_VALUE	0x12

#define	  A9610_CTRL_VOLTAGE_MODULE_STATUS	0x00
#define	  A9610_CTRL_VOLTAGE_TYPE		0x01
#define	  A9610_CTRL_VOLTAGE_VALUE		0x10

#define	  A9610_CTRL_TACHOMETER_MODULE_STATUS	0x00
#define	  A9610_CTRL_TACHOMETER_TYPE		0x01
#define	  A9610_CTRL_TACHOMETER_CONTROL		0x02
#define	  A9610_CTRL_TACHOMETER_VALUE		0x10

#define	  A9610_CTRL_CURRENT_MODULE_STATUS	0x00
#define	  A9610_CTRL_CURRENT_TYPE		0x01
#define	  A9610_CTRL_CURRENT_VALUE		0x10

#define	  A9610_CTRL_PANEL_MODULE_STATUS	0x00
#define	  A9610_CTRL_LVDS_BACKLIGHT_STATUS	0x10
#define	  A9610_CTRL_LVDS_RESET_CONTROL		0x11
#define	  A9610_CTRL_BACKLIGHT_SWITCH		0x12
#define	  A9610_CTRL_BACKLIGHT_SWITCH_POLARITY	0x13
#define	  A9610_CTRL_PWM_DUTY_CYCLE		0x14
#define	  A9610_CTRL_PWM_POLARITY		0x15
#define	  A9610_CTRL_PWM_FREQUENCY		0x16
#define	  A9610_CTRL_BACKLIGHT_DELAY_ON		0x17
#define	  A9610_CTRL_BACKLIGHT_DELAY_OFF	0x18
#define	  A9610_CTRL_BACKLIGHT_CONTROL_MODE	0x19

#define	  A9610_CTRL_CASEOPEN_MODULE_STATUS	0x00
#define	  A9610_CTRL_CASEOPEN_CONTROL		0x02
#define	  A9610_CTRL_CASEOPEN_SPARE		0x10

#define	  A9610_CTRL_WATCHDOG_MODULE_STATUS	0x00
#define	  A9610_CTRL_WATCHDOG_CONTROL		0x02
#define	  A9610_CTRL_WATCHDOG_EVENT_STATUS	0x10
#define	  A9610_CTRL_WATCHDOG_DELAY_TIME	0x11
#define	  A9610_CTRL_WATCHDOG_PWBTN_EVENT_TIME	0x12
#define	  A9610_CTRL_WATCHDOG_IRQ_NMI_EVENT_TIME	0x13
#define	  A9610_CTRL_WATCHDOG_RESET_EVENT_TIME	0x14
#define	  A9610_CTRL_WATCHDOG_PIN_EVENT_TIME	0x15
#define	  A9610_CTRL_WATCHDOG_SCI_EVENT_TIME	0x16
#define	  A9610_CTRL_WATCHDOG_IRQ_NUMBER	0x17

#define	  A9610_CTRL_BOARD_INFO_MODULE_STATUS	0x00
#define	  A9610_CTRL_BOARD_INFO_PASSWORD	0x03
#define	  A9610_CTRL_BOARD_INFO_ACCESS		0x04
#define	  A9610_CTRL_BOARD_NAME			0x10

#define	  A9610_CTRL_MANUFACTURER_NAME		0x11
#define	  A9610_CTRL_CHIP_NAME			0x12
#define	  A9610_CTRL_PLATFORM_TYPE		0x13
#define	  A9610_CTRL_PLATFORM_VERSION		0x14

#define	  A9610_CTRL_BOARD_ID			0x1E
#define	  A9610_CTRL_BOARD_SERIAL_NUMBER	0x1F

#define	  A9610_CTRL_FIRMWARE_TYPE		0x20
#define	  A9610_CTRL_FIRMWARE_VERSION_NUMBER	0x21
#define	  A9610_CTRL_FIRMWARE_VERSION_STRING	0x22
#define	  A9610_CTRL_FIRMWARE_BUILD_TIME	0x23

#define	  A9610_CTRL_SYSTEM_MODULE_STATUS	0x00
#define	  A9610_CTRL_SYSTEM_BOOT_COUNT		0x10
#define	  A9610_CTRL_POWER_ON_HOURS		0x11
#define	  A9610_CTRL_BIOS_POST_DONE		0x12
#define	  A9610_CTRL_NOTIFY_EC_ACPI_MODE	0x13
#define	  A9610_CTRL_DEEP_SLEEP_CONTROL		0x14
#define	  A9610_CTRL_AT_ATX_MODE_SELECT		0x15
#define	  A9610_CTRL_LAN_ENABLE_CONTROL		0x16
#define	  A9610_CTRL_COM_MODE_SELECT		0x17
#define	  A9610_CTRL_COM_PORT_EN_CONTROL	0x18
#define	  A9610_CTRL_COM_RI_STATUS		0x19

#define	  A9610_CTRL_WAKE_ON_RING_CONTROL	0x1A

#define	  A9610_CTRL_PCIE_BIFURCATION_CONTROL	0x1B

#define	  A9610_CTRL_CONFIGURATION_MODULE_STATUS	0x00
#define	  A9610_CTRL_CONFIGURATION_PASSWORD	0x03
#define	  A9610_CTRL_UART_TYPE			0x10
#define	  A9610_CTRL_GPIO_AVAILABLE		0x20
#define	  A9610_CTRL_GPIO_DIRECTION		0x21
#define	  A9610_CTRL_GPIO_DATA			0x22
#define	  A9610_CTRL_CONFIGURATION_SAVE		0x30
#define	  A9610_CTRL_CONFIGURATION_EC		0x31

// PMC Device Byte List
#define	  A9610_DEVICE_NONE			0x00
#define	  A9610_DEVICE_1			0x00
#define	  A9610_DEVICE_2			0x01

#define	  A9610_WATCHDOG_STOP			0x00
#define	  A9610_WATCHDOG_START			0x01
#define	  A9610_WATCHDOG_CLEAR			0x02

// Platform information register
#define FIRMWARE_VERSION                0x00
#define PLATFORM_PROJECT_ID             0x04
#define PLATFORM_PROJECT_TYPE           0x05
#define PLATFORM_NAME_LEN               0x06
#define PLATFORM_NAME                   0x07

// Thermal Control Registers
#define THERMAL_DEVICE_STATUS           0x00	//Thermal Control Status Register
#define THERMAL_TYPE                    0x01	//Temperature Type Register
#define THERMAL_VALUE                   0x02	//Temperature Value Register
#define THERMAL_MAX_VALUE               0x04	//Maximum Temperature Value Register
#define THERMAL_MIN_VALUE               0x06	//Minimum Temperature Value Register

// Voltage Registers
#define VOLTAGE_DEVICE_STATUS           0x00	//Voltage Status Register
#define VOLTAGE_TYPE                    0x01	//Voltage Type Register
#define VOLTAGE_VALUE                   0x02	//Voltage Value Register
#define VOLTAGE_RATED_VALUE             0x04	//Rated VoltageValue Register
#define VOLTAGE_MAX_VALUE               0x06	//Voltage Maximum Value Register
#define VOLTAGE_MIN_VALUE               0x08	//Voltage Minimum Value Register

// PWM Controller Registers
#define PWM_DEVICE_STATUS           	0x00	//PWM Status Register
#define PWM_DUTY_CYCLE                  0x01	//PWM Duty Cycle Register
#define PWM_FREQ		        0x02	//PWM Frequency Register

// Tachometer Controller Registers
#define TACHOMETER_DEVICE_STATUS        0x00	//Tachometer Status Register
#define TACHOMETER_CONTROL              0x01	//Tachometer Control Register
#define TACHOMETER_RPM                  0x02	//Tachometer RPM Register
#define TACHOMETER_TYPE		        0x04	//Tachometer Type Register

// Backlight Controller Registers
#define BACKLIGHT_DEVICE_STATUS         0x00	//Backlight Status Register
#define BACKLIGHT_CONTROL               0x01	//Backlight Control Register
#define BACKLIGHT_DELAY_ON              0x02	//Backlight Delay ON Register
#define BACKLIGHT_DELAY_OFF             0x03	//Backlight Delay OFF Register
#define BACKLIGHT_PWM_DUTY              0x04	//Backlight PWM Duty Register
#define BACKLIGHT_PWM_FREQ	        0x05	//Backlight PWM Frequency Register

// Thermal Protection Registers
#define THERPROT_STATUS         	0x40 //shutdown thermal protection status
#define THERPROT_HIGH         	    0x41 //high temperautre of thermal protection
#define THERPROT_HIGH_2             0x49 //default configuration of high temperautre of shutdown thermal protection
#define THERPROT_HIGH_DEFCFG        0x48 //default configuration of shutdown thermal protection

// Fan Controller Registers
#define   FAN_MODULE_STATUS                 0x00
#define   FAN_TYPE                          0x01
#define   FAN_CONTROL                       0x02
#define   FAN_PWM_DUTY                      0x10
#define   FAN_PWM_POLARITY                  0x11
#define   FAN_PWM_FREQ                      0x12
#define   FAN_TEMP_HIGH_LIMIT               0x13
#define   FAN_TEMP_LOW_LIMIT                0x14
#define   FAN_TEMP_STOP_FAN                 0x15
#define   FAN_PWM_MAX_DUTY                  0x16
#define   FAN_PWM_MIN_DUTY                  0x17
#define   FAN_RPM_MAX_SPEED                 0x18
#define   FAN_RPM_MIN_SPEED                 0x19
#define   FAN_RPM_CURRENT_SPEED             0x1A

#define DEEP_SLEEP_CONTROL              0x00	//Deep Sleep Control register

typedef struct
{
	UINT8		CommandByte;                    //Command Byte
	UINT8		ControlByte;                    //Control Byte
	UINT8		DeviceByte;                     //Device Byte
	UINT8		PayloadSizeByte;                //Payload Size Byte
	UINT16		Token;                          //String Token
	UINT8		Flag;                           //Value Type Flag
}A9610_HM_COMM;

#define TEMPERATURE_FLAG                0x01    //Temperature Monitoring Display Flag
#define VOLTAGE_FLAG                    0x02    //Voltage Monitoring Display Flag
#define TACHOMETER_FLAG                 0x04    //Tachometer Monitoring Display Flag
#define CURRENT_FLAG                 	0x10    //iCurrent Monitoring Display Flag

//-------------------------------------------------------------------------
// Include Files
//-------------------------------------------------------------------------

EFI_STATUS
EcIbFree ();

EFI_STATUS
EcObFull ();

EFI_STATUS
CheckEcObf ();

EFI_STATUS
EcPmcWriteCmd (UINT8	cmd);

EFI_STATUS
EcPmcWriteData (UINT8	data);

EFI_STATUS
EcPmcReadData (UINT8 *pData);

EFI_STATUS
EcPmcWrite_Protocol (UINT8 CommandByte, UINT8 ControlByte, UINT8 DeviceByte, UINT8 PayloadSizeByte, UINT8 *PayloadByte);

EFI_STATUS
EcPmcRead_Protocol (UINT8 CommandByte, UINT8 ControlByte, UINT8 DeviceByte, UINT8 PayloadSizeByte, UINT8 *PayloadByte);

/****** DO NOT WRITE BELOW THIS LINE *******/
//#ifdef __cplusplus
//}
//#endif
#define A9610_PMC_CMD_PORT	0x66
#define A9610_PMC_DATA_PORT	0x62
#define A9610_PMC1_CMD_PORT	0x2f6
#define A9610_PMC1_DATA_PORT	0x2f2 

EFI_STATUS
A9610Read_FW_Version (
	OUT UINT8 *MajorVersion,
	OUT UINT8 *MinorVersion
);

#endif

//*************************************************************************
//*************************************************************************


