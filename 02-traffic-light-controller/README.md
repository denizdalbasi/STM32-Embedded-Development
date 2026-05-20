# Project 02: Traffic Light Controller (STM32Cube HAL)

## Project Overview
This project upgrades the repository from bare-metal register manipulation to the STM32Cube Hardware Abstraction Layer (HAL) framework to build a state machine that controls a three-stage LED traffic light cycle.


## Technical Specifications
* **Hardware:** STM32 Nucleo Ecosystem (ARM Cortex-M)
* **Framework:** PlatformIO / STM32Cube HAL
* **Peripherals Used:** GPIOA (Pins 5, 6, 7), RCC (HSE & PLL Clocks), SysTick Timer

## Key Engineering Concepts Applied

### Clock Tree Configuration (HSE & PLL)
Instead of relying on the slow internal clock, the system is explicitly configured to use the stable External Crystal Oscillator (HSE) multiplied by a Phase-Locked Loop (PLL) to boost the core CPU clock speed while applying appropriate prescalers for the internal APB peripheral buses.