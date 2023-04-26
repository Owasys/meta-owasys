/*
 * Copyright © 2017 Owasys.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __OWA4X_GPIO_H__
#define __OWA4X_GPIO_H__

#include <linux/types.h>

#if 0 //TO-DO OWA4X
//#define GPIO_TO_PIN(bank, gpio)		(32 * (bank) + (gpio))
//#define GPIO_LED_SW0	 GPIO_TO_PIN(1, 15)  /* gpmc_ad15 */
//#define GPIO_LED_SW1	 GPIO_TO_PIN(3, 7)  /* emu0 */
//#define GPIO_LED_SW2	 GPIO_TO_PIN(2, 20) /* mii1_rxd1 */
#define GPIO_LIN_K_EN GPIO_TO_PIN(1, 12)  /* gpmc_ad12 */
//#define GPIO_PPS_GPS	 GPIO_TO_PIN(1, 13)  /* gpmc_ad13 */
//#define GPIO_BOOT_UC  GPIO_TO_PIN(1, 23) /* gpmc_a7 */
//#define GPIO_RESET_UC GPIO_TO_PIN(2, 9) /* lcd_data3 */
//#define GPIO_GPS_ON    GPIO_TO_PIN(2, 13) /* lcd_data7 */
//#define GPIO_ANT_OPEN  GPIO_TO_PIN(2, 21) /* mii1_rxd0  */
//#define GPIO_ANT_SHORT GPIO_TO_PIN(3, 8)  /* emu1 */
#define GPIO_CAN_NRESET GPIO_TO_PIN(2, 22)  /* lcd_vsync */
#define GPIO_CAN2_SLOPE  GPIO_TO_PIN(1, 18) /* gpmc_a2 */
#define GPIO_CAN3_SLOPE  GPIO_TO_PIN(1, 19) /* gpmc_a3 */
#define GPIO_CAN4_SLOPE  GPIO_TO_PIN(1, 22) /* gpmc_a6 */
//#define GPIO_CAN_EN      GPIO_TO_PIN(2, 12) /* lcd_data6 */
//#define GPIO_ETH_ON      GPIO_TO_PIN(2, 11) /* lcd_data5 */
//#define GPIO_nDAI_ENABLE GPIO_TO_PIN(2, 24) /* lcd_pclk */
#define GPIO_SPI0_MOSI   GPIO_TO_PIN(0, 3) /* spi0_d0 */
#define GPIO_CODEC_NRST  GPIO_TO_PIN(2, 23) /* lcd_hsync */
#define GPIO_USB0_DRVVBUS  GPIO_TO_PIN(0, 18) /* USB0_DRVVBUS */
//#define GPIO_GPMC_A8  GPIO_TO_PIN(1, 24) /* gpmc_a8 */
#define GPIO_KLINE1_LOWTH  GPIO_TO_PIN(1, 25) /* gpmc_a9 */
#define GPIO_KLINE2_LOWTH  GPIO_TO_PIN(1, 17) /* gpmc_a1 */
#define GPIO_UART2_TXD GPIO_TO_PIN(3, 10) /* gmii1_rxclk */
#define GPIO_UART2_RXD GPIO_TO_PIN(3, 9) /* gmii1_txclk */
#define GPIO_UART2_RTS GPIO_TO_PIN(3, 6) /* I2C0_SCL */
#define GPIO_UART1_RXD GPIO_TO_PIN(0, 14) /* uart1_rxd */
#define GPIO_UART4_CTS GPIO_TO_PIN(0, 8) /* lcd_data12 */
#define GPIO_UART4_RTS GPIO_TO_PIN(0, 9) /* lcd_data13 */
//#define GPIO_EXTSIM_SEL GPIO_TO_PIN(2, 10) /* lcd_data4 */
#define GPIO_SPI0_CS1 GPIO_TO_PIN(0, 6) /* spi0_cs1 */
//#define GPIO_I2C0_SDA GPIO_TO_PIN(3, 5) /* i2c0_sda (SAFEBOOTn placas viejas) */
#define GPIO_HUB_RST	GPIO_TO_PIN(2, 25) /* lcd_ac_bias_en */
//#define GPIO_TPM_INT	GPIO_TO_PIN(0, 20) /* xdma_event_intr1 */
//#define GPIO_GPMC_BEn1 GPIO_TO_PIN(1, 28) /* gpmc_ben1 (SAFEBOOTn placas nuevas) */
#endif

