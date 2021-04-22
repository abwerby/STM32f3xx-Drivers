#include <stdint.h>
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "DMA_interface.h"
#include "DAC_interface.h"


uint32_t msticks = 0;
uint16_t adc1Val;
uint32_t adc2Val;
uint32_t ticks_before = 0;
uint32_t ticks_after = 0;

uint8_t seq_arr[3] = {5};
uint32_t AdcArr[3];

int main(void)
{
	RCC_voidInitSysClock();
	STK_voidInit(72000);
	
    
	RCC_voidEnableClock(RCC_AHB, 28);
	RCC_voidEnableClock(RCC_APB1, 29);
	RCC_voidEnableClock(RCC_AHB, 0);
	RCC_voidEnableClock(RCC_AHB, 1);


	
//	GPIO_Pin_Conf_t pin_confg;
//	
//	pin_confg.pin = PIN0;
//	pin_confg.mode = GPIO_PIN_INPUT_MODE;
//	pin_confg.pull = GPIO_PIN_NO_PULL;
//	GPIO_Init(GPIOA, &pin_confg);
//	pin_confg.pin = PIN6;
//	GPIO_Init(GPIOA, &pin_confg);
	
	DAC_config dac_config;
	dac_config.Buffer = DAC_BUFFER_ENABLE;
	dac_config.Channel = 1;
	dac_config.DMA_State = DAC_DMA_DISABLE;
	dac_config.Trigger_Source = DAC_SWTRIG_Event;
	dac_config.Wave = DAC_WAVE_DISABLE;
	DAC_Init(DAC1, &dac_config);

	ADC_config adc_config;
	adc_config.Numbers_of_Channels = 1;
	adc_config.Channels_Sequence = seq_arr;
	adc_config.CLK_Source = ADC_CLOCK_ASYNC_DIV1;
	adc_config.Data_Resolution = ADC_DATA_RES_12;
	adc_config.DMA_State = ADC_DMA_DISABLE;
	adc_config.DMA_Mode = ADC_DMA_SCAN_DISABLE;
	adc_config.Scan_State = ADC_SCAN_DISABLE;
	

	ADC_Init(ADC2, &adc_config);
	

//	DMA_config dma_config;
//	dma_config.Channel_Number = 0;
//	dma_config.Channel_Priority = DMA_Channel_Priority_High;
//	dma_config.Circular_Mode = DMA_Circular_Mode_ON;
//	dma_config.Data_Direction = DMA_Data_Direction_Read_From_PER;
//	dma_config.Memory_Address = AdcArr;
//	dma_config.Peripheral_Reg = &ADC2->DR;
//	dma_config.Memory_Size = DMA_MEM_OR_PER_Size_32;
//	dma_config.Peripheral_Size = DMA_MEM_OR_PER_Size_32;
//	dma_config.Total_Data = 1;
//	dma_config.MINC = DMA_MINC_ON;
//	dma_config.PINC = DMA_PINC_OFF; 
//	dma_config.MEM2MEM = DMA_MEM2MEM_OFF;
//	DMA_Init(DMA2, &dma_config);

	ADC_Start_DMA(ADC2);
	
	while(1)
	{
		msticks = STK_uint32_t_millis();
		DAC_Soft_Write(DAC1, 1, 500);
		adc1Val = ADC_Read(ADC2);
	}
	
	return 0;
}



