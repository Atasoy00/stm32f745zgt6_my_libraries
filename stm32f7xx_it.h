#ifndef __STM32F7xx_IT_H
#define __STM32F7xx_IT_H

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void DebugMon_Handler(void);
//void USART3_IRQHandler(void);
void UART7_IRQHandler(void);

#endif 

