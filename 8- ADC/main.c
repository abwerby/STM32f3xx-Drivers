#include <stdint.h>
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "TFT_Interface.h"


uint32_t msticks = 0;
uint16_t adc1Val;
uint32_t adc2Val;
uint32_t ticks_before = 0;
uint32_t ticks_after = 0;


int main(void)
{
	RCC_voidInitSysClock();
	STK_voidInit(32000);
	
    
	RCC_voidEnableClock(RCC_AHB, 28);
	RCC_voidEnableClock(RCC_AHB, 17);
	RCC_voidEnableClock(RCC_AHB, 18);
	RCC_voidEnableClock(RCC_AHB, 19);

	
	
//	GPIO_Pin_Conf_t pin_confg;
//	
//	pin_confg.pin = PIN0;
//	pin_confg.mode = GPIO_PIN_INPUT_MODE;
//	pin_confg.pull = GPIO_PIN_NO_PULL;
//	GPIO_Init(GPIOA, &pin_confg);
//	pin_confg.pin = PIN6;
//	GPIO_Init(GPIOA, &pin_confg);


	ADC_Init(ADC2, ADC_IN5, ADC_DATA_RES_12);

	TFT_Init();
	TFT_Set_Rotation(TFT_LANDSCAPE_REV);	
	TFT_fillScreen(ILI9486_BLACK); // FILL SCREEN WITH BLACK

	TFT_SetTextSize(3);
	TFT_SetCursor(2,40);
	TFT_SetTextColor(ILI9486_GREENYELLOW,ILI9486_BLACK);
	TFT_Print_String("Volt: ",TFT_STRING_MODE_NO_BACKGROUND);

	TFT_SetTextSize(2);



	
	while(1)
	{
		msticks = STK_uint32_t_millis();
		adc1Val = ADC_Read(ADC2);
		TFT_fillRect(100, 40, 80, 40, ILI9486_RED);
		TFT_SetCursor(100,40);
		TFT_Print_Number((adc1Val*3300)/4095, TFT_STRING_MODE_NO_BACKGROUND);
		TFT_SetCursor(100,60);
		TFT_Print_Number(msticks/1000, TFT_STRING_MODE_NO_BACKGROUND);
		STK_voidDelayMs(100);
	}
	
	return 0;
}



