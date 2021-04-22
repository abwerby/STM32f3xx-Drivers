

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <stdint.h>
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"

#define BaudRate    115200

uint8_t Rxchar = 'B';

 // Perform an action every 10 ticks.
 void vTask1Function( void * pvParameters )
 {
 TickType_t xLastWakeTime;
 const TickType_t xFrequency = 1000;

     // Initialise the xLastWakeTime variable with the current time.
     xLastWakeTime = xTaskGetTickCount();

     for( ;; )
     {
         // Wait for the next cycle.
         // vTaskDelay( xFrequency );
					vTaskDelayUntil(&xLastWakeTime, xFrequency );

         // Perform action here.
					USART_Send_String(USART1, "\nTask1: ");
					USART_Send_Number(USART1, xTaskGetTickCount());
					USART_Send(USART1, '\n');
     }
 }
 
  void vTask2Function( void * pvParameters )
 {
 TickType_t xLastWakeTime;
 const TickType_t xFrequency = 2000;

     // Initialise the xLastWakeTime variable with the current time.
     xLastWakeTime = xTaskGetTickCount();

     for( ;; )
     {
         // Wait for the next cycle.
         vTaskDelayUntil(&xLastWakeTime, xFrequency );
         // Perform action here.
			 USART_Send_String(USART1, "\nTask2: ");
			 USART_Send_Number(USART1, xTaskGetTickCount());
			 USART_Send(USART1, '\n');
     }
 }

int main(void)
{
	RCC_voidInitSysClock();	
   
	/* GPIOB CLK */
	RCC_voidEnableClock(RCC_AHB, 18);
	/* GPIOA CLK */
	RCC_voidEnableClock(RCC_AHB, 17);
	/* DMA CLK */
	RCC_voidEnableClock(RCC_AHB, 0);
	/* USART1 CLK */
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
	
	GPIOInitStruct.pin = PIN5;
	GPIOInitStruct.mode = GPIO_PIN_OUTPUT_MODE;
	GPIOInitStruct.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	GPIOInitStruct.pull = GPIO_PIN_NO_PULL;
	GPIO_Init(GPIOA, &GPIOInitStruct);

	
	GPIOInitStruct.pin = PIN6;
	GPIOInitStruct.mode = GPIO_PIN_OUTPUT_MODE;
	GPIOInitStruct.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	GPIOInitStruct.pull = GPIO_PIN_NO_PULL;
	GPIO_Init(GPIOA, &GPIOInitStruct);



	
	USART_config usart_config;
	usart_config.Baud_Rate = BaudRate;
	usart_config.Over_Sampling = USART_OVER_SAMPLING_16;
	usart_config.Parity_State = USART_PARITY_DISABLED;
	usart_config.Stop_Bit = USART_1_BIT_STOP;
	usart_config.Word_Len = USART_8_BIT_WORD;
	USART_Init(USART1, &usart_config);

	/* Create tasks */
  xTaskCreate( vTask1Function, "Task1", configMINIMAL_STACK_SIZE, NULL, 2, NULL );
	xTaskCreate( vTask2Function, "Task2", configMINIMAL_STACK_SIZE, NULL, 0, NULL );

	/* Start the scheduler so the tasks start executing. */
	vTaskStartScheduler();

	while(1)
	{
//		GPIO_Write_Pin(GPIOA, PIN5, HIGH);
//		for (size_t i = 0; i < 100000; i++);
//		GPIO_Write_Pin(GPIOA, PIN5, LOW);
//		for (size_t i = 0; i < 100000; i++);
//		USART_Send_String(USART1, "Task1..\n");
//		for (size_t i = 0; i < 200000; i++);
	}
	
	return 0;
}



