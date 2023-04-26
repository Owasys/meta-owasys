/**
 * @file RTUControlDefs.h
 * @author Owasys
 * @date 03 Aug 2017
 * @brief File containing definitions for Owasys RTU API.
 *
 */

#ifndef __RTUControlDefs_H

   #define __RTUControlDefs_H

   #ifdef __cplusplus
    extern "C"{
   #endif

   #include "owcomdefs.h"
   #include <dlfcn.h>
   #include <termios.h>

   #define MAX_PORT_NAME    16            // Name of the port
   typedef struct {                       // Select function configuration structure
      char     PortName[ MAX_PORT_NAME];  // Port name.
      int      FileDescriptor;            // File Descriptor
      void     *Object;                   // In case of SDK instead of API
      struct   termios  NewConfig;        // New configuration of the port to be opened
      struct   termios  OldConfig;        // Old Port configuration to be restaured before close the port.
      int      ToOpen;                    // Flag to open the port in the port list.
      int      ToClose;                   // Flag to close the port in the port list.
      int      ToEliminate;               // Flag to erase node from Select list.
   } TCONF_SELECT;

   #define ONE_TICK        0
   #define MULTIPLE_TICK   1

   typedef struct {
      unsigned char Release;
      unsigned char Version;  /**< Version of low power mode processor */
      unsigned char SubV;     /**< Subversion of low power mode processor */
   } StructVersion;

   typedef struct {
      unsigned long     Year;
      unsigned char     Month;
      unsigned char     Day;
      unsigned short    DayInYear;
      unsigned char     DayInWeek;
      unsigned char     Hour;
      unsigned char     Minute;
      unsigned char     Second;
   } TSYSTEM_TIME;

   typedef struct
   {
      unsigned char sec;
      unsigned char min;
      unsigned char hour;
      unsigned char day;
      unsigned char month;
      unsigned short year;
   } THW_TIME_DATE;

   typedef struct
   {
		unsigned char wEnable;			// Accelerometer Enabled(1) or Disabled(0). Only used when reading configuration
		unsigned char wScale;			// Configures the operational range of the accelerometer(0...3).
		unsigned char wLimit;			// Threshold of the accelerometer(0...127). Bumps surpassing the threshold value will
												// send an interruption. Each step is equivalent to [scale] / 127
		unsigned char wTime;				// Time value(0...127) that the sensor must be moving before sending the interruption.
												// Each step is equivalent to 10 ms.
		void(*wHandler)(move_int_t);	// Function handler to execute with a moving interruption.
		unsigned short int wMinTimeMovement;		// Minimun time detecting interrupts (0,2....900)
		unsigned short int wMaxTimeBetweenInts;	// Max time between interrupts to detect movement (0,1....300)
	} CONFIG_MOVEMENT_DETECT;


	#define TIMER_DISABLED		0

	#define MIN_TIME_MOVE		2
	#define MAX_TIME_MOVE		900

	#define MIN_TIME_INTS		1
	#define MAX_TIME_INTS		300
	
   #define MIN_TIME_TO_OFF    10
   #define MAX_TIME_TO_OFF    600


   // Power Management: defines with the mask of the return conditions
   #define LP_MODE_STANDBY      1
   #define LP_MODE_OFF          2


   // Bitmasks for comming back from  Power Management modes
   #define RTU_WKUP_MOVING     (1 << 0)
   #define RTU_WKUP_PWRFAIL    (1 << 1)
   #define RTU_WKUP_CONSOLE    (1 << 2)
   #define RTU_WKUP_GSM        (1 << 3)
   #define RTU_WKUP_CAN1RD     (1 << 4)
   #define RTU_WKUP_RTC        (1 << 6)
   #define RTU_WKUP_DIN0       (1 << 7)
   #define RTU_WKUP_DIN1       (1 << 8)
   #define RTU_WKUP_DIN2       (1 << 9)
   #define RTU_WKUP_DIN3       (1 << 10)
   #define RTU_WKUP_DIN4       (1 << 11)
   #define RTU_WKUP_DIN5       (1 << 12)
   #define RTU_WKUP_DIN6       (1 << 13)
   #define RTU_WKUP_DIN7       (1 << 14)
   #define RTU_WKUP_DIN8       (1 << 15)
//   #define RTU_WKUP_DIN9       (1 << 16)
   #define RTU_REMOVE_VOUT     (1 << 19)
   #define RTU_ONLY_POWERUP    (1 << 20)
   #define RTU_WKUP_BLE        (1 << 21)
   #define RTU_WKUP_ETHERNET   (1 << 22)
   
   #define WKUP_ALL        (RTU_WKUP_MOVING | RTU_WKUP_PWRFAIL | RTU_WKUP_CONSOLE | RTU_WKUP_GSM | RTU_WKUP_CAN1RD\
                           | RTU_WKUP_RTC | RTU_WKUP_DIN0 | RTU_WKUP_DIN1\
                           | RTU_WKUP_DIN2 | RTU_WKUP_DIN3 | RTU_WKUP_DIN4 | RTU_WKUP_DIN5 | RTU_WKUP_DIN6\
                           | RTU_WKUP_DIN7 | RTU_WKUP_DIN8 | RTU_WKUP_ETHERNET)
