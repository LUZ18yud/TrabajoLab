#include "diag/Trace.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"



void SysTick_Handler(void)
   {
    HAL_IncTick();
   }

void GPIO_Config (void)
{
	GPIO_InitTypeDef GPIO_InitStruct ={0};

	__HAL_RCC_GPIOD_CLK_ENABLE();

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);

	GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15 ;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init (GPIOD, &GPIO_InitStruct);
}


int main()
{
	HAL_Init();
	GPIO_Config();
	while(1){
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
		HAL_Delay(1000);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);

		HAL_Delay(1000);

		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
		HAL_Delay(1000);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);

		HAL_Delay(1000);

		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
		HAL_Delay(1000);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);

		HAL_Delay(1000);

		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
		HAL_Delay(1000);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
	}

}
