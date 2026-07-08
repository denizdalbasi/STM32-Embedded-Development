/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdint.h> // uint8_t için gerekli
/* --- USER CODE BEGIN Includes --- */
// Buraya ek bir şey eklemenize gerek yok, main.h zaten yeterli
/* --- USER CODE END Includes --- */
uint8_t rakamlar[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void segmentleri_yaz(uint8_t rakam) {
    uint8_t veri = rakamlar[rakam];
    GPIOA->ODR = (GPIOA->ODR & 0xFF00) | veri;
}

void hane_sec(int hane) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_SET);
    switch(hane) {
        case 0: HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET); break;
        case 1: HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET); break;
        case 2: HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET); break;
        case 3: HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); break;
    }
}
/* --- USER CODE END 0 --- */

int main(void) {
    // ... (HAL_Init(), SystemClock_Config() vs. buradadır) ...

    /* --- USER CODE BEGIN 2 --- */
    // Burası boş kalabilir
    /* --- USER CODE END 2 --- */

	while (1)
	    {
	        // 4. Hane (Sol): 1 rakamı
	        hane_sec(3);
	        segmentleri_yaz(1);
	        HAL_Delay(2);

	        // 3. Hane: 2 rakamı
	        hane_sec(2);
	        segmentleri_yaz(2);
	        HAL_Delay(2);

	        // 2. Hane: 3 rakamı
	        hane_sec(1);
	        segmentleri_yaz(3);
	        HAL_Delay(2);

	        // 1. Hane (Sağ): 4 rakamı
	        hane_sec(0);
	        segmentleri_yaz(4);
	        HAL_Delay(2);
	    }
}
