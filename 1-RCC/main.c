/*********************************************************************************/
/* Author    : Abdelrhman Werby                                                  */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#include "BIT_MATH.h"
#include "stdint.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "GPIO_interface.h"


#define delay for(uint32_t i = 0; i < 5000000; i++);
void CLK_PLL_Config(void);
uint8_t clk = 0x05;;

int main()
{
	RCC_voidInitSysClock();
	clk = RCC_uint8_tGetClock();
	RCC_voidEnableClock(RCC_AHB, 17); // PORTA
	RCC_voidEnableClock(RCC_AHB, 18); // PORTB
	
	GPIO_Pin_Conf_t pin_confg;
	pin_confg.pin = PIN5;
	pin_confg.mode = GPIO_PIN_OUTPUT_MODE;
	pin_confg.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	pin_confg.speed = GPIO_PIN_SPEED_MEDIUM;
	pin_confg.pull = GPIO_PIN_NO_PULL;
	GPIO_Init(GPIOA, &pin_confg);

	while(1)
	{
		GPIO_write_to_pin(GPIOA, PIN5, HIGH);
		delay;
		GPIO_write_to_pin(GPIOA, PIN5, LOW);
		delay;

	}
	
	return 0;
}

