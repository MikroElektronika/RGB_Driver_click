![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# RGB_Driver Click

- **CIC Prefix**  : RGBDRIVER
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : Jan 2018.

---

### Software Support

We provide a library for the RGB_Driver Click on our [LibStock](https://libstock.mikroe.com/projects/view/2329/rgb-driver-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library carries all necessary functions for complete control over RGB Driver click.

Key functions :

- ``` void rgbdriver_setColor(uint32_t color) ``` - Set some of predefined colors provided as constants
- ``` void rgbdriver_setRGB_Color(uint8_t red, uint8_t green, uint8_t blue) ``` - Set raw RGB value

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Driver initialize
- Application Task - (code snippet) - Sets the brightness over rgb value,
        Red value sets from 0x60 to 0x7F,
        Green value sets from 0x80 to 0x9F and
        Blue value sets from 0x40 to 0x5F.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2329/rgb-driver-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
