/**
 * @file owerrors.h
 * @author Owasys
 * @date 03 Jan 2018
 * @brief File containing definitions for possible errors returned by Owasys libraries.
 *
 */
#ifndef __OWERRORS_H

   #define __OWERRORS_H

   #define NO_ERROR                                   0                          /**< All OK. */
   #define ERROR_NOT_IMPLEMENTED                      1                          /**< Function not yet implemented. */
   #define ERROR_IN_PARAMETERS                        2                          /**< Non-Valid Parameters */
   //*************    RTU Section
   #define RTUCONTROL_ERROR_BASE                      3                          /**< Base error index for RTUControl error codes. */
   #define ERROR_OPENING_PORT                         RTUCONTROL_ERROR_BASE + 0  /**< Error 3: Error when opening port. */
   #define ERROR_CLOSING_PORT                         RTUCONTROL_ERROR_BASE + 1  /**< Error 4: Error chen closing port. */
   #define ERROR_CREATING_NODE                        RTUCONTROL_ERROR_BASE + 2  /**< Error 5: Insuficient memory for creating Port node. */
   #define ERROR_UNDEFINED_NODE_STATUS                RTUCONTROL_ERROR_BASE + 3  /**< Error 6: Invalid status of port. */
   #define ERROR_INVALID_NODE                         RTUCONTROL_ERROR_BASE + 4  /**< Error 7: No valid port node passed to function. */
   #define ERROR_PORT_ALREADY_JOINED                  RTUCONTROL_ERROR_BASE + 5  /**< Error 8: Port already inserted in Select list. */
   #define ERROR_INSERTING_NODE                       RTUCONTROL_ERROR_BASE + 6  /**< Error 9: Error when inserting Port node in Select list. */
   #define ERROR_PORT_NOT_JOINED                      RTUCONTROL_ERROR_BASE + 7  /**< Error 10: Port not inserted in Select list. */
   #define ERROR_PORT_NOT_YET_CLOSED                  RTUCONTROL_ERROR_BASE + 8  /**< Error 11: Port not closed when trying to delete from Select list. */
   #define ERROR_RTUCONTROL_RESERVED                  RTUCONTROL_ERROR_BASE + 9  /**< Error 12: Invalid parameter passed to function. */
   #define ERROR_SELECT_ALREADY_RUNNING               RTUCONTROL_ERROR_BASE + 10 /**< Error 13: Select Control loop already running. */
   #define ERROR_SELECT_NOT_RUNNING                   RTUCONTROL_ERROR_BASE + 11 /**< Error 14: Select control loop not running. */
   #define ERROR_SELECT_LOOP_THREAD_CREATING          RTUCONTROL_ERROR_BASE + 12 /**< Error 15: Impossible to create Select control loop thread. */
   #define ERROR_SELECT_CLOSING_TIMEOUT               RTUCONTROL_ERROR_BASE + 13 /**< Error 16: Timeout reached when closing Select control loop thread. */
   #define ERROR_SELECT_LOOP_THREAD_CLOSING           RTUCONTROL_ERROR_BASE + 14 /**< Error 17: Impossible to close Select control loop thread. */
   #define ERROR_PORT_NOT_OPEN                        RTUCONTROL_ERROR_BASE + 15 /**< Error 18: Port not open. */
   #define ERROR_INVALID_FILE_DESCRIPTOR              RTUCONTROL_ERROR_BASE + 16 /**< Error 19: Invalid file descriptor assigned to port. */
   #define ERROR_INSUFICIENT_MEMORY                   RTUCONTROL_ERROR_BASE + 17 /**< Error 20: No available memory for a reservation. */
   #define ERROR_LAST_FREE_SIGNAL                     RTUCONTROL_ERROR_BASE + 18 /**< Error 21: Last free signal obtained. */
   #define ERROR_NO_FREE_SIGNALS_AVAILABLE            RTUCONTROL_ERROR_BASE + 19 /**< Error 22: No free signals are available in the system. */
   #define ERROR_RTUCONTROL_ALREADY_INITALIZED        RTUCONTROL_ERROR_BASE + 20 /**< Error 23: RTU Control already initialized. */
   #define ERROR_RTUCONTROL_NOT_INITALIZED            RTUCONTROL_ERROR_BASE + 21 /**< Error 24: RTU Control not yet initialized. */
   #define ERROR_RTUCONTROL_ALREADY_STARTED           RTUCONTROL_ERROR_BASE + 22 /**< Error 25: RTU Control already started. */
   #define ERROR_RTUCONTROL_NOT_STARTED               RTUCONTROL_ERROR_BASE + 23 /**< Error 26: RTU Control not yet started. */
   #define ERROR_OWA22XM_DRIVER_OPENING               RTUCONTROL_ERROR_BASE + 24 /**< Error 27: Error when opening OWA22X_M driver. */
   #define ERROR_OWA22XM_DRIVER_CLOSING               RTUCONTROL_ERROR_BASE + 25 /**< Error 28: Error when closing OWA22X_M driver. */
   #define ERROR_OWA22XM_DRIVER_ALREADY_OPENED        RTUCONTROL_ERROR_BASE + 26 /**< Error 29: OWA22X_M driver already opened. */
   #define ERROR_OWA22XM_DRIVER_NOT_OPENED            RTUCONTROL_ERROR_BASE + 27 /**< Error 30: OWA22X_M driver not opened. */
   #define ERROR_IN_COMMAND_CALL                      RTUCONTROL_ERROR_BASE + 28 /**< Error 31: Error when executing a device driver IOCTL command. */
   #define ERROR_PARTITION_NAME                       RTUCONTROL_ERROR_BASE + 29 /**< Error 32: Error in file type */
   #define ERROR_FILE_NAME                            RTUCONTROL_ERROR_BASE + 30 /**< Error 33: Error in file name */
   #define ERROR_BOOT_HEADER                          RTUCONTROL_ERROR_BASE + 31 /**< Error 34: Error in BootLoader Header */
   #define ERROR_OPENING_RTU_DRIVER                   RTUCONTROL_ERROR_BASE + 32 /**< Error 35: Error Opening PM driver */
   #define ERROR_CLOSING_RTU_DRIVER                   RTUCONTROL_ERROR_BASE + 33 /**< Error 36: Error Closing PM driver */
   #define ERROR_CALLING_RTU_DRIVER                   RTUCONTROL_ERROR_BASE + 34 /**< Error 37: Error Calling PM driver */
   #define ERROR_USECSLEEP_NOT_EXECUTED               RTUCONTROL_ERROR_BASE + 35 /**< Error 38: Error calling usecsleep function. */
   #define ERROR_OWA3X_FD_DRIVER_OPENING              RTUCONTROL_ERROR_BASE + 36 /**< Error 39: Error when opening owa3x_fd driver. */
   #define ERROR_OWA3X_FD_DRIVER_CLOSING              RTUCONTROL_ERROR_BASE + 37 /**< Error 40: Error when closing owa3x_fd driver. */
   #define ERROR_OWA3X_FD_DRIVER_ALREADY_OPENED       RTUCONTROL_ERROR_BASE + 38 /**< Error 41: owa3x_fd driver already opened. */
   #define ERROR_OWA3X_FD_DRIVER_NOT_OPENED           RTUCONTROL_ERROR_BASE + 39 /**< Error 42: owa3x_fd driver not opened. */
   #define ERROR_POWER_MANAGEMENT_NOT_WORKING         RTUCONTROL_ERROR_BASE + 40 /**< Error 43: Communication with the power managemnet unit not started. */
   #define ERROR_POWER_MANAGEMENT_NOT_ANSWER          RTUCONTROL_ERROR_BASE + 41 /**< Error 44: Not answer from power management unit. */
   #define ERROR_OWA3X_PM_DRIVER_NOT_OPENED           RTUCONTROL_ERROR_BASE + 42 /**< Error 45: owa3x_pm driver not opened. */
   #define ERROR_OWA3X_DIGITAL_INPUT                  RTUCONTROL_ERROR_BASE + 43 /**< Error 46: Impossible to read Digital Input. */
   #define ERROR_OWA3X_DIGITAL_OUTPUT                 RTUCONTROL_ERROR_BASE + 44 /**< Error 47: Impossible to set Digital Output. */
   #define ERROR_OWA3X_CFG_INPUT_INT                  RTUCONTROL_ERROR_BASE + 45 /**< Error 48: Impossible to config interrup for input. */
   #define ERROR_OWA3X_BAD_INPUT_NUM                  RTUCONTROL_ERROR_BASE + 46 /**< Error 49: Error in input number. */
   #define ERROR_OWA3X_BAD_OUTPUT_NUM                 RTUCONTROL_ERROR_BASE + 47 /**< Error 50: Error in Output number. */
   #define ERROR_OWA3X_ALREADY_CFG                    RTUCONTROL_ERROR_BASE + 48 /**< Error 51: Input already configured. */
   #define ERROR_OWA3X_INT_NOT_ENABLED                RTUCONTROL_ERROR_BASE + 49 /**< Error 52: Interrupt not enabled. */
   #define ERROR_OWA3X_BAD_PD_SELECT                  RTUCONTROL_ERROR_BASE + 50 /**< Error 53: Error in PD mask */
   #define ERROR_OWA3X_BAD_OUTPUT_VAL                 RTUCONTROL_ERROR_BASE + 51 /**< Error 54: Error in Output Value. */
   #define ERROR_EXPANSION_BOARD_NOT_WORKING          RTUCONTROL_ERROR_BASE + 52 /**< Error 55: Communication with the expansion board not possible. */
   #define ERROR_EXPANSION_BOARD_NOT_ANSWER           RTUCONTROL_ERROR_BASE + 53 /**< Error 56: Not answer from expansion board unit. */
   #define ERROR_IBUTTON_NOT_DETECTED                 RTUCONTROL_ERROR_BASE + 54 /**< Error 57: iButton not detected */
   #define ERROR_UMOUNT_CMD                           RTUCONTROL_ERROR_BASE + 55 /**< Error 58: error umount /home */
   #define ERROR_MOUNT_CMD                            RTUCONTROL_ERROR_BASE + 56 /**< Error 59: error mount /home */
   #define ERROR_NOT_USED                             RTUCONTROL_ERROR_BASE + 57 /**< Error 60: NOT_USED */
   #define ERROR_OWA3X_ACCEL_NOT_READY                RTUCONTROL_ERROR_BASE + 58 /**< Error 61: Acceleration not available. */
   #define ERROR_ACCEL_ALREADY_STARTED                RTUCONTROL_ERROR_BASE + 59 /**< Error 62: Accelerometer already started. */
   #define ERROR_PM_ANSWER                            RTUCONTROL_ERROR_BASE + 60 /**< Error 63: Error in PM answer */
   #define ERROR_ENTER_STANDBY                        RTUCONTROL_ERROR_BASE + 61 /**< Error 64: Error Entering Stand-By */
   #define ERROR_BATTERY_LOW_OR_NOT_PRESENT           RTUCONTROL_ERROR_BASE + 62 /**< Error 65: Error low battery voltage or battery not present */

   //*************    IOs Section
   #define IOS_ERROR_BASE                             100
   #define ERROR_INVALID_OUTPUT_TYPE                  IOS_ERROR_BASE + 1  /**< Error 101: Trying to use a Digital output as PWM, or viceverse. */
   #define ERROR_INVALID_CALIBRATION_TYPE             IOS_ERROR_BASE + 2  /**< Error 102: Invalid calibration type when configuring a AD input. */
   #define ERROR_INVALID_END_ADVICE_TYPE              IOS_ERROR_BASE + 3  /**< Error 103: Invalid end advice type when configuring a AD input. */
   #define ERROR_INVALID_USAGE_TYPE                   IOS_ERROR_BASE + 4  /**< Error 104: Invalid usage type when configuring a AD input. */
   #define ERROR_INVALID_PWM_DUTY_CYCLE               IOS_ERROR_BASE + 5  /**< Error 105: Invalid Duty Cycle value when configuring a PWM output. */
   #define ERROR_INVALID_PWM_SOURCE_FREQ              IOS_ERROR_BASE + 6  /**< Error 106: Invalid Source Frequency value when configuring a PWM output. */
   #define ERROR_INVALID_PWM_CYCLE_TYPE               IOS_ERROR_BASE + 7  /**< Error 107: Invalid Cycle type value when configuring a PWM output. */
   #define ERROR_OPENING_DEVICE_DRIVER                IOS_ERROR_BASE + 8  /**< Error 108: Problems when opening the device driver. */
   #define ERROR_CLOSING_DEVICE_DRIVER                IOS_ERROR_BASE + 9  /**< Error 109: Problems when closing the device driver. */
   #define ERROR_IN_IOCTL_COMMAND                     IOS_ERROR_BASE + 10 /**< Error 110: Error when executing a device driver IOCTL command. */
   #define ERROR_TIMER_ALREADY_USED                   IOS_ERROR_BASE + 11 /**< Error 111: Trying to use an already used timer. */
   #define ERROR_TIMER_NOT_USED                       IOS_ERROR_BASE + 12 /**< Error 112: Trying to disconnect a not used timer. */
   #define ERROR_NO_FREE_TIMERS                       IOS_ERROR_BASE + 13 /**< Error 113: There is no free timer available. */
   #define ERROR_IOS_ALREADY_INITIALIZED              IOS_ERROR_BASE + 14 /**< Error 114: IOs Module already initialized. */
   #define ERROR_IOS_NOT_INITIALIZED                  IOS_ERROR_BASE + 15 /**< Error 115: IOs Module not yet initialized. */
   #define ERROR_IOS_ALREADY_STARTED                  IOS_ERROR_BASE + 16 /**< Error 116: IOs Module already started. */
   #define ERROR_IOS_NOT_STARTED                      IOS_ERROR_BASE + 17 /**< Error 117: IOs Module not yet started. */
   #define ERROR_READ_ANALOG_INPUT                    IOS_ERROR_BASE + 18 /**< Error 118: Error reading analog input. */
   #define ERROR_IBUTTON_SEARCHING                    IOS_ERROR_BASE + 19 /**< Error 119: iButton searching in progress */
	#define ERROR_OW_DISCOVERING                       IOS_ERROR_BASE + 20 /**< Error 120: 1-WIRE automatic update in progress */
	#define ERROR_OW_TOO_MANY_DEVICES                  IOS_ERROR_BASE + 21 /**< Error 121: More than MAX_OW_DEVICES in 1-WIRE */
   #define ERROR_IB_DATA_SIZE                         IOS_ERROR_BASE + 22 /**< Error 122: iButton data size too big */
   #define ERROR_IB_READ_DATA                         IOS_ERROR_BASE + 23 /**< Error 123: iButton error reading data */
   #define ERROR_PPS_IN_USE                           IOS_ERROR_BASE + 24 /**< Error 124: PPS led is in use */

   //*************    GSM Section
   #define GSM_ERROR_BASE                             200
   #define GSM_ERR_ME_FAILURE                         GSM_ERROR_BASE + 0  /**< Error 200: GSM failure */
   #define GSM_ERR_CONNECTION_FAILURE                 GSM_ERROR_BASE + 1  /**< Error 201: Connection failure with the net. */
   #define GSM_ERR_ME_PHONE_ADAPTOR_LINK_RESERVED     GSM_ERROR_BASE + 2
   #define GSM_ERR_OPERATION_NOT_ALLOWED              GSM_ERROR_BASE + 3  /**< Error 203: Operation not allowed by the GSM */
   #define GSM_ERR_OPERATION_NOT_SUPPORTED            GSM_ERROR_BASE + 4  /**< Error 204: Operation not supported */
   #define GSM_ERR_PH_SIM_PIN_REQUIRED                GSM_ERROR_BASE + 5  /**< Error 205: Phone SIM PIN required. Phone Code Locked */
   #define GSM_ERR_SIM_NOT_INSERTED                   GSM_ERROR_BASE + 6  /**< Error 206: SIM not inserted. */
   #define GSM_ERR_SIM_PIN_REQUIRED                   GSM_ERROR_BASE + 7  /**< Error 207: SIM PIN required */
   #define GSM_ERR_SIM_PUK_REQUIRED                   GSM_ERROR_BASE + 8  /**< Error 208: SIM PUK required */
   #define GSM_ERR_SIM_FAILURE                        GSM_ERROR_BASE + 9  /**< Error 209: SIM failure. Contact operator */
   #define GSM_ERR_SIM_BUSY                           GSM_ERROR_BASE + 10 /**< Error 210: SIM is busy. */
   #define GSM_ERR_SIM_WRONG                          GSM_ERROR_BASE + 11 /**< Error 211: SIM operation wrong. */
   #define GSM_ERR_INCORRECT_PASSWORD                 GSM_ERROR_BASE + 12 /**< Error 212: SIM incorrect password, change. */
   #define GSM_ERR_SIM_PIN2_REQUIRED                  GSM_ERROR_BASE + 13 /**< Error 213: SIM PIN2 required */
   #define GSM_ERR_SIM_PUK2_REQUIRED                  GSM_ERROR_BASE + 14 /**< Error 214: SIM PUK2 required */
   #define GSM_ERR_MEMORY_FULL                        GSM_ERROR_BASE + 15 /**< Error 215: GSM folder full( PhoneBook / SIM) */
   #define GSM_ERR_INVALID_INDEX                      GSM_ERROR_BASE + 16 /**< Error 216: Index non used or major than max index.(SMS/PB) */
   #define GSM_ERR_NOT_FOUND                          GSM_ERROR_BASE + 17
   #define GSM_ERR_MEMORY_FAILURE                     GSM_ERROR_BASE + 18 /**< Error 218: There is a memory failure (SIM/ME) */
   #define GSM_ERR_TEXT_STRING_TOO_LONG               GSM_ERROR_BASE + 19
   #define GSM_ERR_INVALID_CHARACTERS_IN_TEXT_STRING  GSM_ERROR_BASE + 20
   #define GSM_ERR_DIAL_STRING_TOO_LONG               GSM_ERROR_BASE + 21 /**< Error 221: The dial string is too long */
   #define GSM_ERR_INVALID_CHARACTERS_IN_DIAL_STRING  GSM_ERROR_BASE + 22 /**< Error 222: Dial String has invalid characters */
   #define GSM_ERR_NO_NETWORK_SERVICE                 GSM_ERROR_BASE + 23 /**< Error 223: There is no GSM network service */
   #define GSM_ERR_NETWORK_TIMEOUT                    GSM_ERROR_BASE + 24 /**< Error 224: GSM Network returns timeout. */
   #define GSM_ERR_UNKNOWN                            GSM_ERROR_BASE + 25 /**< Error 225: Unknown SMS error on the function */
      //SMS FAILURES
   #define GSM_ERR_SMS_ME_FAILURE                     GSM_ERROR_BASE + 26 /**< Error 226: Failure on sending a SMS */
   #define GSM_ERR_SMS_SERVICE_OF_ME_RESERVED         GSM_ERROR_BASE + 27
   #define GSM_ERR_SMS_OPERATION_NOT_ALLOWED          GSM_ERROR_BASE + 28 /**< Error 228: SMS Operation not allowed */
   #define GSM_ERR_SMS_OPERATION_NOT_SUPPORTED        GSM_ERROR_BASE + 29 /**< Error 229: SMS Operation not supported. */
   #define GSM_ERR_SMS_INVALID_PDU_MODE_PARAMETER     GSM_ERROR_BASE + 30 /**< Error 230: Invalid PDU sending SMS */
   #define GSM_ERR_SMS_SMSC_ADDRESS_UNKNOWN           GSM_ERROR_BASE + 31 /**< Error 231: SMSC Unknown */
   #define GSM_ERR_SMS_NO_CNMA_ACK_EXPECTED           GSM_ERROR_BASE + 32 /**< Error 232: CNMA ACK not received */
   #define GSM_ERR_SMS_UNKNOWN                        GSM_ERROR_BASE + 33 /**< Error 233: Unknown Error on SMSs */
   #define GSM_ERR_BUSY                               GSM_ERROR_BASE + 34 /**< Error 234: Remote side is busy */
   #define GSM_ERR_NO_ANSWER                          GSM_ERROR_BASE + 35 /**< Error 235: No answer at the peer side. */
   #define GSM_ERR_NO_CARRIER                         GSM_ERROR_BASE + 36 /**< Error 236: Network has released the current call. */
   #define GSM_ERR_DIALING                            GSM_ERROR_BASE + 37 /**< Error 237: Error if trying to dial when it is on conversation or other */
   #define GSM_ERR_INIT_FAILURE                       GSM_ERROR_BASE + 38 /**< Error 238: GSM Initialization Failure: Due to communication lack */
   #define GSM_ERR_TIMEOUT                            GSM_ERROR_BASE + 39 /**< Error 239: GSM Function securety timeout */
   #define GSM_ERR_DATA_MODE                          GSM_ERROR_BASE + 40 /**< Error 240: GSM is in data mode. */
   #define GSM_ERR_GENERAL_FAILURE                    GSM_ERROR_BASE + 41 /**< Error 241: GSM communication lost. */
   #define GSM_ERR_INIT_IN_PROGRESS                   GSM_ERROR_BASE + 42 /**< Error 242: GSM is being initialized */
   #define GSM_ERR_IN_GPRS_PARAM                      GSM_ERROR_BASE + 43 /**< Error 243: Non-valid GPRS parameters */
   #define GSM_ERR_ALREADY_INITIALIZED                GSM_ERROR_BASE + 44 /**< Error 244: GSM Module already initialized. */
   #define GSM_ERR_NOT_INITIALIZED                    GSM_ERROR_BASE + 45 /**< Error 245: GSM Module not yet initialized. */
   #define GSM_ERR_ALREADY_STARTED                    GSM_ERROR_BASE + 46 /**< Error 246: GSM Module already started. */
   #define GSM_ERR_NOT_STARTED                        GSM_ERROR_BASE + 47 /**< Error 247: GSM Module not yet started. */
   #define GSM_ERR_INVALID_DATA                       GSM_ERROR_BASE + 48 /**< Error 248: Error due to Failure on Data. */
   #define GSM_ERR_NETWORK_LOCK                       GSM_ERROR_BASE + 49 /**< Error 249: Network Lock */
   #define GSM_ERR_SMS_TYPE                           GSM_ERROR_BASE + 50 /**< Error 250: Unknown SMS format */
   #define GSM_ERR_AUDIO_PARAMETER                    GSM_ERROR_BASE + 51 /**< Error 251: Error on the Audio file. */
   #define GSM_ERR_NOT_SWITCHED_ON                    GSM_ERROR_BASE + 52 /**< Error 252: GSM HW has an error and does not switch on. */
   #define GSM_ERR_PLMN_SELECT_FAILURE                GSM_ERROR_BASE + 53 /**< Error 253: PLMN selection failure */
   #define GSM_ERR_NO_DIALTONE                        GSM_ERROR_BASE + 54 /**< Error 254: NO DIALTONE present */
   #define GSM_ERR_OPEN_AUDIO                         GSM_ERROR_BASE + 55 /**< Error 255: Error opening digital audio system */
   #define GSM_ERR_AUDIO_ALLOC_HW                     GSM_ERROR_BASE + 56 /**< Error 256: Error allocating HW structure */
   #define GSM_ERR_AUDIO_INIT_HW                      GSM_ERROR_BASE + 57 /**< Error 257: Error initializing HW structure */
   #define GSM_ERR_AUDIO_SET_ACTYPE                   GSM_ERROR_BASE + 58 /**< Error 258: Error setting access type */
   #define GSM_ERR_AUDIO_SAMP_FORM                    GSM_ERROR_BASE + 59 /**< Error 259: Error setting sample format */
   #define GSM_ERR_AUDIO_SAMP_RATE                    GSM_ERROR_BASE + 60 /**< Error 260: Error setting sample rate */
   #define GSM_ERR_AUDIO_CHAN_COUNT                   GSM_ERROR_BASE + 61 /**< Error 261: Error setting channel count */
   #define GSM_ERR_AUDIO_SET_PARAMS                   GSM_ERROR_BASE + 62 /**< Error 262: Error setting HW parameters */
   #define GSM_ERR_AUDIO_PCM_PREPARE                  GSM_ERROR_BASE + 63 /**< Error 263: Error in PCM prepare */
   #define GSM_ERR_AUDIO_PCM_LINK                     GSM_ERROR_BASE + 64 /**< Error 264: Error in PCM link */
   #define GSM_ERR_AUDIO_NOT_ALLOWED                  GSM_ERROR_BASE + 65 /**< Error 265: Digital audio not allowed */
   #define GSM_ERR_PS_BUSY                            GSM_ERROR_BASE + 66 /**< Error 266: PS Busy */
   #define GSM_ERR_SMS_SIM_NOT_READY                  GSM_ERROR_BASE + 67 /**< Error 267: SIM not ready */
   #define GSM_ERR_AUDIO_ALREADY_OPENED               GSM_ERROR_BASE + 68 /**< Error 268: Digital audio already opened */
   #define GSM_ERR_REJECTED_BUSY                      GSM_ERROR_BASE + 69 /**< Error 269: Remote side rejects call (busy) */
   #define GSM_ERR_NOT_TIME_AVAILABLE                 GSM_ERROR_BASE + 70 /**< Error 270: None connection time available */
   #define GSM_ERR_NO_LCP_TIME                        GSM_ERROR_BASE + 71 /**< Error 271: No LCP time available */
   #define GSM_ERR_NO_IP_TIME                         GSM_ERROR_BASE + 72 /**< Error 272: No IP time available */
   #define GSM_ERR_LINK_CREATE                        GSM_ERROR_BASE + 73 /**< Error 273: Not possible to create link */
   #define GSM_ERR_TEMP_NOT_ALLOWED                   GSM_ERROR_BASE + 74 /**< Error 274: Operation temporary not allowed */
   #define GSM_ERR_NO_COVERAGE                        GSM_ERROR_BASE + 75 /**< Error 275: No GSM Coverage */
   #define GSM_ERR_MODEL_UNKNOWN                      GSM_ERROR_BASE + 76 /**< Error 276: Unknown GSM model */
   #define GSM_ERR_SDM_DISABLED                       GSM_ERROR_BASE + 77 /**< Error 277: SIM Dual Mode disabled. Only PLS62-W  */
   #define GSM_ERR_DEVICE_DETECTION                   GSM_ERROR_BASE + 78 /**< Error 278: GSM Modem not detected  */
   #define GSM_ERR_NO_RESOURCES                       GSM_ERROR_BASE + 79 /**< Error 279: No resources available */
   #define GSM_ERR_GENERIC_UNKNOWN                    GSM_ERROR_BASE + 80 /**< Generic unknown error */
   #define GSM_ERR_CHECK_0                            GSM_ERROR_BASE + 81 /**< Error 0 checking error response */
   #define GSM_ERR_CHECK_1                            GSM_ERROR_BASE + 82 /**< Error 1 checking error response */
   #define GSM_ERR_CHECK_2                            GSM_ERROR_BASE + 83 /**< Error 2 checking error response */
   #define GSM_ERR_CHECK_3                            GSM_ERROR_BASE + 84 /**< Error 3 checking error response */
   #define GSM_ERR_CHECK_4                            GSM_ERROR_BASE + 85 /**< Error 4 checking error response */
   #define GSM_ERR_MODEL                              GSM_ERROR_BASE + 86 /**< Unknown GSM model */
   #define GSM_ERR_SMS_NUMBER                         GSM_ERROR_BASE + 87 /**< Error in SMS number */
   #define GSM_ERR_CMD_FORMAT                         GSM_ERROR_BASE + 88 /**< Error in command format */
   #define GSM_ERR_PORT_MUX_MODE                      GSM_ERROR_BASE + 89 /**< Error port mode changing speed */
   #define GSM_ERR_SPEED_NOT_SUPPORTED                GSM_ERROR_BASE + 90 /**< Baud rate not supported */
   #define GSM_ERR_SET_SPEED                          GSM_ERROR_BASE + 91 /**< Error setting baud rate */
   #define GSM_ERR_RESP_HANDLER                       GSM_ERROR_BASE + 92 /**< Error in response handler */
   #define GSM_ERR_SMS_INVALID_TEXT_MODE_PARAMETER    GSM_ERROR_BASE + 93 /**< Error SMS text mode */
   #define GSM_ERR_SMS_READ_PDU                       GSM_ERROR_BASE + 94 /**< Error reading PDU SMS */
   #define GSM_ERR_GET_MANUFACTURER                   GSM_ERROR_BASE + 95 /**< Error getting GSM manufacturer */
   #define GSM_ERR_TX_CMD_MOT_ALLOWED                 GSM_ERROR_BASE + 96 /**< GSM TX channel is not available */
   #define GSM_ERR_GSM_SOCKET                         GSM_ERROR_BASE + 97 /**< Error create GSM socket */
   #define GSM_ERR_AUDIO_SERVICE                      GSM_ERROR_BASE + 98 /**< Error in audio service */
   #define GSM_ERR_GET_SIGNAL                         GSM_ERROR_BASE + 99 /**< Signal to get is not defined */
   #define GSM_ERR_SET_SIGNAL                         GSM_ERROR_BASE + 100/**< Signal to set is not defined */
   #define GSM_ERR_SET_UART_SIGNAL                    GSM_ERROR_BASE + 101/**< Error setting UART signal */
   #define GSM_ERR_REINIT_REQUIRED                    GSM_ERROR_BASE + 102/**< Reinit module is required */

   //..
   //Reserved ranges for GSM_ERR:                     GSM_ERROR_BASE + 100

   //*************    GPS Section
   #define GPS_ERROR_BASE                             400
   #define ERROR_IN_GPS_TYPE                          GPS_ERROR_BASE + 1 /**< Error 401: Invalid GPS receiver type passed in configuration. */
   #define ERROR_NO_VALID_BAUDRATE                    GPS_ERROR_BASE + 2 /**< Error 402: Invalid GPS baudrate passed in configuration. */
   #define ERROR_NO_VALID_PARITY                      GPS_ERROR_BASE + 3 /**< Error 403: Invalid parity type passed in configuration. */
   #define ERROR_NO_VALID_BYTE_LENGTH                 GPS_ERROR_BASE + 4 /**< Error 404: Invalid byte length passed in configuration. */
   #define ERROR_NO_VALID_STOPBITS                    GPS_ERROR_BASE + 5 /**< Error 405: Invalid number of stop bits passed in configuration. */
   #define ERROR_NO_VALID_PROTOCOL                    GPS_ERROR_BASE + 6 /**< Error 406: Invalid GPS protocol type passed in configuration. */
   #define ERROR_PROTOCOL_NOT_IMPLEMENTED             GPS_ERROR_BASE + 7 /**< Error 407: GPS protocol type not yet implemented. */
   #define ERROR_NO_VALID_PORT                        GPS_ERROR_BASE + 8 /**< Error 408: Not GPS connected in this port. */
   #define ERROR_GPS_NOT_STARTED                      GPS_ERROR_BASE + 9 /**< Error 409: The GPS is not started. */
   #define ERROR_MSG_NOT_SENT_TO_GPS                  GPS_ERROR_BASE + 10 /**< Error 410: The message was not sent to the GPS. */
   #define ERROR_NO_DATA_FROM_GPS                     GPS_ERROR_BASE + 11 /**< Error 411: No data received from GPS. */
   #define ERROR_GPS_MSG_WITH_BAD_CHK                 GPS_ERROR_BASE + 12 /**< Error 412: Message received from GPS with bad checksum. No valid message. */
   #define ERROR_GPS_PORT_NOT_OPENED                  GPS_ERROR_BASE + 13 /**< Error 413: GPS port not opened. */
   #define ERROR_GPS_NOT_POWER_ON                     GPS_ERROR_BASE + 14 /**< Error 414: Switch on of the GPS not possible. */
   #define ERROR_UNLINKPORT_IN_FINALIZE               GPS_ERROR_BASE + 15 /**< Error 415: Unlink from port was not possible. */
   #define ERROR_UNLOAD_LIBRARY_IN_FINALIZE           GPS_ERROR_BASE + 16 /**< Error 416: Unload external library was not possible. */
   #define ERROR_MSG_NOT_ALLOWED                      GPS_ERROR_BASE + 17 /**< Error 417: The request of the message is not allowed. */
   #define ERROR_GPS_ALREADY_INITIALIZED              GPS_ERROR_BASE + 18 /**< Error 418: The GPS has been already initialized calling to GPS_Initialize. */
   #define ERROR_GPS_NOT_INITIALIZED                  GPS_ERROR_BASE + 19 /**< Error 419: The GPS is not initialized. Call GPS_Initialize before calling to GPS_Start. */
   #define ERROR_GPS_ALREADY_STARTED                  GPS_ERROR_BASE + 20 /**< Error 420: The GPS has been started. */
   #define ERROR_GPS_BINARY_TIMEOUT                   GPS_ERROR_BASE + 21 /**< Error 421: Not used */
   #define ERROR_GPS_BINARY_NACK                      GPS_ERROR_BASE + 22 /**< Error 422: Not used */
   #define ERROR_FUNCTION_NOT_ALLOWED_IN_NMEA         GPS_ERROR_BASE + 23 /**< Error 423: Not used */
   #define ERROR_FUNCTION_NOT_ALLOWED_IN_BINARY       GPS_ERROR_BASE + 24 /**< Error 424: Function not allowed */
   #define ERROR_NO_MEMORY_IN_GPS_FUNCTION            GPS_ERROR_BASE + 25 /**< Error 425: There are no memory resources left for the GPS to work properly */
   #define ERROR_FUNCTION_NOT_ALLOWED_ON_GPS          GPS_ERROR_BASE + 26 /**< Error 426: The function is not supported in the GPS module */
   #define ERROR_GPS_BINARY_TX                        GPS_ERROR_BASE + 27 /**< Error 427: Error when sending configuration message to the GPS module */
   #define ERROR_GPS_BINARY_WAIT                      GPS_ERROR_BASE + 28 /**< Error 428: Error waiting the answer to a configuration message */
   #define ERROR_GPS_BINARY_RX_NACK                   GPS_ERROR_BASE + 29 /**< Error 429: NACK received from GPS module */
   #define ERROR_GPS_NOT_NEW_MSG                      GPS_ERROR_BASE + 30 /**< Error 430: The message with GPS information (position, time, speed, etc) has not been refreshed since last request */
   #define ERROR_GPS_RX_WAIT                          GPS_ERROR_BASE + 31 /**< Error 431: Timeout when waiting for answer */
   #define ERROR_GPS_BIN_CHK                          GPS_ERROR_BASE + 32 /**< Error 432: Checksum error */
   #define ERROR_NO_VALID_MEAS_RATE                   GPS_ERROR_BASE + 33 /**< Error 433: No valid measurement rate returned */

   // ****************** TEST_ORION Section

   #define TEST_ERROR_BASE                            500
   #define ERROR_TEST_IO                              TEST_ERROR_BASE + 1
   #define ERROR_TEST_RTU                             TEST_ERROR_BASE + 2
   #define ERROR_TEST_GSM                             TEST_ERROR_BASE + 3
   #define ERROR_TEST_UART                            TEST_ERROR_BASE + 4
   #define ERROR_TEST_LED                             TEST_ERROR_BASE + 5

   //****************** INET ERROR Section
   
   #define INET_ERROR_BASE                            600
   #define ERROR_INET_ALREADY_RUNNING                 INET_ERROR_BASE + 0
   #define ERROR_INET_NOT_INITIALIZED                 INET_ERROR_BASE + 1
   #define ERROR_INET_NOT_STARTED                     INET_ERROR_BASE + 2
   #define ERROR_INET_IP_IF_NOT_READY                 INET_ERROR_BASE + 3   /**< Error 603: IF error by the kernel on IPget */
   #define ERROR_INET_IP_NOT_AVAILABLE                INET_ERROR_BASE + 4   /**< Error 604: No IP availble. Lack of Connection */
   #define ERROR_INET_GSM_ON_VOICE                    INET_ERROR_BASE + 5   /**< Error 605: GSM on Voice, inet stop not available */
   #define ERROR_INET_GSM_ON_CALL                     INET_ERROR_BASE + 6   /**< Error 606: GSM on Call, inet stop not available */


   //****************** FMS ERROR Section
	#define FMS_ERROR_BASE			                  	1500
   #define ERROR_FMS_ALREADY_INITIALIZED					FMS_ERROR_BASE + 1 /**< Error 1501: The FMS library has been already initialized and it is running */
	#define ERROR_FMS_NOT_INITIALIZED						FMS_ERROR_BASE + 2 /**< Error 1502: Error when starting FMS as it has not been yet initialized */
	#define ERROR_FMS_ALREADY_STARTED						FMS_ERROR_BASE + 3 /**< Error 1503: Error when starting FMS as it is already started */
	#define ERROR_STARTING_FMS									FMS_ERROR_BASE + 4 /**< Error 1504: Error starting FMS library */
	#define ERROR_FMS_CREATE_SOCKET							FMS_ERROR_BASE + 5 /**< Error 1505: Error when creating the CAN socket */
	#define ERROR_FMS_CFG_SOCKET								FMS_ERROR_BASE + 6 /**< Error 1506: Error when configuring the CAN socket */
	#define ERROR_FMS_BIND_SOCKET								FMS_ERROR_BASE + 7 /**< Error 1507: Error when trying to bind to the CAN socket */
	#define ERROR_FMS_THREAD_INIT								FMS_ERROR_BASE + 8 /**< Error 1508: Error when creating a thread on the system */
	#define ERROR_FMS_NOT_STARTED								FMS_ERROR_BASE + 9 /**< Error 1509: Error when trying to finalize FMS without starting it first */
	#define ERROR_FMS_LOAD_LIBRARY							FMS_ERROR_BASE + 10 /**< Error 1510: Error when loading FMS library */
	#define ERROR_FMS_UNLOAD_LIBRARY							FMS_ERROR_BASE + 11 /**< Error 1511: Error when unloading functions from the system */
	#define ERROR_FMS_LOAD_FUNCTION							FMS_ERROR_BASE + 12 /**< Error 1512: Error when loading functions on the system */
	#define ERROR_FMS_OPTION_NOT_ENABLED					FMS_ERROR_BASE + 13 /**< Error 1513: FMS library not validated as option in the unit */
	#define ERROR_FMS_ENABLE_CAN								FMS_ERROR_BASE + 14 /**< Error 1514: Error when enabling the CAN driver */
	#define ERROR_FMS_GET_OPTION								FMS_ERROR_BASE + 15 /**< Error 1515: FMS library option validation check up error */
	#define ERROR_FMS_TIRE_NOT_FOUND							FMS_ERROR_BASE + 16 /**< Error 1516: Number of tire above the maximum value of 20 */
	#define ERROR_FMS_SRV_CONF									FMS_ERROR_BASE + 17 /**< Error 1517: Wrong FMS configuration */

#endif

