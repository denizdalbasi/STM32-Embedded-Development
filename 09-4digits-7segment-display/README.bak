# STM32 Light Sensor Project

This project implements a light-sensing system using an STM32 microcontroller. It uses an Analog-to-Digital Converter (ADC) to read light levels from an LDR and controls an LED based on the environmental brightness.

## Hardware Configuration

* **Sensor Pin:** The Light Dependent Resistor (LDR) circuit is connected to **Pin PA0**, which is mapped to **ADC1_IN0**.
* **LED Pin:** An LED is connected to **Pin PA7** (configured as an output) to provide visual feedback based on the sensor data.
* **Configuration:** The ADC is set to **12-bit resolution** with **Continuous Conversion Mode** enabled to allow for constant real-time monitoring of the incoming analog signal.

![ADC Configuration](image_3a11c3.png)

## How the Code Works

The system operates through a continuous loop that monitors light intensity:

1.  **ADC Initialization:** The `MX_ADC1_Init` function configures the hardware to convert analog voltage (from the LDR) into a digital value ranging from 0 to 4095.
2.  **Calibration:** `HAL_ADCEx_Calibration_Start` is called during setup to ensure the ADC provides the most accurate readings possible for your specific board.
3.  **Data Acquisition:** Inside the `while(1)` loop, the program triggers `HAL_ADC_Start` and polls the conversion status to retrieve the current light value.
4.  **Decision Logic:** * **Threshold Comparison:** The code compares the `adcValue` against a threshold of **2000**.
    * **Bright State:** If the light level is above 2000, the LED is set to a constant `ON` state.
    * **Dark State:** If the light level falls below 2000, the system enters a `blink` pattern, toggling the LED state every 250 milliseconds.



## Logic Visualization
To see the control flow of the sensor-to-LED logic in action, see the video below:
[visualisation.mp4](https://your-video-link-here)