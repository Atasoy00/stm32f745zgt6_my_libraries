#include "EXTI_Callbacks.h"

void EXTI1_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(BUTTON_Pin);
}

void EXTI9_5_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(OPTO2_Pin);
  HAL_GPIO_EXTI_IRQHandler(OPTO1_Pin);
}


/*

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_1)
	{
		button_Pressed();
	}
	
	if(GPIO_Pin == GPIO_PIN_7 || GPIO_Pin == GPIO_PIN_8)
	{
		opto_Triggered();
	}	
}

*/
