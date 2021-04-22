/*********************************************************************************/
/* Author    : Ahmed Atia                                                        */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/
#include "stdint.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
/**
	* @brief  Configures the mode of a pin : input, output, alt or analog mode 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  mode   : mode to be configured
	* @retval None
	*/
void GPIO_configure_pin_mode(uint8_t GPIOx, uint16_t pin_no, uint32_t mode)
{
	 switch (GPIOx)
	 {
	 case GPIOA: 
	 	GPIOA_MODER  &= ~(0x03 << ( 2 * pin_no));
		GPIOA_MODER   |= (mode << ( 2 * pin_no));		 
		break;
	 case GPIOB: 
	 	GPIOB_MODER  &= ~(0x03 << ( 2 * pin_no));
		GPIOB_MODER   |= (mode << ( 2 * pin_no));		 
		break;
	 case GPIOC: 
	 	GPIOC_MODER  &= ~(0x03 << ( 2 * pin_no));
		GPIOC_MODER   |= (mode << ( 2 * pin_no));		 
		break;
	 case GPIOD: 
	 	GPIOD_MODER  &= ~(0x03 << ( 2 * pin_no));
		GPIOD_MODER   |= (mode << ( 2 * pin_no));		 
		break;
	case GPIOE: 
	 	GPIOE_MODER  &= ~(0x03 << ( 2 * pin_no));
		GPIOE_MODER   |= (mode << ( 2 * pin_no));		 
		break;
	case GPIOF: 
	 	GPIOF_MODER  &= ~(0x03 << ( 2 * pin_no));
		GPIOF_MODER   |= (mode << ( 2 * pin_no));		 
		break;
	 default:
		 break;
	 }
}

/**
	* @brief  Configures the speed of a pin 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  speed   : value of the speed 
	* @retval None
	*/
void GPIO_configure_pin_speed(uint8_t GPIOx, uint16_t pin_no, uint32_t speed)
{
	switch (GPIOx)
	{
	case GPIOA: GPIOA_OSPEEDR |= (speed << (2 * pin_no));		break;
	case GPIOB: GPIOB_OSPEEDR |= (speed << (2 * pin_no));		break;
	case GPIOC: GPIOC_OSPEEDR |= (speed << (2 * pin_no));		break;
	case GPIOD: GPIOD_OSPEEDR |= (speed << (2 * pin_no));		break;
	case GPIOE: GPIOE_OSPEEDR |= (speed << (2 * pin_no));		break;
	case GPIOF: GPIOF_OSPEEDR |= (speed << (2 * pin_no));		break;
	default: /* Error handling  */								break;
	}
	 
}

/**
	* @brief  Configures the output type of a pin  
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  op_type   : output type to be configured with 
	* @retval None
	*/
void GPIO_configure_pin_otype(uint8_t GPIOx, uint16_t pin_no, uint32_t op_type)
{
	switch (GPIOx)
	{
	case GPIOA: GPIOA_OTYPER |= (op_type << pin_no);		break;
	case GPIOB: GPIOB_OTYPER |= (op_type << pin_no);		break;
	case GPIOC: GPIOC_OTYPER |= (op_type << pin_no);		break;
	case GPIOD: GPIOD_OTYPER |= (op_type << pin_no);		break;
	case GPIOE: GPIOE_OTYPER |= (op_type << pin_no);		break;
	case GPIOF: GPIOF_OTYPER |= (op_type << pin_no);		break;
	default: /* Error handling  */							break;
	}
}

/**
	* @brief  Activates the internall pull up or pull down resistors
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  pupd   : specifies which resistor to activate
	* @retval None
	*/
void GPIO_configure_pin_pupd(uint8_t GPIOx, uint16_t pin_no, uint32_t pupd)
{
	switch (GPIOx)
	{
	case GPIOA: GPIOA_PUPDR |= (pupd << (2 * pin_no));		break;
	case GPIOB: GPIOB_PUPDR |= (pupd << (2 * pin_no));		break;
	case GPIOC: GPIOC_PUPDR |= (pupd << (2 * pin_no));		break;
	case GPIOD: GPIOD_PUPDR |= (pupd << (2 * pin_no));		break;
	case GPIOE: GPIOE_PUPDR |= (pupd << (2 * pin_no));		break;
	case GPIOF: GPIOF_PUPDR |= (pupd << (2 * pin_no));		break;
	default: /* Error handling  */							break;
	}
}

/**
	* @brief  Set the alternate functionality for the given pin  
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  alt_fun_value   :  alternate function to be configured with 
	* @retval None
	*/
