#include "Click_RGB_Driver_types.h"

#ifdef  ENABLE_SPI
const uint32_t _RGBDRIVER_SPI_CFG[ 3 ] = 
{ 
	_SPI_MASTER, 
	_SPI_FCY_DIV32, 
	_SPI_CLK_LO_LEADING 
};
#endif

#ifdef  ENABLE_I2C
const uint32_t _RGBDRIVER_I2C_CFG[ 1 ] = 
{
	100000
};
#endif

#ifdef ENABLE_UART
const uint32_t _RGBDRIVER_UART_CFG [ 3 ] = 
{
	9600, 
	_UART_NOPARITY, 
	_UART_ONE_STOPBIT
};
#endif
