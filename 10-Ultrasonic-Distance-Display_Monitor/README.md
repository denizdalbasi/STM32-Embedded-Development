# Ultrasonic Distance and Display Monitor

This is an embedded project built for the STM32 Nucleo-F401RE board. It measures distance using an ultrasonic sensor and shows the distance on a 7-segment display while using an LED for close-range warnings.

## Main Features

- **Distance Measurement:** Uses an HC-SR04 ultrasonic sensor to find out how far an object is, keeping only the whole number (integer part).
- **7-Segment Display:** Shows the measured distance as a single digit from 0 to 9.
- **Proximity Alert:** Turns on an LED automatically if an object gets closer than 2 cm.

## Hardware and Pin Connections

| Component / Sensor | MCU Pin | Description |
| :--- | :--- | :--- |
| **7-Segment Display** | PA7, PA8, PA9, PA10 | Segment and control pins |
| **7-Segment Display** | PB3, PB4, PB5, PB6 | Segment and control pins |
| **7-Segment Display & LED** | PB10, PC7 | Display pins and LED indicator |
| **Ultrasonic Sensor** | Timer 3 (TIM3) | Measures time for the echo signal |

## Project Files

- **`main.c`**: Contains the main program loop, distance calculation, and display functions.
- **`distance-light-system.ioc`**: The STM32CubeMX configuration file.

## How to Run This Project

1. Open this folder in your IDE (like VS Code with the STM32 extension or STM32CubeIDE).
2. Make sure CMake and the GNU Arm Toolchain are installed on your computer.
3. Build the project using these commands:
   ```bash
   cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug
   cmake --build build
