# STM32 Temperature Alarm System

This project uses an STM32 Nucleo board to monitor the temperature. It gives you visual and sound feedback based on how hot it is.

## How it works
* **The Sensor:** It reads the temperature using a DHT22 sensor.
* **The Display:** It uses an RGB LED to show the status:
    * **Green:** Everything is fine (below 30°C).
    * **Yellow:** It is getting warm (between 30°C and 40°C).
    * **Red:** It is too hot (above 40°C).
* **The Alarm:** A buzzer sounds only when the temperature goes above 40°C.

## What you need
* STM32 Nucleo-C031C6 board.
* DHT22 temperature sensor.
* RGB LED (Common Cathode).
* Active Buzzer.
* Wokwi simulator.

## How to set it up
1. **Wiring:** Connect your components to the pins defined in the `diagram.json` file. Make sure the sensor has power (3.3V) and a ground (GND) connection.
2. **Library:** You need the **DHT sensor library** (by Adafruit). Add it to your `libraries.txt` file in Wokwi.
3. **Code:** Copy the `sketch.ino` file into your project.
4. **Run:** Press the "Start" button in Wokwi.
5. **Test:** Click on the DHT22 sensor. Use the slider to change the temperature. Watch the LED color change and listen for the buzzer at high temperatures.
