/**
 * @file GPS2_ModuleDefs.h
 * @author Owasys
 * @date 03 Aug 2017
 * @brief File containing definitions for Owasys GPS2 API.
 *
 */

#ifndef __GPS2_MODULEDEFS_H

   #define __GPS2_MODULEDEFS_H

   #ifdef __cplusplus
    extern "C"{
   #endif

//-----------------------------------------------------------------------//
//System Includes
//-----------------------------------------------------------------------//
   #include <dlfcn.h>
	#include <termios.h>


//-----------------------------------------------------------------------//
//Defines
//-----------------------------------------------------------------------//
   #define		COM1  	0
   #define		COM2  	1
   #define		COM3  	2
   #define		COM4  	3
   #define		COM5  	4
   #define		COM6  	5

   #define		MAX_RECEIVER_NAME	20
   #define		MAX_PROTOCOL_NAME	10

   //ANTARIS Acquisition and Tracking sensitivity settings
   #define     NORMAL_ACQUISITION            0
   #define     FAST_ACQUISITION              1
   #define     HIGH_SENSITIVITY_ACQUISITION  2

   //Fixing Position mask flags
   #define FLAG_NONE     0x0000
   #define FLAG_NF       0x0001  /**< NF No Fix */
   #define FLAG_DR       0x0002  /**< DR Dead reckoning only solution */
   #define FLAG_G2       0x0004  /**< G2 Stand alone 2D solution */
   #define FLAG_G3       0x0008  /**< G3 Stand alone 3D solution */
   #define FLAG_D2       0x0010  /**< D2 Differential 2D solution */
   #define FLAG_D3       0x0020  /**< D3 Differential 3D solution */
   #define FLAG_RK       0x0040  /**< RK Combined GPS + dead reckoning solution */
   #define FLAG_TT       0x0080  /**< TT Time only solution */

   #define ALL_FIX_FLAGS (FLAG_NF | FLAG_DR | FLAG_G2 | FLAG_G3 | FLAG_D2 | FLAG_D3 | FLAG_RK | FLAG_TT)

   //Fix Status
   #define STATUS_NF       0  /**< NF No Fix */
   #define STATUS_DR       1  /**< DR Dead reckoning only solution */
   #define STATUS_G2       2  /**< G2 Stand alone 2D solution */
   #define STATUS_G3       3  /**< G3 Stand alone 3D solution */
   #define STATUS_D2       4  /**< D2 Differential 2D solution */
   #define STATUS_D3       5  /**< D3 Differential 3D solution */
   #define STATUS_RK       6  /**< RK Combined GPS + dead reckoning solution */
   #define STATUS_TT       7  /**< TT Time only solution */

//-----------------------------------------------------------------------//
//Type definitions
//-----------------------------------------------------------------------//

   typedef enum {
      GGA=0,
      GLL=1,
      GSA=2,
      GSV=3,
      RMC=4,
      VTG=5,
      ZDA=7,
      PSRF161=9
   }MSGNMEA;

   typedef struct {
      unsigned short Degrees;
      unsigned char  Minutes;
      double         Seconds;
      char           Dir;
   }TGPS_COORD;

   typedef struct {   //Geodetic position type
      TGPS_COORD  Latitude,
                  Longitude;
      int         DataValid;
   }TGPS_POS;

   typedef struct {   //Speed and course type
      float  speed_in_knots;
      float  speed_in_mph;
      float  speed_in_kmh;
      float  course_over_ground;
   }TGPS_SPEED;

   typedef enum {
      RATE_NO_MSG,
      RATE_POSITION,
      RATE_SPEED,
      RATE_GGA,
      RATE_GLL,
      RATE_GSA,
      RATE_GSV,
      RATE_RMC,
      RATE_VTG,
      RATE_ZDA,
      RATE_PSRF161,
      RATE_MSS
   }rateMsgType_e;

   typedef struct {
      rateMsgType_e   rateMsgType;
      TGPS_POS        Coordenates;
      TGPS_SPEED      Speed;
      char            Message[256];
   }TRATE_MESSAGE;

   typedef struct {   //GPS module configuration type
      char          DeviceReceiverName[MAX_RECEIVER_NAME];
      speed_t       ParamBaud;
      int           ParamParity;
      unsigned char ParamLength;
      char          ProtocolName[MAX_PROTOCOL_NAME];
      unsigned char GPSPort;
   } TGPS_MODULE_CONFIGURATION;

   typedef enum {     //antenna status possible values for TIM gps
      ANTENNA_ON_OK = 0,
      OPEN_CIRCUIT,
      SHORT_CIRCUIT,
      ANTENNA_OFF,
      PASSIVE_ANTENNA,
      VALUE_NOT_VALID
   }AntennaStatusValue;

   typedef	struct {    //TIM antenna status type
      AntennaStatusValue Status;
      unsigned char      AGC;
   }TANTENNA_STATUS;

   typedef enum {       //antenna status possible values for new Antaris gps
      INIT = 0,
      STATUS_DONTKNOW,  /**< active antenna supervisor is not configured and deactivated */
      OK,               /**< active antenna connected and powered */
      SHORTCIRCUIT,     /**< antenna short */
      OPEN              /**< antenna not connected or antenna defective */
   }tAntennaStatusValue;

   typedef enum {       //antenna power state possible values for new Antaris gps
      OFF = 0,
      ON,
      POWER_DONTKNOW
   }tAntennaPowerValue;

   typedef struct {      //ANTARIS antenna status type
      tAntennaStatusValue  A_Status;
      tAntennaPowerValue   A_Power;
   }tANTENNA_NEW_STATUS;

   typedef enum {
      HOT_START = 1,
      WARM_START,
      WARM_START_WITH_INIT,
      COLD_START,
      CLEAR_MEMORY = 8
   }START_TYPE;
   /**
   * @brief UTC date and time type
   *
   */
   typedef struct {
      unsigned char Hours;     /**< 00...23 */
      unsigned char Minutes;   /**< 00...59 */
      float         Seconds;   /**< 00.00...59.99 */
      unsigned char Day;       /**< 01...31 */
      unsigned char Month;     /**< 01...12 */
      int           Year;      /**< 4 digit year */
   }TUTC_DATE_TIME;
   /**
   * @brief ECEF coordinates type
   *
   */
   typedef struct {
      int    Px;         /**< X position in centimeters */
      int    Py;         /**< position in centimeters */
      int    Pz;         /**< Z position in centimeters */
      int    Vx;         /**< X velocity in cm/sec */
      int    Vy;         /**< Y velocity in cm/sec */
      int    Vz;         /**< Z velocity in cm/sec */
   }tECEF_COORDINATES;
   /**
   * @brief ESF Measurement data for Dead Reckoning Ublox6R
   *
   */
   typedef struct {
      int    Odom;     /**< Odometer speed value */
      double Gyro;     /**< Gyroscope value */
      double Temp;     /**< Temperature value */
   }tESF_MEAS;
   /**
   * @brief UTM coordinates type, only for ANTARIS gps
   *
   */
   typedef struct {
      double        East;         /**< UTM easting in cm */
      unsigned char LongitudeDir; /**< Longitude direction ('E'=East, 'W'=West) */
      double        North;        /**< UTM northing in cm */
      unsigned char Hemisphere;   /**< Hemisphere indicator ('N'=north, 'S'=south) */
      unsigned char Zone;         /**< UTM zone number */
      double        Altitude;     /**< Altitude in meters */
      char          NavStatus[3]; /**< Navigation status */
   }tUTM_COORDINATES;
   /**
   * @brief Geodetic coordinates type
   *
   */
   typedef struct {
      TGPS_COORD  Latitude,        /**< Latitude */
                  Longitude;       /**< Longitude */
      double      Altitude;        /**< Altitude in meters */
      char        NavStatus[3];    /**< Navigation status */
   }tGEODETIC_COORDINATES;
   /**
   * @brief GNSS DOP type
   *
   */
   typedef struct {
      unsigned char PosFixMode;  // Position fix mode (0= No fix, 1=DR fix, 2=G2 fix, 3=G3 fix,
                                 // 4=D2 fix, 5=D3 fix, 6=RK fix, 7=TT fix
      float         TDOP;        /**< Time dilution of precision */
      float         HDOP;        /**< Horizontal dilution of precision */
      float         VDOP;        /**< Vertical dilution of precision */
   }tGNSS_DOP_SV;
   /**
   * @brief Stellites in view data
   *
   */
   typedef struct {
      unsigned char SV_Id;         /**< Satellite id */
      unsigned char SV_Elevation;  /**< SV elevation in degrees */
      short int     SV_Azimuth;    /**< SV azimuth in degrees */
      char          SV_SNR;        /**< C/No ratio, range 0 to 99, null when no tracking */
   }tSV_Data;

   typedef struct {   //GNSS SV in view type
      unsigned char SV_InView;
      tSV_Data      SV[64];
   }tGSV_Data;

   typedef struct {  //Datum parameters
         short   datumNum;
         char    datumName[6];
         double  majA;
         double  flat;
         float    dX;
         float    dY;
         float    dZ;
         float    rotX;
         float    rotY;
         float    rotZ;
         float    scale;
      }tDATUM;
  /**
  * @brief Position data
  *
  */
	typedef struct {
      unsigned char  PosValid;         /**< Valid Fix (according to configuration) */
		unsigned char	OldValue;			/**< Data not updated */
		TGPS_COORD 		Latitude,			/**< Latitude */
							Longitude;			/**< Longitude */
		double 			Altitude;			/**< Altitude in meters */
		char				NavStatus[3];		/**< Navigation status */
		double			HorizAccu;			/**< Horizontal Accuracy */
		double			VertiAccu;			/**< Vertical Accuracy */
		double			Speed;				/**< Speed over ground */
		double			Course;				/**< Course over ground */
		double			HDOP;					/**< Horizontal dilution of precision */
		double			VDOP;					/**< Vertical dilution of precision */
		double			TDOP;					/**< Time dilution of precision */
		unsigned char	numSvs;				/**< Number of satellites used in the navigation solution */
      double         LatDecimal;       /**< Latitude     negative degrees means South */
      double         LonDecimal;       /**< Longitude    negative degrees means West */
	}tPOSITION_DATA;

	typedef struct {    //Survey-in data
      unsigned int TimeOfWeek;      /**< GPS time of week in msecs */
      char SurveyStatus;            /**< Survey-in status: 1->"In progress" otherwise 0 */
      char MeanPosValid;            /**< Survey-in position valid: 1->"Yes" */
      unsigned int ObservationTime; /**< Observation time in seconds */
      unsigned int PositionsUsed;   /**< Number of position observations */
      double MeanPosAcc;            /**< Current survey-in mean position accuracy in meters */
      double meanX;                 /**< Current survey-in mean position ECEF X coordinate in meters */
      double meanY;                 /**< Current survey-in mean position ECEF Y coordinate in meters */
      double meanZ;                 /**< Current survey-in mean position ECEF Z coordinate in meters */
   }tNAV_SVIN_DATA;

	typedef struct {           //TMODE3 data
      unsigned char  mode;          /**< Receiver mode: 0 Disable, 1 Survey In, 2 Fixed Mode, 3-255 Reserved */
      char           units;         /**< Position is given in ECEF(0) or LAT/LON/ALT(1) */
      double         ecefX;         /**< ECEF X coorinate in meters */
      double         ecefY;         /**< ECEF Y coorinate in meters */
      double         ecefZ;         /**< ECEF Z coorinate in meters */
      double         FixPosAccu;    /**< Fixed position accuracy in meters */
      unsigned int   svinMinDur;    /**< Survey In minimum duration */
      double         SurveyPosAccu; /**< Survey In position accuracy in meters */
   }t_TMODE3_DATA;

	typedef struct {    //UBX-NAV-SOL data
		unsigned char	OldValue;      /**< Data is not updated */
      double         TimeOfWeek;    /**< GPS time of week in seconds */
      short int      WeekNumber;    /**< GPS week number */
      unsigned char  gpsFix;        /**< GPSFix. 0: NoFix, 1: DR only, 2: 2D-Fix, 3: 3D-Fix, 4: GPS+DR, 5: Time only fix */
      char           flags;         /**< Fix status flags. 0x01: Fix within limits, 0x02: DGPS used, 0x04: Valid GPS week number, 0x08: Valid GPS time of week. */
      double         ecefX;         /**<ECEF X coorinate in meters */
      double         ecefY;         /**<ECEF Y coorinate in meters */
      double         ecefZ;         /**<ECEF Z coorinate in meters */
      double         PosAccu;       /**<3D Position Accurate Estimate */
      double         ecefVX;        /**<ECEF X velocity in m/s */
      double         ecefVY;        /**<ECEF Y velocity in m/s */
      double         ecefVZ;        /**<ECEF Z velocity in m/s */
      double         SpeedAccu;     /**<Speed Accuracy Estimate in m/s */
      int            PositionDOP;   /**<Position DOP (Scaling 0.01) */
      unsigned char  numSV;         /**<Number of SVs used in Nav Solution */
   }tNAV_SOL_DATA;

/**
 * @brief  Configures the GPS module.
 *
 * To start the GPS, the RTUControl and IOs libraries must be loaded before any GPS operation.
 *
 * @param *wConfiguration It must contain an structure with the GPS configuration parameters.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_Initialize( void *wConfiguration );

/**
 * @brief Startup of the GPS receiver.
 *
 * To start the GPS, the RTUControl and IOs libraries must be loaded before any GPS operation.
 * If the FncGPS_Start() Function returns an error, the user must finalize the GPS calling
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_Start( void );

/**
 * @brief Check for the correct operation of the GPS module.
 *
 * @param *wActive 0: Not active, 1: Active.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_IsActive( int *wActive );

/**
 * @brief Stop execution of the GPS module and switches the GPS off.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_Finalize( void );

/**
 * @brief Return the GPS2 library version.
 *
 * @param *wVersion Contains the returned version code. Format "CYA 999 9999, x.x.x"
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetVersion( unsigned char *wVersion );

/**
 * @brief Get all the GPS data received and available in memory.
 *
 * @param *pCurCoords Retrived GPS data.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetAllPositionData( tPOSITION_DATA *pCurCoords );

/**
 * @brief Gets the GPS receiver position.
 *
 * If the GPS has not computed a valid position, the DataValid field in the
 * structure TGPS_POS value is set to FALSE.
 *
 * @param *pCurCoords Latitude/longitude position coordinates.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetPosition_Polling( TGPS_POS *pCurCoords );

/**
 * @brief Get the speed (kmh, mph and knots) and course over ground. 
 * 
 * This function is kept in the GPS2 library from the old GPS library 
 * to be backward compatible
 *
 * @param *pCurSpeed GPS speed and cours data.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetSpeedCourse_Polling( TGPS_SPEED *pCurSpeed );

/**
 * @brief Get the UTC (Universal Time Coordinated) Date and Time.
 * 
 * This function is kept in the GPS2 library from the old GPS library 
 * to be backward compatible
 *
 * @param *pDateTime UTC date and time from GPS.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetUTCDateTime( TUTC_DATE_TIME *pDateTime );

/**
 * @brief Get the status of a GPS active antenna
 *
 * @param *pStatus Active antenna status.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetStatusAntenna( tANTENNA_NEW_STATUS *pStatus );

/**
 * @brief This function gets the ANTARIS GPS geodetic coordinates.
 *
 * @param *pGEODETIC_Coord Latitude, longitude coordinates, altitude and navigation status.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetGeodetic_Coordinates( tGEODETIC_COORDINATES *pGEODETIC_Coord );

/**
 * @brief This function gets the satellites in view used in the navigation calculation.
 *
 * These data will be available even when there is not GPS coverage, and in such
 * case the SNR will take a value of 0.
 *
 * @param *pData Number of satellites in view and elevation and azimuth for each one.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetSV_inView( tGSV_Data *pData );

/**
 * @brief This function gets the GPS firmware version.
 *
 * @param *pData GPS firmware version string.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_Get_Software_Version( char *pData );

/**
 * @brief Enable or disable the jamming information feature
 *
 * @param mode Enable(1) / disable(0) jamming calculation. Default is 0
 * @param bbthres Broadband jamming detection threshold (dB). Default is 3. Possible values 0..15
 * @param cwthres Continous wave jamming detection threshold (dB). Default is 15. Possible values 0..31
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_Configure_ITFM( char mode, char bbthres, char cwthres );

/**
 * @brief Poll for the jamming state
 *
 * @param *pStatus Jamming status. Possible values 0..3
 *    - 0: unknown or feature disabled
 *    - 1: ok - no significant jamming
 *    - 2: warning - interference visible but fix OK
 *    - 3: critical - interference visible and no fix
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetStatusJamming( char *pStatus );

/**
 * @brief Use this function to customize some gps receiver navigation filters.
 *
 * @param MinSV defines the minimum number of satellites to give a valid navigation solution,
 *    range 0..16 (0=no change default). By default is set to 3 satellites.
 *    - Note that a solution using only 3 satellites (2D fix) could give a worse accuracy
 *    that a solution using 4 or more satellites (3D fix).
 * @param MinEle It defines the minimum satellite elevation to use in the navigation
 *    calculation, range 5..20 (0=no change). By default is set to 5 degrees.
 *    - Low elevation satellites may provide degraded accuracy because of the long signal
 *    path through the atmosphere
 * @param PDOP It defines the maximum position dilution of precision of the navigation
 *    solution from being output, range 0..25 (0=no change default) By default is set to 25.
 *    - Note that if you choose a PDOP under 25 you will pevent poor quality solution
 *    from being output.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_SetNavigationConfig( unsigned char MinSV, unsigned char MinEle, short int PDOP );

/**
 * @brief Configure the criteria to decide when position is valid.
 *
 * @param wMask is the decimal value of the 16bit mask. Possible values are
 *    FLAG_NF, FLAG_DR, FLAG_G2, FLAG_G3, FLAG_D2, FLAG_D3, FLAG_RK, FLAG_TT. Default
 *    value is (FLAG_D3 | FLAG_G3)
 * @param wHAccu Maximum horizontal accuracy. Default value is 30 meters
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_SetFixConfig( short int wMask, unsigned int wHAccu);

/**
 * @brief Get the configured criteria to decide when position is valid.
 *
 * @param *pMask 16bit mask. Possible values are FLAG_NF, FLAG_DR, FLAG_G2, FLAG_G3,
 *    FLAG_D2, FLAG_D3, FLAG_RK, FLAG_TT.
 * @param *pHAccu Maximum horizontal accuracy.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetFixConfig( short int *pMask, unsigned int *pHAccu);

/**
 * @brief Return the GPS receiver model.
 *
 * @param *pBuffer Contain the returned GPS model
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_Get_Model( char *pBuffer );

/**
 * @brief Return the "Relative Positioning Information in NED frame" message from the GPS receiver.
 *
 * @param *pBuffer Contains the message UBX-NAV-RELPOSNED in binary format.
 * @param *pLen length of the message.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetRELPOSNED_Data( char *pBuffer, int *pLen ); // ****

/**
 * @brief Sends a RTCM message to the GPS receiver.
 *
 * Those messages are intended for Differential GPS mode. Consult external standard RTCM messages.
 *
 * @param *pMessage RTCM string to be sent to the GPS.
 * @param Len Lenght of pMessage.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_Send_DGPS_Message( char *pMessage, int Len );

/**
 * @brief Use this function to get a message containing the navigation configuration parameters.
 *
 * @param *pBuffer Pointer to the buffer containing the UBX-NAV-SBAS message in binary format.
 * @param *pLen Length of the message.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetCFG_NAV( char *pBuffer, int *pLen ); // ****

/**
 * @brief Use this function to get a message containing NAVX5 information.
 *
 * With this message the Assist Now Autonomous mode can be get.
 *
 * @param *pBuffer Pointer to the buffer containing the CFG-NAVX5 message in binary format.
 * @param *pLen Length of the message.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetNAVX5_Data( char *pBuffer, int *pLen ); // ****

/**
 * @brief Enable/disable the Assit Now Autonomous mode of the GNSS receiver.
 *
 * Enabling this mode the receiver calculates the orbit of the satellites to get
 * a faster fix when starting after more than two hours off.
 *
 * @param mode 0: Disable Assit Now Autonomous feature(default mode).
 *    - 1: Enable Assist Now Autonomous feature
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_SetANA( char mode);

/**
 * @brief Set the setting of sensitivity for acquisition and tracking in the GPS module
 *
 * @param GpsMode 0: Normal, 1: Fast Acquisition, 2:  High Sensitivity (Default value)
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_SetGpsMode( char GpsMode );

/**
 * @brief Set the setting for the dynamic platform model in the GPS receiver.
 *
 * @param DynamicModel Possible options:
 *    - 0 Portable (Default value)
 *    - 2 Stationary
 *    - 3 Pedestrian
 *    - 4 Automotive
 *    - 5 Sea
 *    - 6 Airbone < 1g
 *    - 7 Airbone < 2g
 *    - 8 Airbone < 4g
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_SetDynamicModel( char DynamicModel );

/**
 * @brief Set the speed threshold for gps navigation solution.
 *
 * If the speed goes below this threshold the gps position is kept constant.
 *
 * @param Threshold Static hold threshold value in cm/s. Default value is 0.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_SetStaticThreshold( unsigned char Threshold );

/**
 * @brief Get the dilution of precision parameters and the position fix mode used by the gps receiver.
 *
 * @param *pDOP_SV Dilution of precision parameters and position fix mode.
 *    - Note: in this API "PosFixMode" field of tGNSS_DOP_SV can be one of STATUS_NF,
 *    STATUS_DR, STATUS_G2, STATUS_G3, STATUS_D2, STATUS_D3, STATUS_RK, STATUS_TT
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetDOP_FixMode( tGNSS_DOP_SV *pDOP_SV ); // ****

/**
 * @brief Get the GPS ECEF coordinates.
 *
 * @param *pECEF_Coord GPS ECEF coordinates.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetECEF_Coordinates( tECEF_COORDINATES *pECEF_Coord );

/**
 * @brief Set the Navigation/Measurement Rate.
 *
 * @param measRate This can be 1Hz, 2Hz, 4Hz or 10Hz.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_SetMeasurementRate( char measRate);

/**
 * @brief Get the Navigation/Measurement Rate.
 *
 * @param *measRate Value of actual Rate setting.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetMeasurementRate( char *measRate);

/**
 * @brief Enable/disable reception of RTCM3 messages from GPS receiver.
 *
 * When this function is called to enable any message Navigation/Measurement Rate is
 * set to 1Hz and reception of GPS position data is disabled.
 *
 * @param mask Mask with messages to be enabled/disable. Possible values
 *    ENABLE_RTCM3_1005, ENABLE_RTCM3_1077, ENABLE_RTCM3_1087
 * @param *wHandler function handler to be called when RTCM3 message is received.
 *    Code inside this handler must be as short and fast as possible. Best option is just
 *    take data and proccess it somewhere else in the program.
 * @return NO_ERROR if success. Specific error number if fails.
 * @warning Only available for M8P GPS modules
 */
   int GPS_EnableRTCM3( char mask, void(*wHandler)( char *, int) );

/**
 * @brief Allow to enter the GPS receiver in Time Mode (Fix Mode).
 *
 * When this function is called Navigation/Measurement Rate is set to 1Hz and
 * reception of GPS position data is disabled.
 *
 * @param ecefx ECEF X coorinate in meters (x.xxxx)
 * @param ecefy ECEF Y coorinate in meters (x.xxxx)
 * @param ecefz ECEF Z coorinate in meters (x.xxxx)
 * @param accuracy Fixed position 3D accuracy in meters (x.xxxx)
 * @return NO_ERROR if success. Specific error number if fails.
 * @warning Only available for M8P GPS modules
 */
   int GPS_SetTMODE3_Fix( double ecefx, double ecefy, double ecefz, double accuracy ); // ****

/**
 * @brief Allow to enter the GPS receiver in Time Mode (Survey-in Mode).
 *
 * When this function is called Navigation/Measurement Rate is set to 1Hz and reception
 * of GPS position data is disabled.
 *
 * @param seconds Survey-in minimum duration
 * @param accuracy Survey-in position accuracy limit
 * @return NO_ERROR if success. Specific error number if fails.
 * @warning Only available for M8P GPS modules
 */
   int GPS_SetTMODE3_Survey( unsigned int seconds, double accuracy ); // ****

/**
 * @brief Allow to exit the GPS receiver of Time Mode.
 *
 * When this function is called reception of GPS position data is enabled if no RTCM3
 * messages are enabled.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 * @warning Only available for M8P GPS modules
 */
   int GPS_SetTMODE3_Disable( void ); // ****

/**
 * @brief Return actual Time Mode settings.
 *
 * @param *pData Time Mode Settings values.
 * @return NO_ERROR if success. Specific error number if fails.
 * @warning Only available for M8P GPS modules
 */
   int GPS_Get_TMODE3( t_TMODE3_DATA *pData );

/**
 * @brief Return actual Survey-in data values.
 *
 * @param *pData Survey-in data values.
 * @return NO_ERROR if success. Specific error number if fails.
 * @warning Only available for M8P GPS modules
 */
   int GPS_GetNAV_SVIN( tNAV_SVIN_DATA *pData );

/**
 * @brief Return actual Navigation Solution Information data.
 *
 * @param *pData Navigation Solution Information.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_GetNAV_SOL( tNAV_SOL_DATA *pData );

/**
 * @brief Set control path for GPS LED
 *
 * @param wMode 0: GPS module control, 1: user control.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int GPS_Set_Led_Mode( unsigned char wMode );

   #ifdef __cplusplus
    }
   #endif

#endif
