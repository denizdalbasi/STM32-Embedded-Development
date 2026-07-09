# STM32 Light-Sensitive LED Sequence Project

This project uses an STM32 microcontroller to monitor ambient light levels using an ADC (Analog-to-Digital Converter) and control three LEDs based on the detected light intensity.

## Features
- **Dark Mode (< 500):** All three LEDs blink simultaneously to indicate low light conditions.
- **Light Mode (> 2000):** The LEDs perform a sequential pattern (1 -> 2 -> 3).
- **Neutral Mode:** LEDs remain OFF when light levels are between the two thresholds.

## Hardware Requirements
- STM32 Microcontroller
- 3 LEDs
- Light Dependent Resistor (LDR) sensor
- Current limiting resistors for LEDs
- Voltage divider circuit for the LDR

## Pin Configuration
Ensure the following pins are configured as `GPIO_Output` in STM32CubeMX and labeled accordingly:
* **PA5**: `LED1`
* **PA6**: `LED2`
* **PA7**: `LED3`

> **Note:** The LDR sensor must be connected to the ADC input pin (default: **PA0**).



## Logic Overview
The program operates in a continuous loop:
1.  **Read ADC:** Polls the ADC for the current light value.
2.  **Evaluate Thresholds:**
    * **Low Light:** Uses `HAL_GPIO_TogglePin` with a bitwise OR mask (`LED1_Pin | LED2_Pin | LED3_Pin`) to blink all at once.
    * **High Light:** Uses a state machine (`ledStep`) to trigger one LED at a time.
    * **Thresholding:** Implements basic hysteresis to prevent flickering between states.

## How to Compile
1.  Import the project into **STM32CubeIDE**.
2.  Ensure `LED1_Pin`, `LED2_Pin`, and `LED3_Pin` are correctly defined in your `main.h` file.
3.  If you encounter an error regarding `HAL_ADCEx_Calibration_Start`, simply remove that line from `main.c`, as it is not supported by all STM32F4 variants.
4.  Build and flash to your device.