#if 1 //TO-DO OWA5X
#define GPIO_TO_PIN(bank, gpio)		(32 * (bank-1) + (gpio))
#define GPIO_LED_SW0        GPIO_TO_PIN(5, 19)   /* [AJ6] I2C3_SDA (GPIO5_IO19), Output, (Externo pull-down) */
#define GPIO_LED_SW1        GPIO_TO_PIN(5, 20)   /* [AF8] I2C4_SCL (GPIO5_IO20), Output, (Externo pull-down) */
#define GPIO_LED_SW2	       GPIO_TO_PIN(5, 21)   /* [AD8] I2C4_SDA (GPIO5_IO21), Output */
#define GPIO_PPS_GPS        GPIO_TO_PIN(5, 18)   /* [AJ7] I2C3_SCL (GPIO5_IO18), Input */
#define GPIO_BOOT_UC        GPIO_TO_PIN(4, 25)   /* [AH15] SAI2_TXC (GPIO4_IO25), Output, (Externo pull-down) */
#define GPIO_RESET_UC       GPIO_TO_PIN(4, 26)   /* [AH16] SAI2_TXD0 (GPIO4_IO26), Output, (Externo pull-down)*/
#define GPIO_GPS_ON         GPIO_TO_PIN(5, 5)    /* [AC18] SPDIF_EXT_CLK (GPIO5_IO05), Output, Pull Down */
#define GPIO_ANT_SHORT      GPIO_TO_PIN(1, 14)   /* [A4] GPIO1_IO14, Input, Pull Up */
#define GPIO_ANT_OPEN       GPIO_TO_PIN(1, 15)   /* [B5] GPIO1_IO15, Input */
#define GPIO_CAN_EN         GPIO_TO_PIN(5, 4)    /* [AD18] SPDIF_RX (GPIO5_IO04), Output, (Externo pull-down) */
#define GPIO_ETH_REG_ON     GPIO_TO_PIN(4, 14)   /* [AH11] SAI1_TXD2 (GPIO4_IO14), Output, Pull Up */
#define GPIO_ETH_EN         GPIO_TO_PIN(4, 9)    /* [AH12] SAI1_RXD7 (GPIO4_IO09), Output, (Externo pull-up) */
#define GPIO_nDAI_ENABLE    GPIO_TO_PIN(4, 3)    /* [AF10] SAI1_RXD1 (GPIO4_IO03), Output, Pull Up */
#define GPIO_SAFEBOOTn      GPIO_TO_PIN(1, 13)   /* [A6] GPIO1_IO13, Input */
#define GPIO_EXTSIM_SEL     GPIO_TO_PIN(5, 2)    /* [AJ20] SAI3_MCLK (GPIO5_IO02), Output, Pull Up */
#define GPIO_SD_CD          GPIO_TO_PIN(2, 12)   /* [AD29] SD2_CD_B (GPIO2_IO12), Input, Pull Up */
#define GPIO_SD_EN          GPIO_TO_PIN(1, 10)   /* [B7] GPIO1_IO10, Output, Pull Up, (Externo) */
#define GPIO_USB_FAULT_OD   GPIO_TO_PIN(2, 19)   /* [AD28] SD2_RESET_B (GPIO2_IO19), Input, Pull Up */
#define GPIO_NXP_TO_uC_WAKE GPIO_TO_PIN(4, 27)   /* [AJ15] SAI2_MCLK (GPIO4_IO27), Output, Pull Down */
#define GPIO_RESET_SC16     GPIO_TO_PIN(5, 3)    /* [AE18] SPDIF_TX (GPIO5_IO03), Output, Pull Up, (Externo NM)*/
#define GPIO_USB_0_ON       GPIO_TO_PIN(2, 20)   /* [AC26] SD2_WP (GPIO2_IO20), Output, Pull up, (Externo) */

