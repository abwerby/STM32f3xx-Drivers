


#include <stdio.h>
#include <stdint.h>
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "DMA_interface.h"
#include "USART_interface.h"

#define BaudRate    230400

uint32_t msticks = 0;
uint8_t str[10] = "SEND\n";
uint32_t buffer[10] = {0};



int main(void)
{
	
	RCC_voidInitSysClock();
	STK_voidInit(32000);
	
    
	RCC_voidEnableClock(RCC_AHB, 18);
	RCC_voidEnableClock(RCC_AHB, 0);
	RCC_voidEnableClock(RCC_APB2, 14);


	GPIO_Pin_Conf_t GPIOInitStruct;

	/* set pin(TX) to AF7 and pull up and output to push pull */
	GPIOInitStruct.pin = PIN6;
	GPIOInitStruct.mode = GPIO_PIN_ALT_FUN_MODE;
	GPIOInitStruct.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	GPIOInitStruct.pull = GPIO_PIN_PULL_UP;
	GPIOInitStruct.alternate = 7;
	GPIO_Init(GPIOB, &GPIOInitStruct);
	/* set pin (RX) to AF7 and pull up no need to set the output mode since it an input pin */
	GPIOInitStruct.pin = PIN7;
	GPIOInitStruct.mode = GPIO_PIN_ALT_FUN_MODE;
	GPIOInitStruct.pull = GPIO_PIN_PULL_UP;
	GPIOInitStruct.alternate = 7;
	GPIO_Init(GPIOB, &GPIOInitStruct);


	
	USART_config usart_config;
	usart_config.Baud_Rate = BaudRate;
	usart_config.Over_Sampling = USART_OVER_SAMPLING_16;
	usart_config.Parity_State = USART_PARITY_DISABLED;
	usart_config.Stop_Bit = USART_1_BIT_STOP;
	usart_config.Word_Len = USART_8_BIT_WORD;
	USART_Init(USART1, &usart_config);



	DMA_config dma_config;
	dma_config.Channel_Number = 4;
	dma_config.Channel_Priority = DMA_Channel_Priority_High;
	dma_config.Circular_Mode = DMA_Circular_Mode_ON;
	dma_config.Data_Direction = DMA_Data_Direction_Read_From_PER;
	dma_config.Memory_Address = buffer;
	dma_config.Peripheral_Reg = &USART1->RDR;
	dma_config.Memory_Size = DMA_MEM_OR_PER_Size_32;
	dma_config.Peripheral_Size = DMA_MEM_OR_PER_Size_32;
	dma_config.Total_Data = 10;
	dma_config.MINC = DMA_MINC_ON;
	dma_config.PINC = DMA_PINC_OFF; 
	dma_config.MEM2MEM = DMA_MEM2MEM_OFF;
	DMA_Init(DMA1, &dma_config);
	
	USART_DMA_Receive(USART1);
	
	while(1)
	{
		msticks = STK_uint32_t_millis();
		USART_Send_String(USART1, str);
		STK_voidDelayMs(1000);
		void * garbge =  memset((void *) buffer, 0x00, 40);
	}
	
	return 0;
}



