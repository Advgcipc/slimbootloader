/*++

Copyright (C) 2009-2021 Intel Corporation

SPDX-License-Identifier: BSD-2-Clause

File Name:
    errorlist.c

Abstract:
    List of all error codes, categories and error strings.

--*/

#include "errorlist.h"

#define MAX_STRING_DESCRIPTION                  500

// Added in order to resolve analiser error
// Currently library clean of any dependency, don't want to add any
#ifndef ARRAY_SIZE
# define ARRAY_SIZE(array) (sizeof((array))/sizeof((array)[0]))
#endif /* ARRAY_SIZE */

typedef struct _STRING_CATEGORY
{
    unsigned char        Id;
    char                 Description[MAX_STRING_DESCRIPTION];
}STRING_CATEGORY;

typedef struct _STRING_DATA
{
    unsigned int         Id;
    STRING_CATEGORY      Category;
    char                 Description[MAX_STRING_DESCRIPTION];
}STRING_DATA;


STRING_CATEGORY gCategoriesList[] =
{
    {CATEGORY_SUCCESS,                         ""},
    {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
    {CATEGORY_WARNING,                         "Passed with warnings."},
    {CATEGORY_UNSUPPORTED_OS,                  "The tool was executed on an unsupported OS."},
    {CATEGORY_UNSUPPORTED_HW,                  "Tool isn't compatible with current HW or current HW environment isn't supported."},
    {CATEGORY_MEMORY_ALLOCATION,               "Memory allocation error."},
    {CATEGORY_SYSTEM_API_CALL_ERROR,           "System API returned unexpected error code."},
    {CATEGORY_SYSTEM_API_NOT_FOUND,            "System library or API does not exist."},
    {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
    {CATEGORY_PERIPHERALS_VALIDATION_FAILURE,  "Failed to validate tool peripherals files (file does not exist, file signature validation failed)."},
    {CATEGORY_ME_COMMUNICATION_FAILURE,        "Failed to communicate with "  MAKE_STR(ME_STR)  " device or invalid "  MAKE_STR(ME_STR)  " HW response."},
    {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
    {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
    {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
    {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
    {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
    {CATEGORY_CSE_FILE_COMPARE_GENERAL_ERROR,  "CSE File compare error."},
    {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
    {CATEGORY_OS_DEVICE_COMMUNICATION_FAILURE, "OS device not found or failed to perform program request."},
    {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
    {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
    {CATEGORY_SMBUS_ACCESS_ERROR,              "Unable to access SMBUS device with read/write error."},
    {CATEGORY_SMBIOS_ACCESS_ERROR,             "Unable to access SMBIOS device with read/write error."},
    {CATEGORY_TOOL_INITIALIZATION_ERROR,       "Failed to initialize the tool."},
    {CATEGORY_XML_USER_FILE_ERROR,             "Error in parsing user XML file."},
    {CATEGORY_KEYBOX_INVALID_RESPONSE,         "Keybox response header values are not as expected."},
    {CATEGORY_KEYBOX_INVALID_STATUS,           "Invalid Keybox response status."},
    {CATEGORY_MEMANUF_TEST_RUN_ERROR,          MAKE_STR(ME_STR) "Manuf test failed to run."},
    {CATEGORY_MEMANUF_TEST_RESULT_READ_ERROR,  "Cannot read " MAKE_STR(ME_STR) "Manuf test result."},
    {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
    {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
    {CATEGORY_MEMANUF_OPERATION_FAILED,        MAKE_STR(ME_STR) "Manuf operation failed."},
    {CATEGORY_MEINFO_FEATURE_NOT_FOUND,        "Cannot find " MAKE_STR(ME_STR) "Info feature or feature is not supported."},
    {CATEGORY_MEINFO_FEATURE_COMPARE_ERROR,    MAKE_STR(ME_STR) "Info feature not equals to user value."},
    {CATEGORY_MEINFO_FEATURE_EXECUTION_ERROR,  MAKE_STR(ME_STR) "Info failed to execute specific feature."},
    {CATEGORY_FPT_INVALID_SPI_CONF,            "Invalid FPT SPI devices configuration file."},
    {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
    {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
    {CATEGORY_FWU_RESTORE_POINT_ERROR,         "FWU Restore Point Image Failure."},
    {CATEGORY_INVALID_PARTITION,               "Partition does not exist in the flash image."},
    {CATEGORY_FWU_OPERATION_FAILED,            "FWU tool failed to execute the requested command."},
    {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
    {CATEGORY_GENERAL_ERROR,                   MAKE_STR(FW_STR) " or general environment error."},
    {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
    {CATEGORY_SOFTSTRAP_INVALID_INPUT_VALUE,   "Invalid update value provided for SoftStrap update."},
    {CATEGORY_SOFTSTRAP_UPDATE_ERROR,          "SoftStrap write or update error."},
    {CATEGORY_FWU_RECOVERY_IMAGE_ERROR,        "FWU Recovery Image Failure."},
    {ERROR_CATEGORIES_COUNT,                   ""},
};


STRING_DATA gErrorList[] =
{
    {/* Line-Tools do not print this string */
        SUCCESS,
        {CATEGORY_SUCCESS, ""},
        "Success."
    },
    {
        TOOL_COMMON_ERROR,
        {CATEGORY_GENERAL_ERROR, MAKE_STR(FW_STR) " or general environment error."},
        ""
    },
    {/* Passed With Warning ErrorLevel */
        PASSED_WITH_WARNING,
        {CATEGORY_WARNING,                         "Passed with warnings."},
        ""
    },
    {
        INTERNAL_ERROR,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal Error. Unexpected error occurred."
    },
    {
        ERROR_UNSUPPORTED_OS,
        {CATEGORY_UNSUPPORTED_OS,                  "The tool was executed on an unsupported OS."},
        "Unsupported OS."
    },
    {
        ERROR_MEMORY_ALLOC,
        {CATEGORY_MEMORY_ALLOCATION,               "Memory allocation error."},
        "Memory allocation error occurred."
    },
    {
        SM_BIOS_ERROR_PROCADDR,
        {CATEGORY_SMBIOS_ACCESS_ERROR,             "Unable to access SMBIOS device with read/write error."},
        "Error accessing the function \"GetSystemFirmwareTable\" from \"kernel32.dll\"."
    },
    {
        SM_BIOS_ERROR_GENERAL,
        {CATEGORY_SMBIOS_ACCESS_ERROR,             "Unable to access SMBIOS device with read/write error."},
        "The function \"GetSystemFirmwareTable\" failed with Windows Error Code: %d."
    },
    {
        SM_BIOS_ERROR_PERMISSION,
        {CATEGORY_SMBIOS_ACCESS_ERROR,             "Unable to access SMBIOS device with read/write error."},
        "Error accessing the \"kernel32.dll\"."
    },
    {
        COMMIT_SVN_FAILED,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "Commit Anti Rollback SVN failed."
    },
    {
        FILE_READ_ERROR,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "Error occurred while reading the file."
    },
    {
        FILEIO_ERROR_GETTING_CWD,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "Error getting current working directory path."
    },
    {
        FILEIO_ERROR_GETTING_CWD_PERMISSIONS,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "Error getting current working directory permission:"
    },
    {
        FILEIO_ERROR_OPEN_FILE,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "An unknown error occurred while opening the file."
    },
    {
        FILEIO_ERROR_SEEK,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "An unknown error occurred while working with the file."
    },
    {
        FILEIO_ERROR_WRITE,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "Error occurred while writing to the file."
    },
    {
        SERVICE_EXISTS,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Service already exists."
    },
    {
        ITOUCH_STOPPING_DRIVER_FAILED,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Failed to stop iTouch driver."
    },
    {
        FILEIO_ERROR_INVALID_ARGUMENT,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "Invalid file name or path provided."
    },
    {
        FAILED_TO_WRITE_TO_IO_PORT,
        {CATEGORY_OS_DEVICE_COMMUNICATION_FAILURE, "OS device not found or failed to perform program request."},
        "Failed to write 0x%02X to IO Port 0x%04X."
    },
    {
        HECI_STATUS_LOCATE_DEVICE_ERROR,
        {CATEGORY_ME_COMMUNICATION_FAILURE,        "Failed to communicate with "  MAKE_STR(ME_STR)  " device or invalid "  MAKE_STR(ME_STR)  " HW response."},
        "Cannot locate " MAKE_STR(ME_STR) " device."
    },
    {
        HECI_STATUS_WRITE_REGISTER_ERROR,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Write register failure."
    },
    {
        HECI_STATUS_BUFFER_OVEREFLOW_ERROR,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Circular buffer overflow."
    },
    {
        HECI_STATUS_MSG_TRANSMISSION_ERROR,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Communication error between application and Intel(R) " MAKE_STR(ME_STR) " module."
    },
    {
        HECI_STATUS_VERSION_MISMATCH,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Unsupported HECI bus message protocol version."
    },
    {
        HECI_STATUS_TIMEOUT_ERROR,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "HECI Timeout."
    },
    {
        HECI_STATUS_UNEXPECTED_RESPONSE,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Unexpected result in command response."
    },
    {
        HECI_STATUS_CANNOT_FOUND_HOST_CLIENT,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Cannot find host client."
    },
    {
        HECI_STATUS_CANNOT_FOUND_ME_CLIENT,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Cannot find " MAKE_STR(ME_STR) " client."
    },
    {
        HECI_STATUS_CANNOT_DISCONNECT,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Failure occurred during " MAKE_STR(ME_STR) " disconnect."
    },
    {
        HECI_STATUS_CLIENT_ALREADY_CONNECTED,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Client already connected."
    },
    {
        HECI_STATUS_NO_FREE_CONNECTION,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "No free connection available."
    },
    {
        HECI_STATUS_FLOW_CONTROL_ERROR,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Flow control error."
    },
    {
        HECI_STATUS_NO_MESSAGE,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "No message."
    },
    {
        HECI_STATUS_BUFFER_TOO_LARGE,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Buffer size is too large."
    },
    {
        HECI_STATUS_BUFFER_TOO_SMALL,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Buffer is too small."
    },
    {
        CERTIFICATE_NAME_TOO_LONG,
        {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
        "%s is too long."
    },
    {
        CLI_ERROR_INVALID_COMMAND_ARGUMENT,
        {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
        "Invalid command line option(s)."
    },
    {
        CLI_ERROR_INVALID_OPTION,
        {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
        "The following Parameter is not a valid option: %s."
    },
    {
        LPC_DID_ERROR_PCH_NOT_SUPPORTED,
        {CATEGORY_UNSUPPORTED_HW,                  "Tool isn't compatible with current HW or current HW environment isn't supported."},
        MAKE_STR(PCH_STR) " is not supported."
    },
    {
        SAFE_FUNC_ERROR_INVALID_SIZE,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal Error (Safe function wrapper error: Invalid size)."
    },
    {
        SAFE_FUNC_ERROR_COMPOSE_STR_FROM_LIST,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal Error (Safe function wrapper error: compose string from list)."
    },
    {
        SAFE_FUNC_ERROR_COMPOSE_STR,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal Error (Safe function wrapper error: compose string)."
    },
    {
        SAFE_FUNC_ERROR_MEMNCPY,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal Error (Safe function wrapper error: memncpy)."
    },
    {
        SAFE_FUNC_ERROR_STRNCPY,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal Error (Safe function wrapper error: strncpy)."
    },
    {
        SAFE_FUNC_ERROR_STRNCAT,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal Error (Safe function wrapper error: strncat)."
    },
    {
        SAFE_FUNC_ERROR_TOKEN_STR,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal Error (Safe function wrapper error: strtok)."
    },
    {
        DISPLAY_ERROR_PRINTF,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Printf function failed."
    },
    {
        NVAR_SUPPORT_FAILED_VAR,
        {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
        "Failed getting variable \"%s\" value."
    },
    {
        NVAR_SKU_DEP_SUPPORT_FAILED_VAR,
        {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
        "The variable \"%s\" is supported on Corporate SKU only."
    },
    {
        PLAT_INFO_NO_MATCHED_LOCL,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Unable to find matching LOCL."
    },
    {
        CANNOT_ACCESS_PCI,
        {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
        "Could not access PCI device."
    },
    {
        MEMANUF_ERROR_EOL_RPMB_NOT_SUPPORTED,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Replay protection of UFS device not supported "
    },
    {
        OS_STATUS_NOT_PERMITTED,
        {CATEGORY_SYSTEM_API_CALL_ERROR,           "System API returned unexpected error code."},
        "Unable to change permission."
    },
    {
        OS_STATUS_PERMISSION_FAILURE,
        {CATEGORY_SYSTEM_API_CALL_ERROR,           "System API returned unexpected error code."},
        "Unable to perform request due to permission failure."
    },
    {
        DEVICE_NOT_FOUND,
        {CATEGORY_OS_DEVICE_COMMUNICATION_FAILURE, "OS device not found or failed to perform program request."},
        "Cannot find requested device."
    },
    {
        OS_STATUS_INTEGRITY_CHECK_FAILED,
        {CATEGORY_OS_DEVICE_COMMUNICATION_FAILURE, "OS device not found or failed to perform program request."},
        "Unable to perform CreateFile."
    },
    {
        FPF_COMPARE_FAILURE,
        {CATEGORY_CSE_FILE_COMPARE_GENERAL_ERROR,  "CSE File compare error."},
        "The FPF compare failed."
    },
    {
        INVALID_CSE_FILE_NAME,
        {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
        "The " MAKE_STR(CSE_STR) " File Component requested, File Name is not valid for this operation."
    },
    {
        ERROR_BG_MUST_BE_ENABLED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Boot Guard must be enabled with Policy 5."
    },
    {
        FPT_INVALID_CONFIG_FORMAT,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Failed to read FPT NVARs config file."
    },
    {
        FW_REGISTER_READ_ERROR,
        {CATEGORY_ME_COMMUNICATION_FAILURE,        "Failed to communicate with "  MAKE_STR(ME_STR)  " device or invalid "  MAKE_STR(ME_STR)  " HW response."},
        "Fail to read " MAKE_STR(FW_STR) " Status Register value."},
    {
        TOOL_ERROR_CREATE_LOG_FILE,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "Fail to create verbose log file."
    },
    {
        ERROR_UNKNOWN_UNSUPPORTED_HW,
        {CATEGORY_UNSUPPORTED_HW,                  "Tool isn't compatible with current HW or current HW environment isn't supported."},
        "Unknown or unsupported hardware platform."
    },
    {
        FAILED_TO_INIT_SPI,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Failed to initialize SPI interface."
    },
    {
        FPT_VAR_UPDATE_FAILED,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Could not update [%s]."
    },
    {
        CANNOT_UPDATE_FPT_VAR,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Cannot update %s. Invalid data length."
    },
    {
        MEINFO_ERROR_PARAM_NOT_FOUND,
        {CATEGORY_MEINFO_FEATURE_NOT_FOUND,        "Cannot find " MAKE_STR(ME_STR) "Info feature or feature is not supported."},
        "Feature not found."
    },
    {
        MEINFO_ERROR_PARAM_INVALID,
        {CATEGORY_MEINFO_FEATURE_NOT_FOUND,        "Cannot find " MAKE_STR(ME_STR) "Info feature or feature is not supported."},
        "Feature not available."
    },
    {
        MEINFO_ERROR_PARAM_NOT_EQUAL,                                   {CATEGORY_MEINFO_FEATURE_COMPARE_ERROR,    MAKE_STR(ME_STR) "Info feature not equals to user value."},       "%s actual value is - %s."},
    {
        ERROR_FW_STATUS_FAILURE,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        MAKE_STR(FW_STR) " status test failed."
    },
    {
        ERROR_BG_FW_STATUS_FAILURE,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Boot Guard status test failed."
    },
    {
        FPT_CERT_INVALID_FILE,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Parameter \"%s\" - %s."
    },
    {
        FPT_CERT_UPDATE_MISSING_COMPONENTS,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "The value of \'%s\' is missing."
    },
    {
        ERROR_TOOL_INIT,
        {CATEGORY_TOOL_INITIALIZATION_ERROR,       "Failed to initialize the tool."},
        "Failed to communicate with " MAKE_STR(CSME_STR_UC) "\nThis tool must be run from a privileged account(administrator / root)."
    },
    {
        FPT_MASTER_ACCESS_VALUE_INVALID,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Master Access config file value for \"%s\" format is invalid."
    },
    {
        MEINFO_ERROR_PARAM_RETRIEVE,
        {CATEGORY_MEINFO_FEATURE_NOT_FOUND,        "Cannot find " MAKE_STR(ME_STR) "Info feature or feature is not supported."},
        "Failed to retrieve feature."
    },
    {
        FPT_MASTER_ACCESS_VALUE_EXCEED,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Master Access config file value for \"%s\" exceed maximum allowed value."
    },
    {
        MEINFO_ERROR_FIT_VER,
        {CATEGORY_MEINFO_FEATURE_EXECUTION_ERROR,  MAKE_STR(ME_STR) "Info failed to execute specific feature."},
        "Failed to retrieve Intel (R) FIT version."
    },
    {
        MEINFO_ERROR_INT_VER,
        {CATEGORY_MEINFO_FEATURE_EXECUTION_ERROR,  MAKE_STR(ME_STR) "Info failed to execute specific feature."},
        "Failed to retrieve Intel (R) Internal Build Version."
    },
    {
        FPT_MASTER_DUPLICATE_REGION,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Ambiguous Master Access value. Master Access config file region \"%s\"\ndefined more than once."
    },
    {
        MEMANUF_ERROR_OPT_FAILED,
        {CATEGORY_MEMANUF_OPERATION_FAILED,        MAKE_STR(ME_STR) "Manuf operation failed."},
        MAKE_STR(ME_STR) "Manuf Operation Failed."
    },
    {
        FPT_MASTER_ACCESS_INVALID_ACCESS_NODE,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Invalid Access node name in Master Access configuration file."
    },
    {
        FPT_MASTER_ACCESS_INVALID_REQUIRED_NODE,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Invalid RequiredValue node name in Master Access configuration file."
    },
    {
        NVAR_MCA_WRONG_SERVER_ADDRESS,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Invalid server address."
    },
    {
        MEMANUF_ERROR_BIST_NOTSTARTED,
        {CATEGORY_MEMANUF_TEST_RUN_ERROR,          MAKE_STR(ME_STR) "Manuf test failed to run."},
        "Intel(R) test failed to start, error 0x%X returned."
    },
    {
        MEMANUF_ERROR_BIST_NOTFINISHED,
        {CATEGORY_MEMANUF_TEST_RUN_ERROR,          MAKE_STR(ME_STR) "Manuf test failed to run."},
        "Intel(R) test timeout (exceeded 30 seconds)."
    },
    {
        MEMANUF_ERROR_BIST_RUNNING_RETRY,
        {CATEGORY_MEMANUF_TEST_RUN_ERROR,          MAKE_STR(ME_STR) "Manuf test failed to run."},
        "Intel(R) " MAKE_STR(ME_STR) " test is currently running, try again later."
    },
    {
        MEMANUF_ERROR_CFGGEN,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "MEManuf EOL & BIST config file generation failed."
    },
    {
        MEMANUF_ERROR_NOM3BIST_ON_FLASH,
        {CATEGORY_MEMANUF_TEST_RESULT_READ_ERROR,  "Cannot read " MAKE_STR(ME_STR) "Manuf test result."},
        "M3 results are not available from SPI. Please run -test option to perform the BIST test."
    },
    {
        MEMANUF_ERROR_M3_BIST_CONFIGURATION,
        {CATEGORY_MEMANUF_TEST_RESULT_READ_ERROR,  "Cannot read " MAKE_STR(ME_STR) "Manuf test result."},
        "Could not read M3 results from SPI."
    },
    {
        ERROR_SMBUS_READ_BYTE_STATUS_NOT_READY,
        {CATEGORY_SMBUS_ACCESS_ERROR,              "Unable to access SMBUS device with read/write error."},
        "SMBus hardware is not ready."
    },
    {
        ERROR_SMBUS_READ_BYTE_STATUS_FAILURE,
        {CATEGORY_SMBUS_ACCESS_ERROR,              "Unable to access SMBUS device with read/write error."},
        "Internal error - SMBus Read Byte PEC failure."
    },
    {
        ERROR_SMBUS_READ_BYTE_STATUS_TIMED_OUT,
        {CATEGORY_SMBUS_ACCESS_ERROR,              "Unable to access SMBUS device with read/write error."},
        "SMBus encountered time-out."
    },
    {
        SPI_SIGN_INVALID,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "    Signature: invalid! No more information can be displayed."
    },
    {
        ERROR_M3_LIVE_HEAP_TEST_DO_NOT_MATCH,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal error - Failed to match."
    },
    {
        ERROR_M3_LIVE_HEAP_TEST_OUT_OF_MEMORY,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal error - Out of memory."
    },
    {
        M3_LIVE_HEAP_TEST_FAILED_GET_POWER_PACKAGE,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal error - Unable to get current PP."
    },
    {
        WLAN_POWER_WELL_FAILED_GET_TEST_RESULT,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Failed to retrieve test result from SPI."
    },
    {
        ERROR_WLAN_POWER_WELL_FAILED_GET_PACKAGE,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Failed to retrieve power package setting."
    },
    {
        ERROR_WLAN_POWER_WELL_TEST_FAILED_GET_RULE,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Failed to retrieve power rule from SPI."
    },
    {
        ERROR_WLAN_POWER_WELL_TEST_CFG_INCORRECT,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "WLAN power well setting is set incorrectly."
    },
    {
        ERROR_CPU_MISSING_TEST_FAILED_GET_RESULT,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Failed to retrieve test result from SPI."
    },
    {
        ERROR_CPU_MISSING_TEST_FAILED_GET_PLAT_ATTR,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Internal error - Failed to retrieve Platform Attribute."
    },
    {
        ERROR_CPU_MISSING_TEST_GET_LOGIC_RULE,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Failed to retrieve PROC_MISSING NVAR setting."
    },
    {
        ERROR_CPU_MISSING_TEST_LOGIC_INCORRECT,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "PROC_MISSING NVAR setting is set incorrectly."
    },
    {
        ERROR_GET_PASSWORD_FAILED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Failed to retrieve password from SPI."
    },
    {
        ERROR_PASSWORD_LENGTH_IS_INCORRECT,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Internal error - Password length is incorrect."
    },
    {
        ERROR_CALL_IsLocalPwdModified_FAILED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Internal error - Modified local password."
    },
    {
        ERROR_PASSWORD_INVALID,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Internal error - Invalid password."
    },
    {
        ERROR_SB_SELF_TEST_FAILED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Boot Guard Self Test Failed."
    },
    {
        ERROR_LAN_HW_NOT_READY,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Intel integrated LAN setting is set incorrectly."
    },
    {
        ERROR_LAN_NIC_FAILURE,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Intel LAN Connected Device (PHY) physical connectivity error with ME."
    },
    {
        ERROR_ILLEGAL_LENGTH,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Internal error - Illegal data length."
    },
    {
        ERROR_ILLEGAL_VALUE,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Internal error - Illegal data value."
    },
    {
        ERROR_EHBC_STATE_FLASH_READ_ERROR,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "EHBC State Test Failed - Error while reading data from flash."
    },
    {
        ERROR_EHBC_STATE_PRIV_LEVEL_MISMATCH,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "EHBC State Test Failed - Contradiction with current Privacy Level."
    },
    {
        ERROR_WLAN_CODE_INVALID,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Current WLAN does not match micro-code, please update WLAN micro-code in " MAKE_STR(FW_STR) "."
    },
    {
        ERROR_WLAN_NIC_FAILURE,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Communication with WLAN device failed."
    },
    {
        ERROR_INVALID_HASH_LENGTH,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Length of OEM Customizable Certificate Friendly Name setting is set incorrectly."
    },
    {
        ERROR_INVALID_HASH_VALUE,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "OEM Customizable Certificate Stream setting is set incorrectly."
    },
    {
        ERROR_INVALID_HASH_ALGORITHM,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "OEM Customizable Certificate Hash Algorithm setting is set incorrectly."
    },
    {
        ERROR_INVALID_NAME_LENGTH,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Length of OEM Customizable Certificate Stream is set incorrectly."
    },
    {
        ERROR_UNABLE_TO_COMPRESS,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Internal error - Unable to compress."
    },
    {
        ERROR_INVALID_COMPRESSION_VAL,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "The compressed data is incorrect."
    },
    {
        ERROR_USBR_NVAR_WRONG_CONFIG,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "USBr EHCI 1 Enabled and/or USBr EHCI 2 Enabled setting is set incorrectly."
    },
    {
        ERROR_USBR_IN_USE,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "KVM device is already in use by other components."
    },
    {
        ERROR_EC_UNABLE_TO_GET_SOURCE,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Failed to retrieve power source."
    },
    {
        ERROR_EC_POWER_NOT_AC,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Power source is not AC."
    },
    {
        ERROR_POWER_WELL_LAN_INCORRECT,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "LAN power well setting is set incorrectly."
    },
    {
        ERROR_POWER_WELL_WLAN_INCORRECT,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "WLAN power well setting is set incorrectly."
    },
    {
        MEMANUF_ERROR_EOL_UUIDCHECK_ALLZERO,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "System UUID actual value is all 0x00."
    },
    {
        MEMANUF_ERROR_EOL_UUIDCHECK_ALLF,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "System UUID actual value is all 0xFF."
    },
    {
        MEMANUF_ERROR_EOL_MANUFJMPCHECK,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Security Descriptor Override Strap (SDO) is enabled."
    },
    {
        MEMANUF_ERROR_EOL_EOPCHECK,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "End-Of-Post message is not sent."
    },
    {
        MEMANUF_ERROR_EOL_FOVLOCKCHECK_UNKNOWN,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Unable to determine Intel(R) " MAKE_STR(ME_STR) " Manufacturing Mode status."
    },
    {
        MEMANUF_ERROR_EOL_FOVLOCKCHECK_NOT_EOM,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Intel(R) " MAKE_STR(ME_STR) " is still in Manufacturing Mode."
    },
    {
        MEMANUF_ERROR_EOL_RPMC_FUSE_EN_DISABLED,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "RPMC enablement fuse is not set.\nRPMC manufacturing process is not complete."
    },
    {
        MEMANUF_ERROR_EOL_MISMATCH,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "%s mismatch, actual value is - %s."
    },
    {
        FPROG_SYSTEM_FOLDER_WRITE_ACCESS,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "Generating file in System Folder is not allowed"
    },
    {
        MEMANUF_ERROR_NO_AMT,
        {CATEGORY_MEMANUF_TEST_RUN_ERROR,          MAKE_STR(ME_STR) "Manuf test failed to run."},
        "Cannot run the command since Intel(R) AMT is not available."
    },
    {
        MEMANUF_MFS_CORRUPTED_ERROR,
        {CATEGORY_MEMANUF_TEST_RUN_ERROR,          MAKE_STR(ME_STR) "Manuf test failed to run."},
        "MFS is corrupted."
    },
    {
        MEMANUF_PCH_ID_MISMATCH_ERROR,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Using wrong " MAKE_STR(PCH_STR) " SKU Emulation via Intel (R) FIT vs what's the actual HW Type."
    },
    {
        MEMANUF_ERROR_FAILED_HIBERNATION,
        {CATEGORY_MEMANUF_TEST_RUN_ERROR,          MAKE_STR(ME_STR) "Manuf test failed to run."},
        "Cannot perform hibernation. Please manually reboot the system."
    },
    {
        MEMANUF_ERROR_TEST_FAILED,
        {CATEGORY_MEMANUF_OPERATION_FAILED,        MAKE_STR(ME_STR) "Manuf operation failed."},
        "MEManuf Test Failed."
    },
    {
        MEMANUF_ERROR_TEST_NOT_RUN,
        {CATEGORY_MEMANUF_TEST_RUN_ERROR,          MAKE_STR(ME_STR) "Manuf test failed to run."},
        "Test is enabled by the user but is unknown by the platform - %s."
    },
    {
        ROOT_NODE_ADDING_SIBLING_ERROR,
        {CATEGORY_XML_USER_FILE_ERROR,             "Error in parsing user XML file."},
        "Attempting to add sibling to XML root node."
    },
    {
        EMPTY_FILE_ERROR,
        {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
        "File size is zero."
    },
    {
        XML_PARSING_FAILURE,
        {CATEGORY_XML_USER_FILE_ERROR,             "Error in parsing user XML file."},
        "XML parsing failed."
    },
    {
        SPI_ERASE_STATUS_BIT_NOT_SUPPORTED,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "SPI Erase failed since platform doesn't support SPI erase status bit flow"
    },
    {
        XML_INVALID_ERROR_CODE_CONVERSION,
        {CATEGORY_XML_USER_FILE_ERROR,             "Error in parsing user XML file."},
        "Invalid XML error code conversion."
    },
    {
        XML_PARSER_ERROR_NO_MEMORY,
        {CATEGORY_XML_USER_FILE_ERROR,             "Error in parsing user XML file."},
        "XML parser - out of memory error."
    },
    {
        XML_MISSING_REQUIRED_NODE,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Missing RequiredValue xml node in Master Access configuration file."
    },
    {
        XML_INCORRECT_REGION_NAME,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Incorrect region name in Master Access configuration file."
    },
    {
        MEMANUF_ERROR_FAILED_QUERY_TEST,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Failed to retrieve list of BIST tests to run from " MAKE_STR(FW_STR) "."
    },
    {
        MEMANUF_ERROR_FAILED_BIST_BISTRESULT_CMD,
        {CATEGORY_MEMANUF_TEST_RESULT_READ_ERROR,  "Cannot read " MAKE_STR(ME_STR) "Manuf test result."},
        "Unexpected failure when retrieving BIST results."
    },
    {
        MEMANUF_ERROR_RETRIEVE_EOL_CFG,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Retrieving the EOL Config list of tests failed."
    },
    {
        MEMANUF_ERROR_RETRIEVE_EOL_VAR,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Retrieving the EOL Var list of tests failed."
    },
    {
        MEMANUF_CONFIG_FILE_NO_NAME_FOR_TEST,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "No name attribute specified for test: %s."
    },
    {
        MEMANUF_CONFIG_FILE_PARSING_ERROR,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Failed to parse configuration file provided."
    },
    {
        MEMANUF_CONFIG_FILE_WRITE_NO_FILE_PATH,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "No output file path specified to write configuration file."
    },
    {
        MEMANUF_CONFIG_FILE_WRITE_NO_DATA,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "No data to write to configuration file."
    },
    {
        MEMANUF_CONFIG_FILE_INVALID_ERRACTION_DATA,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Invalid ErrAction specified"
    },
    {
        SPI_INIT_INCOMPATIBLE_DEVICES,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "The 2 SPI flash devices do not have compatible command sets."
    },
    {
        INVALID_DESC,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Flash descriptor is not valid."
    },
    {
        SPI_LOADDEVFILE_NO_MEMORY,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Failed to allocate memory for the flash part definition file \"%s\"."
    },
    {
        SPI_LOADFILE_PARSE_FAILED,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Parsing file failed."
    },
    {
        SPI_PROTECTED_RANGE_ACCESS_DENIED,
        {CATEGORY_FPT_INVALID_SPI_CONF,            "Invalid FPT SPI devices configuration file."},
        "Protected Range Registers are currently set by BIOS, preventing flash access.\nPlease contact the target system BIOS vendor for an option to disable\nProtected Range Registers."
    },
    {
        HECI_STATUS_DRIVER_ACCESS_DENIED,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        MAKE_STR(ME_STR)" client access denied."
    },
    {
        SPI_READ_ACCESS_DENIED,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "The host CPU does not have read access to the target flash area.\nTo enable read access for this operation you must modify the descriptor settings to give host access to this region."
    },
    {
        SPI_READ_OUT_OF_RANGE,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "An attempt was made to read beyond the end of flash memory."
    },
    {
        FEAT_NOT_RELEVANT,
        {CATEGORY_MEINFO_FEATURE_NOT_FOUND,        "Cannot find " MAKE_STR(ME_STR) "Info feature or feature is not supported."},
        "Feature %s is not relevant in the current environment."
    },
    {
        FPT_INVALID_BLOCK_ERASE_SIZE,
        {CATEGORY_FPT_INVALID_SPI_CONF,            "Invalid FPT SPI devices configuration file."},
        "Invalid Block Erase Size."
    },
    {
        FPT_INVALID_WRITE_GRANULARITY,
        {CATEGORY_FPT_INVALID_SPI_CONF,            "Invalid FPT SPI devices configuration file."},
        "Invalid Write Granularity value."
    },
    {
        ERASE_SIZE,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Flash device does not support block erase size of 4KB."
    },
    {
        SPI_DEV_INFO_INVALID_INDEX,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "The supplied zero-based index of the SPI Device is out of range."
    },
    {
        SPI_REGION_INVALID_DESC,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Invalid descriptor region."
    },
    {
        SPI_REGION_NO_EXIST,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Region does not exist."
    },
    {
        SPI_WRITE_OUT_OF_RANGE,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "An attempt was made to write beyond the end of flash memory."
    },
    {
        SPI_ERASE_OUT_OF_RANGE,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "An attempt was made to erase beyond the end of flash memory."
    },
    {
        SPI_ERASE_ALIGNMENT_ERROR,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "The address 0x%08X of the block to erase is not aligned correctly."
    },
    {
        SPI_HARDWARE_TIMEOUT_OCCURRED,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Hardware timeout occurred in SPI device."
    },
    {
        SPI_INIT_DEVICE_NOT_SUPPORTED,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "There are no supported SPI flash devices installed. Please check connectivity."
    },
    {
        SPI_UNRECOGNISED_HSFSTS_VALUE,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Unrecognized value in the HSFSTS register."
    },
    {
        SPI_STATUS_AEL,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "AEL is not equal to zero."
    },
    {
        SPI_STATUS_FCERR,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "FCERR is set. Hardware sequencing failed. Make sure that you have access to target flash area."
    },
    {
        MEMANUF_EOL_CHECKING_VAR_FAILED,
        {CATEGORY_CSE_FILE_COMPARE_GENERAL_ERROR,  "CSE File compare error."},
        "Checking variable \"%s\" failed."
    },
    {
        NVAR_MCA_WRONG_VPRO_NIC_TBT_ADDRESS,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "On board and docked vPro NIC cannot have the same value."
    },
    {
        FPROG_FOV_INVALID_VAR_NAME,
        {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
        "Invalid Manufacturing Line Configurable variable name \"%s\"."
    },
    {
        FPROG_FILE_DOESNOT_EXISTS,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "File does not exist."
    },
    {
        FPROG_VERIFY_LOCK_SETTINGS_FAILED,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "End Of Manufacturing Operation failure - Verification failure on Descriptor Lock settings."
    },
    {
        FPROG_ERROR_GET_MASTER_BASE_ADDR,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Unable to get master base address from the descriptor."
    },
    {
        NVAR_MCA_WRONG_RETIMER_TBT_ADDRESS,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Retimers cannot have the same I2C address."
    },
    {
        FPROG_INVALID_VALUE_LENGTH,
        {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
        "Invalid length of Manufacturing Line Configurable value.\nCheck configuration file for correct length."
    },
    {
        FPROG_INVALID_HASH_FILE,
        {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
        "Invalid hash certificate file."
    },
    {
        FPROG_VERIFY_GLOBAL_LOCKED_FAILED,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "End Of Manufacturing Operation failure - Verification failure on " MAKE_STR(ME_STR) " Manufacturing\nMode Done settings."
    },
    {
        NVAR_MCA_POLICY_CFG_RULES_WRONG_MANUF_STATE,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "cfg_rules: the requested rule change is not supported after end of manufacturing."
    },
    {
        FPROG_VALIDATION_PARAM_FAILED,
        {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
        "Invalid parameter value specified by user. Use -? option to see help."
    },
    {
        ME_DISABLED_OLD,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        MAKE_STR(ME_STR) "  disabled."
    },
    {
        FPROG_FAILED_GET_DEVICE_INFO,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Failed to get information about the installed flash devices."
    },
    {
        FPROG_ERROR_READ_FLASH_DESC,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "An error occurred reading the flash descriptor signature."
    },
    {
        FPROG_DESC_INVALID_SIGNATURE,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Flash descriptor does not have correct signature."
    },
    {
        FPT_FOV_COMMIT_FAILED,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "The attempt to commit the Manufacturing Line Configurables has failed."
    },
    {
        FPROG_ACCESS_DENIED_FILE_OPEN,
        {CATEGORY_FPT_INVALID_SPI_CONF,            "Invalid FPT SPI devices configuration file."},
        "Access was denied opening file."
    },
    {
        FPROG_FAILED_FILE_READ_ENTIRE,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "Failed to read the entire file into memory. File: %s."
    },
    {
        FPROG_READ_ADDR_OUTSIDE_BOUNDARY,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "The address is outside the boundaries of the flash area."
    },
    {
        FPROG_CANNOT_WRITE_FLASH,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Unable to write data to flash. Address 0x%x."
    },
    {
        FPROG_VERIFY_MISMATCH_FOUND,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Data verify mismatch found."
    },
    {
        FPROG_FAILED_WRITE_FLASH_TO_FILE,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "Failed to write the entire flash contents to file."
    },
    {
        FPROG_ERROR_READ_MAPPING_DATA,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "An error occurred reading the flash mapping data."
    },
    {
        NVAR_MCA_INVALID_PASSWORD,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Password does not match the criteria."
    },
    {
        FPROG_ERROR_READ_COMPONENT_DATA,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "An error occurred reading the flash components data."
    },
    {
        FPROG_ERROR_READ_BASE_LIMIT,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "An error occurred reading the flash region base/limit data."
    },
    {
        FPROG_ERROR_READ_MASTER_ACCESS_DATA,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "An error occurred reading the flash master access data."
    },
    {
        FPROG_FLASH_NOT_BLANK,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Flash is not blank."
    },
    {
        NVAR_MCA_WRONG_PAVP_EDP_CONFIG_VALUE,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "PAVP oem config data: invalid edp port value."
    },
    {
        SETTING_GLOBAL_RESET_FAILED,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "Setting Global Reset Failed."
    },
    {
        ME_DISABLE_NOT_NEEDED,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "ME disable not needed."
    },
    {
        ME_ALREADY_DISABLED,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "ME already disabled."
    },
    {
        FPT_ME_DISABLE_FAILURE,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "Unable to detect if the request to disable " MAKE_STR(ME_STR) " succeeded."
    },
    {
        FPT_GBE_ERROR_SAVING_GBE_DATA,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "There is a problem with the GbE binary which prevents saving the data."
    },
    {
        FPT_MISSING_REQUIRED_PARAMETER,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "A required parameter is missing."
    },
    {
        FPF_COMMIT_NOT_ALLOWED,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Committing the FPF is not allowed at this time."
    },
    {
        FPF_ALREADY_COMMITTED,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "The FPF has already been committed."
    },
    {
        NVAR_MCA_WRONG_PAVP_LSPCON_CONFIG_VALUE,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "PAVP oem config data: invalid lspcon port value."
    },
    {
        FPF_COMMIT_SPECIFIC_NOT_SUPPORTED,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Committing a specific FPF is not supported. Consider committing all the FPFs."
    },
    {
        KEYBOX_FILE_SIZE_ERROR,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Keybox file size invalid."
    },
    {
        NVAR_MCA_WRONG_ALL_HASHES_STATE,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Invalid all hashes state file."
    },
    {
        NVAR_MCA_WRONG_IDLE_TIMEOUT,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Invalid idle timeout file."
    },
    {
        NVAR_MCA_WRONG_PROV_STATE,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Invalid provisioning state file."
    },
    {
        KEYBOX_PROVISION_CEK_INVALID,
        {CATEGORY_KEYBOX_INVALID_STATUS,           "Invalid Keybox response status."},
        "CEK is invalid."
    },
    {
        KEYBOX_PROVISION_CEK_NOT_AVAILABLE,
        {CATEGORY_KEYBOX_INVALID_STATUS,           "Invalid Keybox response status."},
        "CEK is not available."
    },
    {
        KEYBOX_PROVISION_AFTER_EOM,
        {CATEGORY_KEYBOX_INVALID_STATUS,           "Invalid Keybox response status."},
        "Cannot provision after EOM."
    },
    {
        NVAR_MCA_WRONG_REDIR_STATE,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Invalid redirection state file."
    },
    {
        KEYBOX_PROVISION_BAD_CRC,
        {CATEGORY_KEYBOX_INVALID_STATUS,           "Invalid Keybox response status."},
        "Bad CRC."
    },
    {
        KEYBOX_PROVISION_BAD_MAGIC,
        {CATEGORY_KEYBOX_INVALID_STATUS,           "Invalid Keybox response status."},
        "Bad Magic."
    },
    {
        NVAR_MCA_WRONG_EHBC_STATE,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Invalid EHBC state file."
    },
    {
        KEYBOX_NOT_PROVISIONED,
        {CATEGORY_KEYBOX_INVALID_STATUS,           "Invalid Keybox response status."},
        "Keybox is not provisioned."
    },
    {
        SPI_WRITE_ACCESS_DENIED,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "The host CPU does not have write access to the target flash area.\nTo enable write access for this operation you must modify the descriptor\nsettings to give host access to this region."
    },
    {
        USER_CANCELLED_OPERATIION,
        {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
        "User selected to cancel the operation."
    },
    {
        HECI_RESP_LEN_INVALID,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Internal error - Invalid Heci response length."
    },
    {
        SYS_STATE_ERROR,
        {CATEGORY_SYSTEM_API_CALL_ERROR,           "System API returned unexpected error code."},
        "Error determining possible system states."
    },
    {
        HECI_STATUS_CANNOT_LOCATE_DRIVER,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Cannot locate " MAKE_STR(MEI_STR) " driver."
    },
    {
        FWU_FW_NOT_FOUND,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Unexpected internal " MAKE_STR(FW_STR) " error occurred. Object was not found."
    },
    {
        MEMANUF_ERROR_CONFIG_FILE_INVALID_STATE,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Invalid \"State\" found for test - %s."
    },
    {
        ERROR_ISH_SRV_BIST_TEST_ERROR,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "ISH Internal Error."
    },
    {
        ERROR_ISH_SRV_BIST_IUP_NOT_FOUND_ERROR,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "IUP Not Found."
    },
    {
        HID_STATUS_LOCATE_DEVICE_ERROR,
        {CATEGORY_OS_DEVICE_COMMUNICATION_FAILURE, "OS device not found or failed to perform program request."},
        "Cannot locate HID device."
    },
    {
        HID_STATUS_GET_FEATURE_REPORT_FAILED,
        {CATEGORY_OS_DEVICE_COMMUNICATION_FAILURE, "OS device not found or failed to perform program request."},
        "Incorrect Report ID received."
    },
    {
        ERROR_BIST_TEST_MCTP_SMBUS3_FAILED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "MCTP SMBUS test failed."
    },
    {
        MEMANUF_ERROR_CONFIG_FILE_MISSING_STATE,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Invalid config file. \"State\" was not found for test - %s."
    },
    {
        MEMANUF_ERROR_CONFIG_FILE_MISSING_REQ_VALUE,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Invalid config file. \"RequiredValue\" was not found for test - %s."
    },
    {
        MEMANUF_ERROR_CFG_FILE_MISSING_ERR_ACTION,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Invalid config file. \"ErrAction\" was not found for test - %s."
    },
    {
        ERROR_TOUCH_STATUS_ACCESS_DENIED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Unable to validate address range."
    },
    {
        ERROR_TOUCH_STATUS_NOT_READY,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Memory window not set or device is not armed for operation."
    },
    {
        ERROR_TOUCH_STATUS_NO_SENSOR_FOUND,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Sensor could not be found. Either no sensor is connected, the sensor has not yet initialized,\nor the system is improperly configured."
    },
    {
        ERROR_TOUCH_STATUS_OUT_OF_MEMORY,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Not enough memory/storage for requested operation."
    },
    {
        ERROR_TOUCH_STATUS_SENSOR_DISABLED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Used in TOUCH_SENSOR_HID_READY_FOR_DATA_RSP to indicate sensor has been disabled or reset and\nmust be reinitialized."
    },
    {
        ERROR_TOUCH_STATUS_COMPAT_CHECK_FAIL,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Used to indicate compatibility revision check between sensor and " MAKE_STR(ME_STR) " failed,\nor protocol ver between ME/HID/Kernels failed."
    },
    {
        ERROR_TOUCH_STATUS_SENSOR_UNEXPECTED_RESET,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Indicates sensor went through an unexpected reset."
    },
    {
        ERROR_TOUCH_STATUS_RESET_FAILED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Requested sensor reset failed to complete."
    },
    {
        ERROR_TOUCH_STATUS_TIMEOUT,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Operation timed out."
    },
    {
        ERROR_TOUCH_STATUS_TEST_MODE_FAIL,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Test mode pattern did not match expected values."
    },
    {
        ERROR_TOUCH_STATUS_SENSOR_FAIL_FATAL,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Indicates sensor reported fatal error during reset sequence. Further progress is not possible."
    },
    {
        ERROR_TOUCH_STATUS_SENSOR_FAIL_NONFATAL,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Indicates sensor reported non-fatal error during reset sequence.\nHID/BIOS logs error and attempts to continue."
    },
    {
        ERROR_TOUCH_STATUS_INVALID_DEVICE_CAPS,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Indicates sensor reported invalid capabilities, such as not supporting required minimum frequency or I/O mode."
    },
    {
        ERROR_TOUCH_STATUS_QUIESCE_IO_IN_PROGRESS,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Indicates that command cannot be complete until ongoing Quiesce I/O flow has completed."
    },
    {
        NVAR_MCA_NO_FILE,
        {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
        "Cannot find the NVAR file; the system maybe in EOM."
    },
    {
        NVAR_MCA_INVALID_CFG_RULE,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Invalid cfg rule data."
    },
    {
        NVAR_MCA_NO_FILE_ATTRIBUTE,
        {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
        "Cannot access the NVAR file attributes."
    },
    {
        CSE_FILE_HASH_ERROR,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Failed to hash " MAKE_STR(CSE_STR) " file data."
    },
    {
        NVAR_MCA_AFTER_LOCK,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Operation is not allowed after EOM."
    },
    {
        NVAR_MCA_INVALID_INPUT,
        {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
        "Used an invalid input parameter to access the NVAR file."
    },
    {
        FPF_MCA_FILE_NOT_WRITTEN,
        {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
        "FPF is not written."
    },
    {
        NVAR_MCA_WRONG_PRIVACY_LEVEL,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Invalid privacy level file."
    },
    {
        FILE_INVALID,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "File is invalid."
    },
    {
        HDCP_RX_PROVISION_AFTER_EOM,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "Can not provision after EOM."
    },
    {
        HDCP_RX_PROVISION_CERT_VERIFICATION_FAILED,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "Certificate verification failed."
    },
    {
        HDCP_RX_NOT_PROVISIONED,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "HDCP Rx is not provisioned."
    },
    {
        FPROG_INVALID_STRING,
        {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
        "Invalid string value entered for the Manufacturing Line Configurable."
    },
    {
        ME_RECOVERY_MODE,
        {CATEGORY_ME_COMMUNICATION_FAILURE,        "Failed to communicate with "  MAKE_STR(ME_STR)  " device or invalid "  MAKE_STR(ME_STR)  " HW response."},
        "Detected " MAKE_STR(ME_STR) " in recovery mode."
    },
    {
        FPT_DELETE_TOKEN_FAILED,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        MAKE_STR(FW_STR) " returned status: Erase token failure."
    },
    {
        SIZE_FAILURE,
        {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
        "Detected invalid data size."
    },
    {
        INVALID_HEX_FAILURE,
        {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
        "Detected invalid hex value."
    },
    {
        ERROR_BIST_TEST_PAVP_SET_EDP_FAILED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Failed to retrieve 5K port setting."
    },
    {
        ERROR_BIST_TEST_PAVP_SET_LSPCON_FAILED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Failed to retrieve LSPCON Port setting."
    },
    {
        ERROR_PAVP_CHECK_EDP_LSPCON_CONFIG_FAILED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "Display port settings are not correct."
    },
    {
        MEMANUF_ERROR_CHECK_EC_REGION_WRITE,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "EC Region write access permissions don't match Intel recommended values."
    },
    {
        NVAR_SUPPORT_FILE_SIZE_MISMATCH,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Unexpected size found in the file \"%s\". Expected: 0x%X. Received: 0x%X."
    },
    {
        FW_PHASE_IN_BUP,
        {CATEGORY_ME_COMMUNICATION_FAILURE,        "Failed to communicate with "  MAKE_STR(ME_STR)  " device or invalid "  MAKE_STR(ME_STR)  " HW response."},
        "Unable to execute command in this Firmware State. Please reboot."
    },
    {
        MEMANUF_ERROR_CHECK_GBE_REGION_WRITE,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "GBE Region write access permissions don't match Intel recommended values."
    },
    {
        FPT_SETDAM_FAILED,
        {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
        "SetDam command failed."
    },
    {
        MEMANUF_ERROR_CHECK_ME_REGION_WRITE,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "ME Region write access permissions don't match Intel recommended values."
    },
    {
        MEMANUF_ERROR_EOL_MISMATCH_UEP_VS_HW,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Mismatch on FPF file %s - UEP: %s, FPF HW: %s."
    },
    {
        MEMANUF_ERROR_EOL_FPF_NOT_COMMITTED,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "FPFs are not committed to HW."
    },
    {
        MEMANUF_ERROR_CHECK_BIOS_REGION_WRITE,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "BIOS Region write access permissions don't match Intel recommended values."
    },
    {
        MEMANUF_ERROR_READING_FPF_HW,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Failed to read FPF HW."
    },
    {
        MEMANUF_ERROR_FPF_CONFIG_NOT_SET,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "SOC Config Lock is not set."
    },
    {
        MEMANUF_ERROR_EOL_FPF_LOCK_BIT_NOT_SET,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Lock bit FPF is not set on file."
    },
    {
        MEMANUF_ERROR_READING_FPF_UEP,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Failed to read FPF in UEP."
    },
    {
        MEMANUF_ERROR_EOL_FWUPDATE_OEM_ID,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        MAKE_STR(FW_STR) " Update OEM ID incorrectly set to 00 or FF."
    },
    {
        MEMANUF_ERROR_EOL_FWUPDATE_OEM_ID_UNKNOWN,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Unable to determine " MAKE_STR(FW_STR) " Update OEM ID status."
    },
    {
        MEMANUF_ERROR_CHECK_BIOS_REGION_READ,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "BIOS Region read access permissions don't match Intel recommended values."
    },
    {
        MEMANUF_ERROR_CHECK_ME_REGION_READ,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "ME Region read access permissions don't match Intel recommended values."
    },
    {
        MEMANUF_ERROR_CHECK_GBE_REGION_READ,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "GBE Region read access permissions don't match Intel recommended values."
    },
    {
        MEMANUF_ERROR_CHECK_EC_REGION_READ,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "EC Region read access permissions don't match Intel recommended values."
    },
    {
        MEMANUF_ERROR_EOL_RPMC_NOT_ENABLED,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "RPMC SPI device did not initialize RPMC support correctly,\nRPMC SPI device needs replacement/ refurbishment."
    },
    {
        MEMANUF_ERROR_EOL_RPMC_NOT_BOUND,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "RPMC SPI device has not been bound to the platform yet,\nRPMC manufacturing process is not complete."
    },
    {
        MEMANUF_ERROR_HW_BINDING_CHECK,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "\"HW Binding\" state is not enabled."
    },
    {
        FPROG_VAR_NOT_UPDATABLE_ERROR,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "The \"%s\" var is not updatable."
    },
    {
        NVAR_DEP_SUPPORT_FAILED_VAR,
        {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
        "The variable \"%s\" is not supported on this platform."
    },
    {
        ERROR_PCH_UNLOCK_STATE,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        MAKE_STR(PCH_STR) " is unlocked. Disable Delayed Authentication Mode and retry."
    },
    {
        ERROR_BAD_SIGNATURE,
        {CATEGORY_MEINFO_FEATURE_EXECUTION_ERROR,         MAKE_STR(ME_STR) "Info failed to execute specific feature."},
        "Invalid signature."
    },
    {
        ERROR_SIGNATURE_VERIFICATION_FAILED,
        {CATEGORY_MEINFO_FEATURE_EXECUTION_ERROR,         MAKE_STR(ME_STR) "Info failed to execute specific feature."},
        "Mis-matching Signature."
    },
    {
        ERROR_READ_FAIL,
        {CATEGORY_MEINFO_FEATURE_EXECUTION_ERROR,         MAKE_STR(ME_STR) "Info failed to execute specific feature."},
        "Failed to Read Signature."
    },
    {
        MEMANUF_INVALID_REQUIRED_VALUE_FORMAT,
        {CATEGORY_CSE_FILE_COMPARE_GENERAL_ERROR,  "CSE File compare error."},
        "Test required value format is not valid."
    },
    {
        ERROR_BTG_CONFIGURATION,
        {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
        "Invalid BootGuard configuration."
    },
    {
        ERROR_CONFIRM_ARB_SVN,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Minimum ARB SVN value set on current platform does not match corresponding ARB SVN in " MAKE_STR(FW_STR) " image."
    },
    {
        FWU_FW_INVALID,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Unexpected internal " MAKE_STR(FW_STR) " error occurred. Invalid parameter."
    },
    {
        ERROR_PLATFORM_NAME_FOUND,
        {CATEGORY_UNSUPPORTED_HW,                  "Tool isn't compatible with current HW or current HW environment isn't supported."},
        "Platform name for this " MAKE_STR(PCH_STR) " type not found or not exists."
    },
    {
        FPROG_CLEAR_FPF_ERROR,
        {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
        "Clear option is not supported for FPFs."
    },
    {
        STORAGE_TYPE_NOT_SUPPORTED,
        {CATEGORY_UNSUPPORTED_HW,                  "Tool isn't compatible with current HW or current HW environment isn't supported."},
        "This command cannot be processed on platforms using %s as the storage type."
    },
    {
        REGION_NOT_SUPPORTED,
        {CATEGORY_UNSUPPORTED_HW,                  "Tool isn't compatible with current HW or current HW environment isn't supported."},
        "This command cannot be processed. Region is not supported on this platform."
    },
    {
        FPROG_SIZE_EXCEED_LIMIT,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "The maximum number of updated NVARs has been reached."
    },
    {
        INVALID_VALUE_FOR_CVAR,
        {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
        "Invalid value for this CVAR."
    },
    {
        VAR_COMPARE_FAILURE,
        {CATEGORY_CSE_FILE_COMPARE_GENERAL_ERROR,  "CSE File compare error."},
        "The VAR compare failed."
    },
    {
        ERROR_FLASH_LOGS_EXIST,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Fatal flash logs exist in NVM."
    },
    {
        HECI_REQUEST_REPLY_SIZE_MISMATCH,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Request and Reply messages' size mismatch."
    },
    {
        HECI_UNSUPPORTED_MSG_TYPE,
        {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
        "Intel (R) " MAKE_STR(ME_STR) " Interface : Unsupported message type."
    },
    {
        PART_NOT_PRESENT,
        {CATEGORY_INVALID_PARTITION,               "Partition does not exist in the flash image."},
        "Specified partition was not found in the Update Image."
    },
    {
        FWU_NO_FPT_IN_IMAGE,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "FPT is not found in the image."
    },
    {
        FWU_ALLOWSV_MISSING,
        {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
        "Full " MAKE_STR(FW_STR) " Update using same version is not allowed. Include -allowsv in command line to allow it."
    },
    {
        FWU_RESTORE_POINT_FAILURE,
        {CATEGORY_FWU_RESTORE_POINT_ERROR,         "FWU Restore Point Image Failure."},
        "Restore Point Image Failure. Reboot may be required."
    },
    {
        FWU_INVALID_PARTID,
        {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
        "Invalid Partition ID. Use a Partition ID which is possible to do Partial " MAKE_STR(FW_STR) " Update on."
    },
    {
        FWU_PID_NOT_EXPECTED,
        {CATEGORY_INVALID_PARTITION,               "Partition does not exist in the flash image."},
        "The partition provided is not supported by the platform."
    },
    {
        FWU_INVALID_IMG_LENGTH,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "The requested size of partition to read/write/erase exceeds the actual partition size."
    },
    {
        FWU_UPD_PROCESS,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware Update operation not initiated because a firmware update is already in progress."
    },
    {
        FWU_SKU_MISMATCH,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Sku capabilities bits are different between the Update Image and the Flash Image."
    },
    {
        FWU_VER_MISMATCH,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Major version number of Update Image is not the same as major version number of Flash Image."
    },
    {
        FWU_ERROR_CREATING_FT,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error\nThe total size of the backup partitions is bigger than NFTP size."
    },
    {
        FWU_SAL_NOTIFICATION,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error caused by a failure in event publishing."
    },
    {
        FWU_FW_DEVICE_ERROR,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        MAKE_STR(FW_STR) " Flash read/write/erase operation failed."
    },
    {
        FWU_UPDATE_TIMEOUT,
        {CATEGORY_ME_COMMUNICATION_FAILURE,        "Failed to communicate with "  MAKE_STR(ME_STR)  " device or invalid "  MAKE_STR(ME_STR)  " HW response."},
        "Update operation timed-out; cannot determine if the operation succeeded."
    },
    {
        FWU_LOCAL_DIS,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        MAKE_STR(FW_STR) " Update is disabled. MEBX has options to disable / enable " MAKE_STR(FW_STR) " Update."
    },
    {
        FWU_INVALID_OEM_ID,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update cannot be initiated because the OEM ID given for " MAKE_STR(FW_STR) " Update did not match the OEM ID in the " MAKE_STR(FW_STR) "."
    },
    {
        FWU_DISPLAY_FW_VERSION,
        {CATEGORY_FWU_OPERATION_FAILED,            "FWU tool failed to execute the requested command."},
        "Display " MAKE_STR(FW_STR) " Version failed."
    },
    {
        FWU_DOWNGRADE_VETOED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update was blocked by one of the " MAKE_STR(FW_STR)" modules."
    },
    {
        FWU_FW_WRITE_FILE_FAIL,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error\nWrite file failed."
    },
    {
        FWU_PARTITION_LAYOUT_NOT_COMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Sanity check in erase/write of partitions. Error might have happened when size of partition is not 4K aligned."
    },
    {
        FWU_FLASH_CODE_PARTITION_INVALID,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "FTPR invalid."
    },
    {
        FWU_FLASH_NFT_PARTITION_INVALID,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "NFTP invalid."
    },
    {
        FWU_HOST_RESET_REQUIRED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Host reset is required after the last " MAKE_STR(FW_STR) " Update operation."
    },
    {
        FWU_LOWER_TCB_SVN,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update to Image with lower TCB SVN is not allowed."
    },
    {
        FWU_INSTID_IS_NOT_EXPECTED_ID,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Partial update is allowed only to the expected instance ID of an IUP.\nThe Update Image contains IUP with instance ID that is not the currently expected one by the " MAKE_STR(FW_STR) ".\nTo update LOCL, please use The Intel Management and Security Status (IMSS) tool."
    },
    {
        FWU_REJ_IPU_FULL_UPDATE_NEEDED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Partial Update is not allowed, because CSE is in Recovery Mode."
    },
    {
        FWU_IPU_NAMEID_NOT_FOUND,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Partial Update of an IUP was requested, but this IUP doesn't exist in the Flash Image."
    },
    {
        FWU_RESTORE_POINT_OPERATION_NOT_ALLOWED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Get Restore Point Image is not allowed, because " MAKE_STR(FW_STR) " Update is in progress. (The regular FW Update will continue)."
    },
    {
        FWU_LOWER_VCN,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update to Image with lower VCN is not allowed."
    },
    {
        FWU_INVALID_SVN,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "SVN invalid: SVN is too large."
    },
    {
        FWU_OUT_OF_SVN_RESOURCES,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "PSVN partition is full, so cannot update to higher SVN."
    },
    {
        FWU_RESTORE_POINT_REQUEST_FLASH_IN_RECOVERY,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Restore Point Image was requested, but it is not allowed because " MAKE_STR(CSE_STR) " is in Recovery Mode."
    },
    {
        FWU_DISPLAY_PART_VERSION,
        {CATEGORY_FWU_OPERATION_FAILED,            "FWU tool failed to execute the requested command."},
        "Display Partition Version failed."
    },
    {
        FWU_RESTORE_POINT_REQUEST_RESTART_NEEDED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Restore Point Image was requested, but there was Full/Partial " MAKE_STR(FW_STR) " Update before without Restart after it."
    },
    {
        FWU_ERROR_PMC_INSTANCE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update to incompatible PMC: The PMC instance ID is different, which may be due to H/LP SKU incompatibility."
    },
    {
        FWU_ERROR_H_LP_MISMATCH,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update to incompatible H/LP SKU image."
    },
    {
        FWU_ERROR_UPD_IMG_TOO_BIG,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update Image length is bigger than the expected size of the image according to its size in the flash.\nFor example: Error on updating from Consumer to Corporate."
    },
    {
        FWU_ERROR_INVALID_MANIFEST_SIZE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Manifest size in Update Image is too large."
    },
    {
        FWU_ERROR_364,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 364."
    },
    {
        FWU_ERROR_365,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 365."
    },
    {
        FWU_ERROR_366,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Failed to verify signature of OEM or RoT key manifests. For example: Error on update from Production to Pre-Production."
    },
    {
        FWU_ERROR_367,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 367."
    },
    {
        FWU_ERROR_SKUMGR_FAILED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 368."
    },
    {
        FWU_ERROR_CFGMGR_FAILED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 369."
    },
    {
        FWU_ERROR_MAN_NOT_FOUND,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Manifest not found in partition (in Update or Flash Image)."
    },
    {
        FWU_ERROR_371,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 371."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_FTPR,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of FTPR. Production vs. Pre-Production."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_NFTP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of NFTP."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_DLMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of IDLM."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_RBEP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of RBE."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_PMCP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of PMC."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_OEMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of OEM KM."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_WCOD,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of WCOD."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_LOCL,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of LOCL."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_PCHC,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of PCHC."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_IOMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of IOMP."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_NPHY,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of NPHY."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_TBTP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of TBTP."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_ISHC,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of ISHC."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_IUNP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of IUNIT."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_FTPR,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in FTPR."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_NFTP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in NFTP."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_DLMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in IDLM."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_RBEP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in RBE."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_PMCP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in PMC. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_OEMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in OEM KM. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_WCOD,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in WCOD."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_LOCL,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in LOCL."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_PCHC,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in PCHC. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_IOMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in IOMP. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_NPHY,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in NPHY. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_TBTP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in TBTP. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_ISHC,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in ISHC. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_IUNP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in IUNIT. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_FTPR,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "FTPR partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_NFTP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "NFTP partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_DLMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "DLMP partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_RBEP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "RBEP partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_PMCP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "PMCP partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_OEMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "OEMP partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_WCOD,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "WCOD partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_LOCL,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "LOCL partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_PCHC,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "PCHC partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_IOMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "IOMP partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_NPHY,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "NPHY partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_TBTP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "TBTP partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_ISHC,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "ISHC partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_IUNP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "IUNP partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_API_VER_MAJOR_FTPR,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Place holder. This error code will not be returned by the " MAKE_STR(FW_STR) "."
    },
    {
        FWU_ERROR_API_VER_MAJOR_NFTP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Place holder. This error code will not be returned by the " MAKE_STR(FW_STR) "."
    },
    {
        FWU_ERROR_API_VER_MAJOR_DLMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Place holder. This error code will not be returned by the " MAKE_STR(FW_STR) "."
    },
    {
        FWU_ERROR_API_VER_MAJOR_RBEP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Place holder. This error code will not be returned by the " MAKE_STR(FW_STR) "."
    },
    {
        FWU_ERROR_API_VER_MAJOR_PMCP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "PMCP must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update."
    },
    {
        FWU_ERROR_API_VER_MAJOR_OEMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "OEMP must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update."
    },
    {
        FWU_ERROR_API_VER_MAJOR_WCOD,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "WCOD must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        FWU_ERROR_API_VER_MAJOR_LOCL,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "LOCL must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        FWU_ERROR_API_VER_MAJOR_PCHC,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "PCHC must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        FWU_ERROR_API_VER_MAJOR_IOMP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "IOMP must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        FWU_ERROR_API_VER_MAJOR_NPHY,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "NPHY must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        FWU_ERROR_API_VER_MAJOR_TBTP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "TBTP must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        FWU_ERROR_API_VER_MAJOR_ISHC,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "ISHC must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        FWU_ERROR_API_VER_MAJOR_IUNP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "IUNP must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        FWU_ERROR_PART_SIZE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "The size of an Update partition is bigger than the size of the Flash partition."
    },
    {
        FWU_ERROR_BACKUP_OUTSIDE_NFTP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Location of partition to backup is not inside NFTP."
    },
    {
        FWU_ERROR_MAX_IUPS,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "The number of IUPs in the Update/Flash Image is bigger than MAX_IUPS."
    },
    {
        FWU_ERROR_NOT_IUP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Partition name inside IUPs list (in FTPR manifest extension) is not IUP."
    },
    {
        FWU_ERROR_IUP_MISSING_UPDATE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Non-optional IUP (like LOCL, WCOD) inside IUPs list (in FTPR manifest extension) is not in the Update Image."
    },
    {
        FWU_ERROR_PMC_MISSING_UPDATE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "PMC partition is not in the Update Image."
    },
    {
        FWU_ERROR_NOT_PARTIAL_IUP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "It is not allowed to do Partial Update on this partition."
    },
    {
        FWU_ERROR_PARTIAL_TCSS,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "It is not allowed to do Partial Update on Type-C partitions, according to NVAR."
    },
    {
        FWU_ERROR_FTPR_VER,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "RBEP and NFTP must have the same version as FTPR, in the Update Image."
    },
    {
        FWU_ERROR_FTPR_SVN,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "RBEP and NFTP must have the same SVN as FTPR, in the Update Image."
    },
    {
        FWU_ERROR_FTPR_VCN,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "RBEP and NFTP must have the same VCN as FTPR, in the Update Image."
    },
    {
        FWU_ERROR_FTPR_VER_MAJOR,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Non-optional IUPs (like LOCL, WCOD) must have the same major build version as FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        FWU_ERROR_IUP_SVN,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update IUP must not have SVN smaller than SVN of Flash IUP."
    },
    {
        FWU_ERROR_IMAGE_LEN,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update Image length is not the same as Flash Image length."
    },
    {
        FWU_ERROR_IUP_VCN,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update IUP must not have VCN smaller than VCN of Flash IUP."
    },
    {
        FWU_ERROR_PV_BIT,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update from PV bit ON to PV bit OFF is not allowed."
    },
    {
        FWU_ERROR_REVENUE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update to PV bit OFF on Revenue platform is not allowed."
    },
    {
        FWU_ERROR_SVN_UPGRADE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update to higher SVN must be an upgrade - to higher build version."
    },
    {
        FWU_ERROR_SVN_HOTFIX,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update to higher SVN must be to a higher Hot Fix number (the third number in the build version)."
    },
    {
        FWU_ERROR_IUP_MISSING_FLASH,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Non-optional IUP (like LOCL, WCOD) inside IUPs list (in FTPR manifest extension) is not in the Flash Image."
    },
    {
        FWU_ERROR_PARTITION_NOT_FOUND,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "A partition that was searched in the Update Image is not in it."
    },
    {
        FWU_ERROR_ENGINEERING_MISMATCH,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update between engineering build vs regular build is not allowed.\nBoth builds have to be the same type: regular or engineering build.\nEngineering build is 7000 and above. Regular build is below 7000."
    },
    {
        FWU_ERROR_OEMP_MISSING,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "OEM KM partition is not in the Update Image, but ISHC/IUNP is in the Update Image, which is not allowed."
    },
    {
        FWU_ERROR_IUPS_NOT_COMPATIBLE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "ISHC/IUNP do not exist in the same way in the Update Image and in the Flash Image."
    },
    {
        FWU_ERROR_OEMP_IN_UPDATE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "OEM KM partition is not in the Flash Image, but it is in the Update Image, which is not allowed."
    },
    {
        FWU_ERROR_WRONG_IUP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Partial " MAKE_STR(FW_STR) " Update: the Update Image contains IUP that is different than the one that was requested to be updated in the Partial Update command."
    },
    {
        FWU_ERROR_IMAGE_IUP_SIZE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "The Partial Update Image size is different than the size of the IUP in it (as it is in the manifest).\nThis means that the Update Image contains more (or less) than the IUP partition."
    },
    {
        FWU_ERROR_OPEN_IUP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 455."
    },
    {
        FWU_ERROR_SPI_IUP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 456."
    },
    {
        FWU_ERROR_ENABLED_INVALID,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Invalid " MAKE_STR(FW_STR) " Update enabled state."
    },
    {
        FWU_ERROR_PWR_FAILED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 458."
    },
    {
        FWU_ERROR_SPI_FAILED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 459."
    },
    {
        FWU_ERROR_RESTORE_POINT_ALREADY_STARTED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Get Restore Point Image is not allowed, because a previous Get Restore Point operation already started.\nBoth operations will be aborted. (Get Restore Point can be started again after this)."
    },
    {
        FWU_ERROR_RESTORE_POINT_OFFSET_INVALID,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 461."
    },
    {
        FWU_ERROR_WRONG_HECI_MSG_LENGTH,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Heci message length is not as expected."
    },
    {
        FWU_ERROR_ENV_INVALID,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "FWU_START_MSG Heci message contains invalid value in UpdateEnvironment.\nValue should be FWU_ENV_MANUFACTURING. (Other possible value: FWU_ENV_IFU is obsolete)."
    },
    {
        FWU_ERROR_WRONG_DATA_OPERATION,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "FWU_DATA Heci command was sent, but the " MAKE_STR(FW_STR) " Update wasn't started with FWU_START Heci command before it."
    },
    {
        FWU_ERROR_NVM_FAILED,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 465."
    },
    {
        FWU_ERROR_UFS_EOP,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "FW Update is not possible on UFS Flash after End Of Post (after the OS is running).\nIt is possible only before the OS is running using Bios Capsule Update."
    },
    {
        FWU_ERROR_API_VER_MAJOR_SPHY,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "SPHY must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_SPHY,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "SPHY partition hash and calculated hash are not the same. If partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_SPHY,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in SPHY. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_SPHY,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of SPHY."
    },
    {
        FWU_ERROR_SVN_TCB_ARB,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update to higher TCB SVN must be also to higher ARB SVN."
    },
    {
        FWU_INVALID_PARTID_ALL,
        {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
        "Invalid Partition ID. Use a Partition ID which is on the Flash Image."
    },
    {
        FWU_DISPLAY_PART_VENDOR_ID,
        {CATEGORY_FWU_OPERATION_FAILED,            "FWU tool failed to execute the requested command."},
        "Display Partition Vendor ID failed."
    },
    {
        FWU_ERROR_INVALID_UPDATE_IMAGE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Wrong structure of Update Image."
    },
    {
        FWU_ERROR_INVALID_FLASH_IMAGE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Flash Image content is invalid."
    },
    {
        FWU_ERROR_PG_FAILURE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 476."
    },
    {
        FWU_ERROR_IPK_FAILURE,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 477."
    },
    {
        FWU_ERROR_FLUSH_NVM_ERR,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 478."
    },
    {
        FWU_ERROR_WRONG_END_OPERATION,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "FWU_END Heci command was sent, but there was no FWU_DATA command before it."
    },
    {
        FWU_ERROR_DATA_LENGTH_INVALID,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "FWU_DATA Heci command has invalid data length (too big)."
    },
    {
        FWU_INVALID_HECI_CMD,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        MAKE_STR(FW_STR) " Update process received Heci command message with unknown command type."
    },
    {
        HECI_STATUS_CANNOT_DETECT_ME_STATE,
        {CATEGORY_ME_COMMUNICATION_FAILURE,        "Failed to communicate with "  MAKE_STR(ME_STR)  " device or invalid "  MAKE_STR(ME_STR)  " HW response."},
        "Cannot obtain " MAKE_STR(ME_STR) " Mode."
    },
    {
        MEMANUF_ERROR_EOL_RPMB_NOT_POST_BIND,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Replay protection of UFS device is in Pre-Bind status ."
    },
    {
        ERROR_DROP_SHIP_NOT_SUPPORTED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "BIOS does not support TDS."
    },
    {
        ERROR_SETUP_LOCK_NOT_SUPPORTED,
        {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
        "BIOS lock is not supported."
    },
    {
        SLIM_SKU_UNSUPPORTED_COMMAND,
        {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
        "This command is not supported on Slim SKU."
    },
    {
        UNIQUE_VARS_ALREADY_SET,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "ODM ID \\ System Integrator ID \\ Reserved ID: value already set."
    },
    {
        ERROR_FILE_ALREADY_EXIST,
        {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
        "File already exists."
    },
    {
        MEMANUF_ERROR_EOL_FW_VERSIONCHECK,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        MAKE_STR(ME_STR) " " MAKE_STR(FW_STR) " version mismatch, actual value is - %s."
    },
    {
        MEMANUF_ERROR_EOL_GBE_VERSIONCHECK,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Intel(R) Gbe version mismatch, actual value is - %s."
    },
    {
        MEMANUF_ERROR_EOL_BIOS_VERSIONCHECK,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "BIOS version mismatch, actual value is - %s."
    },
    {
        MEMANUF_ERROR_EOL_UUIDCHECK_MISMATCH,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "System UUID mismatch, actual value is - %s."
    },
    {
        MEMANUF_ERROR_EOL_MACCHECK_MISMATCH,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Intel(R) Wired LAN MAC address mismatch, actual value is - %s."
    },
    {
        MEMANUF_ERROR_EOL_WLAN_MACCHECK_MISMATCH,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Intel(R) Wireless LAN MAC address mismatch, actual value is - %s."
    },
    {
        MEMANUF_ERROR_EOL_WLAN_UCODE_MISMATCH,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Wireless LAN micro-code mismatch, actual value is - %s."
    },
    {
        MEMANUF_ERROR_EOL_FWU_OEM_ID_MISMATCH,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Firmware Update OEM ID mismatch, actual value is - %s."
    },
    {
        MEMANUF_ERROR_EOL_TOUCH_VENDORID_CHECK,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Touch - Vendor ID mismatch, actual value is - %s."
    },
    {
        NVAR_MCA_WRONG_PKI_SUFFIX,
        {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
        "Invalid PKI suffix file."
    },
    {
        FWU_LOWER_ARB_SVN,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update to Image with lower ARB SVN is not allowed."
    },
    {
        FWU_ERROR_FTPR_BUILD,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "RBEP and NFTP must have the same unique build as FTPR, in the Update Image."
    },
    {
        FWU_ERROR_501,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Firmware update failed due to an internal error 501."
       },
    {
        FPT_COMMITFPF_RPMB_FUSE_SET,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "RPMB fuse is set. Cannot commit FPFs."
       },
    {
        FWU_ERROR_PCHC_MISSING_UPDATE,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "PCHC partition is not in the Update Image."
       },
    {
        MEMANUF_ERROR_EOL_MISMATCH_UEP_HW,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Mismatch between FPF UEP and HW values."
    },
    {
        FWU_SMALL_BUFFER,
        {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
        "Invalid Update Image length, size is smaller than required."
    },
    {
        FWU_CORRUPTED,
       {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
       "The internal structure of the Update Image is corrupted."

    },
    {
        FWU_FULL_INVALID,
       {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
       "Update Image has wrong structure for Full Update operation."
    },
    {
        FWU_PARTIAL_INVALID,
       {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
       "Update Image has wrong structure for Partial Update operation."
    },
    {
        FWU_MANDATORY_INVALID,
       {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
       "Mandatory partitions (FTPR / NFTP / RBEP) were not found in the Update Image."
    },
    {
        FWU_MAX_IUP_ERROR,
       {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
       "Number of IUPs in " MAKE_STR(FW_STR) " exceeds allowed maximum."
    },
    {
        MEMANUF_ERROR_CFG_FILE_UNKNOWN_TEST,
       {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
       "Invalid config file. Unknown test name found - %s."
    },
    {
        FWU_MAN_NOT_FOUND,
       {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
       "Missing a required partition manifest in the Update Image."
    },
    {
        FWU_EXT_NOT_FOUND,
       {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
       "Missing a required partition manifest extension in the Update Image."
    },
    {
        VAR_INVALID_DATA_SIZE,
       {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
       "The VAR invalid data size."
    },
    {
        FWU_ALLOCATED_BUFFER_SMALL,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update Image size exceeds allocated buffer."
    },
    {
        FWU_FWSTS_REG,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       MAKE_STR(FW_STR) " failed to read FWSTS register."
    },
    {
        FWU_FW_READ_FILE_FAIL,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Firmware update failed due to an internal error\nRead file failed."
    },
    {
        FWU_PG_IN_PROGRESS,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Firmware update failed due to an internal error 518."
    },
    {
        FWU_ALLOWSV_RS_MISSING,
       {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
       "Full " MAKE_STR(FW_STR) " Update using same version is not allowed. Include /s in command line to allow it."
    },
    {
        ICC_INVALID_MPHY_LENGTH,
       {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
       "Invalid MPHY length."
    },
    {
        FWU_FW_ISH_CFG,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       MAKE_STR(FW_STR) " failed to set ISH configuration file."
    },
    {
        ERROR_LAN_PCIE_NOT_READY,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "PCIe connectivity failure. Unable to connect to vPro NIC through designated bus."
    },
    {
        ERROR_LAN_SMBUS_NOT_READY,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "SMBUS connectivity failure. Unable to connect to vPro NIC through designated bus."
    },
    {
        ERROR_EDP_LSPCON_VALUES_OVERLAP,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Conflict in OEM Data: Overlapping values of LSPCON Port Config and eDP Port Config found."
    },
    {
        ERROR_SRV_FQDN_INVALID_VALUE,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Invalid configuration server FQDN value."
    },
    {
        NVAR_MCA_WRONG_HOST_FQDN,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Invalid host FQDN file."
    },
    {
        NVAR_MCA_WRONG_GPIO_OWN_MODE,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "One or more GPIO pads provided in file have invalid ownership mode set."
    },
    {
        NVAR_MCA_WRONG_GPIO_PAD_MODE,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "One or more GPIO pads provided in file have invalid pad mode set."
    },
    {
        NVAR_MCA_WRONG_GPIO_FEATURE_IN_USE,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Two or more GPIO pads provided in file have same feature field value set."
    },
    {
        NVAR_MCA_WRONG_GPIO_FEATURE,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "One or more GPIO pads provided in file have invalid feature field value set."
    },
    {
        NVAR_MCA_WRONG_CERT_HASH_VALUE,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Invalid cert hash file."
    },
    {
        NVAR_MCA_WRONG_HOST_FQDN_DOMAIN,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Invalid host FQDN domain name."
    },
    {
        NVAR_MCA_WRONG_HOST_FQDN_HOSTNAME,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Invalid host FQDN hostname."
    },
    {
        ERROR_UPID_PSR_CONFIGURATION,
       {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
       "Invalid configuration between UPID and PSR NVARs."
    },
    {
        NVAR_MCA_POLICY_SYSINTID_WRONG_DATA,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "ODM ID \\ System Integrator ID \\ Reserved ID: invalid value."
    },
    {
        NVAR_MCA_WRONG_GPIO_PAD_ADDR_PARAM,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "One or more GPIO pads provided in file have invalid pad address set (group / pad number)."
    },
    {
        NVAR_MCA_WRONG_GPIO_PAD_ADDR_IN_USE,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Two or more GPIO pads provided in file have same pad address set."
    },
    {
        NVAR_MCA_PRE_PROV_INVALID_STATE,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "AMT is provisioned. Updating AMT vars at this stage is not supported."
    },
    {
        NVAR_MCA_EHBC_STATE_PRIV_LEVEL_MISMATC,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Unsupported combination of EHBC state and privacy level files."
    },
    {
        FWU_ERROR_FWSTS_INVALID,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       MAKE_STR(CSE_STR) " is in Recovery Mode but FWSTS registers report Normal Mode."
    },
    {
        FWU_ERROR_BURN_INVALID,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "The Flash Image that was burned on the platform was corrupted. " MAKE_STR(CSE_STR) " is in Recovery Mode at first boot."
    },
    {
        FPROG_CLEAR_HASH_ERROR,
       {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
       "Clear option is not supported for Hashed vars."
    },
    {
        FWU_ERROR_NVM_COMPAT_FTPR,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update FTPR must have the same NVM compatibility (SPI/UFS) as Flash FTPR."
    },
    {
        ICC_FW_ERROR_INCORRECT_API_VERSION,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Incorrect API version."
    },
    {
        FWU_ERROR_NVM_COMPAT_RBEP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update RBEP must have the same NVM compatibility (SPI/UFS) as Flash RBEP."
    },
    {
        FWU_ERROR_NVM_COMPAT_NFTP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update NFTP must have the same NVM compatibility (SPI/UFS) as Flash NFTP."
    },
    {
        FWU_ERROR_NVM_COMPAT_IUP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update IUP must have the same NVM compatibility (SPI/UFS) as Flash IUP."
    },
    {
        ICC_FW_ERROR_FLASH_WEAR_OUT_VIOLATION,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Flash wear out violation."
    },
    {
        ICC_FW_ERROR_FLASH_CORRUPTION,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Flash corruption."
    },
    {
        ICC_FW_ERROR_PROFILE_NOT_SELECTABLE_BY_BIOS,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Profile is not selectable in BIOS."
    },
    {
        ICC_FW_ERROR_TOO_LARGE_PROFILE_INDEX,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Profile index is too large."
    },
    {
        ICC_FW_ERROR_NO_SUCH_PROFILE_IN_FLASH,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "No such profile in flash."
    },
    {
        ICC_FW_ERROR_CMD_NOT_SUPPORTED_AFTER_END_OF_POST,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Command is not supported after EOP."
    },
    {
        ICC_FW_ERROR_NO_SUCH_RECORD,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "No such record."
    },
    {
        ICC_FW_ERROR_FILE_NOT_FOUND,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "File not found."
    },
    {
        ICC_FW_ERROR_INVALID_RECORD_FORMAT,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Invalid record format."
    },
    {
        ICC_FW_ERROR_TOO_LARGE_UOB_RECORD,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "UOB record is too large."
    },
    {
        ICC_FW_ERROR_CLOCK_NOT_CONFIGURABLE,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Clock is not configurable"
    },
    {
        ICC_FW_ERROR_REGISTER_IS_LOCKED,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Register is locked."
    },
    {
        ICC_FW_ERROR_NO_VALID_PRE_UOB,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "No valid PRE UOB."
    },
    {
        ICC_FW_ERROR_NO_VALID_PERM_UOB,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "No valid PERM UOB."
    },
    {
        ICC_FW_ERROR_NO_DATA_FOR_THIS_CLOCK,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "No data for this clock."
    },
    {
        ICC_FW_ERROR_PROFILE_INDEX_IS_CURRENT,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Profile index is current."
    },
    {
        ICC_FW_ERROR_NO_BCLK_ADJUSTMENT_FOUND,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "No bclk adjustment found."
    },
    {
        ICC_FW_ERROR_WARM_RESET_RAMP_NOT_SUPPORTED,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Warm reset ramp is not supported."
    },
    {
        ICC_FW_ERROR_UOB_RECORD_IS_ALREADY_INVALID,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "UOB record is already invalid."
    },
    {
        ICC_FW_ERROR_NO_PROFILES_EXIST,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "No profile exists."},
    {
        ICC_FW_ERROR_AUTH_FAILURE,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Authentication failure."
    },
    {
        ICC_FW_ERROR_ERROR_READING_FILE,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Pending file."
    },
    {
        MEMANUF_ERROR_EOL_RPMB_REBINDING_NOT_ALLOWED,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Replay protection rebinding of UFS device is not allowed."
    },
    {
        ICC_FW_ERROR_FREQ_TOO_HIGH,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Frequency is too high."
    },
    {
        ICC_FW_ERROR_PENDING_REVERT_TO_DEFAULT,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Pending to revert to default."
    },
    {
        ICC_FW_ERROR_PENDING_SET_PROFILE,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Pending to set profile."
    },
    {
        ICC_FW_ERROR_UNVALID_PROFILE,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Invalid profile"
    },
    {
        ICC_FW_ERROR_UNVALID_OEM_DATA,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Invalid OEM data."
    },
    {
        ICC_FW_ERROR_ERROR_READING_DYNAMIC_RECORD,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Failed to read dynamic record."
    },
    {
        MEMANUF_ERROR_EOL_RPMB_FATAL_ERROR,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Replay protection of UFS device reported fatal error."
    },
    {
        ICC_FW_ERROR_FREQ_TOO_LOW,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Frequency is too low."
    },
    {
        MEMANUF_ERROR_EOL_RPMB_FUSE_DISABLED,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Replay protection disablement fuse is set.\nRPMB manufacturing process is not complete."
    },
    {
        ICC_FW_ERROR_SSC_MODE_CHANGE_NOT_SUPPORTED,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "SSC mode change is not supported."
    },
    {
        ICC_FW_ERROR_RANGE_VIOLATION_SSC_TOO_HIGH,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Range Violation: SSC is too high."
    },
    {
        ICC_FW_ERROR_SURVIVABILITY_SYNC_DISABLED,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Survivability sync disabled."
    },
    {
        ICC_FW_ERROR_WARM_RESET_FREQ_TOO_LOW,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Warm reset required is too low."
    },
    {
        ICC_FW_ERROR_NO_SUCH_TARGET_ID,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Specified target ID does not exist."
    },
    {
        ICC_FW_ERROR_NO_SUCH_REGISTER,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Specified register does not exist."
    },
    {
        ICC_FW_ERROR_INVALIDATE_SUCCESSFUL,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Invalidate successful."
    },
    {
        MEMANUF_ERROR_EOL_RPMB_FUSE_RB_DISABLED,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Replay protection RB fuse is not set.\nRPMB manufacturing process is not complete."
    },
    {
        ICC_FW_ERROR_VALID_UOB_ALREADY_PRESENT,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Valid UOB already present."
    },
    {
        ICC_FW_ERROR_WAITING_FOR_POWER_CYCLE,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Waiting for power cycle."
    },
    {
        ICC_FW_ERROR_SURVIVABILITY_TABLE_ACCESS_VIOLATION,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Survivability table access violation."
    },
    {
        ICC_FW_ERROR_SURVIVABILITY_TABLE_TOO_LARGE,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Survivability table is too large."
    },
    {
        ICC_FW_ERROR_NO_SUCH_EID,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "EID does not exist."
    },
    {
        ICC_FW_ERROR_SUCCESS_TRANSLATE_ONLY,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Success translate only."
    },
    {
        ICC_FW_ERROR_PCIE_FAIL_READING_DATA,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Failure in reading PCIe Data."
    },
    {
        ICC_FW_ERROR_PCIE_FAIL_WRITING_DATA,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Failure in writing PCIe Data."
    },
    {
        ICC_FW_ERROR_PCIE_CONFIG_INVALID,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Invalid PCIe configuration data."
    },
    {
        ICC_FW_ERROR_CMD_NOT_SUPPORTED_BEFORE_DID,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "CMD not supported before DID."
    },
    {
        ICC_FW_ERROR_FIA_MUX_CONFIG_SKU_MISMATCH,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "FIA MUX error - max config sku mismatch."
    },
    {
        ICC_FW_ERROR_FIA_MUX_NO_CONFIG_FOUND,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "FIA MUX error - no config found."
    },
    {
        ICC_FW_ERROR_FIA_MUX_ERROR_GETTING_LANES_LIMIT,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "FIA MUX error - getting laned limit."},
    {
        ICC_FW_ERROR_FIA_MUX_ERROR_READING_CONF_FROM_FILE,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "FIA MUX error - reading configuration from file."
    },
    {
        ICC_FW_ERROR_FIA_MUX_ERROR_PROMPTING_TO_GLOBAL_RESET,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "FIA MUX error - prompting to global reset."
    },
    {
        ICC_FW_ERROR_FIA_MUX_INVALID_FIA_MUX_CONFIG,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Invalid FIA MUX configuration."
    },
    {
        ICC_FW_ERROR_FIA_MUX_ERROR_WRITING_CONF_TO_FILE,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "FIA MUX error - reading configuration to file."
    },
    {
        ICC_FW_ERROR_FIA_MUX_ERROR_READING_CONF_FROM_STRAPS,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "FIA MUX error - reading configuration from straps."
    },
    {
        ICC_FW_ERROR_MAX_BUNDLES_PER_RECORD_REACHED,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Max bundles record reached."
    },
    {
        ICC_FW_ERROR_PLL_UNSUPPORTED,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Specified PLL is not supported"
    },
    {
        ICC_FW_ERROR_DATA_ITEM_UNSUPPORTED,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Data item unsupported."
    },
    {
        ICC_FW_ERROR_OEM_PROFILE_CRDR_VIOLATION,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Oem profile card violation."
    },
    {
        MEMANUF_ERROR_EOL_RPMB_RB_DISABLED,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Replay protection rebinding is disabled.\nRPMB manufacturing process is not complete."
    },
    {
        ICC_SW_INVALID_BUF_LEN,
       {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
       "Invalid buffer length."
    },
    {
        ICC_SW_INVALID_ARG,
       {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
       "Invalid argument."
    },
    {
        AMT_IPV6_DISABLED,
       {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
       "AMT Ipv4 Interface is disabled."
    },
    {
        AMT_INTERFACE_DOES_NOT_EXIST,
       {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
       "Interface does not exists."
    },
    {
        NVAR_MCA_WRONG_UC_POLICY,

       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Invalid user consent policy file."

    },
    {
        FEAT_ARB_SVN_DISABLED,

       {CATEGORY_MEINFO_FEATURE_NOT_FOUND,        "Cannot find " MAKE_STR(ME_STR) "Info feature or feature is not supported."},
       "Anti Rollback SVN feature is disabled."

    },
    {
        INPUT_FILE_TOO_LARGE,

       {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
       "Input file is too big."

    },
    {
        MEMANUF_ERROR_EOL_PCHC_VERSIONCHECK,

       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "PCHC FW version mismatch, actual value is - %s"

    },
    {
        FWU_ERROR_ENGINEERING_PART,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update of partition between engineering build vs regular build is not allowed."

    },
    {
        ERROR_UNKNOWN_HW,

       {CATEGORY_UNSUPPORTED_HW,                  "Tool isn't compatible with current HW or current HW environment isn't supported."},
       "Unknown hardware platform."

    },
    {
        ERROR_UNSUPPORTED_HW,

       {CATEGORY_UNSUPPORTED_HW,                  "Tool isn't compatible with current HW or current HW environment isn't supported."},
       "Unsupported hardware platform. %s"

    },
    {
        ERROR_CFG_FILE_CONTAINS_DUPLICATES,

       {CATEGORY_USER_INPUT_FILE_ERROR,           "User input file (xml, cfg or text) format or content error."},
       "Input configurable file contains cse file name duplicates."
    },
    {
        FWU_ERROR_API_VER_MAJOR_ISIF,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "ISIF must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."

    },
    {
        FWU_ERROR_INTEGRITY_FAILED_ISIF,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "ISIF partition hash and calculated hash are not the same. If partition hash is zero - wrong MEU Tool was used to create the partition."

    },
    {
        FWU_ERROR_GET_EXT_FAILED_ISIF,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Some manifest extension is missing in ISIF. Wrong MEU Tool was used to create the partition."

    },
    {
        FWU_ERROR_VER_MAN_FAILED_ISIF,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Loader failed to verify manifest signature of ISIF."

    },
    {
        HTM_COMMAND_EXEC_ERROR,

       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Failed to enable DAM. Hotham generic execution error is expected when booting on disabled mode."

    },
    {
        ERROR_NON_INITALIZED_NVAR_FILE,

       {CATEGORY_CSE_FILE_COMPARE_GENERAL_ERROR,  "CSE File compare error."},
       "Compare value with non-initialized NVAR file."

    },
    {
        ME_DISABLED,

       {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
       MAKE_STR(ME_STR) " disabled."

    },
    {
        UNKNOWN_GFX_BDF,

       {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
       "GFX device with provided ID is not found."

    },
    {
        FWU_ERROR_FW_TYPE_FTPR,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update FTPR must have the same " MAKE_STR(FW_STR) " Type and Sub-Type as Flash FTPR."

    },
    {
        FWU_ERROR_API_VER_MAJOR_SAMF,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "SAMF must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."

    },
    {
        FWU_ERROR_INTEGRITY_FAILED_SAMF,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "SAMF partition hash and calculated hash are not the same. If partition hash is zero - wrong MEU Tool was used to create the partition."

    },
    {
        FWU_ERROR_GET_EXT_FAILED_SAMF,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Some manifest extension is missing in SAMF. Wrong MEU Tool was used to create the partition."

    },
    {
        FWU_ERROR_VER_MAN_FAILED_SAMF,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Loader failed to verify manifest signature of SAMF."

    },
    {
        FWU_ERROR_API_VER_MAJOR_PPHY,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "PPHY must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."

    },
    {
        FWU_ERROR_INTEGRITY_FAILED_PPHY,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "PPHY partition hash and calculated hash are not the same. If partition hash is zero - wrong MEU Tool was used to create the partition."

    },
    {
        FWU_ERROR_GET_EXT_FAILED_PPHY,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Some manifest extension is missing in PPHY. Wrong MEU Tool was used to create the partition."

    },
    {
        FWU_ERROR_VER_MAN_FAILED_PPHY,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Loader failed to verify manifest signature of PPHY."

    },
    {
        FPROG_ERROR_READ_SPI_DATA,

       {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
       "An error occurred reading flash data."

    },
    {
        MEMANUF_ERROR_EOL_UPID_OEM_ID_EMPTY,

       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "UPID feature is supported while OEM ID FPF was not set."

    },
    {
        ICC_SW_UNSUPPORTED,

       {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
       "This command is not supported on SPS platforms."

    },
    {
        FWU_ERROR_API_VER_MAJOR_GBST,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "GBST must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."

    },
    {
        FWU_ERROR_INTEGRITY_FAILED_GBST,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "GBST partition hash and calculated hash are not the same. If partition hash is zero - wrong MEU Tool was used to create the partition."

    },
    {
        FWU_ERROR_GET_EXT_FAILED_GBST,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Some manifest extension is missing in GBST. Wrong MEU Tool was used to create the partition."

    },
    {
        FWU_ERROR_VER_MAN_FAILED_GBST,

       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Loader failed to verify manifest signature of GBST."

    },
    {
        MEMANUF_ERROR_EOL_UPID_OEM_PLAT_ID_EMPTY,

       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "UPID OEM platform ID is set to zero."

    },
    {
        MEMANUF_ERROR_EOL_AMT_HW_NVAR,

       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "[Intel(R) Manageability Hardware Status FPF] is set to disabled, but NVAR [Intel(R) AMT Supported] is enabled."
    },
    {
        MEMANUF_ERROR_EOL_AMT_HW_EFS,

       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "[Intel(R) Manageability Hardware Status FPF] is set to disabled, but [Intel(R) Manageability Hardware Status NVAR] is enabled."

    },
    {
        ICC_FW_ERROR_SURVIVABILITY_TABLE_REJECTED_BY_PMC,

       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "PMC rejected MPHY table."
    },
    {
        ERROR_LAN_I2C_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "LAN I2C protocol failure."
    },
    {
        ERROR_IPL_BIST_STATUS_UNDEFINED,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading test is undefined."
    },
    {
        ERROR_IPL_BIST_STATUS_MEM_ERROR,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading test memory error."
    },
    {
        ERROR_IPL_BIST_STATUS_DISABLED,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading test is disabled."
    },
    {
        ERROR_IPL_BIST_STATUS_GENERIC_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading test generic error."
    },
    {
        ERROR_IPL_BIST_STATUS_LOAD_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading test failed to load."
    },
    {
        ERROR_IPL_BIST_STATUS_VERIFY_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading test verification failure."
    },
    {
        ERROR_IPL_BIST_STATUS_READ_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading test reading failure."
    },
    {
        ERROR_IPL_BIST_STATUS_HW_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading test hardware failure."
    },
    {
        ERROR_ISH_BIST_STATUS_UNDEFINED,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading ISH test is undefined."
    },
    {
        ERROR_ISH_BIST_STATUS_MEM_ERROR,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading ISH test memory error."
    },
    {
        ERROR_ISH_BIST_STATUS_DISABLED,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading ISH test is disabled."
    },
    {
        ERROR_ISH_BIST_STATUS_GENERIC_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading ISH test generic error."
    },
    {
        ERROR_ISH_BIST_STATUS_LOAD_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading ISH test loading failure."
    },
    {
        ERROR_ISH_BIST_STATUS_VERIFY_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading ISH test verifying failure."
    },
    {
        ERROR_ISH_BIST_STATUS_READ_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading ISH test reading failure."
    },
    {
        ERROR_ISH_BIST_STATUS_HW_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "IP Loading ISH test hardware failure."
    },
    {
        FWU_ERROR_UNLOCK,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       MAKE_STR(CSE_STR) " is in Unlocked Mode. FW Update is not possible."
    },
    {
        MEMANUF_ERROR_EOL_SAMF_PPHY_PRESENCE,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "SAM and PPHY sub-partitions are not present."
    },
    {
        MEMANUF_ERROR_EOL_SAMF_PRESENCE,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "SAM sub-partition is not present."
    },
    {
        MEMANUF_ERROR_EOL_PPHY_PRESENCE,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "PPHY sub-partition is not present."
    },
    {
        MEMANUF_ERROR_EOL_ATTR_KB_EMPTY,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Attestation KeyBox NVAR is empty."
    },
    {
        ATTKB_FILE_SIZE_ERROR,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Attestation KeyBox file size invalid."
    },
    {
        ATTKB_FILE_DATA_INVALID_ERROR,
       {CATEGORY_CSE_FILE_READ_ERROR,             "CSE File read error."},
       "Attestation KeyBox file data is invalid."
    },
    {
        ATTKB_NOT_PROVISIONED,
       {CATEGORY_KEYBOX_INVALID_STATUS,           "Invalid Keybox response status."},
       "Attestation KeyBox is not provisioned."
    },
    {
        NVAR_MCA_WRONG_SEAL_POLICY,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Invalid value for Signing Policy."
    },
    {
        NVAR_MCA_WRONG_RESEAL_TIMEOUT,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "Invalid value for Reseal Timeout."
    },
    {
        READ_PCI_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Read PCI failed."
    },
    {
        WRITE_PCI_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Write PCI failed."
    },
    {
        READ_MMIO_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Read MMIO failed."
    },
    {
        WRITE_MMIO_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Write MMIO failed."
    },
    {
        REBOOT_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Reboot failed."
    },
    {
        SPI_MMIO_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Get SPI MMIO failed."
    },
    {
        EXTRACT_RES_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Extracting driver resource failed."
    },
    {
        TEMP_FOLDER_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Creating temporary folder for driver installation failed."
    },
    {
        DRIVER_PATH_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Creating path for driver installation failed."
    },
    {
        WOW64_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Handling WOW64 redirection for driver installation failed."
    },
    {
        DELETE_DRIVER_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Failed to delete driver files when uninstalling."
    },
    {
        DRIVER_CREATE_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Creating driver failed."
    },
    {
        DRIVER_START_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Starting driver failed."
    },
    {
        DRIVER_STOP_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Stopping driver failed."
    },
    {
        DRIVER_REMOVE_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Removing driver failed."
    },
    {
        DRIVER_OPERATION_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Driver operation failed."
    },
    {
        WDF_INSTALLER_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "WDF installer failure."
    },
    {
        DRIVER_INSTALL_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Driver installation failed."
    },
    {
        DRIVER_UNINSTALL_FAILURE,
       {CATEGORY_PCI_ACCESS_ERROR,                "Unable to access PCI device with read/write error."},
       "Uninstalling driver failed."
    },
    {
        RESERVED_FILE_NAME,
       {CATEGORY_IO_ERROR,                        "Failed to open, read, write or close used for program execution or user file."},
       "The given file name is a reserved name by OS."
    },
    {
        SVN_MISMATCH,
       {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
       "Minimum allowed ARB SVN do not match executing ARB SVN."
    },
    {
        MEMANUF_ERROR_EOL_GLITCH_DETECTION_DISABLED,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "HW Glitch Detection is Disabled."
    },
    {
        MEMANUF_ERROR_EOL_GLITCH_DETECTION_ENABLED,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "HW Glitch Detection is Enabled."
    },
    {
        MEMANUF_ERROR_EOL_PLATFORM_BINDING_STATUS_ENABLED,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Platform Binding Status is Enabled."
    },
    {
        MEMANUF_ERROR_EOL_PLATFORM_BINDING_STATUS_DISABLED,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Platform Binding Status is Disabled."
    },
    {
        MANUF_ERROR_EOL_MRC_INIT_STATUS,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "MRC initialization failed."
    },
    {
        MANUF_ERROR_EOL_GFX_FW_VERSION,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       MAKE_STR(FW_STR) " version mismatch."
    },
    {
        MANUF_ERROR_HDA_CONTROLLER_INIT_STATUS,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Error in HDA initialization."
    },
    {
        MANUF_ERROR_MASTER_ACCESS_PERMISSIONS_CHECK,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Master access permissions don't match Intel recommended values."
    },
    {
        MANUF_ERROR_EOL_OPROM_VERSION,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "OPROM version mismatch."
    },
    {
        ERROR_GFX_BIST_STATUS_FID_NOT_REACHED,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "GFX FID not reached."
    },
    {
        ERROR_GFX_BIST_STATUS_FATAL_ERROR_OCCURED,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "GFX Fatal error occurred."
    },
    {
        ERROR_GFX_BIST_STATUS_FSP_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "GFX FSP failure occurred."
    },
    {
        ERROR_GFX_BIST_STATUS_CSE_RESET_ON_ERROR_OCCURED,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "GFX CSE reset on error occured."
    },
    {
        VERIFY_EOM_CONFIG_WRONG_SIZE,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "EOM config file size is incorrect."
    },
    {
        FWU_GSC_BP_COPY,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update of Boot Partition Copy failed."
    },
    {
        MANUF_EOL_VAR_WITHOUT_CONFIG,
       {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
       "EOL VAR requires config file to be provided."
    },
    {
        FWU_ERROR_INCOMPLETE_DATA,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "FWUpdate Data is shorter than the update image length."
    },
    {
        MANUF_EOL_EOM_NOT_SET,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Platform is in Manufacturing Mode."
    },
    {
        MEMANUF_ERROR_EOL_UPID_NOT_SUPPORTED,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "UPID feature is not supported."
    },
    {
        UPID_MAX_COUNTER_EXCEEDED,
       {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
       "UPID Refurbish counter can be increment only 5 times."
    },
    {
        UPID_INVALID_INPUT_PARAMETER,
       {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
       "invalid parameter."
    },
    {
        MEMANUF_ERROR_EOL_EOM_CFG_LOCKCHECK_NOT_EOM,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Platform is in Manufacturing Mode though NVAR Configuration State is Locked."
    },
    {
        MEMANUF_ERROR_SYSTEM_IS_EOP,
       {CATEGORY_MEMANUF_OPERATION_FAILED,        MAKE_STR(ME_STR) "Manuf operation failed."},
       "Intel(R) " MAKE_STR(ME_STR) " is in End Of Post state."
    },
    {
        MEMANUF_ERROR_EOL_FLASHLOCKCHECK_NOT_EOM,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Platform is in Manufacturing Mode though Flash Protection Mode is set to Protected."
    },
    {
        FPT_FPF_AMT_ENABLED,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "It is not allowed to disable [Intel(R) Manageability Hardware Status FPF] when NVAR [Intel(R) Manageability HW Status] is set to enabled."
    },
    {
        HECI_COMMAND_NOT_SUPPORTED,
       {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
       "Intel (R) " MAKE_STR(ME_STR) " Interface : Message type is not supported by " MAKE_STR(FW_STR) "."
    },
    {
        MKHI_COMMAND_GENERAL_ERROR,
       {CATEGORY_HECI_COMMUNICATION_FAILURE,      "HECI device API failure (possible open, IO, read, write, or close APIs)."},
       "Intel (R) " MAKE_STR(ME_STR) " Interface : " MAKE_STR(FW_STR) " failed for invalid input or general error."
    },
    {
        FWU_ERROR_SKU_MISMATCH,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update to incompatible FW type: Consumer / Corporate or other."
    },
    {
        MEMANUF_ERROR_EOL_UPID_OEM_PLAT_ID_NOT_SET,
       {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "UPID OEM Platform ID is not set."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_PSEP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Loader failed to verify manifest signature of PSEP."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_PSEP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Some manifest extension is missing in PSEP. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_PSEP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "PSEP partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_API_VER_MAJOR_PSEP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "PSEP must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        MULTIPLE_GFX_SETUP_ERROR,
       {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature."},
       "Current GFX setup has more than 1 device. Missing -Device command line parameter"
    },
    {
        D3_AWAKE_FAILED,
       {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
       "Failed to wake up GfxFW."
    },
    {
        D3_RELEASE_FAILED,
       {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
       "Failed to release GfxFW."
    },
    {
        DISPLAY_LIB_NOT_INIT,
       {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
       "The display library is not initialized."
    },
    {
        FILE_STREAM_NOT_INIT,
       {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
       "The file stream is not initialized."
    },
    {
        FAILED_TO_INIT_DISPLAY_LIB,
       {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
       "Failed to initialized display library."
    },
    {
        FILE_SCREEN_STREAMS_NOT_INIT,
       {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
       "The screen  and file streams are not initialized."
    },
    {
        INVALID_SOFTSTRAP_NAME,
       {CATEGORY_SOFTSTRAP_INVALID_INPUT_VALUE,   "Invalid update value provided for SoftStrap update."},
       "The softStrap Component requested, softStrap Name is not valid for this operation."
    },
    {
        INVALID_SOFTSTRAP_VALUE,
       {CATEGORY_SOFTSTRAP_INVALID_INPUT_VALUE,   "Invalid update value provided for SoftStrap update."},
       "Invalid value for this softStrap."
    },
    {
        SOFTSTRAP_NOT_UPDATEABLE,
       {CATEGORY_SOFTSTRAP_UPDATE_ERROR,          "SoftStrap write or update error."},
       "The \"%s\" softStrap is not updatable."
    },
    {
        SOFTSTRAP_NOT_SUPPORTED_ON_SKU,
       {CATEGORY_SOFTSTRAP_UPDATE_ERROR,          "SoftStrap write or update error."},
       "This softStrap is not supported on this SKU."
    },
    {
        SS_DEP_SUPPORT_FAILED_VAR,
       {CATEGORY_SOFTSTRAP_UPDATE_ERROR,          "SoftStrap write or update error."},
       "This softStrap is not supported on this platform."
    },
    {
        AMT_PROHIBIT_SHA1_HASH,
       {CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,    "Invalid update value provided for NVAR or FPF."},
       "SHA1 is not supported."
    },
    {
        ERROR_CHASSIS_BIST_STATUS_UNDEFINED,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "Chassis test is undefined."
    },
    {
        ERROR_CHASSIS_BIST_STATUS_GENERIC_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "Chassis test generic error."
    },
    {
        ERROR_CHASSIS_BIST_STATUS_LOAD_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "Chassis test failed to load."
    },
    {
        ERROR_CHASSIS_BIST_STATUS_VERIFY_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "Chassis test verification failure."
    },
    {
        ERROR_CHASSIS_BIST_STATUS_READ_FAILURE,
       {CATEGORY_MEMANUF_BIST_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf BIST test failed."},
       "Chassis test reading failure."
    },
    {
        ICC_SDK_BCLK_IS_NOT_SUPPORTED,
       {CATEGORY_ICC_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error on ICC command."},
       "Base clock setting is not supported."
    },
    {
        AMT_ERROR_DISABLE_NETWORK_SERVICES,
       {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
       "It is not allowed to disable [Intel(R) Network Services Supported] while other manageability configurations are enabled"
    },
    {
       FWU_ERROR_VER_MAN_FAILED_ADSP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Loader failed to verify manifest signature of ADSP."
    },
    {
       FWU_ERROR_GET_EXT_FAILED_ADSP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Some manifest extension is missing in ADSP. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_ADSP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "ADSP partition hash and calculated hash are not the same.\nIf partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_API_VER_MAJOR_ADSP,
       {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "ADSP must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update, in the Flash Image for Partial Update."
    },
    {
        SAVE_MAC_SXID_CORPORATE_ONLY,
       {CATEGORY_INVALID_CLI_OPTIONS,             "Invalid CLI parameters."},
       "SaveMac and SaveXID command are supported on Corporate sku only"
    },
    {
        NVAR_INVALID_LSPCON_PORT_COUNT,
           {CATEGORY_CSE_FILE_UPDATE_ERROR,       "CSE File write or update error."},
      "PAVP oem config data: invalid lspcon port count."
    },
    {
        FWU_HECI_CLIENT_UNMAPPED_ERROR,
           {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
      "Internal Error - FW Update HECI client unmapped status."
    },
    {
        MCA_HECI_CLIENT_UNMAPPED_ERROR,
           {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
      "Internal Error - MCA HECI client unmapped status."
    },
    {
        HCDP_PAVP_HECI_CLIENT_UNMAPPED_ERROR,
           {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
      "Internal Error - HCDP/PAVP HECI client unmapped status."
    },
    {
        HCI_HECI_CLIENT_UNMAPPED_ERROR,
           {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
      "Internal Error - HCI HECI client unmapped status."
    },
    {
        HOTHAM_HECI_CLIENT_UNMAPPED_ERROR,
           {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
      "Internal Error - HOTHAM HECI client unmapped status."
    },
    {
        ICC_FIXED_HECI_CLIENT_UNMAPPED_ERROR,
           {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
      "Internal Error - ICC Fixed HECI client unmapped status."
    },
    {
        AMT_HECI_CLIENT_UNMAPPED_ERROR,
           {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
      "Internal Error - AMT HECI client unmapped status."
    },
    {
        UPID_HECI_CLIENT_UNMAPPED_ERROR,
           {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
      "Internal Error - UPID HECI client unmapped status."
    },
    {
        UNKNOWN_HECI_CLIENT_GUID,
           {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
      "Internal Error - Unknown HECI client unmapped status."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_OUT_OF_RESOURCES,
           {CATEGORY_FWU_FW_ERROR,                MAKE_STR(FW_STR) " returned an error during the FWU process."},
      "Resource allocation error."
    },
    {
        MPHY_TABLE_DONT_EXIST,
           {CATEGORY_WARNING,                         "Passed with warnings."},
      "Retrieving MPHY table data is not possible as table does not exist in the IFWI."
    },
    {
        VERIFY_WRONG_ALG_SET,
           {CATEGORY_CSE_FILE_UPDATE_ERROR,            "CSE File write or update error."},
      "Wrong PTT disabled Algorithms set."
    },
    {
        FPT_FPF_AMT_DISABLED,
           {CATEGORY_CSE_FILE_UPDATE_ERROR,            "CSE File write or update error."},
      "It is not allowed to enable NVAR [Intel(R) AMT Supported] when [Intel(R) Manageability Hardware Status FPF] is set to disabled."
    },
    {
        NO_GFX_DEVICES,
           {CATEGORY_INVALID_USER_INPUT,              "Invalid user parameter for specified tool feature." },
      "Gfx device not found, please check device is connected."
    },
    {
        COMMIT_FVC_FAILED,
           {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error." },
      "Commit Firmware Version Control SVN failed."
    },
    {
        ERROR_CONFIRM_FVC_SVN,
           {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
       "Minimum FVC SVN value set on current platform does not match corresponding FVC SVN in " MAKE_STR(FW_STR) " image."
    },
    {
        FWU_ERROR_FVC_TCB_ARB,
           {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update to higher TCB SVN must be also to higher FVC SVN."
    },
    {
        FEAT_FVC_SVN_DISABLED,
           {CATEGORY_MEINFO_FEATURE_NOT_FOUND,        "Cannot find " MAKE_STR(ME_STR) "Info feature or feature is not supported."},
       "Firmware Version Control SVN feature is disabled."

    },
    {
        FVC_SVN_MISMATCH,
           {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
       "Minimum allowed ARB SVN do not match executing ARB SVN."
    },
    {
        FWU_LOWER_FVC_SVN,
           {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
       "Update to Image with lower FVC SVN is not allowed."
    },
    {
        MESSAGING_LIBRARY_MISSING_FORMAT_STRING,
           {MESSAGING_LIBRARY,                         "Messaging Library."},
       "Missing format string for this message."
    },
    {
        MESSAGING_LIBRARY_INCORRECT_PARAMETER,
           {MESSAGING_LIBRARY,                         "Messaging Library."},
       "Incorrect Messaging API parameter."
    },
    {
        MANUF_ERROR_EOL_HDAS_VENDOR_ID,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "HD Audio Subsystem Vendor ID test failed."
    },
    {
        MANUF_ERROR_EOL_HDAS_DEVICE_ID,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "HD Audio Subsystem Device ID test failed."
    },
    {
        MANUF_ERROR_EOL_GIS_VENDOR_ID,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "GT Subsystem Vendor ID test failed."
    },
    {
        MANUF_ERROR_EOL_GIS_DEVICE_ID,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "GT Subsystem Device ID test failed."
    },
    {
        FWU_ERROR_KM_LOWER_SVN,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "It is not allowed to update to an image with OEM or RoT Key Manifest that contains ARB SVN for a partition, that is lower than its ARB SVN inside the OEM or RoT Key Manifest in the flash."
    },
    {
        FWU_ERROR_IUP_KM_SVN,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "It is not allowed to update to a partition with ARB SVN that is lower than its ARB SVN in OEM or RoT Key Manifest."
    },
    {
        MANUF_ERROR_EOL_PSR_EMPTY,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,        MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "One or more empty PSR Genesis records."
    },
    {
        PSR_HECI_CLIENT_UNMAPPED_ERROR,
        {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
        "Internal Error - PSR HECI client unmapped status."
    },
    {
        ERROR_PSR_NOT_ALLOWED,
        {CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,    "Tool feature execution failed with general error."},
        "PSR log is already started."
    },
    {
        ERROR_SPI_RECOVERY_DESC_ACCESS,
        {CATEGORY_SPI_ACCESS_ERROR,                "Unable to access SPI device with read/write error."},
        "Direct access to SPI Descriptor region recovery area address space is forbidden."
    },
    {
        PSR_NOT_SUPPORTED,
        {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
        "PSR is not supported."
    },
    {
        PSR_NOT_STARTED,
        {CATEGORY_INTERNAL_ERROR,              "Internal tool execution error."},
        "PSR not started yet."
    },
    {
        FWU_RECOVERY_IMAGE_FAILURE,
        {CATEGORY_FWU_RECOVERY_IMAGE_ERROR,              "FWU Recovery Image Failure."},
        "Recovery Image Failure."
    },
    {
        FWU_ERROR_GET_RECOVERY_NOT_ALLOWED,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Get Recovery Image is not allowed, because " MAKE_STR(FW_STR) " Update is in progress. (The regular FW Update will continue)."
    },
    {
        FWU_ERROR_GET_RECOVERY_FLASH_IN_RECOVERY,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Recovery Image was requested, but it is not allowed because " MAKE_STR(CSE_STR) " is in Recovery Mode."
    },
    {
        FWU_ERROR_GET_RECOVERY_ALREADY_STARTED,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Get Recovery Image is not allowed, because a previous Get Recovery operation already started.\nBoth operations will be aborted. (Get Recovery Image can be started again after this)."
    },
    {
        FWU_ERROR_GET_RECOVERY_NOT_STARTED,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "FWU_GET_RECOVERY_IMAGE_DATA was received without FWU_GET_RECOVERY_IMAGE_INFO before it."
    },
    {
        FWU_ERROR_GET_RECOVERY_OFFSET_INVALID,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "The offset in FWU_GET_RECOVERY_IMAGE_DATA request is not as expected."
    },
    {
        FWU_ERROR_GET_RECOVERY_AFTER_EOP,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Get Recovery Image to buffer command is not supported after EOP."
    },
    {
        FWU_ERROR_RECOVERY_IMAGE_FAILURE,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Firmware update failed due to an internal error 801."
    },
    {
        FWU_ERROR_DMA_FAILURE,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Failed to configure or access the DMA buffer."
    },
    {
        FWU_ERROR_DMA_BUFFER_NOT_ALIGNED,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "The address or size of the DMA buffer are not aligned to 4 KB."
    },
    {
        FWU_ERROR_EPS_LICENSE,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Sufficient Extended Platform Service license was not installed."
    },
    {
        FWU_ERROR_PV_BIT_MISMATCH,
        {CATEGORY_FWU_FW_ERROR,                   MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Update to a partition with PV bit OFF on Revenue platform is not allowed."
    },
    {
        GFX_LINUX_MTD_DEVICE_BAD_CONFIG,
        {CATEGORY_INVALID_USER_INPUT,                  "Internal tool execution error."},
        "MTD device is not loaded or not configured well. Please check kernel configuration."
    },
    {
        NVAR_MCA_NOT_ALLOWED,
        {CATEGORY_CSE_FILE_UPDATE_ERROR,           "CSE File write or update error."},
        "Operation is not allowed."
    },
    {
        MCA_FEAT_NOT_SUPPORTED,
        {CATEGORY_MEINFO_FEATURE_EXECUTION_ERROR,  MAKE_STR(ME_STR) "Info failed to execute specific feature."},
        "Feature is disabled."
    },
    {
        MCA_FEAT_GENERAL_ERROR,
        {CATEGORY_MEINFO_FEATURE_EXECUTION_ERROR,  MAKE_STR(ME_STR) "Info failed to execute specific feature."},
        "Unexpected error."
    },
    {
        FWU_ERROR_VER_MAN_FAILED_OPIM,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify manifest signature of OPIM."
    },
    {
        FWU_ERROR_GET_EXT_FAILED_OPIM,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Some manifest extension is missing in OPIM. Wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_INTEGRITY_FAILED_OPIM,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "OPIM partition hash and calculated hash are not the same. If partition hash is zero - wrong MEU Tool was used to create the partition."
    },
    {
        FWU_ERROR_API_VER_MAJOR_OPIM,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "OPIM must have the same major API version as the version inside the list in FTPR,\nin the Update Image for Full Update."
    },
    {
        FWU_ERROR_AAB_HASH,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify the manifest hash of a partition. The hash doesn't match the hash of the partition in OPIM."
    },
    {
        FWU_ERROR_OPIM_MAN_KM,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Loader failed to verify signature of OPIM manifest, during verifying Key Manifests."
    },
    {
        FWU_ERROR_OPIM_MISSING,
        {CATEGORY_FWU_FW_ERROR,                    MAKE_STR(FW_STR) " returned an error during the FWU process."},
        "Automotive Authorized Boot fuse is enabled, but OPIM partition is missing."
    },
    {
        MEMANUF_ERROR_EOL_ICPS_AND_ICM,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         MAKE_STR(ME_STR) "Manuf EOL test failed."},
        "Entitlement can't be set to both ICPS and ICM."
    },
    {
        FPT_INVALID_ICPS_AND_ICM_CONFIG,
        {CATEGORY_MEMANUF_EOL_TEST_FAILED,         "FPT NVAR update failed."},
        "Entitlement can't be set to both ICPS and ICM."
    },
    {
        ERROR_MCA_NO_PERMISSION,
        {CATEGORY_GENERAL_ERROR,                   "General error."},
        "Unable to perform request due to permission failure."
    },
    {
        ERROR_MCA_INVALID_MANIFEST_INPUT,
        {CATEGORY_GENERAL_ERROR,                   "General error."},
        "Unable to perform request due to invalid manifest input."
    },
    {
        ERROR_MCA_NOT_SUPPORTED_FOR_SETOEMHASHKEY,
        {CATEGORY_GENERAL_ERROR,                   "General error."},
        "Command is not supported on this platform."
    },
    {
        ERROR_CODES_COUNT,
           {CATEGORY_INTERNAL_ERROR,                  "Internal tool execution error."},
       ""
    }
};

/**
@brief  Return the error string matching the error id
@param[in]  errorId - Error Id enum
@return Error string
**/
const char* GetErrorString(const ErrorCodes errorId)
{
    if (ERROR_CODES_COUNT < (unsigned int)errorId)
    {
        // unexpected
        return gErrorList[INTERNAL_ERROR].Description;
    }

    return gErrorList[errorId].Description;
}

/**
@brief  Return the error category number matching the error id
@param[in]  errorId - Error Id enum
@return Error category number
**/
unsigned char GetErrorCategory(const ErrorCodes errorId)
{

    if (ARRAY_SIZE(gErrorList) <= (unsigned int)errorId)
    {
        // unexpected
        return gErrorList[INTERNAL_ERROR].Category.Id;
    }

    return gErrorList[errorId].Category.Id;
}

/**
 * \brief Returns description string associated with specific category
 * \param errorCategory
 * \return
 */
const char* GetErrorCategoryString(const ErrorCategories errorCategory)
{
    if (ARRAY_SIZE(gCategoriesList) <= errorCategory)
    {
        // unexpected
        return gCategoriesList[CATEGORY_INTERNAL_ERROR].Description;
    }

    return gCategoriesList[errorCategory].Description;
}