//                           | RTU_WKUP_DIN7 | RTU_WKUP_DIN8 | RTU_WKUP_DIN9)

    #define IB_ID_LENGTH 8

   //-20 --> +50  seconds per month
   //-19 --> +47  seconds per month
   //-18 --> +45  seconds per month
   //-17 --> +42  seconds per month
   //-16 --> +40  seconds per month
   //-15 --> +37  seconds per month
   //-14 --> +35  seconds per month
   //-13 --> +32  seconds per month
   //-12 --> +30  seconds per month
   //-11 --> +27  seconds per month
   //-10 --> +25  seconds per month
   //-9  --> +22  seconds per month
   //-8  --> +20  seconds per month
   //-7  --> +17  seconds per month
   //-6  --> +15  seconds per month
   //-5  --> +12  seconds per month
   //-4  --> +10  seconds per month
   //-3  --> +8  seconds per month
   //-2  --> +5 seconds per month
   //-1  --> +3 seconds per month
   //+1  --> -2 seconds per month
   //+2  --> -5 seconds per month
   //+3  --> -7  seconds per month
   //+4  --> -10  seconds per month
   //+5  --> -12  seconds per month
   //+6  --> -15  seconds per month
   //+7  --> -17  seconds per month
   //+8  --> -20  seconds per month
   //+9  --> -22  seconds per month
   //+10 --> -25  seconds per month
   //+11 --> -27  seconds per month
   //+12 --> -30  seconds per month
   //+13 --> -32  seconds per month
   //+14 --> -35  seconds per month
   //+15 --> -37  seconds per month
   //+16 --> -39  seconds per month
   //+17 --> -42  seconds per month
   //+18 --> -44  seconds per month
   //+18 --> -47  seconds per month
   //+20 --> -49  seconds per month
   #define MIN_CUSTOM_RTC_CAL      -80
   #define MAX_CUSTOM_RTC_CAL      80
   #define DEF_CUSTOM_RTC_CAL      0


/**
 * @brief Initializes and configures the module.
 *
 * RTU module is needed internally by GSM and GPS system modules. For that reason,
 * before using any functionality from those modules, the RTU module must be
 * initialized and started.
 *
 * @param *wConfiguration NULL
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUControl_Initialize( void *wConfiguration);

/**
 * @brief Starts the RTU Control Module.
 *
 * RTU module is needed internally by GSM and GPS system modules. For that reason,
 * before using any functionality from those modules, the RTU module must be
 * initialized and started.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUControl_Start( void);

/**
 * @brief Finalizes the RTU module.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUControl_Finalize( void);

/**
 * @brief Checks the current status of the RTU Control module.
 *
 * @param *wActive 0: Not active, 1: Active.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUControl_IsActive( int *wActive);

/**
 * @brief Return the RTU library version.
 *
 * @param *wVersion Contains the returned version code. Format "CYA 999 9999, x.x.x"
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUControl_GetVersion( unsigned char *wVersion);

/**
 * @brief Get the System Time.
 *
 * @param *wSystemTime Retrieved time information.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GetSystemTime( TSYSTEM_TIME *wSystemTime);

/**
 * @brief Set System time.
 *
 * @param wSystemTime Time info to set.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int SetSystemTime( TSYSTEM_TIME wSystemTime);

/**
 * @brief Sleeps a process during the programmed time.
 *
 * @param secs seconds to sleep
 * @param usecs micro seconds to sleep
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int usecsleep( int secs, int usecs);

/**
 * @brief Get a timer for the user application.
 *
 * @param *wTimer Timer number
 * @param *wHandler Function executed when the timer counter reaches 0.
 *    The timer that triggered the function can be obtained from
 *    the unsigned char argument of the function.
 * @param wSeconds Number of seconds
 * @param wMicroSeconds Number of microseconds.
 * @return NO_ERROR if success. Specific error number if fails.
 * @warning Inside handler no other functions must be called, just post a
 *    semaphore to execute the code in a different thread.
 */
   int OWASYS_GetTimer( unsigned char *wTimer, void ( *wHandler) ( unsigned char), unsigned long wSeconds, unsigned long wMicroSeconds );

