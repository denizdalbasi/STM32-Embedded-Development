# 05-pwm-led-music

This project shows how to play musical notes (Do, Re, Mi) using a buzzer and blink three different LEDs at the same time. It was created using **STM32CubeIDE** and uses **PWM (Pulse Width Modulation)** on an STM32 microcontroller to change the sound frequencies.

## Features

* **Built with STM32CubeIDE:** Uses the integrated CubeMX tool for easy graphical hardware configuration.
* **3 Musical Notes:** Plays Do (261 Hz), Re (294 Hz), and Mi (329 Hz) in a loop.
* **LED Sync:** Each note turns on a specific LED while the sound is playing.
* **PWM Control:** Uses a hardware timer to generate clear square waves for a passive buzzer.

---

## Hardware Setup

To run this code, configure your hardware pins using the built-in CubeMX tool inside STM32CubeIDE to match these settings:

| Component | Function | CubeMX Pin Name | Note |
| :--- | :--- | :--- | :--- |
| **Buzzer** | PWM Output | `TIM4_CH1` | Connected to a passive buzzer |
| **LED 1** | GPIO Output | `LED_DO_Pin` | Lights up during the 'Do' note |
| **LED 2** | GPIO Output | `LED_RE_Pin` | Lights up during the 'Re' note |
| **LED 3** | GPIO Output | `LED_MI_Pin` | Lights up during the 'Mi' note |

> [!TIP]
> Make sure your Timer 4 clock is set up so that the counter runs at **1 MHz** (e.g., Internal Clock = 16MHz, Prescaler = 15). This makes the note math work perfectly.

---

## How to Test It

1. Open the project in **STM32CubeIDE**.
2. Set up your pins and timer configuration in the `.ioc` file and generate the code.
3. Replace your `main.c` code with this code.
4. Wire your passive buzzer and three LEDs (with appropriate resistors) to the correct STM32 pins.
5. Build the project and flash the code to your board directly through **STM32CubeIDE**.
6. The board will continuously loop through the notes Do, Re, and Mi while flashing the respective LEDs.