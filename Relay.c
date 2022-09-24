#include "Relay.h"

void relay_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    __HAL_RCC_GPIOE_CLK_ENABLE();
    GPIO_InitStruct.Pin = RELAY_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}



