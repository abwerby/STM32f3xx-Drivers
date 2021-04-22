/*********************************************************************************/
/* Author    : Abdelrhamn Werby                                                       */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define HIGH    1
#define LOW     0

#define GPIOA   0
#define GPIOB   1
#define GPIOC   2
#define GPIOD   3
#define GPIOE   4
#define GPIOF   5

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10    10
#define PIN11    11
#define PIN12    12
#define PIN13    13
#define PIN14    14
#define PIN15    15


/* GPIO Mode Settings values*/
#define GPIO_PIN_INPUT_MODE                            ( (uint32_t)0x00)
#define GPIO_PIN_OUTPUT_MODE                           ( (uint32_t)0x01)
#define GPIO_PIN_ALT_FUN_MODE                          ( (uint32_t)0x02)

/* GPIO OP type selection values */
#define GPIO_PIN_OP_TYPE_PUSHPULL                      ( (uint32_t)0x00 )
#define GPIO_PIN_OP_TYPE_OPEN_DRAIN                    ( (uint32_t)0x01 )

/* GPIO Speed type selection values */
#define GPIO_PIN_SPEED_LOW                             ( (uint32_t)0x00 )
#define GPIO_PIN_SPEED_MEDIUM                          ( (uint32_t)0x01 )
#define GPIO_PIN_SPEED_HIGH                            ( (uint32_t)0x02 )
#define GPIO_PIN_SPEED_VERY_HIGH                       ( (uint32_t)0x03 )

/* GPIO pull up/pull dwn  selection values */
#define GPIO_PIN_NO_PULL                               ( (uint32_t)0x00 )
#define GPIO_PIN_PULL_UP                               ( (uint32_t)0x01 )
#define GPIO_PIN_PULL_DOWN                             ( (uint32_t)0x02 )

typedef struct
{
	uint32_t pin;            /*Specifies the GPIO pins to be configured */

	uint32_t mode;           /*Specifies the operating mode for the selected pins */
													
	uint32_t op_type;        /*Specifies the output type for the selected pins*/

	uint32_t pull;           /*Specifies the Pull-up or Pull-Down activation for the selected pins */
							
	uint32_t speed;          /* Specifies the speed for the selected pins */
							 
	uint32_t alternate;      /*Specifies the alternate function value, 
											 if the mode is set for alt function mode */                      
}GPIO_Pin_Conf_t;


void GPIO_Init(uint8_t GPIOx, GPIO_Pin_Conf_t *gpio_pin_conf);
void GPIO_write_to_pin(uint8_t GPIOx,uint16_t pin_no, uint8_t val);
void GPIO_write_to_port(uint8_t GPIOx, uint16_t val);
uint8_t GPIO_read_from_pin(uint8_t GPIOx, uint16_t pin_no);

#endif
