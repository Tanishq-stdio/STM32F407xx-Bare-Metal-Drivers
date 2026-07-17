/*
 * stm32f407xx_spi_drivers.c
 *
 *  Created on: Jun 16, 2026
 *      Author: Tanishq
 */

#include "stm32f407xx_spi_drivers.h"

/*****************************************************
 *
 * @fn                     - GPIO_PeriClockControl
 *
 * brief                   - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]              - Base address of the GPIO peripheral
 * @param[in]              - ENABLE or DISABLE macros
 * @param[in]              -
 *
 * @return                 - none
 *
 * @Note                   - none
 *
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if (pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if (pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}
	}
	else
	{
	   	if(pSPIx == SPI1)
		{
		    SPI1_PCLK_DI();
	    }
		else if (pSPIx == SPI2)
    	{
     		SPI2_PCLK_DI();
		}
		else if (pSPIx == SPI3)
		{
			SPI3_PCLK_DI();
		}
	}
}


/*****************************************************
 *
 * @fn                     - GPIO_PeriClockControl
 *
 * brief                   - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]              - Base address of the GPIO peripheral
 * @param[in]              - ENABLE or DISABLE macros
 * @param[in]              -
 *
 * @return                 - none
 *
 * @Note                   - none
 *
 */
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
	//enable peripheral clock
	SPI_PeriClockControl(pSPIHandle->pSPIx,ENABLE);


	uint32_t tempreg = 0;

	// 1. Config Device mode

	tempreg |= pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR ;

	// 2. Config bus config

	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		//bidi mode should be cleared
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		//bidi mode should be set
		tempreg |= (1 << SPI_CR1_BIDIMODE);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
		{
			//bidi mode should be cleared
			tempreg &= ~(1 << SPI_CR1_BIDIMODE);
			//RXONLY bit must be set
			tempreg |= (1 << SPI_CR1_RXONLY);
		}

	// 3. Config Sclk speed(Baud rate)
	tempreg |= pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;

	//4. Config DFF
	tempreg |= pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF;

	//4. Config CPOL
	tempreg |= pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL;

	//4. Config CPHA
	tempreg |= pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA;

	pSPIHandle->pSPIx->CR1 |= tempreg;
}

/*****************************************************
 *
 * @fn                     - GPIO_PeriClockControl
 *
 * brief                   - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]              - Base address of the GPIO peripheral
 * @param[in]              - ENABLE or DISABLE macros
 * @param[in]              -
 *
 * @return                 - none
 *
 * @Note                   - none
 *
 */
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{

}

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx,uint8_t FlagName)
{
	if(pSPIx->SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}
/*****************************************************
 *
 * @fn                     - GPIO_PeriClockControl
 *
 * brief                   - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]              - Base address of the GPIO peripheral
 * @param[in]              - ENABLE or DISABLE macros
 * @param[in]              -
 *
 * @return                 - none
 *
 * @Note                   - This is blocking call
 *
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
	while(Len > 0)
	{
		// 1. wait until TXE is set
		while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG) == FLAG_RESET );

		//2. check the DFF bit in CR1
		if((pSPIx->CR1 & ( 1 << SPI_CR1_DFF)))
		{
			// 16 bit DFF
			//1. load the data in to DR
			pSPIx->DR = *((uint16_t*)pTxBuffer);
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;
		}else
		{
			// 8 bit DFF
			pSPIx->DR = *pTxBuffer;
			Len--;
			pTxBuffer++;
		}
	}

}

/*****************************************************
 *
 * @fn                     - GPIO_PeriClockControl
 *
 * brief                   - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]              - Base address of the GPIO peripheral
 * @param[in]              - ENABLE or DISABLE macros
 * @param[in]              -
 *
 * @return                 - none
 *
 * @Note                   - none
 *
 */
void SPI_RecieveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{

}

/*****************************************************
 *
 * @fn                     - GPIO_PeriClockControl
 *
 * brief                   - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]              - Base address of the GPIO peripheral
 * @param[in]              - ENABLE or DISABLE macros
 * @param[in]              -
 *
 * @return                 - none
 *
 * @Note                   - none
 *
 */
void SPI_IRQConfig(uint8_t iRQNumber,uint8_t EnorDi)
{

}

/*****************************************************
 *
 * @fn                     - GPIO_PeriClockControl
 *
 * brief                   - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]              - Base address of the GPIO peripheral
 * @param[in]              - ENABLE or DISABLE macros
 * @param[in]              -
 *
 * @return                 - none
 *
 * @Note                   - none
 *
 */
void SPI_IRQPriorityConfig(uint8_t iRQNumber,uint8_t IRQPriority)
{

}

/*****************************************************
 *
 * @fn                     - GPIO_PeriClockControl
 *
 * brief                   - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]              - Base address of the GPIO peripheral
 * @param[in]              - ENABLE or DISABLE macros
 * @param[in]              -
 *
 * @return                 - none
 *
 * @Note                   - none
 *
 */
void SPI_IRQHandling(SPI_Handle_t *pHandle)
{

}
/*****************************************************
 *
 * @fn                     - GPIO_PeriClockControl
 *
 * brief                   - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]              - Base address of the GPIO peripheral
 * @param[in]              - ENABLE or DISABLE macros
 * @param[in]              -
 *
 * @return                 - none
 *
 * @Note                   - none
 *
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi)
{
	if(EnOrDi  == ENABLE)
	{
		pSPIx->CR1 |= (1 << SPI_CR1_SPE);
	}else
	{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
	}

}
/*****************************************************
 *
 * @fn                     - GPIO_PeriClockControl
 *
 * brief                   - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]              - Base address of the GPIO peripheral
 * @param[in]              - ENABLE or DISABLE macros
 * @param[in]              -
 *
 * @return                 - none
 *
 * @Note                   - none
 *
 */
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi)
{
	if(EnOrDi  == ENABLE)
	{
		pSPIx->CR1 |= (1 << SPI_CR1_SSI);
	}else
	{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SSI);
	}

}


