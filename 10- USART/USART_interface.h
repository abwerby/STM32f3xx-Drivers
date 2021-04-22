
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "USART_private.h"


/* Defining Macros */
#define USART_1_BIT_STOP					0
#define USART_2_BIT_STOP					2

#define USART_8_BIT_WORD					0
#define USART_9_BIT_WORD					1
#define USART_7_BIT_WORD					2

#define USART_OVER_SAMPLING_8      1
#define USART_OVER_SAMPLING_16     0

#define USART_PARITY_DISABLED			0
#define USART_PARITY_ENABLED		    1
#define USART_EVEN_PARITY				0
#define USART_ODD_PARITY				1


/*******************/
typedef struct 
{
    uint8_t Word_Len;
    uint32_t Baud_Rate;
    uint8_t Stop_Bit;
    uint8_t Parity_State;
    uint8_t Parity_Type;
    uint8_t Over_Sampling;
}USART_config;


/******************************/
void USART_Init(USART_Typedef * USARTx, USART_config * usart_config);
void USART_Deinit(USART_Typedef * USARTx);
void USART_Send(USART_Typedef * USARTx, uint8_t data);
void USART_Send_String(USART_Typedef * USARTx, uint8_t * data);
void USART_Receive_String(USART_Typedef* USARTx, uint8_t *str);
void USART_Send_Number(USART_Typedef * USARTx, long long Number);
uint8_t USART_Receive(USART_Typedef * USARTx);
void USART_DMA_Send(USART_Typedef * USARTx);
void USART_DMA_Receive(USART_Typedef * USARTx);

#endif






