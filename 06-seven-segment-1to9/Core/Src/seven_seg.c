#include "seven_seg.h"

// Define the segment map here so it is only visible to this file
// (or you can move it to the .h file if other files need to see it)
static const uint16_t SEGMENT_MAP[] = {
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9,      // 0
    GPIO_PIN_5 | GPIO_PIN_6,                                                          // 1
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_10,                  // 2
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_10,                  // 3
    GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_9 | GPIO_PIN_10,                               // 4
    GPIO_PIN_4 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_9 | GPIO_PIN_10,                  // 5
    GPIO_PIN_4 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10,      // 6
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6,                                             // 7
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10, // 8
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_9 | GPIO_PIN_10       // 9
};
/**
void Display_Number(uint8_t number) {
    // Clear all segments first
    HAL_GPIO_WritePin(SEG_PORT, ALL_SEGMENTS, GPIO_PIN_RESET);

    // Check if the number is valid
    if (number <= 9) {
        // Set the specific pins high
        HAL_GPIO_WritePin(SEG_PORT, SEGMENT_MAP[number], GPIO_PIN_SET);
    }
}

*/
void Display_Number(uint8_t number) {
    // For Common Anode:
    // To turn OFF all segments, set them to 3.3V (SET)
    HAL_GPIO_WritePin(SEG_PORT, ALL_SEGMENTS, GPIO_PIN_SET);

    if (number <= 9) {
        // To turn ON specific segments, set them to GND (RESET)
        HAL_GPIO_WritePin(SEG_PORT, SEGMENT_MAP[number], GPIO_PIN_RESET);
    }
}
