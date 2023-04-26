/**
 * @file INET_ModuleDefs.h
 * @author Owasys
 * @date 03 Aug 2017
 * @brief File containing definitions for Owasys INET API.
 *
 */

#ifndef __INET_MODULEDEFS_H

   #define __INET_MODULEDEFS_H

   #ifdef __cplusplus
    extern "C"{
   #endif

   #include "owa4x/owcomdefs.h"
   #include "owa4x/owerrors.h"

   //*********************** DEFINITION SECTION
   //EVENT TYPES
   #define  INET_RELEASED              1 /** Event signaling the loss of the GPRS session */
   //BEARER TYPES
   #define  INET_BEARER_GPRS           1
   #define  INET_BEARER_ENHANCED_GPRS  2
   //OWASYS Definition
   #define  MAX_USER_SIZE         256
   #define  MAX_PWD_SIZE          256
   #define  MAX_IP_SIZE           39      //Ready for IPv6-> XXXX:XXXX:XXXX:XXXX:XXXX:XXXX:XXXX:XXXX
   #define  MAX_APN_SIZE          63
   //*********************** End of DEFINITION SECTION

   //*********************** TYPEDEF SECTION
   //Events Section
   typedef struct _INET_Events{
      unsigned char evType;
      int           evHandled;
   }INET_Events;

   //Configuration Section
   typedef struct _TINET_MODULE_CONFIGURATION{
      unsigned char  wBearer;                   /**< Internet Bearer */
//      int   wSignal;
      void* wBearerParameters;
      void  (*inet_action)( INET_Events * );
   }TINET_MODULE_CONFIGURATION;
   //Bearers Configuration
   //GPRS
   typedef struct _GPRS_CONFIGURATION{
      unsigned char gprsUser[ 20];             /**< User defined in the GPRS network */
      unsigned char gprsPass[ 20];             /**< Password defined in the GPRS network */
      unsigned char gprsDNS1[ 20];             /**< DNS1 defined in the GPRS network, if exists */
      unsigned char gprsDNS2[ 20];             /**< DNS2 defined in the GPRS network, if exists */
      unsigned char gprsAPN [ 20];            /**< Access Point Name for iNet in the GPRS network */
   }GPRS_CONFIGURATION;
   /**
   * @brief GPRS Enhanced Configuration
   *
   * NOTE: GPRS_ENHANCED_CONFIGURATION is related to INET_BEARER_ENHANCED_GPRS.
   */
   typedef struct _GPRS_ENHANCED_CONFIGURATION{
      unsigned char gprsUser[ MAX_USER_SIZE];        /**< User defined in the GPRS/INET network */
      unsigned char gprsPass[ MAX_PWD_SIZE];         /**< Password defined in the GPRS/INET network */
      unsigned char gprsDNS1[ MAX_IP_SIZE + 1];      /**< DNS1 defined in the GPRS network, if exists */
      unsigned char gprsDNS2[ MAX_IP_SIZE + 1];      /**< DNS2 defined in the GPRS network, if exists */
      unsigned char gprsAPN [ MAX_APN_SIZE + 1];     /**< Access Point Name for iNet in the GPRS network */
   }GPRS_ENHANCED_CONFIGURATION;


/**
 * @brief Configures and Initializes the INET Module
 *
 * @param *wConfiguration To start the INET module the wConfiguration will be
 *    a pointer to a struct where it is specified the INET Connection settings.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int iNet_Initialize          ( void *wConfiguration);

/**
 * @brief Finalizes the INET module, returning the control to the Generic bearer control library
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int iNet_Finalize            ( void);

/**
 * @brief Checks the correct working of the INET module.
 *
 * @param *wActive 0: Not active, 1: Active.
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int iNet_IsActive            ( int *wActive);

/**
 * @brief Starts the INET connection.
 *
 * It prepares the system to open a default route to the INTERNET.
 *
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int iNet_Start               ( void);

/**
 * @brief Return the INET library version.
 *
 * @param *wVersion Contains the returned version code. Format "CYA 999 9999, x.x.x"
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int iNet_GetVersion          ( unsigned char *wVersion);

/**
 * @brief Gets the IP address given by the network and used to communicate with the iNet.
 *
 * @param *wIPAddress IP Address buffer(reserved by user program): "192.168.1.100"
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int iNet_GetIPAddress        ( char *wIPAddress);

/**
 * @brief Gets de number of transmited/received bytes.
 *
 * @param *wTxBytes Number of transmited bytes
 * @param *wRxBytes Number of received bytes
 * @return NO_ERROR if success. Specific error number if fails.
 */
   int iNet_GetDataCounters     ( long *wTxBytes, long *wRxBytes);

   //*********************** End of DEFINITION SECTION

   #ifdef __cplusplus
    }
   #endif

#endif
