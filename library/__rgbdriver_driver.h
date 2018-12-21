/*
    __rgbdriver_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __rgbdriver_driver.h
@brief    RGB_Driver Driver
@mainpage RGB_Driver Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   RGBDRIVER
@brief      RGB_Driver Click Driver
@{

| Global Library Prefix | **RGBDRIVER** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **jul 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _RGBDRIVER_H_
#define _RGBDRIVER_H_

/** 
 * @macro T_RGBDRIVER_P
 * @brief Driver Abstract type 
 */
#define T_RGBDRIVER_P    const uint8_t*

/** @defgroup RGBDRIVER_COMPILE Compilation Config */              /** @{ */

//  #define   __RGBDRIVER_DRV_SPI__                            /**<     @macro __RGBDRIVER_DRV_SPI__  @brief SPI driver selector */
   #define   __RGBDRIVER_DRV_I2C__                            /**<     @macro __RGBDRIVER_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __RGBDRIVER_DRV_UART__                           /**<     @macro __RGBDRIVER_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup RGBDRIVER_VAR Variables */                           /** @{ */

// COLOR SET
extern const uint32_t _RGBDRIVER_COLOR_RED;
extern const uint32_t _RGBDRIVER_COLOR_ORANGE;
extern const uint32_t _RGBDRIVER_COLOR_YELLOW;
extern const uint32_t _RGBDRIVER_COLOR_GREEN;
extern const uint32_t _RGBDRIVER_COLOR_BLUE;
extern const uint32_t _RGBDRIVER_COLOR_WHITE;
extern const uint32_t _RGBDRIVER_COLOR_PURPLE;
extern const uint32_t _RGBDRIVER_COLOR_OFF;

                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup RGBDRIVER_INIT Driver Initialization */              /** @{ */

#ifdef   __RGBDRIVER_DRV_SPI__
void rgbdriver_spiDriverInit(T_RGBDRIVER_P gpioObj, T_RGBDRIVER_P spiObj);
#endif
#ifdef   __RGBDRIVER_DRV_I2C__
void rgbdriver_i2cDriverInit(T_RGBDRIVER_P gpioObj, T_RGBDRIVER_P i2cObj, uint8_t slave);
#endif
#ifdef   __RGBDRIVER_DRV_UART__
void rgbdriver_uartDriverInit(T_RGBDRIVER_P gpioObj, T_RGBDRIVER_P uartObj);
#endif
                                                                       /** @} */
/** @defgroup RGBDRIVER_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Function set RGB color
 *
 * @param[in] red        red led
 * @param[in] green      green led
 * @param[in] blue       blue led
 *
 * The function sets the color of the rgb LEDs through the parameters for red, green and blue.
 */
void rgbdriver_setRGB_Color(uint8_t red, uint8_t green, uint8_t blue);

/**
 * @brief Function set color
 *
 * @param[in] color        RGB color
 *
 * Set color:
      RED,
      GREEN,
      BLUE,
      YELLOW,
      WHITE,
      PURPLE,
      ORANGE and OFF.
 *
 */
void rgbdriver_setColor(uint32_t color);

/**
 * @brief shut down mode
 *
 */
void rgbdriver_shutDown();


                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_RGB_Driver_STM.c
    @example Click_RGB_Driver_TIVA.c
    @example Click_RGB_Driver_CEC.c
    @example Click_RGB_Driver_KINETIS.c
    @example Click_RGB_Driver_MSP.c
    @example Click_RGB_Driver_PIC.c
    @example Click_RGB_Driver_PIC32.c
    @example Click_RGB_Driver_DSPIC.c
    @example Click_RGB_Driver_AVR.c
    @example Click_RGB_Driver_FT90x.c
    @example Click_RGB_Driver_STM.mbas
    @example Click_RGB_Driver_TIVA.mbas
    @example Click_RGB_Driver_CEC.mbas
    @example Click_RGB_Driver_KINETIS.mbas
    @example Click_RGB_Driver_MSP.mbas
    @example Click_RGB_Driver_PIC.mbas
    @example Click_RGB_Driver_PIC32.mbas
    @example Click_RGB_Driver_DSPIC.mbas
    @example Click_RGB_Driver_AVR.mbas
    @example Click_RGB_Driver_FT90x.mbas
    @example Click_RGB_Driver_STM.mpas
    @example Click_RGB_Driver_TIVA.mpas
    @example Click_RGB_Driver_CEC.mpas
    @example Click_RGB_Driver_KINETIS.mpas
    @example Click_RGB_Driver_MSP.mpas
    @example Click_RGB_Driver_PIC.mpas
    @example Click_RGB_Driver_PIC32.mpas
    @example Click_RGB_Driver_DSPIC.mpas
    @example Click_RGB_Driver_AVR.mpas
    @example Click_RGB_Driver_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __rgbdriver_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */

