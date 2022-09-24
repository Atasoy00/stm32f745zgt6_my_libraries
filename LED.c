#include "LED.h"

void LED_Init()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    __HAL_RCC_GPIOF_CLK_ENABLE();
    GPIO_InitStruct.Pin = LED1_Pin | LED2_Pin | LED3_Pin | LED4_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
}

