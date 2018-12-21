/*
    __rgbdriver_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__rgbdriver_driver.h"
#include "__rgbdriver_hal.c"

/* ------------------------------------------------------------------- MACROS */

// COLOR SET
const uint32_t _RGBDRIVER_COLOR_RED    = 0x7F8040;
const uint32_t _RGBDRIVER_COLOR_ORANGE = 0x7F8240;
const uint32_t _RGBDRIVER_COLOR_YELLOW = 0x7F9440;
const uint32_t _RGBDRIVER_COLOR_GREEN  = 0x609F40;
const uint32_t _RGBDRIVER_COLOR_BLUE   = 0x60805F;
const uint32_t _RGBDRIVER_COLOR_WHITE  = 0x7F9F5F;
const uint32_t _RGBDRIVER_COLOR_PURPLE = 0x78805C;
const uint32_t _RGBDRIVER_COLOR_OFF = 0x000000;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __RGBDRIVER_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

static void _setIntensity(uint8_t intensity);

/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */

static void _setIntensity(uint8_t intensity)
{
    uint8_t writeReg[1];
    writeReg[0] = intensity;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,writeReg,1,END_MODE_STOP);
}

/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __RGBDRIVER_DRV_SPI__

void rgbdriver_spiDriverInit(T_RGBDRIVER_P gpioObj, T_RGBDRIVER_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RGBDRIVER_DRV_I2C__

void rgbdriver_i2cDriverInit(T_RGBDRIVER_P gpioObj, T_RGBDRIVER_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RGBDRIVER_DRV_UART__

void rgbdriver_uartDriverInit(T_RGBDRIVER_P gpioObj, T_RGBDRIVER_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */


void rgbdriver_setRGB_Color(uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t writeReg[ 3 ];

	_setIntensity(0x30); 
	
    if(blue < 0x40 || blue > 0x5F)
        writeReg[ 0 ] = 0x40;
    else
        writeReg[ 0 ] = blue;

    if(red < 0x60 || red > 0x7F)
        writeReg[ 1 ] = 0x60;
    else
        writeReg[ 1 ] = red;

    if(green < 0x80 || green > 0x9F)
        writeReg[ 2 ] = 0x80;
    else
        writeReg[ 2 ] = green;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,&writeReg[0],1,END_MODE_RESTART);
    hal_i2cWrite(_slaveAddress,&writeReg[1],1,END_MODE_RESTART);
    hal_i2cWrite(_slaveAddress,&writeReg[2],1,END_MODE_STOP);
}

void rgbdriver_setColor(uint32_t color)
{
    uint8_t writeReg[ 3 ];
    writeReg[ 0 ] = color;
    writeReg[ 1 ] = color >> 8;
    writereg[ 2 ] = color >> 16;

	_setIntensity(0x30); 
		
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,&writeReg[0],1,END_MODE_RESTART);
    hal_i2cWrite(_slaveAddress,&writeReg[1],1,END_MODE_RESTART);
    hal_i2cWrite(_slaveAddress,&writeReg[2],1,END_MODE_STOP);
}

/*void rgbdriver_setTimer(uint8_t time)
{
    uint8_t writeReg[1];
    writeReg[0] = time;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,writeReg,1,END_MODE_STOP);
}*/

void rgbdriver_shutDown()
{
    uint8_t writeReg[1];
    writeReg[0] = 0x00;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,writeReg,1,END_MODE_STOP);
}


/* -------------------------------------------------------------------------- */
/*
  __rgbdriver_driver.c

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
