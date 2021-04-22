#include <stdint.h>
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "SYSCFG_interface.h"



volatile uint8_t B_Click;
volatile uint8_t E_Rotate;

void ButtonISR()
{
	while (GPIO_read_from_pin(GPIOC, PIN10) == LOW);
	B_Click++;
	if (B_Click > 4) B_Click = 0;
}

void EncoderISR()
{
	while (GPIO_read_from_pin(GPIOB, PIN7) == LOW);
	E_Rotate++;
	if (E_Rotate > 20) E_Rotate = 0;
}


int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_AHB, RCC_AHB_GPIOB);
	RCC_voidEnableClock(RCC_AHB, RCC_AHB_GPIOC);
	RCC_voidEnableClock(RCC_APB2, 0);
	
	GPIO_Pin_Conf_t pin_confg;
	pin_confg.pin = PIN5;
	pin_confg.mode = GPIO_PIN_OUTPUT_MODE;
	pin_confg.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	pin_confg.speed = GPIO_PIN_SPEED_MEDIUM;
	pin_confg.pull = GPIO_PIN_NO_PULL;
	GPIO_Init(GPIOA, &pin_confg);
	
	pin_confg.pin = PIN10;
	pin_confg.mode = GPIO_PIN_INPUT_MODE;
	pin_confg.pull = GPIO_PIN_PULL_UP;
	GPIO_Init(GPIOC, &pin_confg);
	
	pin_confg.pin = PIN7;
	pin_confg.mode = GPIO_PIN_INPUT_MODE;
	pin_confg.pull = GPIO_PIN_PULL_UP;
	GPIO_Init(GPIOB, &pin_confg);
	
	SYSCFG_Config_EXTI(EXTI_LINE10, SYSCFG_EXTI_GPIOC);
	SYSCFG_Config_EXTI(EXTI_LINE7, SYSCFG_EXTI_GPIOB);
	EXTI_voidEnableEXTI(EXTI_LINE10, EXTI_FALLING_EDGE, ButtonISR);
	EXTI_voidEnableEXTI(EXTI_LINE7, EXTI_FALLING_EDGE, EncoderISR);
	NVIC_voidInit();
	NVIC_voidEnableInterrupt(40);
	NVIC_voidEnableInterrupt(23);
	
	
	while(1)
	{
	
	}
	
	return 0;
}


