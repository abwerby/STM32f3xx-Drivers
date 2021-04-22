#include <stdint.h>
#include "BIT_MATH.h"
#include "TIM_private.h"
#include "TIM_interface.h"

#define NULL		(void * )0

static void (* TIM1_CallBack) (void) = NULL ;
static void (* TIM2_CallBack) (void) = NULL ;
static void (* TIM3_CallBack) (void) = NULL ;
static void (* TIM4_CallBack) (void) = NULL ;
static void (* TIM6_CallBack) (void) = NULL ;
static void (* TIM7_CallBack) (void) = NULL ;
static void (* TIM8_CallBack) (void) = NULL ;
static void (* TIM9_CallBack) (void) = NULL ;
static void (* TIM20_CallBack) (void) = NULL ;
static void (* TIM15_CallBack) (void) = NULL ;
static void (* TIM16_CallBack) (void) = NULL ;
static void (* TIM17_CallBack) (void) = NULL ;




void TIM_Init(TIM_TypeDef * TIMx, TIM_Base_InitTypeDef * tim_config)
{
    TIMx->PSC = tim_config->Prescaller;
    TIMx->ARR = tim_config->Period;
    TIMx->CR1 |= (tim_config->AutoReloadPreload << 7);
    TIMx->DIER |= (tim_config->InterruptState << 0); 
    TIMx->DIER |= (tim_config->DMAState << 8); 
}

void TIM_Set_Callback_Function(uint8_t Timer_NO, void (*Fptr) (void))
{
    switch(Timer_NO)
	{
		case	1	:	TIM1_CallBack = Fptr ; 	break;
		case	2	:	TIM2_CallBack = Fptr ; 	break;
		case	3	:	TIM3_CallBack = Fptr ; 	break;
		case	4	:	TIM4_CallBack = Fptr ; 	break;
		case	6	:	TIM6_CallBack = Fptr ; 	break;
		case	7	:	TIM7_CallBack = Fptr ; 	break;
		case	8	:	TIM8_CallBack = Fptr ; 	break;
		case	20	:	TIM20_CallBack = Fptr ; 	break;
		case	15	:	TIM15_CallBack = Fptr ; 	break;
		case	16	:	TIM16_CallBack = Fptr ; 	break;
		case	17	:	TIM17_CallBack = Fptr ; 	break;
	}
}


void TIM2_IRQHandler()
{
    if (TIM2_CallBack != NULL) TIM2_CallBack();
    SET_BIT(TIM2->SR , 0);
}

void TIM3_IRQHandler()
{
    if (TIM3_CallBack != NULL) TIM3_CallBack();
    SET_BIT(TIM3->SR , 0);
}

void TIM4_IRQHandler()
{
    if (TIM4_CallBack != NULL) TIM4_CallBack();
    SET_BIT(TIM4->SR , 0);
}

void TIM7_IRQHandler()
{
    if (TIM7_CallBack != NULL) TIM7_CallBack();
    SET_BIT(TIM7->SR , 0);
}

