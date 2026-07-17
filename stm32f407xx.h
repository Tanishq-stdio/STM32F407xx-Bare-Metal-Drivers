/*
 * stm32f4xx.h
 *
 *  Created on: Mar 19, 2026
 *      Author: Tanishq
 */

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_

#include<stdint.h>

#define __vo volatile

//                                         Processor Specific Deatils

// ARM Cortex Mx Processor NVIC ISERx register Addresses

#define NVIC_ISER0           ( (__vo uint32_t*)0xE000E100)
#define NVIC_ISER1           ( (__vo uint32_t*)0xE000E104)
#define NVIC_ISER2           ( (__vo uint32_t*)0xE000E108)
#define NVIC_ISER3           ( (__vo uint32_t*)0xE000E10C)

// ARM Cortex Mx Processor NVIC ICERx register Addresses

#define NVIC_ICER0           ( (__vo uint32_t*)0xE000E180)
#define NVIC_ICER1           ( (__vo uint32_t*)0xE000E184)
#define NVIC_ICER2           ( (__vo uint32_t*)0xE000E188)
#define NVIC_ICER3           ( (__vo uint32_t*)0xE000E18C)

// ARM Cortex Mx Processor Priority Register Address Calculation

#define NVIC_PR_BASE_ADDR       ( (__vo uint32_t*)0xE000E400)

// ARM Cortex Mx Processor number of priority bits implemented in Priority register
#define NO_PR_BITS_IMPLEMENTED       4

// Base Addresses of Flash & SRAM memories

#define FLASH_BASEADDR                     0x08000000U      //Flash Base addr in ref manual (main memory sec 0)
#define SRAM1_BASEADDR                     0x20000000U      //SRAM base addr
#define SRAM2_BASEADDR                     0x20001C00U      //Calculated by SRAM1 by mul with 1024 with 112 (112 in ref manual in sys arch)
#define ROM_BASEADDR                       0x1FFF0000U      //
#define SRAM                               SRAM1_BASEADDR

//Peripheral Buses

#define PERIPH_BASE                        0x40000000U
#define APB1PERIPH_BASEADDR                PERIPH_BASE
#define APB2PERIPH_BASEADDR                0x40010000U
#define AHB1PERIPH_BASEADDR                0x40020000U
#define AHB2PERIPH_BASEADDR                0x50000000U

// Base Addresses of peripheral hanging on AHB1 bus

#define GPIOA_BASEADDR                 (AHB1PERIPH_BASEADDR + 0x0000) // 0x0000 is offset
#define GPIOB_BASEADDR                 (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR                 (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR                 (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR                 (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR                 (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR                 (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR                 (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR                 (AHB1PERIPH_BASEADDR + 0x2000)
#define RCC_BASEADDR                   (AHB1PERIPH_BASEADDR + 0x3800) // In ref manual we can see RCC is also in AHB1 bus

// Base Addresses of peripheral hanging on APB1 bus

#define I2C1_BASEADDR                  (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR                  (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR                  (APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR                  (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR                  (APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR                (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR                (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR                 (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR                 (APB1PERIPH_BASEADDR + 0x5000)

// Base Addresses of peripheral hanging on APB2 bus

#define SPI1_BASEADDR                  (APB2PERIPH_BASEADDR + 0x3000)
#define USART1_BASEADDR                (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR                (APB2PERIPH_BASEADDR + 0x1400)
#define EXTI_BASEADDR                  (APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR                (APB2PERIPH_BASEADDR + 0x3800)

// Peripheral register definition for GPIO

typedef struct
{
	__vo uint32_t MODER;                         // Address offset 0x00
	__vo uint32_t OTYPER;                        // Address offset 0x04
	__vo uint32_t OSPEEDR;                       // Address offset 0x08
	__vo uint32_t PUPDR;                         // Address offset 0xC0
	__vo uint32_t IDR;                           // Address offset 0x10
	__vo uint32_t ODR;                           // Address offset 0x14
	__vo uint32_t BSRR;                          // Address offset 0x18
	__vo uint32_t LCKR;                          // Address offset 0x1C
	__vo uint32_t AFR[2];                        // Address offset 0x20 & Address offset 0x24

} GPIO_RegDef_t;

// Peripheral register definition for SPI

typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;

} SPI_RegDef_t;

// Peripheral register definition for RCC

