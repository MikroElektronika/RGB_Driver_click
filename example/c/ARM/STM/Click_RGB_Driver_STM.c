/*
Example for RGB_Driver Click

    Date          : jul 2018.
    Author        : Katarina Perendic

Test configuration STM32 :
    
    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.0.0.0

---
Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Driver initialize
- Application Task - (code snippet) - Sets the brightness over rgb value,
        Red value sets from 0x60 to 0x7F,
        Green value sets from 0x80 to 0x9F and
        Blue value sets from 0x40 to 0x5F.

*/

#include "Click_RGB_Driver_types.h"
#include "Click_RGB_Driver_config.h"

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_RGBDRIVER_I2C_CFG[0] );
    Delay_ms( 100 );
}

void applicationInit()
{
    rgbdriver_i2cDriverInit( (T_RGBDRIVER_P)&_MIKROBUS1_GPIO, (T_RGBDRIVER_P)&_MIKROBUS1_I2C, 0x38 );
}

void applicationTask()
{
    rgbdriver_setColor(_RGBDRIVER_COLOR_RED);
    Delay_1sec();
    rgbdriver_setColor(_RGBDRIVER_COLOR_YELLOW);
    Delay_1sec();
    rgbdriver_setColor(_RGBDRIVER_COLOR_BLUE);
    Delay_1sec();
    rgbdriver_setRGB_Color(0x40, 0x9F, 0x60);
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}