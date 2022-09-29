#include "Opto.h"

void opto_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}


/*
void EXTI9_5_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(OPTO2_Pin);
  HAL_GPIO_EXTI_IRQHandler(OPTO1_Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == OPTO1_Pin || GPIO_Pin == OPTO2_Pin)
	{
		//do something when optocouplers triggered
	}	
}

*/

