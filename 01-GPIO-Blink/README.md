# Project 01: Bare-Metal GPIO Control & RCC Initialization

## Project Overview
What looks like a simple blinking LED is really me working through the Cortex-M4 boot sequence and the Reset and Clock Control (RCC) peripheral. It’s the foundation for everything else in this repository, since it sets up how the system actually comes to life after reset.


## Technical Specifications
* **Hardware:** STM32F407VG (ARM Cortex-M4)
* **Framework:** PlatformIO / CMSIS
* **Communication:** Bit-masking via memory-mapped registers

## Key Engineering Concepts Applied

### 1. Clock Gating (The AHB1 Bus)
On the STM32, peripherals are powered down by default to optimize energy consumption. To interact with Port C, I first had to enable its clock bit in the `RCC_AHB1ENR` (AHB1 Peripheral Clock Enable Register). 
> **Learning:** Attempting to write to a GPIO register without enabling the bus clock results in a silent failure—a vital lesson in hardware-level debugging.

### 2. GPIO Register Configuration
I avoided high-level "black box" functions to manually configure the following:
* **MODER:** Set the pin to General Purpose Output mode.
* **OTYPER:** Configured as Push-Pull to ensure the pin can both source and sink current.
* **OSPEEDR:** Set to Low Speed to minimize electromagnetic interference (EMI) and power consumption for a simple toggle task.

### 3. The Logic Loop
Instead of using a hardware timer (reserved for Project 03), I implemented a software delay loop. This allowed me to observe the relationship between CPU clock cycles and real-time execution, providing a practical understanding of instruction timing.