void GPIO_set_alt_function(uint8_t GPIOx, uint16_t pin_no, uint16_t alt_fun_value)
{
  if ( pin_no  <= 7 )
	{	
		switch (GPIOx)
		{
		case GPIOA: GPIOA_AFRL |= (alt_fun_value << ((pin_no) * 4 ));		break;
		case GPIOB: GPIOB_AFRL |= (alt_fun_value << ((pin_no) * 4 ));		break;
		case GPIOC: GPIOC_AFRL |= (alt_fun_value << ((pin_no) * 4 ));		break;
		case GPIOD: GPIOD_AFRL |= (alt_fun_value << ((pin_no) * 4 ));		break;
		case GPIOE: GPIOE_AFRL |= (alt_fun_value << ((pin_no) * 4 ));		break;
		case GPIOF: GPIOF_AFRL |= (alt_fun_value << ((pin_no) * 4 ));		break;
		default: /* Error handling  */										break;
		}
		
	}
	else
	{
		switch (GPIOx)
		{
		case GPIOA: GPIOA_AFRH |= (alt_fun_value << ( ( pin_no % 8) * 4 ));		break;
		case GPIOB: GPIOB_AFRH |= (alt_fun_value << ( ( pin_no % 8) * 4 ));		break;
		case GPIOC: GPIOC_AFRH |= (alt_fun_value << ( ( pin_no % 8) * 4 ));		break;
		case GPIOD: GPIOD_AFRH |= (alt_fun_value << ( ( pin_no % 8) * 4 ));		break;
		case GPIOE: GPIOE_AFRH |= (alt_fun_value << ( ( pin_no % 8) * 4 ));		break;
		case GPIOF: GPIOF_AFRH |= (alt_fun_value << ( ( pin_no % 8) * 4 ));		break;
		default: /* Error handling  */											break;
		}
	}
}	


/**
	* @brief  Initializes the gpio pin 
	* @param  *GPIOx : GPIO Port Base address
	* @param  *gpio_pin_conf :Pointer to the pin conf structure sent by application 
	* @retval None
	*/
void GPIO_Init(uint8_t GPIOx, GPIO_Pin_Conf_t *gpio_pin_conf)
{
	GPIO_configure_pin_mode(GPIOx, gpio_pin_conf->pin, gpio_pin_conf->mode);
	GPIO_configure_pin_speed(GPIOx, gpio_pin_conf->pin, gpio_pin_conf->speed);
	GPIO_configure_pin_otype(GPIOx, gpio_pin_conf->pin, gpio_pin_conf->op_type);
	GPIO_configure_pin_pupd(GPIOx, gpio_pin_conf->pin, gpio_pin_conf->pull);
	GPIO_set_alt_function(GPIOx, gpio_pin_conf->pin, gpio_pin_conf->alternate);
}



/**
	* @brief  Write a value to given pin number 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  value   : value to be written 
	* @retval None
	*/
void GPIO_write_to_pin(uint8_t GPIOx,uint16_t pin_no, uint8_t val)
{
	if(val)
	{
		switch (GPIOx)
		{
		case GPIOA: GPIOA_ODR |=  (1 << pin_no);		break;
		case GPIOB: GPIOB_ODR |=  (1 << pin_no);		break;
		case GPIOC: GPIOC_ODR |=  (1 << pin_no);		break;
		case GPIOD: GPIOD_ODR |=  (1 << pin_no);		break;
		case GPIOE: GPIOE_ODR |=  (1 << pin_no);		break;
		case GPIOF: GPIOF_ODR |=  (1 << pin_no);		break;
		default: /* Error handling  */					break;
		}
	}
	else
	{
		switch (GPIOx)
		{
		case GPIOA: GPIOA_ODR &=  ~(1 << pin_no);		break;
		case GPIOB: GPIOB_ODR &=  ~(1 << pin_no);		break;
		case GPIOC: GPIOC_ODR &=  ~(1 << pin_no);		break;
		case GPIOD: GPIOD_ODR &=  ~(1 << pin_no);		break;
		case GPIOE: GPIOE_ODR &=  ~(1 << pin_no);		break;
		case GPIOF: GPIOF_ODR &=  ~(1 << pin_no);		break;
		default: /* Error handling  */					break;
		}
	}	
}

/**
	* @brief  Write a value to port 
	* @param  *GPIOx : GPIO Port Base address
	* @param  value   : value to be written 
	* @retval None
	*/
void GPIO_write_to_port(uint8_t GPIOx, uint16_t val)
{
	switch (GPIOx)
	{
	case GPIOA: GPIOA_ODR = val;		break;
	case GPIOB: GPIOB_ODR = val;		break;
	case GPIOC: GPIOC_ODR = val;		break;
	case GPIOD: GPIOD_ODR = val;		break;
	case GPIOE: GPIOE_ODR = val;		break;
	case GPIOF: GPIOF_ODR = val;		break;
	default: /* Error handling  */		break;
	}
}

/**
	* @brief  Read a value from a  given pin number 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @retval uint8_t: Value read 
	*/
uint8_t GPIO_read_from_pin(uint8_t GPIOx, uint16_t pin_no)
{
	uint8_t value ; 
	switch (GPIOx)
	{
	case GPIOA: value = ((GPIOA_IDR >> pin_no ) & 0x00000001 );		break;
	case GPIOB: value = ((GPIOB_IDR >> pin_no ) & 0x00000001 );		break;
	case GPIOC: value = ((GPIOC_IDR >> pin_no ) & 0x00000001 );		break;
	case GPIOD: value = ((GPIOD_IDR >> pin_no ) & 0x00000001 );		break;
	case GPIOE: value = ((GPIOE_IDR >> pin_no ) & 0x00000001 );		break;
	case GPIOF: value = ((GPIOF_IDR >> pin_no ) & 0x00000001 );		break;
	default: /* Error handling  */		break;
	}
	
	
	return value ;
}
