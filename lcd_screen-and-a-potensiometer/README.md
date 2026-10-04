# Arduino I2C 1602 LCD Speed-Controlled Marquee

A continuous scrolling text (marquee) project for an Arduino using a 1602 LCD display with an I2C backpack adapter. The scrolling speed can be adjusted dynamically in real time using an external potentiometer, and debug information is output to the Serial Monitor.

---

##  Hardware Components
* **Arduino Board** (e.g., Arduino Uno or Nano)
* **1602 LCD Display** with an **I2C Interface Adapter (Backpack)**
* **Potentiometer** (3-pin rotary resistor)

---

##  Wiring Guide

### 1. LCD Module (I2C) to Arduino
* **GND** $\rightarrow$ GND
* **VCC** $\rightarrow$ 5V
* **SDA** $\rightarrow$ A4 
* **SCL** $\rightarrow$ A5 

### 2. Potentiometer to Arduino
* **Middle Pin** $\rightarrow$ A0 (Analog In)
* **Outer Pin 1** $\rightarrow$ 5V
* **Outer Pin 2** $\rightarrow$ GND

## Features
* **Continuous Marquee Scrolling:** Text loops smoothly across the 16-column, 2-row display without disappearing.
* **Real-Time Speed Control:** Twist the potentiometer knob to instantly speed up or slow down the scrolling delay.
* **Serial Feedback:** View current delay metrics directly via the Arduino IDE Serial Monitor (set to 9600 baud).
