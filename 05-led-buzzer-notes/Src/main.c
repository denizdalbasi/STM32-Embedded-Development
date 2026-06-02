#include "main.h"

TIM_HandleTypeDef htim4;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM4_Init(void);

void Play_Note(uint16_t frequency, uint16_t duration_ms);
void Rest(uint16_t duration_ms);

int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_TIM4_Init();

  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

  while (1)
  {
    HAL_GPIO_WritePin(LED_DO_GPIO_Port, LED_DO_Pin, GPIO_PIN_SET);
    Play_Note(261, 500);
    HAL_GPIO_WritePin(LED_DO_GPIO_Port, LED_DO_Pin, GPIO_PIN_RESET);
    Rest(100);

    HAL_GPIO_WritePin(LED_RE_GPIO_Port, LED_RE_Pin, GPIO_PIN_SET);
    Play_Note(294, 500);
    HAL_GPIO_WritePin(LED_RE_GPIO_Port, LED_RE_Pin, GPIO_PIN_RESET);
    Rest(100);

    HAL_GPIO_WritePin(LED_MI_GPIO_Port, LED_MI_Pin, GPIO_PIN_SET);
    Play_Note(329, 500);
    HAL_GPIO_WritePin(LED_MI_GPIO_Port, LED_MI_Pin, GPIO_PIN_RESET);
    Rest(500);
  }
}

void Play_Note(uint16_t frequency, uint16_t duration_ms)
{
  if (frequency == 0) {
    Rest(duration_ms);
    return;
  }

  uint32_t arr_value = (1000000 / frequency) - 1;

  __HAL_TIM_SET_AUTORELOAD(&htim4, arr_value);
  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, arr_value / 2);

  HAL_Delay(duration_ms);
}

void Rest(uint16_t duration_ms)
{
  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
  HAL_Delay(duration_ms);
}
