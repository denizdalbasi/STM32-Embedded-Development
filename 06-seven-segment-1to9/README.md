# STM32C0 7-Segment 1-9 Counter

This repository contains a simple bare-metal / HAL implementation for an **STM32C0** microcontroller to drive a 1-digit 7-segment display. The application continuously cycles through digits from **1 to 9** with a 1-second delay between each transition.

## Features
- Optimized for the entry-level **STM32C0** series.
- Uses **STM32CubeHAL** for clock and GPIO management.
- Implements an efficient bitmask lookup array to handle segment state changes.
- Safe pin state clearing (`RESET`) between numbers to prevent "ghosting" effects.

---

## Hardware Configuration

The code is designed by default for a **Common Cathode** 7-segment display. If you are using a Common Anode display, modify the active pin states (`GPIO_PIN_SET` / `GPIO_PIN_RESET`) inside the `Display_Number` function.

### Pinout Mapping

Connect your STM32C0 microcontroller to the 7-segment display according to the following layout:

| 7-Segment Segment | STM32 Pin | GPIO Pin Constant |
| :---: | :---: | :--- |
| **a** | PA4 | `GPIO_PIN_4` |
| **b** | PA5 | `GPIO_PIN_5` |
| **c** | PA6 | `GPIO_PIN_6` |
| **d** | PA7 | `GPIO_PIN_7` |
| **e** | PA8 | `GPIO_PIN_8` |
| **f** | PA9 | `GPIO_PIN_9` |
| **g** | PA10 | `GPIO_PIN_10` |

*Note: Don't forget to connect the common ground (GND) pin of your display to the STM32 GND through appropriate current-limiting resistors (e.g., 220Ω or 330Ω) for each segment.*

---

## Code Architecture

- **`main()`**: Initializes the HAL abstraction, configures the internal High-Speed clock (HSI), sets up Port A pins, and runs an infinite `while(1)` loop driving a `for` loop from 1 to 9.
- **`Display_Number(uint8_t number)`**: A helper utility that clears all active segments first, then references the `SEGMENT_MAP[]` array to light up only the exact pins needed to display the requested digit.
- **`MX_GPIO_Init()`**: Configures `PA4` through `PA10` in Push-Pull output mode (`GPIO_MODE_OUTPUT_PP`) with internal pull-ups disabled (`GPIO_NOPULL`).

---

## Setup & Compilation

1. Copy the provided code into your `main.c` file inside an **STM32CubeIDE**, **Keil uVision**, or **VS Code (Cortex-Debug)** project environment.
2. Ensure you have the `stm32c0xx_hal.h` and associated library drivers linked in your project framework.
3. Build the project and flash the binary to your target STM32C0 development board.