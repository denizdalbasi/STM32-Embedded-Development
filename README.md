# STM32 Systems Engineering Portfolio

This repository documents my transition from high level software development into low level hardware and software integration. My main goal is to develop a deep understanding of the ARM Cortex-M architecture by building bare metal firmware that interacts directly with hardware registers.

---

##  Project Index

| Project | Focus | Status |
| :--- | :--- | :--- |
| **[01-GPIO-Blink](./01-GPIO-Blink/)** | GPIO Configuration, RCC Clock Gating, & Basic Timers |  In Progress |

---
##  Project Deep Dives

### [01-GPIO-Blink](./01-GPIO-Blink/)
This project was my first step in understanding the **Reset and Clock Control (RCC)** unit. 
* **Key Learning:** Learned that hardware peripherals are disabled by default to save energy; enabling the AHB/APB bus clock is the first requirement for any hardware interaction.
* **Tools:** Developed using VS Code and PlatformIO on the STM32 platform.