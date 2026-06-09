#include "dht.h"
static TIM_HandleTypeDef *dht_timer;
static GPIO_TypeDef *dht_gpio_port;
static uint16_t dht_gpio_pin;
static void delay_us(uint16_t us){
  __HAL_TIM_SET_COUNTER(dht_timer, 0);
  while (__HAL_TIM_GET_COUNTER(dht_timer)<us);
}
//pin çıkış
static void Set_Pin_Output(GPIO_TypeDef *GPIOx , uint16_t GPIO_Pin){
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin=GPIO_Pin;
  GPIO_InitStruct.Mode= GPIO_MOD_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}
//pin giriş 
static void Set_Pin_Input(GPIO_TypeDef *GPIOx , uint16_t GPIO_Pin){
   GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin=GPIO_Pin;
  GPIO_InitStruct.Mode= GPIO_MOD_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}
void DHT_Init(TIM_HandleTypeDef *htim , GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
  dht_timer = htim;
  dht_gpio_port = GPIOx;
  dht_gpio_pin = GPI_Pin;
  HAL_TIM_Base_Start(dht_timer);
}
//dht22 başlatma 
static uint8_t DHT_Start(void){
  uint8_t Response = 0;
  Set_Pin_Output(dht_gpio_port,dht_gpio_pin);
  HAL_GPIO_WritePin(dht_gpio_port,dht_gpio_pin,GPIO_PIN_RESET);
  Hal_Delay(1);
  HAL_GPIO_WritePin(dht_gpio_port,dht_gpio_pin,GPIO_PIN_SET);
  Hal_Delay(10);
  HAL_GPIO_WritePin(dht_gpio_port,dht_gpio_pin);
  Hal_Delay(20);
  if(!(HAL_GPIO_ReadPin(dht_gpio_port, dht_gpio_pin))){
    delay_us(80);
    if ((HAL_GPIO_ReadPin(dht_gpio_port, dht_gpio_pin))) Response = 1;
    else Response -1;
    
  }
  uint16_t timeout = 0;
  while((HAL_GPIO_ReadPin(dht_gpio_port, dht_gpio_pin))&& timeout<1000)timeout++;
  return Response;
}
static uint8_t DHT_Read(void){
  uint8_t i,j;
  for (j=0; j<8; j++){
    while(!((HAL_GPIO_ReadPin(dht_gpio_port, dht_gpio_pin)));
    delay_us(40);
    if(!(HAL_GPIO_ReadPin(dht_gpio_port, dht_gpio_pin))){
      i &= ~(1<<(7-j));
    }else{
      i|=(1<<(7-j));
      while ((Hal_GPIO_ReadPin(dht_gpio_port, dht_gpio_pin)));
    }
  } return i;
} 
uint8_t DHT_Read_Data(DHT_DataTypedef *DHT_Data){
  uint8_t Rh_byte1,Rh_byte2,Temp_byte1,Temp_byte2;
  uint16_t sum;
  if (DHT_Start()==1){
    Rh_byte1 = DHT_Read();
    Rh_byte2 = DHT_Read();
    Temp_byte1 = DHT_Read();
    Temp_byte2 = DHT_Read();
    sum = DHT_Read();
    if (sum==((Rh_byte1+Rh_byte2+Temp_byte1+Temp_byte2) & 0xFF)){
      DHT_Data-> Temparature = (float)((((Temp_byte1 & 0x7F)<<8) |  Temp_byte2)/10.0)*(-1);
    }
    else{
      DHT_Data->Temperature=(float)((Temp_byte1 << 8)| Temp_byte2) / 10.0;
    }
    return 1;
  }
  return 0;
}