# STM32 Systems Engineering Portfolio

This repository documents my transition from high-level software development into low-level hardware and software integration. My main goal is to develop a deep understanding of the ARM Cortex-M architecture by building bare-metal firmware that interacts directly with hardware registers.

---

## Project Index

| Project | Focus | Status |
| :--- | :--- | :--- |
| **[01-GPIO-Blink](./01-GPIO-Blink/)** | GPIO Configuration, RCC Clock Gating, & Basic Timers | Completed |
| **[02-traffic-light-controller](./02-traffic-light-controller/)** | Finite State Machines (FSM) & Multi-LED Timing Control | Completed |
| **[03-Button-Interrupt](./03-Button-Interrupt/)** | EXTI Lines, NVIC Configuration, & Switch Debouncing | Completed |
| **[04-usart_printf](./04-usart_printf/)** | UART/USART Serial Communication & Standard I/O Retargeting | Completed |
| **[05-led-buzzer-notes](./05-led-buzzer-notes/)** | PWM Signal Generation & Passive Buzzer Frequency Control | Completed |
| **[06-seven-segment-1to9](./06-seven-segment-1to9/)** | Multiplexing, Lookup Tables, & Digital Display Driving | Completed |
| **[07-sensors-temp](./07-sensors-temp/)** | Sensor Interfacing, & Logic-Based Alerts| In progress |

---

## Project Deep Dives

### [01-GPIO-Blink](./01-GPIO-Blink/)
This project was my first step in understanding the **Reset and Clock Control (RCC)** unit. 
* **Key Learning:** I learned that hardware peripherals are disabled by default to save energy. Enabling the AHB/APB bus clock is the very first requirement before you can interact with any hardware register.
* **Tools:** Developed using VS Code and PlatformIO on the STM32 platform.

### [02-traffic-light-controller](./02-traffic-light-controller/)
A practical project to control multiple LEDs by simulating a real-world traffic light system.
* **Key Learning:** I learned how to implement a **Finite State Machine (FSM)** in C to manage different system states (Red, Yellow, Green) and used non-blocking delays to control precise timing.

### [03-Button-Interrupt](./03-Button-Interrupt/)
Moving away from polling methods to handle external hardware inputs efficiently.
* **Key Learning:** I configured the **Nested Vectored Interrupt Controller (NVIC)** and **EXTI** lines to trigger code instantly when a physical button is pressed. I also solved the hardware switch bouncing issue using software debouncing logic.

### [04-usart_printf](./04-usart_printf/)
Setting up a communication bridge between the STM32 microcontroller and a computer terminal.
* **Key Learning:** I configured the **USART** peripheral registers for serial data transfer. I also retargeted the standard C `printf()` function to send text data over the USB-Serial port for easy debugging.

### [05-led-buzzer-notes](./05-led-buzzer-notes/)
Using hardware timers to generate audio tones and control hardware components.
* **Key Learning:** I learned how to configure timers in **PWM (Pulse Width Modulation)** mode. By changing the timer auto-reload registers, I generated different frequencies to play musical notes through a passive buzzer.

### [06-seven-segment-1to9](./06-seven-segment-1to9/)
Driving a numeric display to count from 1 to 9 using low-level bit manipulation.
* **Key Learning:** I created a binary lookup table to map numbers to the correct GPIO pin outputs. This project helped me understand how to manage multiple pins simultaneously without affecting other hardware registers.

### [07-temp_sensor](./07-temp_sensor/)
Monitoring environmental data and implementing conditional logic for safety alerts.
* **Key Learning:** I learned to interface with the **DHT22 sensor**, which required precise timing protocols to read digital signals. I also implemented a color-coded warning system using an **RGB LED** and an audible buzzer that triggers based on temperature thresholds.
* **Tools:** Developed using the Wokwi simulator to validate hardware-to-code integration before moving to physical hardware testing.