#ifndef SEVEN_SEG_H
#define SEVEN_SEG_H

#include "main.h"

// Define the port for all segments (as per your current setup)
#define SEG_PORT GPIOA

// Define the pin mask for all segments used
#define ALL_SEGMENTS (GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | \
                      GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10)

// Function prototypes
void Display_Number(uint8_t number);

#endif // SEVEN_SEG_H
