#ifndef __ID_SWITCH_H
#define __ID_SWITCH_H

#include "stm32f7xx_hal.h"

#define SW1_READ HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_1);
#define SW2_READ HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_0);
#define SW3_READ HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_15);
#define SW4_READ HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_14);


char IDswitch_Init(void);
char IDswitch_Read(void);

#endif


