# STM32 7-Segment Display Counter

This project demonstrates how to control a 7-segment display using an STM32 Nucleo board. The system cycles through numbers from 0 to 9, updating the display every second.

## How it works

- **The Display:** It uses a 7-segment LED display to show digits.
- **The Logic:** An array maps each number (0–9) to the correct segments (A–G).
- **The Loop:** The program uses a `for` loop to count upwards, setting the required GPIO pins to high or low to form the numbers.

## What you need

- STM32 Nucleo board (e.g., F401RE).
- 7-segment display (Common Cathode).
- 7 resistors (220Ω to 330Ω) to protect the segments.
- Breadboard and jumper wires.

## Wiring Connections

Connect the segments of the display to the STM32 GPIO pins as follows:

| Segment | STM32 Pin |
| :------ | :-------- |
| A       | PA0       |
| B       | PA1       |
| C       | PA2       |
| D       | PA3       |
| E       | PA4       |
| F       | PA5       |
| G       | PA6       |
| Common  | GND       |

[Image of 7-segment display wiring diagram]

## How to set it up

1. **Wiring:** Connect your display segments to the STM32 pins using the resistors listed above. Ensure the common pin is connected to the GND rail.
2. **Configuration:** Ensure that pins PA0 through PA6 are configured as `GPIO_Output` in your project settings.
3. **Code:** Copy the provided code into your `main.c` file within your STM32CubeIDE project.
4. **Run:** Build the project and flash it to your Nucleo board.
5. **Test:** The display should start counting from 0 to 9, repeating the cycle continuously.
