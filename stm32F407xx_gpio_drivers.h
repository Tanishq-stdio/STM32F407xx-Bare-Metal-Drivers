/*
 * stm32f407xx_gpio_drivers.h
 *
 *  Created on: Mar 25, 2026
 *      Author: Tanishq
 */

#ifndef INC_STM32F407XX_GPIO_DRIVERS_H_
#define INC_STM32F407XX_GPIO_DRIVERS_H_

#include<stdint.h>
#include "stm32f4xx.h"

                    // This is a Configuration structure for a GPIO pin

typedef struct
{
	uint8_t GPIO_PinNumber;          //@GPIO_PIN_NUMBERS
	uint8_t GPIO_PinMode;            //@GPIO_PIN_MODES
	uint8_t GPIO_PinSpeed;           //@GPIO_PIN_SPEED
	uint8_t GPIO_PinPuPdControl;     //@GPIO_PIN_PUPD
	uint8_t GPIO_PinOPType;          //@GPIO_PIN_OPTYPE
	uint8_t GPIO_PinAltFunMode;      //@GPIO

}GPIO_PinConfig_t;

                                    // This is Handle structure for GPIO

typedef struct
{
	GPIO_RegDef_t *pGPIOx;            // Holds the base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig;  // This holds GPIO pin config settings

}GPIO_Handle_t;

// GPIO pin possible modes @GPIO_PIN_NUMBERS

#define GPIO_PIN_NO_0                 0
#define GPIO_PIN_NO_1                 1
#define GPIO_PIN_NO_2                 2
#define GPIO_PIN_NO_3                 3
#define GPIO_PIN_NO_4                 4
#define GPIO_PIN_NO_5                 5
#define GPIO_PIN_NO_6                 6
#define GPIO_PIN_NO_7                 7
#define GPIO_PIN_NO_8                 8
#define GPIO_PIN_NO_9                 9
#define GPIO_PIN_NO_10                10
#define GPIO_PIN_NO_11                11
#define GPIO_PIN_NO_12                12
#define GPIO_PIN_NO_13                13
#define GPIO_PIN_NO_14                14
#define GPIO_PIN_NO_15                15

// GPIO pin possible modes @GPIO_PIN_MODES

#define GPIO_MODE_IN                  0
#define GPIO_MODE_OUT                 1
#define GPIO_MODE_ALTFN               2
#define GPIO_MODE_ANALOG              3
#define GPIO_MODE_IT_FT               4
#define GPIO_MODE_IT_RT               5
#define GPIO_MODE_IT_RFT              6

// GPIO pin possible outputs types @GPIO_PIN_OPTYPE

#define GPIO_OP_TYPE_PD               0
#define GPIO_OP_TYPE_OD               1

// GPIO pin possible outputs speed  @GPIO_PIN_SPEED

#define GPIO_SPEED_LOW                0
#define GPIO_SPEED_MEDIUM             1
#define GPIO_SPEED_FAST               0
#define GPIO_SPEED_HIGH               1

// GPIO pin pull and pull down config macros  @GPIO_PIN_PUPD

#define GPIO_NO_PUPD                  0
#define GPIO_PIN_PU                   1
#define GPIO_PIN_PD                   0


                      // APIs supported by this driver //


//Peripheral Clock setup
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

//Init and De-Init
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

// Data read and write
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOnputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

//IRQ Config and ISR Handling
void GPIO_IRQConfig(uint8_t iRQNumber,uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t iRQNumber,uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* INC_STM32F407XX_GPIO_DRIVERS_H_ */