typedef struct
{
	__vo uint32_t CR;                            // Address offset 0x00
	__vo uint32_t PLLCFGR;                       // Address offset 0x04
	__vo uint32_t CFGR;                          // Address offset 0x08
	__vo uint32_t CIR;                           // Address offset 0xC0
	__vo uint32_t AHB1RSTR;                      // Address offset 0x10
	__vo uint32_t AHB2RSTR;                      // Address offset 0x14
	__vo uint32_t AHB3RSTR;                      // Address offset 0x18
	uint32_t      RESERVED0;
	__vo uint32_t APB1RSTR;                      // Address offset 0x20
	__vo uint32_t APB2RSTR;                      // Address offset 0x24
	uint32_t      RESERVED1[2];
	__vo uint32_t AHB1ENR;                       // Address offset 0x30
	__vo uint32_t AHB2ENR;                       // Address offset 0x34
	__vo uint32_t AHB3ENR;                       // Address offset 0x38
	uint32_t      RESERVED2;
	__vo uint32_t APB1ENR;                       // Address offset 0x40
	__vo uint32_t APB2ENR;                       // Address offset 0x44
	uint32_t      RESERVED3[2];
	__vo uint32_t AHB1LPENR;                     // Address offset 0x50
	__vo uint32_t AHB2LPENR;                     // Address offset 0x54
	__vo uint32_t AHB3LPENR;                     // Address offset 0x58
	uint32_t      RESERVED4;
	__vo uint32_t APB1LPENR;                     // Address offset 0x60
	__vo uint32_t APB2LPENR;                     // Address offset 0x64
	uint32_t      RESERVED5[2];
	__vo uint32_t BDCR;                          // Address offset 0x70
	__vo uint32_t CSR;                           // Address offset 0x74
	uint32_t      RESERVED6[2];
	__vo uint32_t SSCGR;                         // Address offset 0x80
	__vo uint32_t PLLI2SCFGR;                    // Address offset 0x84
	__vo uint32_t PLLSAICFGR;                    // Address offset 0x88
	__vo uint32_t DCKCFGR;                       // Address offset 0x8C
	__vo uint32_t CKGATENR;                      // Address offset 0x90

} RCC_RegDef_t;


// Peripheral register definition for EXTI

typedef struct
{
	__vo uint32_t IMR;                          // Address offset 0x00
	__vo uint32_t EMR;                          // Address offset 0x04
	__vo uint32_t RTSR;                         // Address offset 0x08
	__vo uint32_t FTSR;                         // Address offset 0xC0
	__vo uint32_t SWIER;                        // Address offset 0x10
	__vo uint32_t PR;                           // Address offset 0x14

} EXTI_RegDef_t;


// Peripheral register definition for SYSCFG

typedef struct
{
	__vo uint32_t MEMRMP;                      // Address offset 0x00
	__vo uint32_t PMC;                         // Address offset 0x04
	__vo uint32_t EXTICR[4];                   // Address offset 0x08-0x14
	uint32_t      RESERVED1[2];                // Reserved, 0x18-0x1C
	__vo uint32_t CMPCR;                       // Address offset 0x20
	uint32_t      RESERVED2[2];                // Reserved, 0x24-0x28
	__vo uint32_t CFGR;                        // Address offset 0x2C

} SYSCFG_RegDef_t;

// Peripheral Definitions (peripheral base addresses type caste to xxx_RegDef_t)

#define GPIOA                   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB                   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC                   ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD                   ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE                   ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF                   ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG                   ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH                   ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI                   ((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC                     ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI                    ((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG                  ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1                    ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2                    ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3                    ((SPI_RegDef_t*)SPI3_BASEADDR)

// Clock Enable Macros for GPIOx Peripherals

#define GPIOA_PCLK_EN()          (RCC->AHB1ENR |= ( 1 << 0))
#define GPIOB_PCLK_EN()          (RCC->AHB1ENR |= ( 1 << 1))
#define GPIOC_PCLK_EN()          (RCC->AHB1ENR |= ( 1 << 2))
#define GPIOD_PCLK_EN()          (RCC->AHB1ENR |= ( 1 << 3))
#define GPIOE_PCLK_EN()          (RCC->AHB1ENR |= ( 1 << 4))
#define GPIOF_PCLK_EN()          (RCC->AHB1ENR |= ( 1 << 5))
#define GPIOG_PCLK_EN()          (RCC->AHB1ENR |= ( 1 << 6))
#define GPIOH_PCLK_EN()          (RCC->AHB1ENR |= ( 1 << 7))
#define GPIOI_PCLK_EN()          (RCC->AHB1ENR |= ( 1 << 8))

// Clock Enable Macros for I2Cx Peripherals

