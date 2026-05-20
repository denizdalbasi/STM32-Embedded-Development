# Project 03: Button Interrupts

## Project Overview
This project moves the CPU away from constantly checking ("polling") a button. Instead, it configures the hardware to watch the button in the background. The exact millisecond you press it, the system pauses what it's doing, toggles the LED, and goes right back to work.


## Technical Specifications
* **Hardware:** STM32 Nucleo Boards
* **Framework:** PlatformIO / STM32Cube HAL
* **CKey Features:** External Interrupts (EXTI) & Nested Vectored Interrupt Controller (NVIC)

## Key Engineering Concepts Applied

### 1. Interrupts vs. Polling
Instead of wasting CPU power constantly checking if a button is pressed, interrupts let the hardware monitor the button in the background and instantly pause the main program only when an event occurs.

### 2. Handling Button "Bounce"
Because mechanical buttons physically vibrate and fake multiple rapid presses when tapped, we use a quick software delay to let the electrical signal settle for a single, clean toggle.

