#include "main.h"
#include "stm32f7xx_it.h"

extern UART_HandleTypeDef huart3;
//extern UART_HandleTypeDef huart7;


void NMI_Handler(void)
{
  while (1)
  {
  }
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void DebugMon_Handler(void)
{
}
/*
void UART7_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart7);
}
*/
///*
void USART3_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart3);
}
//*/


