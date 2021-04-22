// File Name: main.c
// Author: Abdelrhman Khairy
// Date: 22-5-2020

#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#include "BIT_MATH.h"               
#include "GPIO_interface.h"
#include "TFT_Interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

# define M_PI           3.14159265358979323846  /* pi */

uint32_t msticks;
uint32_t clk;

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

double random2()
{
    return (double)rand() / RAND_MAX;
}

int main(void)
{
	
	RCC_voidInitSysClock();
	STK_voidInit(40000);
	clk = RCC_uint8_tGetClock();
	
	RCC_voidEnableClock(RCC_AHB, 17);
	RCC_voidEnableClock(RCC_AHB, 18);
	RCC_voidEnableClock(RCC_AHB, 19);

	
	TFT_Init();	
	TFT_Set_Rotation(TFT_LANDSCAPE);

	TFT_fillScreen(ILI9486_WHITE);

	TFT_SetTextSize(3);
	TFT_SetCursor(0,20);
	TFT_SetTextColor(ILI9486_RED);
	TFT_Print_String("SAHORAA AL'MORA,AL-WES5AAA");

	GPIO_Pin_Conf_t pin_confg;
	pin_confg.pin = PIN5;
	pin_confg.mode = GPIO_PIN_OUTPUT_MODE;
	pin_confg.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	pin_confg.speed = GPIO_PIN_SPEED_MEDIUM;
	pin_confg.pull = GPIO_PIN_NO_PULL;
	GPIO_Init(GPIOA, &pin_confg);
	
	uint32_t i = 0;
	double t = 2*M_PI;
  while (1)
  {	
//		t = random2();
//		long loc_x = map(t*1000, -1000, 1000, 0, 479);
//		long loc_y = map(sin(t)*1000, -1000, 1000, 0, 319);
//		TFT_Draw_Point(loc_x, loc_y, ILI9486_BLUE);
//		TFT_Scroll_Vertical(0, 480, (i++));
//		TFT_DrawFastVLine(i, 0, 320, ILI9486_WHITE);
//		
//		if (i > 480) i = 0;
//		if (t > 2*M_PI)	t = -2*M_PI; 
//		STK_voidDelayMs(5);
//		// t += .008;
  }
}


