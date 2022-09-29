#ifndef __OPTO_H
#define __OPTO_H

#include "stm32f7xx_hal.h"

#define OPTO1_Port GPIOB
#define OPTO2_Port GPIOB

#define OPTO1_Pin  GPIO_PIN_8
#define OPTO2_Pin  GPIO_PIN_7

void opto_Init(void);
void EXTI9_5_IRQHandler(void);

#endif


