/**
 * @file IOs_ModuleDefs.h
 * @author Owasys
 * @date 03 Aug 2017
 * @brief File containing definitions for Owasys IOs API.
 *
 */

#ifndef __IOS_MODULEDEFS_H

   #define __IOS_MODULEDEFS_H

   #ifdef __cplusplus
    extern "C"{
   #endif

   typedef struct {
      unsigned char InputNumber;
      unsigned char InputValue;
   } input_int_t;

   typedef struct {
      char scale;
      double x_axis;
      double y_axis;
      double z_axis;
   } move_int_t;

   #define MUX_MODE0       0x00
   #define MUX_MODE1       0x01
   #define MUX_MODE2       0x02
   #define MUX_MODE3       0x03
   #define MUX_MODE4       0x04
   #define MUX_MODE5       0x05
   #define MUX_MODE6       0x06
   #define MUX_MODE7       0x07

   #define PULL_DISABLE		(1 << 3)
   #define PULL_UP			(1 << 4)
   #define INPUT_EN		   (1 << 5)
   #define SLEWCTRL_SLOW	(1 << 6)
   #define SLEWCTRL_FAST	0

   #define PIN_OUTPUT            (PULL_DISABLE)
   #define PIN_OUTPUT_PULLUP     (PULL_UP)
   #define PIN_OUTPUT_PULLDOWN   0
   #define PIN_INPUT             (INPUT_EN | PULL_DISABLE)
   #define PIN_INPUT_PULLUP      (INPUT_EN | PULL_UP)
   #define PIN_INPUT_PULLDOWN    (INPUT_EN)

   //Digital Inputs
   #define  DIGITAL_INPUT_0   0
   #define  DIGITAL_INPUT_1   1
   #define  DIGITAL_INPUT_2   2
   #define  DIGITAL_INPUT_3   3
   #define  DIGITAL_INPUT_4   4
   #define  DIGITAL_INPUT_5   5
   #define  DIGITAL_INPUT_6   6
   #define  DIGITAL_INPUT_7   7
   #define  DIGITAL_INPUT_8   8
   #define  DIGITAL_INPUT_9   9
   #define  OUT8_FAULT        12
   #define  OUT9_FAULT        13
   #define  PWR_FAIL          14
   #define  DIGITAL_INPUT_10  22
   #define  DIGITAL_INPUT_11  23
   #define  DIGITAL_INPUT_12  24

   #define  FALLING_EDGE         0
   #define  RISING_EDGE          1
   #define  BOTH_EDGE            2

   //Digital Outputs
   #define  DIGITAL_OUTPUT_0   0
   #define  DIGITAL_OUTPUT_1   1
   #define  DIGITAL_OUTPUT_2   2
   #define  DIGITAL_OUTPUT_3   3
   #define  DIGITAL_OUTPUT_4   4
   #define  DIGITAL_OUTPUT_5   5
   #define  DIGITAL_OUTPUT_6   6
   #define  DIGITAL_OUTPUT_7   7
   #define  DIGITAL_OUTPUT_8   8
   #define  DIGITAL_OUTPUT_9   9
   #define  DIGITAL_OUTPUT_10  35

   //CAN TX Modes
   #define FAST_TX_MODE       0
   #define DISABLE_TX_MODE    1
   #define SLOW_TX_MODE       2

   //KLINE Thershold
   #define LOW_THRESHOLD      0
   #define HIGH_THRESHOLD     1

/**
 * @brief Configure and initalize the IO module.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IO_Initialize( void );

/**
 * @brief Start the IO Module.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IO_Start( void);

/**
 * @brief Finalize the IO module.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IO_Finalize( void);

/**
 * @brief Check wether the IO module is Active or not.
 *
 * @param *wActive 0: Not active, 1: Active.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IO_IsActive( int *wActive);

/**
 * @brief Return the Version of the IO module.
 *
 * @param *wVersion Contains the returned version code. Format "CYA 999 9999, x.x.x"
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IO_GetVersion( char *wVersion);

/**
 * @brief Set to 0 or 1 the digital output LED_SW0 (GSM LED)
 *
 * @param wValue Value (0 or 1) to write.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_LED_SW0( unsigned char wValue );

/**
 * @brief Get the actual value of LED_SW0 (GSM LED)
 *
 * @param *wValue Read value (0 or 1) .
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Get_LED_SW0( unsigned char *wValue );

/**
 * @brief Set LED_SW0 (GSM LED) as output to 0 (user control of led).
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_LED_SW0_Output( void );

/**
 * @brief Set LED_SW0 (GSM LED) as input (GSM module control of led).
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_LED_SW0_Input( void );

/**
 * @brief Set to 0 or 1 the digital output PPS_GPS (GPS LED)
 *
 * @param wValue Value (0 or 1) to write.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_PPS_GPS( unsigned char wValue );

/**
 * @brief Get the actual value of PPS_GPS (GPS LED)
 *
 * @param *wValue Read value (0 or 1).
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Get_PPS_GPS( unsigned char *wValue );

/**
 * @brief Set PPS_GPS (GPS LED) as output to 0 (user control of led).
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_PPS_GPS_Output( void );

/**
 * @brief Set PPS_GPS (GPS LED) as input (GPS module control of led).
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_PPS_GPS_Input( void );

/**
 * @brief Set to 0 or 1 the digital output LED_SW1
 *
 * @param wValue Value (0 or 1) to write.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_LED_SW1( unsigned char wValue );

/**
 * @brief Get the actual value of LED_SW1
 *
 * @param *wValue Read value (0 or 1).
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Get_LED_SW1( unsigned char *wValue );

/**
 * @brief Set to 0 or 1 the digital output LED_SW2
 *
 * @param wValue Value (0 or 1) to write.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_LED_SW2( unsigned char wValue );

/**
 * @brief Get the actual value of LED_SW2
 *
 * @param *wValue Read value (0 or 1).
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Get_LED_SW2( unsigned char *wValue );

/**
 * @brief Set the desired digital outputs to 0 or 1.
 *
 * @param wOutput Number of output to write to, 0...9
 * @param wValue Value to write (0 or 1).
 * @return NO_ERROR if success. Specific error number if fails.
 */
	int DIGIO_Set_DOUT( unsigned char wOutput, unsigned char wValue );

/**
 * @brief Write all digital outputs.
 *
 * @param wOutput Bits 0...9. 0: Leave output as it is, 1: Change output.
 * @param wValue Bits 0...9, values of outputs to change
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_All_DOUT( unsigned short int wOutput, unsigned short int wValue );

/**
 * @brief Switch GSM module ON or OFF.
 *
 * @param wValue 0: OFF, 1: ON.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Switch_GSM_ON_OFF( unsigned char wValue );
   
/**
 * @brief Get the GSm POWER IND signal value.
 *
 * @param *wValue Read value (0 or 1).
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Get_PWR_IND( unsigned char *wValue );

/**
 * @brief Enable or disable the Wifi module
 *
 * @param wValue 0: DISABLE Disable Wifi, 1: ENABLE Enable Wifi
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Enable_Wifi(unsigned char wValue);

/**
 * @brief Enable or disable the BT module
 *
 * @param wValue 0: DISABLE Disable BT, 1: ENABLE Enable BT
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Enable_Bluetooth(unsigned char wValue);

/**
  * @brief Enable or disable RS485
  *
  * This function enables the RS485, that is multiplexed with the kline1 in UART2
  *
  * @param wValue 0: DISABLE Disable RS485, 1: ENABLE Enable RS485
  * @return NO_ERROR if success. Specific error number if fails.
*/
   int DIGIO_Enable_RS485( char wValue );

/**
  * @brief Enable or disable Kline1
  *
  * This function enables the Kline1, that is multiplexed with the RS485 in UART2
  *
  * @param wValue 0: DISABLE Disable Kline1, 1: ENABLE Enable Kline1
  * @return NO_ERROR if success. Specific error number if fails.
*/
   int DIGIO_Enable_KLINE(unsigned char wValue);

/**
 * @brief Set the working threshold levels of Kline1
 *
 * Sets the threshold at which the Kline1 works with the level indicated
 *
 * @param wValue 0: LOW Thershold, 1: HIGH Threshold
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_KLINE1_Threshold( char wValue );

/**
 * @brief Set the working threshold levels of Kline2
 *
 * Sets the threshold at which the Kline2 works with the level indicated
 *
 * @param wValue 0: LOW Thershold, 1: HIGH Threshold
 * @return NO_ERROR if success. Specific error number if fails.
*/
  int DIGIO_Set_KLINE2_Threshold( char wValue );

/**
 * @brief Get the value of the desired input.
 *
 * @param wInput Number of input to read, 0...9
 * @param *wValue Read value (0 or 1).
 * @return NO_ERROR if success. Specific error number if fails.
 */
	int DIGIO_Get_DIN( unsigned char wInput, unsigned char *wValue );

/**
 * @brief Read all the digital inputs.
 *
 * @param *wValue Bits 0...9. Value of inputs 0 to 9
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Get_All_DIN( unsigned short int *wValue );

/**
 * @brief Configures the interruption service for each digital input signal.
 *
 * For all digital inputs, it is possible to configure an interrupt service on
 * the system in such a way that if a change is given in that digital input the
 * system notifies the application by means of a callback function.
 *
 * @param wInput Inputs that can interrupt are DIGITAL_INPUT_[0..9] and PWR_FAIL
 * @param wEdge Edge to interrupt: 0 for falling edge, 1 for rising edge, 2 for both
 * @param *wHandler Function handler that will be executed on each interruption
 * @param wNumInts Number of interrupts to execute the handler function
 * @return NO_ERROR if success. Specific error number if fails.
 * @warning for changing interrupt configuration, first remove the interrupt service
 *    and then configure the interrupt service again.
 */
   int DIGIO_ConfigureInterruptService( unsigned char wInput, unsigned char wEdge, void(*wHandler)(input_int_t), unsigned short int wNumInts);

/**
 * @brief Get the number of times that the processor has been interrupted.
 *
 * @param wInput Number of input, 0...9 and PWR_FAIL
 * @param *pTotal Number of interruptions got from wInput.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_GetNumberOfInterrupts( unsigned char wInput, unsigned long *pTotal);

/**
 * @brief Removes the interruption service for each digital input signal.
 *
 * @param wInput Digital input identifier, 0....9 and PWR_FAIL.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_RemoveInterruptService( unsigned char wInput);

/**
 * @brief Enable or disable the Vout output
 *
 * @param wValue 0: Deactivate Vout, 1: Activate Vout
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_VOUT( unsigned char wValue );

/**
 * @brief Gets the status of the output Vout
 *
 * @param *wValue Status of the Vout output. 
 *                0: Vout status FAIL. Overcurrent or overtemperature condition, it remains to 0 until the overcurrent or overtemperature condition is removed, 
 *                1: Vout status OK
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Get_VOUT_STATUS( unsigned char *wValue );

/**
 * @brief Set any of the possible analog voltage ranges to the analog inputs, which are read with function @ref ANAGIO_GetAnalogIn()
 *
 * @param wRange Analog input. 0 -> AD0, 1 -> AD1, 2 -> AD2, 3 -> AD3
 * @param wValue Range. 0 -> 0V to 5.12V, 1 -> 0V to 30.72V (default range: 0 to 5.12V)
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_ADC_RANGE( unsigned char wRange, unsigned char wValue );

/**
 * @brief Reads the value converted in analogic inputs AIN0, AIN1, AIN2 and AIN3. There are two possible voltage ranges to work with the analog inputs, that can be set with the function @ref DIGIO_Set_ADC_RANGE()
 *
 * @param anag_nbr 0: AIN0, 1: AIN1, 2: AIN2, 3: AIN3
 * @param *value 12 bits readed value
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int ANAGIO_GetAnalogIn( int anag_nbr, int *value );

/**
 * @brief Gets the value of PWR_FAIL internal input
 *
 * @param *wValue 0: PWR_FAIL down, the unit is being powered externally
 *                1: PWR_FAIL up, the unit is being powered with the optional battery
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Get_PWR_FAIL( unsigned char *wValue );

/**
 * @brief Selects battery as main power supply input.
 *
 * @param wValue 0: External is main power supply input.
 *               1: Battery is main power supply input.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Select_Power_Supply_Internal_Battery( unsigned char wValue );

/**
 * @brief Sets the audio path to either GSM or main CPU
 *
 * @param wValue 0: Main CPU control audio. 1: GSM module control audio
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_Audio_Path( unsigned char wValue );

/**
 * @brief Enable/Disables CAN1, CAN2 and also CAN3 and CAN4 if they are installed in the unit.
 *
 * @param wValue 0: Disable CAN, 1: Enable CAN
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Enable_Can( char wValue);

/**
 * @brief Set the ETHERNET ON signal to 0 or 1.
 *
 * @param wValue Value (0 or 1) to write.
 * @return NO_ERROR if success. Specific error number if fails.
 */
	int DIGIO_Set_ETH_ON( unsigned char wValue );

   // iButton
/**
 * @brief Resets the one wire bus.
 *
 * It can be used to read from the memory of an iButton, using this function
 * along IBUTTON_ReadByte() and IBUTTON_WriteByte()
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IBUTTON_Reset( void);

/**
 * @brief Read a byte from the memory of an iButton.
 *
 * @param *pData Buffer where a byte from the memory of the iButton will be copied to
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IBUTTON_ReadByte( unsigned char *pData);

/**
 * @brief Read data from IBUTTON
 *
 * Read specified amount of data. If more than one IBUUTON connected error.
 *
 * @param wAddress Offset in device address
 * @param wSize Number of bytes
 * @param *pData Buffer where data is stored
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IBUTTON_ReadData(unsigned short int wAddress, unsigned short int wSize, char *pData);

/**
 * @brief Writes a byte in the memory of an iButton
 *
 * @param Data Byte sent to the one wire bus
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IBUTTON_WriteByte( unsigned char Data);

/**
 * @brief Reads the ID of the connected iButton.
 *
 * This function can be used if the programmer wants to read this ID
 * by polling for it instead of using the interruption.
 *
 * @param *pData Value of the connected iButton ID
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IBUTTON_ReadID( unsigned char *pData);

/**
 * @brief Configures the interruption for the iButton input
 *
 * @param *wHandler Handler function to be executed when the interruption is raised.
 *                  (unsigned char *) stores ID of the iButton detected
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IBUTTON_CfgInt( void(*wHandler)(unsigned char *));

/**
 * @brief Removes the interruption to get the ID from the iButton.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int IBUTTON_RemoveInt( void);

/**
 * @brief Returns the list of devices found on the 1-wire bus.
 *
 * This can be used to get the ID of 1-wire temperature sensors and one
 * iButton ID in the bus. The maximum 1-wire admited devices number are 16
 *
 * @param **OneWireROMList Estructure where the IDs are copied
 * @param *OneWireROMListSize Size of the list completed after the 1-wire discover process
 * @return NO_ERROR if success. Specific error number if fails.
 * @warning This function can not be used simultaneously with IBUTTON functions, if
 *    iButton interruption is enabled remove first the interruption with function
 *    IBUTTON_RemoveInt() before calling OW_Discover()
 */
   int OW_Discover(OneWireTable_t **OneWireROMList, unsigned char *OneWireROMListSize);

/**
 * @brief Configures the 1-wire interruption to control the connected devices, temperature
 *    sensors and iButton
 *
 * @param *wHandler Handler to the function to the callback function to execute when
 *    there is a change in the 1-wire bus, with the following parameters:
 *    OneWireTable_t *: Status and ID of the connected/disconnected 1-wire devices
 *    unsigned char: Number of updates devices in the bus
 *    int : Possible error: ERROR_OW_DISCOVERING / ERROR_OW_TOO_MANY_DEVICES
 * @param time ime in 100ms steps, with minimum 1 (100ms) and maximum of 50 (5000ms)
 * @return NO_ERROR if success. Specific error number if fails.
 * @warning This function can not be used simultaneously with IBUTTON functions, if
 *    iButton interruption is enabled remove first the interruption with function
 *    IBUTTON_RemoveInt() before calling OW_SetUpdate()
 */
	int OW_SetUpdate(void(*wHandler)(OneWireTable_t *, unsigned char, int), unsigned char time);

/**
 * @brief Resets (stops) the update of devices on 1-wire bus
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
	int OW_ResetUpdate( void);

  /**
   * @brief Enables UART5 or flow control for UART4
   *
   * @param wValue 1: Enable UART5, 0: Enable RTS/CTS for UART4
   * @return NO_ERROR if success. Specific error number if fails.
   */
     int DIGIO_Enable_Uart5( unsigned char wValue );

  /**
   * @brief Enables and disables the uSD card. This function can be used reset the uSD
   *    in case it fails to mount correctly
   *
   * @param wValue 1: Activates the uSD card, 0: Deactivates the uSD card
   * @return NO_ERROR if success. Specific error number if fails.
   */
     int DIGIO_Set_SD_Card( unsigned char wValue );

  /**
   * @brief Gets the activation state of the USB A
   *
   * @param wValue 1: USB A activated,  0: USB A deactivated
   * @return NO_ERROR if success. Specific error number if fails.
   */
     int DIGIO_Get_USB_A( unsigned char *wValue );

     /**
 * @brief Sets the I/O line that controls the CAN1 SLOPE
 *
 * @param wValue: 0: Fast TX, 1: Disable TX, 2: Slow TX
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_CAN1_TX_Mode( char wValue );

   /**
 * @brief Sets the I/O line that controls the CAN2 SLOPE
 *
 * @param wValue: 0: Fast TX, 1: Disable TX, 2: Slow TX
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_CAN2_TX_Mode( char wValue );

   /**
 * @brief Sets the I/O line that controls the CAN3 SLOPE
 *
 * @param wValue: 0: Fast TX, 1: Disable TX, 2: Slow TX
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_CAN3_TX_Mode( char wValue );

   /**
 * @brief Sets the I/O line that controls the CAN4 SLOPE
 *
 * @param wValue: 0: Fast TX, 1: Disable TX, 2: Slow TX
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_CAN4_TX_Mode( char wValue );

   /**
 * @brief Switch GNSS module ON/OFF
 *
 * @param wValue: 0: OFF, 1: ON
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Switch_GPS_ON_OFF( unsigned char wValue );

   
   /**
 * @brief Selects SIM Card interface.
 *
 * @param wValue: 0: MFF2 SIM Card, 1: Secondary SIM Card.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int DIGIO_Set_SIM_SEL( unsigned char wValue );

   #ifdef __cplusplus
    }
   #endif

#endif /* __IOS_MODULEDEFS_H */
