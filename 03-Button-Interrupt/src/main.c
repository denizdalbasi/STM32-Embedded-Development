#include "stm32f1xx_hal.h"

#if defined(NUCLEO_L432KC) || defined(NUCLEO_G431KB)
  #define LED_PORT      GPIOB
  #define LED_PIN       GPIO_PIN_3
#else
  #define LED_PORT      GPIOA
  #define LED_PIN       GPIO_PIN_5
#endif

#define BUTTON_PORT     GPIOC
#define BUTTON_PIN      GPIO_PIN_13

void SystemClock_Config(void);
static void GPIO_Init(void);

volatile uint8_t button_pressed_flag = 0;

int main(void) {
    HAL_Init();
    SystemClock_Config();
    GPIO_Init();

    while (1) {
        if (button_pressed_flag) {
            HAL_Delay(50);
            
            if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_RESET) {
                HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
            }
            
            button_pressed_flag = 0;
        }
    }
}

static void GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = BUTTON_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING; 
    GPIO_InitStruct.Pull = GPIO_NOPULL;       
    HAL_GPIO_Init(BUTTON_PORT, &GPIO_InitStruct);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

/**
  * @brief EXTI line detection callbacks. Triggers when the interrupt fires.
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == BUTTON_PIN) {
        button_pressed_flag = 1;
    }
}

/**
  * @brief Override the default ISR handler for EXTI Lines 10 to 15
  */
void EXTI15_10_IRQHandler(void) {
    HAL_GPIO_EXTI_IRQHandler(BUTTON_PIN);
}

void SystemClock_Config(void) {
}

// SysTick Handler required for HAL_Delay() to function properly
void SysTick_Handler(void) {
    HAL_IncTick();
}