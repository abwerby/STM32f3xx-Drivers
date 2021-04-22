#include <stdint.h>
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"

uint32_t msticks = 0;
uint32_t Msticks = 0;

void stk_callback()
{
	Msticks++;
}

int main(void)
{
	RCC_voidInitSysClock();
	STK_voidInit(8000);
	STK_Set_CallBack(stk_callback);
	
	RCC_voidEnableClock(RCC_AHB, 17);
	
	GPIO_Pin_Conf_t pin_confg;
	pin_confg.pin = PIN5;
	pin_confg.mode = GPIO_PIN_OUTPUT_MODE;
	pin_confg.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	pin_confg.speed = GPIO_PIN_SPEED_MEDIUM;
	pin_confg.pull = GPIO_PIN_NO_PULL;
	GPIO_Init(GPIOA, &pin_confg);
	
	
	while(1)
	{
		msticks = STK_uint32_t_millis();
		GPIO_write_to_pin(GPIOA, PIN5, HIGH);
		STK_voidDelayMs(1000);
		GPIO_write_to_pin(GPIOA, PIN5, LOW);
		STK_voidDelayMs(1000);
		if (msticks > 10000)
		{
			STK_voidStop();
		}
	}
	
	return 0;
}



