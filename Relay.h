#ifndef __RELAY_H
#define __RELAY_H

#include "stm32f7xx_hal.h"

/// Röle pini (Port : E , Pin : 12)
#define RELAY_Port GPIOE
#define RELAY_Pin GPIO_PIN_12

#define RELAY_ON      HAL_GPIO_WritePin(RELAY_Port, RELAY_Pin, GPIO_PIN_SET)
#define RELAY_OFF     HAL_GPIO_WritePin(RELAY_Port, RELAY_Pin, GPIO_PIN_RESET)
#define RELAY_TOGGLE  HAL_GPIO_TogglePin(RELAY_Port, RELAY_Pin)

void relay_Init(void);

#endif


