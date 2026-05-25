# 04-usart_printf

This project shows how to send text from an STM32 microchip to your computer using **USART** (serial communication) and the **libopencm3** library. It sets up the standard C `printf()` function so that instead of printing to a normal computer screen, it sends the text over a wire to a serial monitor.

## Features

* **Works on Multiple Boards:** Ready to use with `NUCLEO_F103RB`, `NUCLEO_F446RE`, `NUCLEO_F302R8`, and `NUCLEO_L432KC`.
* **Simple Printing:** Changes how `printf()` works under the hood so you can use it normally in your code.
* **Speed:** Set to a standard speed of `9600` baud.

---

## Hardware Setup

The project uses **USART2**. The transmission wire is connected to pin **PA2**. On Nucleo boards, this pin connects directly to the built-in ST-LINK programmer, which passes the text to your computer through the USB cable.

| Peripheral | Function | Pin | Note |
| :--- | :--- | :--- | :--- |
| **USART2** | TX (Transmit) | `PA2` | Sends data to your computer's USB port |

---

## How the Code Works

### 1. Turning things on (Initialization)
* `rcc_setup()`: Turns on the internal power and clock for the GPIOA pins and the USART2 system so they can function.
* `usart_setup()`: Tells pin PA2 to act as a communication wire instead of a regular input/output pin. It also sets the communication rules: 9600 speed, 8 bits of data, 1 stop bit, and no extra security checks (parity).

### 2. Redirecting printf()
Normally, `printf()` does nothing on a microchip because there is no computer screen attached to it.