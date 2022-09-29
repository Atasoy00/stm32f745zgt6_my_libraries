#ifndef __RS485_H
#define __RS485_H

#include "stm32f7xx_hal.h"

void rs485_Init(UART_HandleTypeDef* huart);
void rs485_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
void rs485_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

#endif




