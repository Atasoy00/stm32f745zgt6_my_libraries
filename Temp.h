#ifndef __TEMP_H
#define __TEMP_H

#include "stm32f7xx_hal.h"

void temp_Init(ADC_HandleTypeDef* hadc);
double temp_Read(ADC_HandleTypeDef* hadc);

#endif

