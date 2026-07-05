#include "main.h"
#include "stm32f4xx_hal_adc.h"
/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

/* Function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  MX_ADC1_Init();


  while (1)
  {
    /* USER CODE BEGIN WHILE */
    HAL_ADC_Start(&hadc1);

    // Wait for conversion (10ms timeout)
    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
    {
      uint32_t adcValue = HAL_ADC_GetValue(&hadc1);

      // If bright (value > 2000), keep ON. If dark, blink.
      if (adcValue > 2000)
      {
        HAL_GPIO_WritePin(LED_PIN_GPIO_Port, LED_PIN_Pin, GPIO_PIN_SET);
      }
      else
      {
        HAL_GPIO_TogglePin(LED_PIN_GPIO_Port, LED_PIN_Pin);
        HAL_Delay(250);
      }
    }
    /* USER CODE END WHILE */
  }
}

/**
  * @brief ADC1 Initialization Function
  */
static void MX_ADC1_Init(void)
{
  ADC_ChannelConfTypeDef sConfig = {0};

  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = ENABLE; // Changed to ENABLE for continuous reads
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  HAL_ADC_Init(&hadc1);

  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
}

/**
  * @brief GPIO Initialization Function
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* Configure your LED_PIN (PA7) */
  HAL_GPIO_WritePin(LED_PIN_GPIO_Port, LED_PIN_Pin, GPIO_PIN_RESET);
  GPIO_InitStruct.Pin = LED_PIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_PIN_GPIO_Port, &GPIO_InitStruct);
}

// SystemClock_Config and Error_Handler follow here...
void SystemClock_Config(void)
{
  // Basic initialization; if empty, it uses the default internal 16MHz HSI clock
}
