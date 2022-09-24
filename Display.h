#ifndef __DISPLAY_H
#define __DISPLAY_H

#include "stm32f7xx_hal.h"

#define DPY_BL1_Port GPIOE
#define DPY_BL2_Port GPIOC
#define DPY_LE1_Port GPIOD
#define DPY_LE2_Port GPIOC
#define DPY_D0_Port  GPIOE
#define DPY_D1_Port  GPIOE
#define DPY_D2_Port  GPIOE
#define DPY_D3_Port  GPIOE
#define DPY_DP1_Port GPIOD
#define DPY_DP2_Port GPIOG

#define DPY_BL1_Pin GPIO_PIN_15
#define DPY_BL2_Pin GPIO_PIN_0
#define DPY_LE1_Pin GPIO_PIN_14
#define DPY_LE2_Pin GPIO_PIN_2
#define DPY_D0_Pin  GPIO_PIN_14
#define DPY_D1_Pin  GPIO_PIN_11
#define DPY_D2_Pin  GPIO_PIN_10
#define DPY_D3_Pin  GPIO_PIN_13
#define DPY_DP1_Pin GPIO_PIN_15
#define DPY_DP2_Pin GPIO_PIN_2

#define DPY_BL1_ON HAL_GPIO_WritePin(DPY_BL1_Port, DPY_BL1_Pin, GPIO_PIN_SET)
#define DPY_BL2_ON HAL_GPIO_WritePin(DPY_BL2_Port, DPY_BL2_Pin, GPIO_PIN_SET)
#define DPY_LE1_ON HAL_GPIO_WritePin(DPY_LE1_Port, DPY_LE1_Pin, GPIO_PIN_SET)
#define DPY_LE2_ON HAL_GPIO_WritePin(DPY_LE2_Port, DPY_LE2_Pin, GPIO_PIN_SET)
#define DPY_D0_ON  HAL_GPIO_WritePin(DPY_D0_Port,  DPY_D0_Pin,  GPIO_PIN_SET)
#define DPY_D1_ON  HAL_GPIO_WritePin(DPY_D1_Port,  DPY_D1_Pin,  GPIO_PIN_SET)
#define DPY_D2_ON  HAL_GPIO_WritePin(DPY_D2_Port,  DPY_D2_Pin,  GPIO_PIN_SET)
#define DPY_D3_ON  HAL_GPIO_WritePin(DPY_D3_Port,  DPY_D3_Pin,  GPIO_PIN_SET)
#define DPY_DP1_ON HAL_GPIO_WritePin(DPY_DP1_Port, DPY_DP1_Pin, GPIO_PIN_SET)
#define DPY_DP2_ON HAL_GPIO_WritePin(DPY_DP2_Port, DPY_DP2_Pin, GPIO_PIN_SET)

#define DPY_BL1_OFF HAL_GPIO_WritePin(DPY_BL1_Port, DPY_BL1_Pin, GPIO_PIN_RESET)
#define DPY_BL2_OFF HAL_GPIO_WritePin(DPY_BL2_Port, DPY_BL2_Pin, GPIO_PIN_RESET)
#define DPY_LE1_OFF HAL_GPIO_WritePin(DPY_LE1_Port, DPY_LE1_Pin, GPIO_PIN_RESET)
#define DPY_LE2_OFF HAL_GPIO_WritePin(DPY_LE2_Port, DPY_LE2_Pin, GPIO_PIN_RESET)
#define DPY_D0_OFF  HAL_GPIO_WritePin(DPY_D0_Port,  DPY_D0_Pin,  GPIO_PIN_RESET)
#define DPY_D1_OFF  HAL_GPIO_WritePin(DPY_D1_Port,  DPY_D1_Pin,  GPIO_PIN_RESET)
#define DPY_D2_OFF  HAL_GPIO_WritePin(DPY_D2_Port,  DPY_D2_Pin,  GPIO_PIN_RESET)
#define DPY_D3_OFF  HAL_GPIO_WritePin(DPY_D3_Port,  DPY_D3_Pin,  GPIO_PIN_RESET)	
#define DPY_DP1_OFF HAL_GPIO_WritePin(DPY_DP1_Port, DPY_DP1_Pin, GPIO_PIN_RESET)
#define DPY_DP2_OFF HAL_GPIO_WritePin(DPY_DP2_Port, DPY_DP2_Pin, GPIO_PIN_RESET)

void display_Init(void);
void decToBin(char decimalNumber, char BinaryForm[4]);
void display_Write(unsigned char sayi);

#endif


