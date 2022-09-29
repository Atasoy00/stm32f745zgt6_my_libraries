/*******************************************************************************
*Copyright(C)			: INTETRA
*File Name				: rs232.c
*Creator					: Ferhat ATASOY
*Update  					: None
*Latest update	 	: None
*Description			: None
*Current Version	: rv.1.0
*******************************************************************************
Version History:
-Created

(uVision5  v5.37.0.0 , STM32F745ZGTx)
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************INCLUDE******************************************
*/
#include "RS232.h"
#include "stm32f7xx.h"                  // Device header
#include "stm32f7xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
/////////////////////////////////////////////////////////////////////////////////////////
/**************************************DEFINITIONS***************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************VARIABLES****************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************STRUCTURES***************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************FUNCTIONS****************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************THREADS******************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////
/****************************************OTHERS******************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
* Function Name  			: rs232_Init
* Description    			: None
* Input         			: UART_HandleTypeDef huart
* Output        			: None
* Return        			: None
*******************************************************************************/

void rs232_Init(UART_HandleTypeDef* huart)
{
  __HAL_RCC_GPIOE_CLK_ENABLE();
  huart->Instance = UART7;
  huart->Init.BaudRate = RS232_BAUD_RATE;
  huart->Init.WordLength = UART_WORDLENGTH_8B;
  huart->Init.StopBits = UART_STOPBITS_1;
  huart->Init.Parity = UART_PARITY_NONE;
  huart->Init.Mode = UART_MODE_TX_RX;
  huart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart->Init.OverSampling = UART_OVERSAMPLING_16;
  huart->Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart->AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  HAL_UART_Init(huart); // HAL_UART_MspInit burada cagiriliyor

  HAL_NVIC_SetPriority(UART7_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(UART7_IRQn);
	__HAL_UART_ENABLE_IT(huart, UART_IT_RXNE);
}

/*******************************************************************************
* Function Name  			: HAL_UART_MspInit
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/

void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(huart->Instance==UART7)
  {
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_UART7;
    PeriphClkInitStruct.Uart7ClockSelection = RCC_UART7CLKSOURCE_PCLK1;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);
			
    __HAL_RCC_UART7_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    /**UART7 GPIO Configuration
    PE7     ------> UART7_RX
    PE8     ------> UART7_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART7;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
  }
}

/*******************************************************************************
* Function Name  			: rs232_Transmit
* Description    			: None
* Input         			: UART_HandleTypeDef huart, pData, Size, Timeout
* Output        			: None
* Return        			: None
*******************************************************************************/

void rs232_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_UART_Transmit(huart, pData, Size, Timeout);
}

/*******************************************************************************
* Function Name  			: rs232_Receive_IT
* Description    			: None
* Input         			: UART_HandleTypeDef huart, pData, Size
* Output        			: pData
* Return        			: None
*******************************************************************************/

void rs232_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
	HAL_UART_Receive_IT(huart, pData, Size);
}


/*
UART_HandleTypeDef huart7;
uint8_t Rx_data[10];
int main(void)
{
  rs232_Init(&huart7);
  rs232_Receive_IT(&huart7, Rx_data, sizeof(Rx_data));
  while (1)
  {
  }
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  rs232_Receive_IT(&huart7, Rx_data, sizeof(Rx_data));
  rs232_Transmit(&huart7, Rx_data, sizeof(Rx_data), 100);
}
void UART7_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart7);
}
*/

