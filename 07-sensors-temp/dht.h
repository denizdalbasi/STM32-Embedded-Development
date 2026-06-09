#ifendef DHT_H_
#define DHT_H_
#include "stm32f4xx_hal.h"
typedef struct {
  float Temperature;
} DHT_DataTypedef;
void DHT_Init(TIM_HandleTypeDef *htim, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
uint8_t (DHT_Read_DataTypedef *DHT_Data);
#endif