/******************** (C) COPYRIGHT 2010 OWASYS ********************
* File Name          : pm_messages.h
* Author             : owasys
* Version            :
* Date               :
* Description        :
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

#ifndef __PM_MESSAGES_H

	#define __PM_MESSAGES_H

	#ifdef __cplusplus
	 extern "C"{
	#endif

	#define MAX_OW_DEVICES			16  // Maximo 16 dispositivos en el bus 1-Wire
	#define OW_ROMID_SIZE			8

	#define	UPDATE_MIN_TIME		1		// 100ms
	#define	UPDATE_MAX_TIME		50		// 5000ms

	#define	ID_EMPTY 			0
	#define	ID_UPDATED			1
	#define	ID_NEW				2
	#define	ID_REMOVE			3
	#define	ID_PENDING			4

	#define MAX_IB_DATA		128

	typedef struct {
		unsigned char RomId[OW_ROMID_SIZE];
	} OneWireROM_t;

	typedef struct {
		unsigned char 	DeviceStatus;
		OneWireROM_t	DeviceId;
	} OneWireTable_t;

	#ifdef __cplusplus
   }
  #endif

#endif
