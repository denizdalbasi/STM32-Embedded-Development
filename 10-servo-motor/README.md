# My STM32 Servo Motor Sweep Project

I built this project using an STM32 board to automatically spin a standard servo motor back and forth between 0 degrees and 175 degrees.

## What I Made It Do

- **Move Forward:** I programmed the servo to slowly turn from 0° up to 175°.
- **Pause:** I made it stop at 175° for half a second.
- **Move Backward:** I programmed the servo to slowly turn back from 175° to 0°.
- **Pause:** I made it stop at 0° for half a second before starting over.

## Parts I Used

- My STM32 Board (NUCLEO-F401RE)
- My Standard Servo Motor (SG90)
- My jumper wires

## My Pin Setup

I configured a Timer (TIM3 Channel 2) to send the correct signal to the servo:

- **PA7**: I connected this pin to the **Signal wire** of my servo motor.

## How I Wrote the Code Logic

I set up the PWM signal to repeat every 20 milliseconds to tell the motor which angle to turn to:

1. **0 Degrees:** I targeted a pulse that lasts exactly 1.0 millisecond (`pulse = 1000` in my code).
2. **175 Degrees:** I targeted a pulse that lasts about 1.97 milliseconds (`pulse = 1972` in my code).
3. I wrote loops to slowly change the pulse size up and down by `10` every 15 milliseconds so my motor moves smoothly instead of snapping instantly.

## How I Run It

1. I open my project in **STM32CubeIDE**.
2. I add my code to the `main.c` file.
3. I build and upload the code to my board.
