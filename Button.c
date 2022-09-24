#include "Button.h"

void button_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);
}


/*

	int i = 0;

	int main(void)
	{
	  HAL_Init();
	  SystemClock_Config();
	  display_Init();
	  button_Init();

	  while (1)
	  {
		  display_Write(i);
		  HAL_Delay(100);
	  }
	}

	void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
	{
		if(GPIO_Pin == GPIO_PIN_1)
		{
			i++;
		}
	}

*/

