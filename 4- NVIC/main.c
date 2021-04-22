#include <stdint.h>
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"


int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_AHB, 17);
	
	GPIO_Pin_Conf_t pin_confg;
	pin_confg.pin = PIN5;
	pin_confg.mode = GPIO_PIN_OUTPUT_MODE;
	pin_confg.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	pin_confg.speed = GPIO_PIN_SPEED_MEDIUM;
	pin_confg.pull = GPIO_PIN_NO_PULL;
	GPIO_Init(GPIOA, &pin_confg);
	
	NVIC_voidInit();
	NVIC_voidSetPriority(6, 0b01000000);
	NVIC_voidSetPriority(7, 0b00010000);
	NVIC_voidEnableInterrupt(6);
	NVIC_voidEnableInterrupt(7);
	NVIC_voidSetPendingFlag(6);
	
	while(1)
	{
	
	}
	
	return 0;
}


void EXTI0_IRQHandler()
{
	NVIC_voidSetPendingFlag(7);
	GPIO_write_to_pin(GPIOA, PIN5, HIGH);
}

void EXTI1_IRQHandler()
{
	
	GPIO_write_to_pin(GPIOA, PIN5, LOW);
	
}

