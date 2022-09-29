#ifndef __BUTTON_H
#define __BUTTON_H

#include "stm32f7xx_hal.h"

#define BUTTON_Port GPIOB
#define BUTTON_Pin GPIO_PIN_1

void button_Init(void);

#endif
