/**
 * @file      FMS_Defs.h
 * @brief     Header of FMS library:
 * @author    Owasys
 * @date      17/06/2016
 *
 * Copyright (c) 2016 OWASYS
 * All rights reserved. Permission to use, modify or copy this software in whole or in part is
 * forbidden without prior, writen consent of the copyright holder.
 **/

#ifndef _FMS_DESF_H
#define	_FMS_DESF_H

#ifdef __cplusplus
 extern "C"{
#endif

#ifdef CAN_MAX_DLEN
 #define MAX_TELLTALE_BLOCK_LEN CAN_MAX_DLEN
#else
 #define MAX_TELLTALE_BLOCK_LEN 8
#endif
#define NOF_TELLTALE_BLOCKS 5		/**< Number of Tell Tale blocks in FMS v4.00 */

#define NOF_BUS_DOORS	10			/**< Supported number of Bus doors as defined by FMS v4.00 **/
#define VI_MAX_LEN		201			/**< Vehice Identification : from 8 to 200 bytes**/
#define	DI_MAX_LEN		20			/**< Driver ID  = Issuing member state + Card Number = 3 + 16 bytes **/

	typedef struct{
		unsigned char  card_present;  /**< Card present. 00:No, 01:Yes */
		unsigned char  time_state;    /**< Time rel states. 0000: Normal 0001: 15 min before 4 1/2 h 0010: 4 1/2 h reached, 0011: 15 min before 9 h 0100: 9 h reached 0101: 15 min before 16 h 0110: 16 h reached 1110: Error 1111: not available */
		unsigned char  working_state; /**< Working state. 000: Rest, 001: Driver available, 010:Work, 011:Drive, 110:Error, 111:not available */
	}tacho_driver_t;

	typedef struct{ //Tachograph: TCO1 (PGN FE6C)
		time_t         last_change;
      float          engine_speed; /**< Tachograph vevicle speed. km/h */
      unsigned char  direction;    /**< Direction indicator. 00:Forward, 01:Reverse */
      unsigned char  performance;  /**< Tachograph performance. 00:Normal, 01:Analysis */
      unsigned char  handling_info;/**< Handling information. 00:No, 01:Yes */
      unsigned char  event;        /**< System event. 00:No, 01:Yes */
      tacho_driver_t driver1;
      tacho_driver_t driver2;
      unsigned char  motion;       /**< Vehicle motion. 00:No, 01:Yes */
      unsigned char  overspeed;    /**< Vehicle overspeed. 00:No, 01:Yes */
   }tacho_info_t;

   typedef enum{
      FMS_OFF,
      FMS_VEHICLE_STOPPED,
      FMS_VEHICLE_IDLING,
      FMS_VEHICLE_MOVING
   }status_enum_t;

   typedef struct{
      unsigned char present;
      time_t        last_change;
   }fms_event_t;

	typedef struct{ //FMS-standard Interface: FMS (PGN FDD1)
		time_t        last_change;
		char          v_bus[3];   /**< busFMS standard version supported */
		char          v_truck[3]; /**< truck FMS standard version supported */
		unsigned char diagnostic; /**< Diagnostics supported. 00:no, 01:yes, 10:reserved, 11:don't care */
		unsigned char request;    /**< Requests supported. 00:no, 01:yes, 10:reserved, 11:don't care */
	}fms_std_inter_t;

	typedef struct{ //FMS status. Calculated value
		time_t         last_change;
		status_enum_t  status;
	}fms_status_t;

	typedef struct{ //FMS ignition. Calculated value
      time_t        last_ignition_change;
		unsigned char ignition_st;  /**<  TRUE/FALSE */
	}fms_ignition_t;

	typedef struct{ //FMS idling status. Calculated value
		time_t        last_idling_change;
		unsigned char idling_st;  /**<  TRUE/FALSE */
		unsigned long idling_time;
		double        idling_avg_fuel_rate;
	}fms_idling_t;

	typedef struct{ //FMS moving status. Calculated value
		time_t        last_moving_change;
		unsigned char moving_st;
	}fms_moving_t;

	typedef struct{ //FMS Engine Temperature 1: ET1 (PGN FEEE)
		time_t      last_change;
		signed int  coolant_temp; /**<  Engine coolant temperature, ºC */
	}fms_eng_temp1_t;

	typedef struct{ //FMS Ambient Conditions: AMB (PGN FEF5)
		time_t  last_change;
		float   air_temp; /**<  Ambient Air Temperature, ºC */
	}fms_amb_condit_t;

	typedef struct{ //FMS Air Supply Pressure: AIR1 (PGN FEAE)
		time_t       last_change;
		unsigned int air_pressure1; /**<  Service Brake Air Pressure Circuit #1, kPa */
		unsigned int air_pressure2; /**<  Service Brake Air Pressure Circuit #2, kPa */
	}fms_brake_press_t;

	typedef struct{ //FMS Aftertreatment 1 Diesel Exhaust Fluid Tank 1 Information: AT1T1I (PGN FE56)
		time_t last_change;
		float  level;      /**< 0%: Empty, 100%: Full */
	}fms_diesel_t;

	typedef struct{ //FMS Electronic Engine Controller #1: EEC1 (PGN EEC1)
		time_t last_change;
		float  engine_rpm;    /**<  Engine Speed, rpm */
		char   actual_engine; /**<  Actual Engine-Percent Torque, % torque */
	}fms_eng_control1_t;

	typedef struct{ //FMS High Resolution Vehicle Distance: VDHR (PGN FEC1)
		time_t             last_change;
		unsigned long long distance;    	/**<  High resolution total vehicle distance, meters 0 to 21055406 km, meters */
	}fms_distance_t;

	typedef struct{ //FMS High Resolution Fuel Consumption (Liquid): HRLFC (PGN FD09)
		time_t last_change;
		float  hr_total_fuel; /**<  High resolution engine total fuel used, litres */
	}fms_hr_fuel_consum_t;

	typedef struct{ //FMS Fuel Consumption: LFC (PGN FEE9)
		time_t last_change;
		float  total_fuel;  /**<  Engine total fuel used, litres */
	}fms_fuel_consum_t;

	typedef struct{ //FMS Fuel Economy:LFE (PGN FEF2)
		time_t last_change;
		float  fuel_rate;     /**<  Fuel Rate, l/h */
		float  inst_fuel_eco; /**<  Instantaneous Fuel Economy , km/l */
	}fms_fuel_eco_t;

	typedef struct{ //FMS Engine Hours, Revolutions: HOURS (PGN FEE5)
		time_t last_change;
		float  engine_hours; /**<  Engine total hours of Operation, hours */
	}fms_eng_hours_t;

	typedef struct{ //FMS Dash Display: DD (PGN FEFC)
		time_t last_change;
		float  fuel_level; /**<  Fuel level 1, Ratio of the total volume, % display */
		// @important We cannot add fields to existing structures, or we break backwards compatibility
		//float  fuel_level_2; /**<  Fuel level 2, Ratio of the total volume, % display for secondary tank when two fuel types are used */
	}fms_dash_display_t;

	typedef struct{ //FMS Service Information: SERV (PGN FEC0)
		time_t last_change;
		long   service_distance; 	/**<  distance that can be travelled before service is needed, km -160635 to 160640km, km */
	}fms_serv_inform_t;

	typedef struct{ //FMS Electronic Engine Controller #2: EEC2 (PGN EEC2) [Bus only]
		time_t last_change;
		char   engine_load; /**<  % engine percent load at current speed */
      float  accelerator; /**<  Accelerator Pedal Position, % (100% is max) */
	}fms_eng_control2_t;

	typedef struct{ //FMS Cruise Control/Vehicle Speed: CCVS (PGN FEF1) [Bus only]
		time_t        last_change;
		float         engine_speed;  /**<  Wheel based speed, km/h */
		unsigned char brake;         /**<  Brake switch. 00: pedal released, 01: pedal depressed */
		unsigned char clutch;        /**<  Clutch switch. 00: pedal released, 01: pedal pressed */
		unsigned char cruise_control;/**<  Cruise control active. 00: switched off, 01: switched on */
		unsigned char parking_brake; /**<  Parking Brake Switch. 00:Not set, 01: Set */
	}fms_cruise_speed_t;

	typedef struct{
		unsigned char 	alternator[4]; /**< Alternator Status from 1 to 4. Values possible: 0 not charging, 1 charging, 2 error, 3, not available*/
		time_t 			last_change;
	}fms_as_t;

	typedef struct{
		unsigned char seconds;
		unsigned char minutes;
		unsigned char hours;
		unsigned char month;
		unsigned char day;
		unsigned int  year;
		time_t		  epoch_ts;
		time_t last_change;
	}fms_timedate_t;

	typedef struct{ //FMS Electronic Transmission Controller 2: ETC2 (PGN F005) [Bus only]
		time_t last_change;
		char   selected_gear; /**< Negative gear are reverse gears. 00000000: neutral, 11111011: park */
		char   current_gear;  /**< Negative gear are reverse gears. 00000000: neutral, 11111011: park */
	}fms_etc2_t;

	typedef struct{ //FMS Door Control 1: DC1 (PGN FE4E) [Bus only]
		time_t        last_change;
		unsigned char doors_enabled;	/**< Status of doors. 00: all doors disabled, 01: at least one bus door enabled. @note Enabled means the bus doors are able to be automatically opened or closed. */
		unsigned char doors_position; 	/**< Position of doors. 0x00: at least 1 door is open, 0x01: closing last door, 0x02: all doors closed, 0x0E: Error, 0x0F: Not available*/
		unsigned char ramp;				/**< Ramp/Wheel chairlift. 00: inside bus, 01: outside bus**/
	}fms_dc1_t;

	typedef struct{ //FMS Door Control 2: DC2 (PGN FDA5) [Bus only]
		time_t        last_change;
		struct door_status {
			unsigned char status;	/**< 00: closed = door is completely closed, 01: open = door is not completely closed **/
			unsigned char locked; 	/**< 00: locked = doors cannot be operated by the driver or a passenger, 01: unlocked = door may be operated by the driver or a passenger **/
			unsigned char enabled; 	/**< 00: disabled = door cannot be opened by a passenger, 01: enabled = door can be opened by a passenger **/
		} door[NOF_BUS_DOORS]; /**< Individual Door status **/
	}fms_dc2_t;

	typedef struct { // FMS DI information
		unsigned char present;
		char 		  driverId[DI_MAX_LEN];
		time_t		  last_change;
	}fms_driver_info_t;

	typedef struct { // FMS tell Tale status 
		unsigned char block[NOF_TELLTALE_BLOCKS][MAX_TELLTALE_BLOCK_LEN]; /**< we save all the bits in each message for processing at the applicaton level **/
		time_t 	last_change;
	}fms_tt_status_t;

	typedef struct {
		unsigned char fuel_type;	/**< Integer number identifying fuel type of the vehicle @see Table at FMS v4.00 standard for fuel types **/
		time_t last_change;
	} fms_eng_control14_t;

	typedef struct {
		unsigned int cvw; /**< The total weight of the truck and all attached trailers in kilograms **/
		time_t last_change;
	} fms_vehicle_weight_t;

	typedef struct {
		unsigned char engaged; /**< 0 no PTO drive is not engaged, 1 at least one PTO drive is engaged, 2 Error, 3 not available. Information relating to the request for engagement, consent for engagement, and status of engagement of various specific physical PTO drives. **/
		time_t last_change;
	} fms_ptode_t;

	typedef struct {
		float remaining_charge; /**< Indicates the hybrid battery pack remaining charge, in percentage. **/
		time_t last_change;
	} fms_elec_pow_t;

	typedef struct {
		float wheel_angle; /**< rad. The main operator`s steering wheel angle (on the steering column, not the actual wheel angle). The vehicle being steered to the left (counterclockwise) results in a positive steering wheel angle. This is the yaw angle of the steering wheel with the z-axis along the centerline of the steering column. **/
		time_t last_change;
	} fms_dyn_sta_ctr_t;
	
	typedef struct {
		float front_left; /**< kPa. Bellow Pressure front axle left **/
		float front_right; /**< kPa. Bellow Pressure front axle right **/
		float rear_left; /**< kPa. Bellow Pressure rear axle left **/
		float rear_right; /**< kPa. Bellow Pressure rear axle right **/
		time_t last_change;
	} fms_air_susp_ctr_t;

   typedef struct _fms_data_t{
		time_t               any_change;      /**< Any FMS message RX */
		fms_std_inter_t      std_interface;   /**< FMS-standard Interface: FMS (PGN FDD1) */
		fms_status_t         status_data;     /**< FMS status. Calculated value */
		fms_ignition_t       ignition;        /**< FMS ignition. Calculated value */
		fms_idling_t         idling;          /**< FMS idling status. Calculated value */
		fms_moving_t         moving;          /**< FMS moving status. Calculated value */
		fms_event_t          mv_no_throttle;  /**< Not used */
		tacho_info_t         tachograph;
		fms_eng_temp1_t      engine_temp;     /**< FMS Engine Temperature 1: ET1 (PGN FEEE) */
		fms_amb_condit_t     ambient_temp;    /**< FMS Ambient Conditions: AMB (PGN FEF5) */
		fms_brake_press_t    air_supply_press;/**< FMS Air Supply Pressure: AIR1 (PGN FEAE) */
		fms_diesel_t         def_level;       /**< FMS Aftertreatment 1 Diesel Exhaust Fluid Tank 1 Information: AT1T1I (PGN FE56) */
		fms_eng_control1_t   engine_control1; /**< FMS Electronic Engine Controller #1: EEC1 (PGN EEC1) */
		fms_distance_t       odometer;        /**< FMS High Resolution Vehicle Distance: VDHR (PGN FEC1) */
		fms_hr_fuel_consum_t hr_fuel_consum;  /**< FMS High Resolution Fule Consumption (Liquid): HRLFC (PGN FD09) */
		fms_fuel_consum_t    fuel_consum;     /**< FMS Fuel Consumption: LFC (PGN FEE9) */
		fms_fuel_eco_t       fuel_economy;    /**< FMS Fuel Economy:LFE (PGN FEF2) */
		fms_eng_hours_t      total_hours;     /**< FMS Engine Hours, Revolutions: HOURS (PGN FEE5) */
		fms_dash_display_t   dash_display;    /**< FMS Dash Display: DD1 (PGN FEFC) */
		fms_serv_inform_t    service_inform;  /**< FMS Service Information: SERV (PGN FEC0) */
		fms_eng_control2_t   engine_control2; /**< FMS Electronic Engine Controller #2: EEC2 (PGN EEC2) [Bus only] */
		fms_cruise_speed_t   cruise_speed;    /**< FMS Cruise Control/Vehicle Speed: CCVS (PGN FEF1) [Bus only] */
		fms_etc2_t           gear_control;    /**< FMS Electronic Transmission Controller 2: ETC2 (PGN F005) [Bus only] */
		// P1K / v1.0.6
		char 				vin[VI_MAX_LEN+1];	/**< VIN: Vehicle Identification Number. Maximum length 200 ASCII characters, as defined by FMS Standard v4.0. VI (PGN FEEC)**/
		char				di_raw[DI_MAX_LEN+4];		  /**< Driver information raw, without processing. DI (PGN FE6B) */
		fms_driver_info_t	driver[2];		/**< Driver IDs for the two possible drivers. DI (PGN FE6B) */		
		fms_tt_status_t		tell_tale_status;/**< FMS Tell Tale Status 1: FMS1 @note Interpretation of status is manufacturer dependant **/
		fms_dc1_t			doors_control;	/**< FMS Door Control 1: DC1 (PGN FE4E) [Bus only] **/
		fms_dc2_t			doors;			/**< FMS Door Control 2: DC2 (PGN FDA5) [Bus only] **/
		// P1L / v1.1.0
		fms_eng_control14_t engine_control14; /**< FMS Electronic Engine Controller #14: EEC14 (PGN FDC2) - Fuel type **/
		fms_ptode_t			ptode;			/**< FMS PTO Drive Engagement: PTODE (PGN FDA4) **/
		fms_vehicle_weight_t comb_vehicle_weight; /**< FMS Combination Vehicle Weight: CVW (PGN FE70) **/
		fms_elec_pow_t		electrical_power; /**< FMS Vehicle Electrical Power #4: VEP4 (PGN FCB7) **/
		fms_dyn_sta_ctr_t	dyn_sta_control;  /**< FMS Vehicle Dynamic Stability Control #2: VDC2 (PGN F009) **/
		fms_air_susp_ctr_t	air_susp_control; /**< FMS Air Suspension Control #4: ARC4 (PGN FE58) **/
		// P1M / v1.1.1
		fms_as_t			alternator_status;		/**< FMS Alternator Speed: AS (PGN FED5) **/
		fms_timedate_t		td;				/**< FMS Time Date: TD (PGN FEE6) **/
		// P1N / v1.1.2
   }fms_data_t;

	typedef enum{
		PGN_65484 = 0,
		PGN_65485
	}pgn_type_t;

	typedef struct _tire_data_t{
		time_t			last_change;
		pgn_type_t		pgn_number;
		unsigned char	axle_number;
		unsigned char	wheel_position;
		short int		tire_pressure;	/**< PGN_65484: 0-2500 kPa PGN_65485: 0-1035 kPa (higher than 1035 kPa reported as 1051 kpa) */
		float			tire_temp;		/**< PGN_65484: -273 to 1735 deg C PGN_65485: -17,77 to 335 deg C */
		short int		tire_deviation;	/**< PGN_65484: -1260 to +1270 kPa PGN_65485: -522 to +526 kPa */
		unsigned char	fault_bitmap;
	}tire_data_t;


	//Fault Bitmap Values
	#define	SECOND_LEVEL_PRESSURE_FAULT		0x01
	#define	FIRST_LEVEL_LOW_PRESSURE_FAULT	0x02
	#define	FIRST_LEVEL_HIGH_PRESSURE_FAULT	0x04
	#define	HIGH_TEMPERATURE_FAULT			0x08
	#define	SENSOR_FAULT					0x10
	#define	LOW_BATTERY						0x20

	#define	MAX_TIRE_NUMBER		20

	typedef struct _tpms_data_t{
		tire_data_t		TireData[MAX_TIRE_NUMBER];
	}tpms_data_t;

	typedef struct{ //EBS Propriety 1: (PGN FF00)
		time_t             last_change;
		unsigned char		 overload;		/**<  Overload. 00: no, 01: yes, 10: error, 11: not available */
		unsigned short int ebs_pressure;	/**<  EBS Pressure, 0 to 2032 kPa */
	}fms_ebsp1_t;

	typedef struct{ //FMS(bytes not used) Vehicle Weight: (PGN FEEA)
		time_t        last_change;
		unsigned long boogie_load; /**<  Trailer weight, 0 to 128510kg */
	}fms_vehicle_w_t;

	typedef struct{ //EBS Electronic Brake System #2/1: (PGN 0300)
		time_t        last_change;
		unsigned char rsp_event;   /**<  Vehicle VDC active. 00: no, 01: yes, 10: error, 11: not available */
		unsigned char abs_event;   /**<  Vehicle ABS active. 00: no, 01: yes, 10: error, 11: not available */
	}fms_ebs21_t;

	typedef struct{ //EBS Electronic Brake System #2/2: (PGN FEC4)
		time_t        last_change;
		unsigned char red_warning;    /**<  Red warning signal request. 00: no, 01: yes, 10: error, 11: not available */
		unsigned char yellow_warning; /**<  Amber warning signal request. 00: no, 01: yes, 10: error, 11: not available */
	}fms_ebs22_t;

	typedef struct _ebs_data_t{
		fms_distance_t     total_distance; /**< FMS High Resolution Vehicle Distance: VDHR (PGN FEC1) */
		fms_serv_inform_t  service_inform; /**< FMS Service Information: SERV (PGN FEC0) */
		fms_vehicle_w_t    weight;         /**< FMS(bytes not used) Vehicle Weight: (PGN FEEA) */
		fms_ebsp1_t        ebsp1_data;     /**< EBS Propriety 1: (PGN FF00) */
		fms_ebs21_t        ebs21_data;     /**< EBS Electronic Brake System #2/1: (PGN 0300) */
		fms_ebs22_t        ebs22_data;     /**< EBS Electronic Brake System #2/2: (PGN FEC4) */
	}ebs_data_t;

	#define EVENT_NO				0x00
	#define EVENT_YES				0x01
	#define EVENT_ERROR				0x02
	#define EVENT_NOT_AVAILABLE		0x03

   /**
    * Owasys FMS library configuration structure
    */
	#define MIN_BAUDRATE			125000
	#define MAX_BAUDRATE			500000
	#define MIN_IDLING_TIME			30
	#define MAX_IDLING_TIME			3600

   typedef struct fms_conf_t_{
      unsigned int      bitrate;            /**< Integer: bitrate in bps of the J1939 CAN interface. As defined by SAE J1939, value must be between 125kbps and 500kbps */
      char              interface[16];      /**< String: "can0" or "can1" */
      char              enable_log;        /**< Bool: 0 disable logs (default) !=0 enable output of debug traces to /home/fms.log Maximum size of circular log file is 1MB */
      //char              enable_dump;

      /// unused event parameters
      unsigned short    time_for_idling;
      unsigned short    eng_temp_threshold;
      short             rpm_threshold;
      unsigned char     x_accelerator_pos;
      unsigned short    time_for_no_throttle;
   }fms_conf_t;

	 /**
	  * @brief Configures the FMS module
	  *
	  * After initializing library module, function FMS_Start() must be called
	  *
	  * @param *pconf Pointer to configuration data to start FMS API
	  * @return NO_ERROR if success. Specific error number if fails.
	  */
	  int FMS_Initialize  ( fms_conf_t *pconf );

		/**
		 * @brief Initialization of the FMS module
		 *
		 * The connection to the CAN interface is performed
		 *
		 * @param void
		 * @return NO_ERROR if success. Specific error number if fails.
		 */
		int FMS_Start       ( void );

		/**
		 * @brief Finalizes the FMS library
		 *
		 * It finalizes FMS, disconnecting from the CAN interface and switching it off
		 *
		 * @param void
		 * @return NO_ERROR if success. Specific error number if fails.
		 */
    int FMS_Finalize    ( void );

		/**
		 * @brief It asks the library whether FMS is active
		 *
		 *
		 *
		 * @param *wActive Pointer to an integer 0 if not active 1 otherwise
		 * @return NO_ERROR if success. Specific error number if fails.
		 */
    int FMS_IsActive    ( int *wActive);

		/**
		 * @brief Gets the Library Version
		 *
		 *
		 * @param wVersion
		 * @return NO_ERROR if success. Specific error number if fails.
		 */
    int FMS_GetVersion  ( char *wVersion);

		/**
		 * @brief Retrieves the data from fms_data_t structure
		 *
		 *
		 * @param *wData Pointer to the data contained in fms_data_t. Is set to void because this structure can change with the time.
		 * @param wSize Size of the data to be retrieved
		 * @return NO_ERROR if success. Specific error number if fails.
		 */
    int FMS_GetFMSData  ( void *wData, int wSize);

		/**
		 * @brief Retrieves the data from tpms_data_t structure
		 *
		 *
		 * @param *wData Pointer to the data contained in tpms_data_t. Is set to void because this structure can change with the time.
		 * @param wSize Size of the data to be retrieved
		 * @return NO_ERROR if success. Specific error number if fails.
		 */
    int FMS_GetTPMSData ( void *wData, int wSize);

		/**
		 * @brief Removes the axle number and wheel position from the structure tpms_data_t
		 *
		 *
		 * @param axle Axle number
		 * @param wheel Wheel position inside the axle that is not any longer mounted in the truck
		 * @return NO_ERROR if success. Specific error number if fails.
		 */
    int FMS_RemoveTPMSData ( unsigned char axle, unsigned char wheel);

		/**
		 * @brief Retrieves the data from ebs_data_t structure
		 *
		 *
		 * @param *wData Pointer to the data contained in ebs_data_t. Is set to void because this structure can change with the time.
		 * @param wSize Size of the data to be retrieved
		 * @return NO_ERROR if success. Specific error number if fails.
		 */
    int FMS_GetEBSData  ( void *wData, int wSize);

  #ifdef __cplusplus
   }
  #endif

#endif	// _FMS_DESF_H