#define I2C1_PCLK_EN()           (RCC->APB1ENR |= ( 1 << 21))
#define I2C2_PCLK_EN()           (RCC->APB1ENR |= ( 1 << 22))
#define I2C3_PCLK_EN()           (RCC->APB1ENR |= ( 1 << 23))

// Clock Enable Macros for SPIx Peripherals

#define SPI1_PCLK_EN()           (RCC->APB2ENR |= ( 1 << 12))
#define SPI2_PCLK_EN()           (RCC->APB1ENR |= ( 1 << 14))
#define SPI3_PCLK_EN()           (RCC->APB1ENR |= ( 1 << 15))
#define SPI4_PCLK_EN()           (RCC->APB1ENR |= ( 1 << 13))

// Clock Enable Macros for USARTx Peripherals

#define USART1_PCLK_EN()         (RCC->APB2ENR |= ( 1 << 4))
#define USART2_PCLK_EN()         (RCC->APB1ENR |= ( 1 << 17))
#define USART3_PCLK_EN()         (RCC->APB1ENR |= ( 1 << 18))       // Also 2 3 4 5 is on APB1
#define UART4_PCLK_EN()          (RCC->APB1ENR |= ( 1 << 19))       // note: 4 and 5 are UART not USART
#define UART5_PCLK_EN()          (RCC->APB1ENR |= ( 1 << 20))
#define USART6_PCLK_EN()         (RCC->APB2ENR |= ( 1 << 5))

// Clock Enable Macros for SYSCFGx Peripherals

#define SYSCFG_PCLK_EN()         (RCC->APB2ENR |= ( 1 << 14))

// Clock Disable Macros for GPIOx Peripherals

#define GPIOA_PCLK_DI()          (RCC->AHB1ENR &= ~( 1 << 0))
#define GPIOB_PCLK_DI()          (RCC->AHB1ENR &= ~( 1 << 1))
#define GPIOC_PCLK_DI()          (RCC->AHB1ENR &= ~( 1 << 2))
#define GPIOD_PCLK_DI()          (RCC->AHB1ENR &= ~( 1 << 3))
#define GPIOE_PCLK_DI()          (RCC->AHB1ENR &= ~( 1 << 4))
#define GPIOF_PCLK_DI()          (RCC->AHB1ENR &= ~( 1 << 5))
#define GPIOG_PCLK_DI()          (RCC->AHB1ENR &= ~( 1 << 6))
#define GPIOH_PCLK_DI()          (RCC->AHB1ENR &= ~( 1 << 7))
#define GPIOI_PCLK_DI()          (RCC->AHB1ENR &= ~( 1 << 8))

// Clock Disable Macros for I2Cx Peripherals

#define I2C1_PCLK_DI()           (RCC->APB1ENR &= ~( 1 << 21))
#define I2C2_PCLK_DI()           (RCC->APB1ENR &= ~( 1 << 22))
#define I2C3_PCLK_DI()           (RCC->APB1ENR &= ~( 1 << 23))

// Clock Disable Macros for SPIx Peripherals

#define SPI1_PCLK_DI()           (RCC->APB2ENR &= ~( 1 << 12))
#define SPI2_PCLK_DI()           (RCC->APB1ENR &= ~( 1 << 14))
#define SPI3_PCLK_DI()           (RCC->APB1ENR &= ~( 1 << 15))
#define SPI4_PCLK_DI()           (RCC->APB1ENR &= ~( 1 << 13))

// Clock Disable Macros for USARTx Peripherals

#define USART1_PCLK_DI()         (RCC->APB2ENR &= ~( 1 << 4))
#define USART2_PCLK_DI()         (RCC->APB1ENR &= ~( 1 << 17))
#define USART3_PCLK_DI()         (RCC->APB1ENR &= ~( 1 << 18))       // Also 2 3 4 5 is on APB1
#define UART4_PCLK_DI()          (RCC->APB1ENR &= ~( 1 << 19))       // note: 4 and 5 are UART not USART
#define UART5_PCLK_DI()          (RCC->APB1ENR &= ~( 1 << 20))
#define USART6_PCLK_DI()         (RCC->APB2ENR &= ~( 1 << 5))

// Clock Disable Macros for SYSCFGx Peripherals

#define SYSCFG_PCLK_DI()          (RCC->APB2ENR &= ~( 1 << 14))

//Di-int macros for RESET

