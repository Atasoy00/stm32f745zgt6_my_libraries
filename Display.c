#include "Display.h"

void display_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

	DPY_BL1_OFF;
	DPY_BL2_OFF; 
	DPY_LE1_OFF; 
	DPY_LE2_OFF; 
	DPY_D0_OFF;
	DPY_D1_OFF;
	DPY_D2_OFF;
	DPY_D3_OFF;	
	DPY_DP1_OFF;
	DPY_DP2_OFF;

  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
}


void display_Write(unsigned char sayi)
{
	if(sayi<=99)
	{
		char onlarArr[4];
		char birlerArr[4];
		
		char onlarB = sayi/10;
		char birlerB = sayi - (onlarB*10);
		
		decToBin(onlarB, onlarArr);
		decToBin(birlerB, birlerArr);
		
		DPY_BL1_ON;
		DPY_BL2_ON; 
		
		DPY_DP1_OFF;
		DPY_DP2_OFF;
		
		DPY_LE2_ON;
		DPY_LE1_OFF;
		
		if(onlarArr[3]) DPY_D0_ON;
		else DPY_D0_OFF;
		if(onlarArr[2]) DPY_D1_ON;
		else DPY_D1_OFF;
		if(onlarArr[1]) DPY_D2_ON;
		else DPY_D2_OFF;
		if(onlarArr[0]) DPY_D3_ON;
		else DPY_D3_OFF;

		DPY_LE1_ON;
		DPY_LE2_OFF;
		
		if(birlerArr[3]) DPY_D0_ON;
		else DPY_D0_OFF;
		if(birlerArr[2]) DPY_D1_ON;
		else DPY_D1_OFF;
		if(birlerArr[1]) DPY_D2_ON;
		else DPY_D2_OFF;
		if(birlerArr[0]) DPY_D3_ON;
		else DPY_D3_OFF;
		
		DPY_LE2_ON;
		
	}
	else 
	{
		DPY_LE1_OFF;
		DPY_LE2_ON;
		
		DPY_D0_ON;
		DPY_D1_ON;
		DPY_D2_ON;
		DPY_D3_ON;
		
		DPY_LE1_ON;
		DPY_LE2_OFF;
		
		DPY_D0_ON;
		DPY_D1_ON;
		DPY_D2_ON;
		DPY_D3_ON;
		
		DPY_DP1_ON;
		DPY_DP2_ON;
	}
}

void decToBin(char decimalNumber, char BinaryForm[4])
{
	
	char A, B, C, D;
	
	if(decimalNumber >= 8){A=1; decimalNumber-=8;}
	else A=0;
	if(decimalNumber >= 4){B=1; decimalNumber-=4;}
	else B=0;
	if(decimalNumber >= 2){C=1; decimalNumber-=2;}
	else C=0;		
	if(decimalNumber ==1) D=1;
	else D=0;	
			
	BinaryForm[0] = A;
	BinaryForm[1] = B;
	BinaryForm[2] = C;
	BinaryForm[3] = D;
}