/**
 * @brief Starts a timer.
 *
 * See function OWASYS_GetTimer() to know how to get it before calling to this function
 *
 * @param wTimer Timer number
 * @param Mode to run the timer so as to interrupt the application just once
 *    or every time the counter reaches 0
 *    ONE_TICK: One interruption. If the user wants to use it again the timer must be restarted
 *    MULTIPLE_TICK: Continous interruption without the need of restarting the timer each
 *    timeTimer number
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int OWASYS_StartTimer( unsigned char wTimer, unsigned char wMode );

/**
 * @brief Free the timer
 *
 * @param wTimer Timer number
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int OWASYS_FreeTimer( unsigned char wTimer);

/**
 * @brief Stops the timer
 *
 * @param wTimer Timer number
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int OWASYS_StopTimer( unsigned char wTimer );

/**
 * @brief Restarts the timer.
 *
 * @param wTimer Timer number
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int OWASYS_RestartTimer( unsigned char wTimer );

/**
 * @briefGets the Hardware RTC Time and Date.
 *
 * @param *CurrentTime Return Time and Date from RTC.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUGetHWTime(THW_TIME_DATE *CurrentTime);

/**
 * @brief Sets the Hardware RTC Time and Date.
 *
 * @param CurrentTime Time and Date to set the RTC.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUSetHWTime(THW_TIME_DATE CurrentTime);

/**
 * @brief Sets the specific calibration value for RTC. 
 *
 * @param wCalibValue calibration value for RTC. MIN_CUSTOM_RTC_CAL to MAX_CUSTOM_RTC_CAL
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTU_SetRtcCalibrationValue(signed short int wCalibValue);

/**
 * @brief Gets the specific calibration value for RTC. 
 *
 * @param pCalibValue Return calibration value for RTC.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTU_GetRtcCalibrationValue(signed short int *pCalibValue);

/**
 * @brief Set the Hardware Time and Date for Wake Up.
 *
 * @param CurrentTime Time and Date for Wake Up.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUSetWakeUpTime(THW_TIME_DATE CurrentTime);

/**
 * @brief Set the Hardware Time and Date for Waking Up when the number of Seconds has elapsed.
 *
 * @param secs Number of seconds for waking up.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUSetIncrementalWakeUpTime(int secs);

/**
 * @brief Show if the unit has been moved.
 *
 * @param *MovedValue Return the status of the 'MOVED' flag.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUGetMoved(unsigned char *MovedValue);

/**
 * @brief Resets the 'MOVED' flag.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUResetMoved(void);

/**
 * @brief Configure the parameters of the accelerometer
 *
 * @param wScale Scale of the accelerometer. 0: +/-2G 1: +/-4G 2: +/-8G, 3: +/-16G
 * @param wLimit Threshold of the accelerometer, between 0 and 127. Bumps surpassing the
 *    threshold value will send an interruption. Each step is equivalent to [scale] / 127
 * @param wTime Time value between 0 and 127 that the sensor must be moving before sending
 *    the interruption. Each step is equivalent to 10 ms.
 * @param *wHandler Function handler to execute with a moving interruption
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTU_CfgMovementSensor( unsigned char wScale, unsigned char wLimit, unsigned char wTime, void(*wHandler)(move_int_t));

/**
 * @brief Remove the interruption of the Movement sensor from the system.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTU_RemoveMovementSensor( void);

/**
 * @brief Gets the movement value for the 3 axis.
 *
 * @param *pData Pointer to the structure where accelerometer data will be copied.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTU_GetMovementSensor( move_int_t *pData);

/**
 * @brief Configure the parameters to detect "movement"
 *
 * @param *wMovementCfg Configuration parameters.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTU_CfgMovementDetection( CONFIG_MOVEMENT_DETECT *wMovementCfg);

/**
 * @brief Return the accelerometer configuration.
 *
 * @param *wMovementCfg Variable to store configuration data
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTU_GetCfgMovement( CONFIG_MOVEMENT_DETECT *wMovementCfg);

/**
 * @brief Get the acceleration value for the 3 axis, including the gravity acceleration.
 *
 * @param *pData Pointer to the structure where accelerometer data will be copied
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTU_GetRawAcceleration( move_int_t *pData);

/**
 * @brief Sends the device to Standby mode.
 *
 * The program flow will continue when waked up from this mode.
 * Not yet implemented
 *
 * @param wMainWakeup Mask with the signals that will wake up the unit. See values above
 * @param wExpWakeup NOT USED
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUEnterStandby(unsigned long wMainWakeup, unsigned long wExpWakeup);

/**
 * @brief Sends the unit to Stop mode.
 *
 * Main CPU is powered off and once waken up the Linux OS will reboot.
 *
 * @param wMainWakeup Mask with the signals that will wake up the unit. See values above
 * @param wExpWakeup NOT USED
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUEnterStop(unsigned long wMainWakeup, unsigned long wExpWakeup);

/**
 * @brief Sends the unit to Stop mode.
 * 
 * Main CPU is powered off after wOffTime and once waken up the Linux OS will reboot. 
 *
 * @param wMainWakeup Mask with the signals that will wake up the unit. See values above
 * @param wOffTime Time to wait before CPU is switched off.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUEnterStopTime(unsigned long wMainWakeup, unsigned short wOffTime);

/**
 * @brief Get the wake signal that woke up the unit from one of the low power modes,
 *    either Standby or Stop modes.
 *
 * @param *WakeUpReason Signal that woke up the unit. See values above
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUGetWakeUpReason(unsigned long *WakeUpReason);

/**
 * @brief Reset the wake signal that woke up the unit from one of the low power modes,
 *    either Standby or Stop modes.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUResetWakeUpReason(void);

/**
 * @brief Get the battery state of the unit.
 *
 * @param *BattState Battery state value
 *    0: Precharge in progress
 *    1: Charge done
 *    2: Fast charge in progress
 *    3: Charge suspended
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUGetBatteryState(unsigned char *BattState);

/**
 * @brief Get the voltage of the optional battery.
 *
 * @param *ad_vbat_main Value in volts of the optional battery.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUGetAD_VBAT_MAIN(float *ad_vbat_main);

/**
 * @brief Get VIN voltage of the external power source.
 *
 * @param *ad_v_in VIN value in volts.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUGetAD_V_IN(float *ad_v_in);

/**
 * @brief Gets the internal temperature of the unit.
 *
 * @param *ad_temp Temperature of the unit in degrees
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUGetAD_TEMP(int *ad_temp);

/**
 * @brief Gets the factory Serial Number of the device.
 *
 * It returns 6 characters, as the last figure in the serial number specifies only to the unit itself (1) or the unit plus the box (2).
 *
 * @param *wSerialNumber Retrieved Serial Number
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GetSerialNumber( unsigned char *wSerialNumber);

/**
 * @brief Gets the HW version of the main PC board.
 *
 * @param *pVersion 0x00
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTU_Get_Board_Version( unsigned char *pVersion);

/**
* @brief Gets the SW version of the low power management circuitry processor.
*
* @param *pVersion Retrieved SW version
* @return NO_ERROR if success. Specific error number if fails.
*/
  int RTUGetExtControllerVersion( StructVersion *pVersion);

/**
 * @brief Get the battery charge status of the unit.
 *
 * @param *ChargeStatus Battery charge status
 *    0: Disabled
 *    1: Enabled
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUGetBatteryChargeStatus(unsigned char *ChargeStatus);

/**
 * @brief Set the battery charge status of the unit.
 *        The new setting takes effect immediately and is stored
 *        in non-volatile memory
 *
 * @param ChargeStatus Battery charge status
 *    0: Disabled
 *    1: Enabled
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int RTUSetBatteryChargeStatus(unsigned char ChargeStatus);

  #ifdef __cplusplus
   }
  #endif

#endif
