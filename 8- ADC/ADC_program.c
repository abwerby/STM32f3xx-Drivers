/*********************************************************************************/
/* Author    : Abdelrhman                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/



#include <stdint.h>
#include "BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_interface.h"

void ADC_Init(ADC_TypeDef * ADCx, uint8_t line, uint8_t data_res)
{

	/* Enable AHB clk for ADC */
	if(ADCx == ADC1 || ADCx == ADC2)
	{
		SET_BIT(ADC12_COMMON->CCR, 16);
	}
	else if (ADCx == ADC3 || ADCx == ADC4)
	{
		SET_BIT(ADC34_COMMON->CCR, 16);
	}
	else
	{
			// Error Handler ...
	}

	/* Select the data resolution of the conversion */
	ADCx->CFGR |= (data_res << 3);
	/* Select the 1st conversion in regular sequence*/
	ADCx->SQR1 |= (line << 6);
	/* Enable ADC */
	SET_BIT(ADCx->CR, 0);
	while(GET_BIT(ADCx->ISR, 0) == 0);

}

void ADC_Deinit(ADC_TypeDef * ADCx)
{
    SET_BIT(ADCx->CR, 4);
    SET_BIT(ADCx->CR, 1);
}


uint16_t ADC_Read(ADC_TypeDef * ADCx)
{
	SET_BIT(ADCx->CR, 2);
	while(GET_BIT(ADCx->ISR, 3) == 0);
	return ADCx->DR;
}
