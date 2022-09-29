/*******************************************************************************
*Copyright(C)			: INTETRA
*File Name				: Peripheral.c
*Creator					: Ali ÖNER
*Update  					: Ali ÖNER
*Latest update	 	: 03.03.2021
*Description			: 
*Current Version	: rv.1.1.0.3  
*******************************************************************************
Version History: 
Jun 11th, 2020
rv.1.1.0.3  
-Created
	
(uVision5  v5.26.2.0 , STM32F745ZGTx)
*******************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************INCLUDE******************************************
*/
#include "Peripheral.h"
#include "stm32f7xx.h"                  // Device header
#include "stm32f7xx_hal.h"              // Keil::Device:STM32Cube HAL:Common


/////////////////////////////////////////////////////////////////////////////////////////
/**************************************DEFINITIONS***************************************
*/
/////////////////////////////////////////////////////////////////////////////////////////
/***************************************VARIABLES****************************************
*/
int inputState=0;
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

void InitRelay(void){
	GPIO_InitTypeDef GPIO_InitStruct;
		__HAL_RCC_GPIOE_CLK_ENABLE();
	
	
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	
	GPIO_InitStruct.Pin   = GPIO_PIN_12;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}

/*******************************************************************************
* Function Name  			: initFlashors
* Description    			: Flashor output initialize
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void initFlashors(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	
	//FLASHOR 4
	GPIO_InitStruct.Pin   = GPIO_PIN_13;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	
	//FLASHOR 3
	GPIO_InitStruct.Pin   = GPIO_PIN_10;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	
	
	
	//FLASHOR 2
	GPIO_InitStruct.Pin   = GPIO_PIN_9;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	//FLASHOR 1
	GPIO_InitStruct.Pin   = GPIO_PIN_12;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
	
	
	
	GPIO_InitStruct.Pin   = GPIO_PIN_2;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
	
	//FLASHOR 1
	GPIO_InitStruct.Pin   = GPIO_PIN_3;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
}


/*******************************************************************************
* Function Name  			: Flashor_1_On
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_1(uint8_t status){
	if(status==1)
		
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12 , GPIO_PIN_SET);
	else if(status==0)
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12 , GPIO_PIN_RESET);
	else if(status==2){
		if(HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_12)==1)
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12 , GPIO_PIN_RESET);
		else if(HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_12)==0)
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12 , GPIO_PIN_SET);
	}	
}
/*******************************************************************************
* Function Name  			: Flashor_1_On
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_2(uint8_t status){
	if(status==1)
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9 , GPIO_PIN_SET);
	else if(status==0)
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9 , GPIO_PIN_RESET);
	else if(status==2){
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9)==1)
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9 , GPIO_PIN_RESET);
		else if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9)==0)
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9 , GPIO_PIN_SET);
	}
}
/*******************************************************************************
* Function Name  			: Flashor_1_On
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_3(uint8_t status){
	if(status==1)
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10 , GPIO_PIN_SET);
	else if(status==0)
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10 , GPIO_PIN_RESET);
	else if(status==2){
		if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10)==1)
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10 , GPIO_PIN_RESET);
		else if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10)==0)
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10 , GPIO_PIN_SET);
	}
}
/*******************************************************************************
* Function Name  			: Flashor_1_On
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_4(uint8_t status){
	if(status==1)
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13 , GPIO_PIN_SET);
	else if(status==0)
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13 , GPIO_PIN_RESET);
	else if(status==2){
		if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13)==1)
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13 , GPIO_PIN_RESET);
		else if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13)==0)
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13 , GPIO_PIN_SET);
	}
}

/*******************************************************************************
* Function Name  			: Flashor_1_On
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_1_On(void){
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: Flashor_1_Off
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_1_Off(void){
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: Flashor_2_On
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_2_On(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: Flashor_2_Off
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_2_Off(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: Flashor_3_On
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_3_On(void){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: Flashor_3_Off
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_3_Off(void){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: Flashor_4_On
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_4_On(void){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: Flashor_4_Off
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Flashor_4_Off(void){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: getTemprature
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: temprature value
*******************************************************************************/
int getTemprature(){ 
	uint32_t  temperature;
	uint8_t   sign_bit_temperature;
	ADC_TEMP_StartConversion ();
	temperature = (float)ADC_TEMP_GetValue();
	ADC_TEMP_ConversionDone();
	temperature = (uint32_t)(VREF * temperature) / 4096;
	temperature = (temperature - 500);
	sign_bit_temperature = (temperature>>31 & 0x1);
	if (sign_bit_temperature == 0)
		temperature = temperature/10;
	else
	{
		temperature = ~temperature + 1;
		temperature = temperature/10;
		temperature = ~temperature + 1;
	}
	return (uint8_t)(temperature & 0xFF);
}

/*******************************************************************************
* Function Name  			: Switch_Initialize
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void Switch_Initialize(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	__HAL_RCC_GPIOD_CLK_ENABLE();
	GPIO_InitStruct.Pin   = GPIO_PIN_12;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);	
}

/*******************************************************************************
* Function Name  			: Switch_Read
* Description    			: None
* Input         			: Selected Switch
* Output        			: None
* Return        			: Selected Switch Status
*******************************************************************************/
int Switch_Read(int Switch){
	if(Switch==0)
		inputState=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7);
	else if(Switch==1)
		inputState=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
	else
		inputState=-1;
	return inputState;
}

