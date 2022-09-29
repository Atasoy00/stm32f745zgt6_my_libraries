/*******************************************************************************
*Copyright(C)			: INTETRA
*File Name				: LED.h
*Creator					: Ferhat ATASOY
*Update  					: Ferhat ATASOY
*Latest update	 	: None
*Description			: 
*Current Version	: rv.1.0  
*******************************************************************************
Version History: 
-Created
	
(uVision5  v5.37.0.0 , STM32F745ZGTx)
*******************************************************************************/
#ifndef __LED_H
#define __LED_H
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************INCLUDE******************************************
*/
#include "stm32f7xx_hal.h"
/////////////////////////////////////////////////////////////////////////////////////////
/**************************************DEFINITIONS***************************************
*/

#define LED1_Port GPIOF
#define LED2_Port GPIOF
#define LED3_Port GPIOF
#define LED4_Port GPIOF

#define LED1_Pin GPIO_PIN_2
#define LED2_Pin GPIO_PIN_3
#define LED3_Pin GPIO_PIN_4
#define LED4_Pin GPIO_PIN_5

#define LED1_ON HAL_GPIO_WritePin(LED1_Port, LED1_Pin, GPIO_PIN_SET)
#define LED2_ON HAL_GPIO_WritePin(LED2_Port, LED2_Pin, GPIO_PIN_SET)
#define LED3_ON HAL_GPIO_WritePin(LED3_Port, LED3_Pin, GPIO_PIN_SET)
#define LED4_ON HAL_GPIO_WritePin(LED4_Port, LED4_Pin, GPIO_PIN_SET)

#define LED1_OFF HAL_GPIO_WritePin(LED1_Port, LED1_Pin, GPIO_PIN_RESET)
#define LED2_OFF HAL_GPIO_WritePin(LED2_Port, LED2_Pin, GPIO_PIN_RESET)
#define LED3_OFF HAL_GPIO_WritePin(LED3_Port, LED3_Pin, GPIO_PIN_RESET)
#define LED4_OFF HAL_GPIO_WritePin(LED4_Port, LED4_Pin, GPIO_PIN_RESET)

#define LED1_TOGGLE HAL_GPIO_TogglePin(LED1_Port, LED1_Pin)
#define LED2_TOGGLE HAL_GPIO_TogglePin(LED2_Port, LED2_Pin)
#define LED3_TOGGLE HAL_GPIO_TogglePin(LED3_Port, LED3_Pin)
#define LED4_TOGGLE HAL_GPIO_TogglePin(LED4_Port, LED4_Pin)

/////////////////////////////////////////////////////////////////////////////////////////
/***************************************VARIABLES****************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************STRUCTURES***************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************FUNCTIONS****************************************
*/
void LED_Init(void);
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************THREADS******************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////
/****************************************OTHERS******************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////
#endif