#define GPIO_TPM_INT        GPIO_TO_PIN(4, 8)    /* [AH10] SAI1_RXD6 (GPIO4_IO08), Input */
#define GPIO_ETH_INT        GPIO_TO_PIN(1, 5)    /* [B4] GPIO1_IO05, Input */           
#define GPIO_CAN3_INT       GPIO_TO_PIN(1, 0)    /* [A7] GPIO1_IO00, Input, Pull Up */
#define GPIO_CAN4_INT       GPIO_TO_PIN(1, 1)    /* [E8] GPIO1_IO01, Input, Pull Up */
#define GPIO_INT1_AG        GPIO_TO_PIN(1, 4)    /* [E6] GPIO1_IO04, Input */
#define GPIO_PMIC_nINT      GPIO_TO_PIN(1, 7)    /* [F6] GPIO1_IO07, Input, Pull Up */
#define GPIO_INT2_A_G       GPIO_TO_PIN(1, 8)    /* [A8] GPIO1_IO08, Input */
#define GPIO_INT_MAG        GPIO_TO_PIN(1, 12)   /* [A5] GPIO1_IO12, Input */
#define GPIO_SPI3_CS2       GPIO_TO_PIN(4, 1)    /* [AH8] SAI1_RXC (GPIO4_IO01), Output, Pull Up */
#define GPIO_SPI3_CS1       GPIO_TO_PIN(5, 1)    /* [AH18] SAI3_TXD (GPIO5_IO01), Output, Pull Up */
#define GPIO_SPI_UART_IRQ   GPIO_TO_PIN(3, 3)    /* [P28] NAND_CE2_B (GPIO3_IO03), Input, Pull Up */
#define GPIO_ST_TO_NXP_WAKE GPIO_TO_PIN(4, 28)   /* [AJ19] SAI3_RXFS (GPIO4_IO28), Input, Pull Down */
#define GPIO_SPI2_CS1       GPIO_TO_PIN(1, 9)    /* [B8] GPIO1_IO09, Output, Pull Up */

#endif

#define FIRST_GPIO 	GPIO_TO_PIN(1, 29)
#define LAST_GPIO 	GPIO_TO_PIN(5, 29)

#if 0
#define AM3352_SCM_BASE          0x44E10000
#define AM3352_GPIO_CONF_OFFSET  0x0800
#define AM3352_GPIO_CONF_END     0x0A34
#define AM3352_SCM_GPIO_BASE     (AM3352_SCM_BASE + AM3352_GPIO_CONF_OFFSET)
#define AM3352_GPIO_CONF_SIZE    (AM3352_GPIO_CONF_END - AM3352_GPIO_CONF_OFFSET + 4)
#endif

#if 0
#define CONF_MCASP0_ACLKR        0x01A0
#define CONF_MCASP0_FSR          0x01A4
#define CONF_MCASP0_AKR1         0x01A8
#define CONF_MCASP0_AHCLKX       0x01AC
#define CONF_SPI0_D0             0x0154
#define CONF_LCD_DATA12          0x00d0
#define CONF_LCD_DATA13          0x00d4
#define CONF_USB0_DRVVBUS        0x021c
#define CONF_SPI0_CS1            0x0160
#define CONF_CAN2_SLOPE          0x0048
#define CONF_CAN3_SLOPE          0x004c
#define CONF_CAN4_SLOPE          0x0058
#define CONF_KLINE1_LOWTH        0x0064
#define CONF_KLINE2_LOWTH        0x0044
#define CONF_UART2_TXD           0x0130
#define CONF_UART2_RXD           0x012c
#define CONF_UART2_RTS           0x018c
#define CONF_UART1_RXD           0x0180
#define CONF_UART4_CTS           CONF_LCD_DATA12
#define CONF_UART4_RTS           CONF_LCD_DATA13
//#define CONF_GMPC_AD15           0x003C

#define AM3352_GPIO_CONF_MASK    0x0000007F
#endif

#if 0
#define INVALID_OFFSET(offset) ( (offset < 0) || (offset > (AM3352_GPIO_CONF_END - AM3352_GPIO_CONF_OFFSET)))

#define INVALID_CAN_TX_MODE(VALUE) ( (VALUE < 0) || (VALUE > 2) )
#define INVALID_KLINE_THERSHOLD(VALUE) ( (VALUE < 0) || (VALUE > 1) )
#endif
#define INVALID_PIN(PIN) ( (PIN < FIRST_GPIO) || (PIN > LAST_GPIO) )
#define INVALID_VALUE(VALUE) ( (VALUE < 0) || (VALUE > 1) )

typedef struct _t_owa4x_gpio
{
   int pin;
   int value;
} t_owa4x_gpio;

/* Get basic GPIO characteristics info */
#define SET_OUTPUT_VALUE	_IOW ('Y', 1, struct _t_owa4x_gpio)
#define GET_INPUT_VALUE	   _IOW ('Y', 2, struct _t_owa4x_gpio)
#define SET_GPIO_MODE	   _IOW ('Y', 3, struct _t_owa4x_gpio)
#define SET_GPIO_INPUT	   _IOW ('Y', 4, struct _t_owa4x_gpio)
#define SET_GPIO_OUTPUT	   _IOW ('Y', 5, struct _t_owa4x_gpio)

#endif /* __OWA4X_GPIO_H__ */