#define GPIOA_REG_RESET()           do{ (RCC->AHB1RSTR |= ( 1 << 0)); (RCC->AHB1RSTR &= ~( 1 << 0)); } while(0)
#define GPIOB_REG_RESET()           do{ (RCC->AHB1RSTR |= ( 1 << 0)); (RCC->AHB1RSTR &= ~( 1 << 0)); } while(0)
#define GPIOC_REG_RESET()           do{ (RCC->AHB1RSTR |= ( 1 << 0)); (RCC->AHB1RSTR &= ~( 1 << 0)); } while(0)
#define GPIOD_REG_RESET()           do{ (RCC->AHB1RSTR |= ( 1 << 0)); (RCC->AHB1RSTR &= ~( 1 << 0)); } while(0)
#define GPIOE_REG_RESET()           do{ (RCC->AHB1RSTR |= ( 1 << 0)); (RCC->AHB1RSTR &= ~( 1 << 0)); } while(0)
#define GPIOF_REG_RESET()           do{ (RCC->AHB1RSTR |= ( 1 << 0)); (RCC->AHB1RSTR &= ~( 1 << 0)); } while(0)
#define GPIOG_REG_RESET()           do{ (RCC->AHB1RSTR |= ( 1 << 0)); (RCC->AHB1RSTR &= ~( 1 << 0)); } while(0)
#define GPIOH_REG_RESET()           do{ (RCC->AHB1RSTR |= ( 1 << 0)); (RCC->AHB1RSTR &= ~( 1 << 0)); } while(0)
#define GPIOI_REG_RESET()           do{ (RCC->AHB1RSTR |= ( 1 << 0)); (RCC->AHB1RSTR &= ~( 1 << 0)); } while(0)

// this macro returns a code(between 0 to 7) for a given GPIO base address(x)

#define GPIO_BASEADDR_TO_CODE(x)     ( (x == GPIOA) ? 0 :\
		                               (x == GPIOB) ? 1 :\
				                       (x == GPIOC) ? 2 :\
						               (x == GPIOB) ? 3 :\
				                       (x == GPIOA) ? 4 :\
	                                   (x == GPIOB) ? 5 :\
						               (x == GPIOA) ? 6 :\
					                   (x == GPIOB) ? 7 :0 )

// IRQ(Interrupt req) no of STM#@F407x
// NOTE: update these macros with valid values according to your MCU
// TODO: You may complete this list for other peripherals

#define IRQ_NO_EXTI0        6
#define IRQ_NO_EXTI1        7
#define IRQ_NO_EXTI2        8
#define IRQ_NO_EXTI3        9
#define IRQ_NO_EXTI4        10
#define IRQ_NO_EXTI9_5      23
#define IRQ_NO_EXTI15_10    40

// macros for all the possible priority levels

#define NVIC_IRQ_PRI0    0
#define NVIC_IRQ_PRI15   15

// Some Generic Macros

#define ENABLE                      1
#define DISABLE                     0
#define SET                         ENABLE
#define RESET                       DISABLE
#define GPIO_PIN_SET                SET
#define GPIO_PIN_RESET              RESET
#define FLAG_RESET                  RESET
#define FLAG_SET                    SET

// Bit position defination of SPI peripheral SPI_CR1

#define SPI_CR1_CPHA           0
#define SPI_CR1_CPOL           1
#define SPI_CR1_MSTR           2
#define SPI_CR1_BR             3
#define SPI_CR1_SPE            6
#define SPI_CR1_LSBFIRST       7
#define SPI_CR1_SSI            8
#define SPI_CR1_SSM            9
#define SPI_CR1_RXONLY         10
#define SPI_CR1_DFF            11
#define SPI_CR1_CRCNEXT        12
#define SPI_CR1_CRCEN          13
#define SPI_CR1_BIDIOE         14
#define SPI_CR1_BIDIMODE       15

// Bit position defination of SPI peripheral SPI_CR2

#define SPI_CR2_RXDMAEN          0
#define SPI_CR2_TXDMAEN          1
#define SPI_CR2_SSOE             2
#define SPI_CR2_FRF              3
#define SPI_CR2_ERRIE            6
#define SPI_CR2_RXNEIE           7
#define SPI_CR2_TXEIE            8

// Bit position defination of SPI peripheral SPI_SR

#define SPI_SR_RXNE           0
#define SPI_SR_TXE            1
#define SPI_SR_CHSIDE         2
#define SPI_SR_UDR            3
#define SPI_SR_CRCERR         4
#define SPI_SR_MODF           5
#define SPI_SR_OVR            6
#define SPI_SR_BSY            7
#define SPI_SR_FRE            8

#include "stm32f407xx_gpio_drivers.h"
#include "stm32f407xx_spi_drivers.h"


#endif /* INC_STM32F4XX_H_ */
