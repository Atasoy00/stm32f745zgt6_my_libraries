#include "ID_switch.h"

char IDswitch_Init()
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
	
	return IDswitch_Read();
}

char IDswitch_Read()
{
	char sw[4];
	sw[0] = SW1_READ;
	sw[1] = SW2_READ;
	sw[2] = SW3_READ;
	sw[3] = SW4_READ;
	
	return (8*sw[0]+4*sw[1]+2*sw[2]+1*sw[3]);
}


