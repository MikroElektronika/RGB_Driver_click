#include "Click_RGB_Driver_types.h"

#ifdef  ENABLE_SPI
const uint32_t _RGBDRIVER_SPI_CFG[ 8 ] = 
{ 
	_SPI_MASTER,
	_SPI_8_BIT, 
	_SPI_PRESCALE_SEC_4, 
	_SPI_PRESCALE_PRI_4, 
	_SPI_SS_DISABLE, 
	_SPI_DATA_SAMPLE_MIDDLE, 
	_SPI_CLK_IDLE_LOW, 
	_SPI_IDLE_2_ACTIVE 
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
