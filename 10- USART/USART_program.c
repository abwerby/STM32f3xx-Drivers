
#include <stdint.h>
#include "BIT_MATH.h"
#include "USART_private.h"
#include "USART_interface.h"
#include "USART_config.h"


void USART_Init(USART_Typedef * USARTx, USART_config * usart_config)
{
	/* Set oversampling and BaudRate */
	if (usart_config->Over_Sampling == USART_OVER_SAMPLING_16)
	{
		CLR_BIT(USARTx->CR1, 15);
		USARTx->BRR = (F_CPU/usart_config->Baud_Rate);
	}
	else
	{
		SET_BIT(USARTx->CR1, 15);
		// TODO: .......................................
	}
	/* Set word size */
	switch (usart_config->Word_Len)
	{
		case USART_8_BIT_WORD:	CLR_BIT(USARTx->CR1, 28); CLR_BIT(USARTx->CR1, 12); break;
		case USART_9_BIT_WORD:	CLR_BIT(USARTx->CR1, 28); SET_BIT(USARTx->CR1, 12); break;	
		case USART_7_BIT_WORD:	SET_BIT(USARTx->CR1, 28); CLR_BIT(USARTx->CR1, 12); break;	
		default:	/* Error handle */	break;
	}
	/* enable/disable parity */
	USARTx->CR1 |= (usart_config->Parity_State << 10);
	/* Select parity type */
	USARTx->CR1 |= (usart_config->Parity_Type << 9);
	/* Set stop Bits */
	USARTx->CR2 |= (usart_config->Stop_Bit << 0);

	/* Enable USARTx */
	SET_BIT(USARTx->CR1, 0);
	/* Enable transmiter and receevier */
	SET_BIT(USARTx->CR1, 2);
	SET_BIT(USARTx->CR1, 3);
}

void USART_Deinit(USART_Typedef * USARTx)
{
	USARTx->CR1 = 0x0000;
	USARTx->CR2 = 0x0000;
}

void USART_Send(USART_Typedef * USARTx, uint8_t data)
{
	while(GET_BIT(USARTx->ISR, 7) == 0);
	USARTx->TDR = data;
}

void USART_Send_String(USART_Typedef * USARTx, uint8_t * data)
{
	while(*data != '\0')
	{
		USART_Send(USARTx, *data);
		data++;
	}
}

void USART_Send_Number(USART_Typedef * USARTx, long long Number)
{
	long long Temp =1;

	if (Number == 0)
	{
		USART_Send(USARTx, '0');
	}
	else
	{
		while (Number!=0)
		{
			uint8_t Reminder = Number % 10;
			Number = Number / 10 ;
			Temp = Temp * 10 + Reminder ;
		}
		while (Temp != 1)
		{
			uint8_t Reminder2 = Temp % 10 ;
			USART_Send(USARTx, Reminder2+48);
			Temp = Temp / 10 ;
		}
	}
}


void USART_Receive_String(USART_Typedef* USARTx, uint8_t *str)
{
	uint8_t i = 0;
	str[i] = USART_Receive(USARTx);
	while(str[i] != '\0')
	{
		i++;
		str[i] = USART_Receive(USARTx);
	}
	str[i] = '\0';
}


void USART_DMA_Send(USART_Typedef * USARTx)
{
	SET_BIT(USARTx->CR3, 7);
}
void USART_DMA_Receive(USART_Typedef * USARTx)
{
	SET_BIT(USARTx->CR3, 6);
}

uint8_t USART_Receive(USART_Typedef * USARTx)
{
	while(GET_BIT(USARTx->ISR, 5) == 0);
	return USARTx->RDR;
}














