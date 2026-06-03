#include "stm32c0xx_hal.h"

static void MX_GPIO_Init(void);
void SystemClock_Config(void);
void Display_Number(uint8_t number);

// Array mapping numbers 0-9 to 7-segment bitmasks (PA4 to PA10)
// This configuration assumes a COMMON CATHODE display (High = On).
// Pins: PA10=g, PA9=f, PA8=e, PA7=d, PA6=c, PA5=b, PA4=a
const uint16_t SEGMENT_MAP[] = {
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9,              // 0
    GPIO_PIN_5 | GPIO_PIN_6,                                                                  // 1
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_10,                          // 2
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_10,                          // 3
    GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_9 | GPIO_PIN_10,                                       // 4
    GPIO_PIN_4 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_9 | GPIO_PIN_10,                          // 5
    GPIO_PIN_4 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10,              // 6
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6,                                                     // 7
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10, // 8
    GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_9 | GPIO_PIN_10               // 9
};

// All used pins grouped together for easy resetting
const uint16_t ALL_SEGMENTS = GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | 
                             GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;

int main(void){
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  
  while(1){
    // Loop from 1 to 9
    for (int i = 1; i <= 9; i++) {
      Display_Number(i);
      HAL_Delay(1000); // Hold the number for 1 second
    }
  }
}

// Helper function to handle the segment switching
void Display_Number(uint8_t number) {
  // 1. Turn off all segments first to prevent ghosting
  HAL_GPIO_WritePin(GPIOA, ALL_SEGMENTS, GPIO_PIN_RESET);
  
  // 2. Turn on only the pins needed for the current number
  if (number <= 9) {
    HAL_GPIO_WritePin(GPIOA, SEGMENT_MAP[number], GPIO_PIN_SET);
  }
}

static void MX_GPIO_Init(void){
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  
  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct.Pin = ALL_SEGMENTS;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void SystemClock_Config(void){
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    while(1);
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
    while(1);
  }
}