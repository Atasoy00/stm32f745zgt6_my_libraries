#include "Temp.h"

void temp_Init(ADC_HandleTypeDef* hadc)
{
  ADC_ChannelConfTypeDef sConfig = {0};
  __HAL_RCC_GPIOA_CLK_ENABLE();

  hadc->Instance = ADC2;
  hadc->Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc->Init.Resolution = ADC_RESOLUTION_12B;
  hadc->Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc->Init.ContinuousConvMode = DISABLE;
  hadc->Init.DiscontinuousConvMode = DISABLE;
  hadc->Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc->Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc->Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc->Init.NbrOfConversion = 1;
  hadc->Init.DMAContinuousRequests = DISABLE;
  hadc->Init.EOCSelection = ADC_EOC_SINGLE_CONV;

  HAL_ADC_Init(hadc);
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
  HAL_ADC_ConfigChannel(hadc, &sConfig);
}

double temp_Read(ADC_HandleTypeDef* hadc)
{
  HAL_ADC_Start(hadc);
  HAL_ADC_PollForConversion(hadc, 100);
  double adc_val = HAL_ADC_GetValue(hadc);
  HAL_ADC_Stop(hadc);

  double actual_voltage_mV = adc_val * 0.8056640625; // 1/4096 * 3300mV (3.3V)

  double temp = (actual_voltage_mV - 400)/19.5;
  //double temp = (actual_voltage_mV - 500)/10;

  return temp;
}


/*
ADC_HandleTypeDef hadc2;
int main(void)
{
  temp_Init(&hadc2);
  while (1)
  {
	  temp = temp_Read(&hadc2);
	  HAL_Delay(500);
  }
}
*/





