
#ifndef __EXTI_CALLBACKS_H
#define __EXTI_CALLBACKS_H

#include "stm32f7xx_hal.h"
#include "Button.h"
#include "Opto.h"

#define OPTO1_Port GPIOB
#define OPTO2_Port GPIOB

#define OPTO1_Pin  GPIO_PIN_8
#define OPTO2_Pin  GPIO_PIN_7

void EXTI1_IRQHandler(void);
void EXTI9_5_IRQHandler(void);

#endif