/*******************************************************************************
* Function Name  			: IP_DefaultButton
* Description    			: None
* Input         			: None
* Output        			: IP button
* Return        			: None
*******************************************************************************/
void IP_DefaultButton(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/*******************************************************************************
* Function Name  			: Switch_Read
* Description    			: None
* Input         			: Selected Switch
* Output        			: None
* Return        			: Selected Switch Status
*******************************************************************************/
int IP_default_button(void){
	inputState=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
	return inputState;
}

/*******************************************************************************
* Function Name  			: FAN_OUT_Initialize
* Description    			: None
* Input         			: None
* Output        			: Run Fan
* Return        			: None
*******************************************************************************/
void FAN_OUT_Initialize(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOE_CLK_ENABLE();
	GPIO_InitStruct.Pin   = GPIO_PIN_12;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}

/*******************************************************************************
* Function Name  			: FAN_Start
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void FAN_Start(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: FAN_Stop
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void FAN_Stop(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: ADC_TEMP_Initialize
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: ADC Value of read for temprature sensor
*******************************************************************************/
int32_t ADC_TEMP_Initialize (void) {
  ADC_ChannelConfTypeDef sConfig;
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* ADC3 GPIO Configuration: PF10 -> ADC3_IN8 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* Peripheral clock enable */
  __HAL_RCC_ADC1_CLK_ENABLE();

  /* Configure the global features of the ADC
    (Clock, Resolution, Data Alignment and number of conversion) */
  hadcTEMP.Instance = ADC1;
  hadcTEMP.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV4;
  hadcTEMP.Init.Resolution = ADC_RESOLUTION_12B;
  hadcTEMP.Init.ScanConvMode = DISABLE;
  hadcTEMP.Init.ContinuousConvMode = DISABLE;
  hadcTEMP.Init.DiscontinuousConvMode = DISABLE;
  hadcTEMP.Init.NbrOfDiscConversion = 1;
  hadcTEMP.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadcTEMP.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadcTEMP.Init.NbrOfConversion = 1;
  hadcTEMP.Init.DMAContinuousRequests = DISABLE;
  hadcTEMP.Init.EOCSelection = EOC_SINGLE_CONV;
  HAL_ADC_Init(&hadcTEMP);

  /* Configure the selected ADC channel */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  HAL_ADC_ConfigChannel(&hadcTEMP, &sConfig);

  AD_done = 0;

  return 0;
}

/*******************************************************************************
* Function Name  			: ADC_TEMP_Uninitialize
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
int32_t ADC_TEMP_Uninitialize (void) {

  /* Peripheral clock disable */
  __HAL_RCC_ADC1_CLK_DISABLE();

  /* ADC3 GPIO Configuration: PF10 -> ADC3_IN8 */
  HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0);

  return 0;
}

/*******************************************************************************
* Function Name  			: ADC_TEMP_StartConversion
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
int32_t ADC_TEMP_StartConversion (void) {
  __HAL_ADC_CLEAR_FLAG(&hadcTEMP, ADC_FLAG_EOC);
  HAL_ADC_Start(&hadcTEMP);

  AD_done = 0;

  return 0;
}

/*******************************************************************************
* Function Name  			: ADC_TEMP_ConversionDone
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
int32_t ADC_TEMP_ConversionDone (void) {
  HAL_StatusTypeDef status;

  status = HAL_ADC_PollForConversion(&hadcTEMP, 0);
  if (status == HAL_OK) {
    AD_done = 1;
    return 0;
  } else {
    AD_done = 0;
    return -1;
  }
}

/*******************************************************************************
* Function Name  			: ADC_TEMP_GetValue
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
int32_t ADC_TEMP_GetValue (void) {
  HAL_StatusTypeDef status;

  if (AD_done == 0) {
    status = HAL_ADC_PollForConversion(&hadcTEMP, 0);
    if (status != HAL_OK) return -1;
  } else {
    AD_done = 0;
  }

  return (int32_t)(HAL_ADC_GetValue(&hadcTEMP));
}

/*******************************************************************************
* Function Name  			: sevenSegmentGPIO_Init
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void sevenSegmentGPIO_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOD_CLK_ENABLE();
	GPIO_InitStruct.Pin   = GPIO_PIN_14 | GPIO_PIN_15;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	
	__HAL_RCC_GPIOE_CLK_ENABLE();
	GPIO_InitStruct.Pin   = GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_13 | GPIO_PIN_14;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	__HAL_RCC_GPIOG_CLK_ENABLE();
	GPIO_InitStruct.Pin   = GPIO_PIN_2;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
}

/*******************************************************************************
* Function Name  			: DSPLY0_High
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLY0_High(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: DSPLY0_Low
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLY0_Low(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: DSPLY1_High
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLY1_High(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: DSPLY1_Low
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLY1_Low(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: DSPLY2_High
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLY2_High(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: DSPLY2_Low
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLY2_Low(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: DSPLY3_High
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLY3_High(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: DSPLY3_Low
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLY3_Low(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: DSPLYLE_High
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLYLE_High(void){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: DSPLYLE_Low
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLYLE_Low(void){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: DSPLYD2_High
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLYD2_High(void){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: DSPLYD2_Low
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLYD2_Low(void){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15 , GPIO_PIN_RESET);
}

/*******************************************************************************
* Function Name  			: DSPLYD1_High
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLYD1_High(void){
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_2 , GPIO_PIN_SET);
}

/*******************************************************************************
* Function Name  			: DSPLYD1_Low
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/
void DSPLYD1_Low(void){
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_2 , GPIO_PIN_RESET);
}
/*******************************************************************************
* Function Name  			: Flash Read init
* Description    			: None
* Input         			: None
* Output        			: None
* Return        			: None
*******************************************************************************/

