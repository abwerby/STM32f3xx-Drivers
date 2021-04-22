/*********************************************************************************/
/* Author    : Ahmed Assaf                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2

#define RCC_HSI_CLK      0 
#define RCC_HSE_CLK      1
#define RCC_PLL_CLK      2

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(uint8_t Copy_uint8_tBusId, uint8_t Copy_uint8_tPerId);
void RCC_voidDisableClock(uint8_t Copy_uint8_tBusId, uint8_t Copy_uint8_tPerId);
uint8_t RCC_uint8_tGetClock(void);

#endif