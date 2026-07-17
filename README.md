# STM32F407xx Bare-Metal Drivers

## Overview

This repository contains a custom **bare-metal peripheral driver library** for the **STM32F407xx** microcontroller, developed entirely in **Embedded C** using register-level programming.

The project is built from scratch by referring to the **STM32F407 Reference Manual** and **Datasheet**, without using the **STM32 HAL** or **Low-Layer (LL)** libraries.

The primary objective is to gain an in-depth understanding of the STM32F4 architecture and develop reusable, modular, and efficient peripheral drivers for embedded firmware development.

## Features

- Custom STM32F407xx device header (`stm32f407xx.h`)
- GPIO driver
- SPI driver
- Memory-mapped register definitions
- Peripheral register structures
- RCC clock control macros
- NVIC interrupt definitions
- Register-level peripheral configuration
- Modular driver architecture

## Project Structure

```
STM32F407xx-Bare-Metal-Drivers/
│
├── Drivers/
│   ├── Inc/
│   │   ├── stm32f407xx.h
│   │   ├── stm32f407xx_gpio_driver.h
│   │   └── stm32f407xx_spi_driver.h
│   │
│   └── Src/
│       ├── stm32f407xx_gpio_driver.c
│       └── stm32f407xx_spi_driver.c
│
└── README.md
```

## Technologies Used

- Embedded C
- STM32F407xx
- ARM Cortex-M4
- Bare-Metal Programming
- Register-Level Programming
- STM32CubeIDE
- ARM GCC

## Current Drivers

- ✅ Device Header
- ✅ GPIO Driver
- ✅ SPI Driver
- ⏳ UART Driver
- ⏳ I2C Driver
- ⏳ CAN Driver
- ⏳ ADC Driver

## Author

**Tanishq Vhanmane**
