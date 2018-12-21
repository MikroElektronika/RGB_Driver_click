#include "Click_RGB_Driver_types.h"

#ifdef  ENABLE_SPI
const uint32_t _RGBDRIVER_SPI_CFG[ 4 ] = 
{ 
	_SPI_MASTER_OSC_DIV64, 
	_SPI_DATA_SAMPLE_MIDDLE, 
	_SPI_CLK_IDLE_LOW, 
	_SPI_LOW_2_HIGH 
};
#endif

#ifdef  ENABLE_I2C
const uint32_t _RGBDRIVER_I2C_CFG[ 1 ] = 
{
	100000
};
#endif

#ifdef ENABLE_UART
const uint32_t _RGBDRIVER_UART_CFG[ 1 ] = 
{
	9600
};
#endif
