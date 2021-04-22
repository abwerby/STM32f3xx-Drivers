#include <stdint.h>
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "OS_interface.h"


uint32_t msticks = 0;

int led1 = 0;
int led2 = 0;
int led3 = 0;

void fled1()
{
	GPIO_write_to_pin(GPIOA, PIN5, led1);
	led1 = !led1;
}

void fled2()
{
	GPIO_write_to_pin(GPIOA, PIN6, led2);
	led2 = !led2;
}

void fled3()
{
	GPIO_write_to_pin(GPIOA, PIN7, led3);
	led3 = !led3;
}


int main(void)
{
	RCC_voidInitSysClock();
	STK_voidInit(1000);
	
	OS_Init();
	/* Create Set temp Task with 0 'ms' delay and 10 'ms' periodic time */
	OS_Add_Task(fled1, 0, 10);
	/* Create Update_Temp Task with 10 'ms' delay and 100 'ms' periodic time */
	OS_Add_Task(fled2,  10, 100);
	/* Create Control_Temp Task with 20 'ms' delay and 1000 'ms' periodic time */
	OS_Add_Task(fled3, 20, 1000);
    
	RCC_voidEnableClock(RCC_AHB, 17);
	
	
	GPIO_Pin_Conf_t pin_confg;
	pin_confg.pin = PIN5;
	pin_confg.mode = GPIO_PIN_OUTPUT_MODE;
	pin_confg.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	pin_confg.speed = GPIO_PIN_SPEED_MEDIUM;
	pin_confg.pull = GPIO_PIN_NO_PULL;
	GPIO_Init(GPIOA, &pin_confg);
	pin_confg.pin = PIN6;
	GPIO_Init(GPIOA, &pin_confg);
	pin_confg.pin = PIN7;
	GPIO_Init(GPIOA, &pin_confg);
	
	
	while(1)
	{
		msticks = STK_uint32_t_millis();
		OS_Dispatch_Tasks();
	}
	
	return 0;
}



