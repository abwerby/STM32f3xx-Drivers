/*********************************************************************************/
/* Author    : Ahmed Atia                                                        */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H


#define GPIOA_Base_Address        0x48000000            // define the boundary address of GPIO port A
#define GPIOB_Base_Address        0x48000400            // define the boundary address of GPIO port B
#define GPIOC_Base_Address        0x48000800            // define the boundary address of GPIO port C
#define GPIOD_Base_Address        0x48000C00            // define the boundary address of GPIO port D
#define GPIOE_Base_Address        0x48001000            // define the boundary address of GPIO port E
#define GPIOF_Base_Address        0x48001400            // define the boundary address of GPIO port F


        /*       REGISTERS ADDRESSES FOR Port A        */
#define GPIOA_MODER               *((uint32_t*)(GPIOA_Base_Address + 0x00))
#define GPIOA_OTYPER              *((uint32_t*)(GPIOA_Base_Address + 0x04))
#define GPIOA_OSPEEDR             *((uint32_t*)(GPIOA_Base_Address + 0x08))
#define GPIOA_PUPDR               *((uint32_t*)(GPIOA_Base_Address + 0x0C))
#define GPIOA_IDR                 *((uint32_t*)(GPIOA_Base_Address + 0x10))
#define GPIOA_ODR                 *((uint32_t*)(GPIOA_Base_Address + 0x14))
#define GPIOA_BSRR                 *((uint32_t*)(GPIOA_Base_Address + 0x18))
#define GPIOA_BRR                 *((uint32_t*)(GPIOA_Base_Address + 0x28))
#define GPIOA_AFRL                *((uint32_t*)(GPIOA_Base_Address + 0x20))
#define GPIOA_AFRH                *((uint32_t*)(GPIOA_Base_Address + 0x24))


        /*       REGISTERS ADDRESSES FOR Port B        */

#define GPIOB_MODER               *((uint32_t*)(GPIOB_Base_Address + 0x00))
#define GPIOB_OTYPER              *((uint32_t*)(GPIOB_Base_Address + 0x04))
#define GPIOB_OSPEEDR             *((uint32_t*)(GPIOB_Base_Address + 0x08))
#define GPIOB_PUPDR               *((uint32_t*)(GPIOB_Base_Address + 0x0C))
#define GPIOB_IDR                 *((uint32_t*)(GPIOB_Base_Address + 0x10))
#define GPIOB_ODR                 *((uint32_t*)(GPIOB_Base_Address + 0x14))
#define GPIOB_BSRR                 *((uint32_t*)(GPIOB_Base_Address + 0x18))
#define GPIOB_BRR                 *((uint32_t*)(GPIOB_Base_Address + 0x28))
#define GPIOB_AFRL                *((uint32_t*)(GPIOA_Base_Address + 0x20))
#define GPIOB_AFRH                *((uint32_t*)(GPIOA_Base_Address + 0x24))
        /*       REGISTERS ADDRESSES FOR Port C        */

#define GPIOC_MODER               *((uint32_t*)(GPIOC_Base_Address + 0x00))
#define GPIOC_OTYPER              *((uint32_t*)(GPIOC_Base_Address + 0x04))
#define GPIOC_OSPEEDR             *((uint32_t*)(GPIOC_Base_Address + 0x08))
#define GPIOC_PUPDR               *((uint32_t*)(GPIOC_Base_Address + 0x0C))
#define GPIOC_IDR                 *((uint32_t*)(GPIOC_Base_Address + 0x10))
#define GPIOC_ODR                 *((uint32_t*)(GPIOC_Base_Address + 0x14))
#define GPIOC_BSRR                 *((uint32_t*)(GPIOC_Base_Address + 0x18))
#define GPIOC_BRR                 *((uint32_t*)(GPIOC_Base_Address + 0x28))
#define GPIOC_AFRL                *((uint32_t*)(GPIOA_Base_Address + 0x20))
#define GPIOC_AFRH                *((uint32_t*)(GPIOA_Base_Address + 0x24))
        /*       REGISTERS ADDRESSES FOR Port D        */

#define GPIOD_MODER               *((uint32_t*)(GPIOD_Base_Address + 0x00))
#define GPIOD_OTYPER              *((uint32_t*)(GPIOD_Base_Address + 0x04))
#define GPIOD_OSPEEDR             *((uint32_t*)(GPIOD_Base_Address + 0x08))
#define GPIOD_PUPDR               *((uint32_t*)(GPIOD_Base_Address + 0x0C))
#define GPIOD_IDR                 *((uint32_t*)(GPIOD_Base_Address + 0x10))
#define GPIOD_ODR                 *((uint32_t*)(GPIOD_Base_Address + 0x14))
#define GPIOD_BSRR                 *((uint32_t*)(GPIOD_Base_Address + 0x18))
#define GPIOD_BRR                 *((uint32_t*)(GPIOD_Base_Address + 0x28))
#define GPIOD_AFRL                *((uint32_t*)(GPIOA_Base_Address + 0x20))
#define GPIOD_AFRH                *((uint32_t*)(GPIOA_Base_Address + 0x24))
        /*       REGISTERS ADDRESSES FOR Port E        */

#define GPIOE_MODER               *((uint32_t*)(GPIOE_Base_Address + 0x00))
#define GPIOE_OTYPER              *((uint32_t*)(GPIOE_Base_Address + 0x04))
#define GPIOE_OSPEEDR             *((uint32_t*)(GPIOE_Base_Address + 0x08))
#define GPIOE_PUPDR               *((uint32_t*)(GPIOE_Base_Address + 0x0C))
#define GPIOE_IDR                 *((uint32_t*)(GPIOE_Base_Address + 0x10))
#define GPIOE_ODR                 *((uint32_t*)(GPIOE_Base_Address + 0x14))
#define GPIOE_BSRR                 *((uint32_t*)(GPIOE_Base_Address + 0x18))
#define GPIOE_BRR                 *((uint32_t*)(GPIOE_Base_Address + 0x28))
#define GPIOE_AFRL                *((uint32_t*)(GPIOA_Base_Address + 0x20))
#define GPIOE_AFRH                *((uint32_t*)(GPIOA_Base_Address + 0x24))
        /*       REGISTERS ADDRESSES FOR Port F        */

#define GPIOF_MODER               *((uint32_t*)(GPIOF_Base_Address + 0x00))
#define GPIOF_OTYPER              *((uint32_t*)(GPIOF_Base_Address + 0x04))
#define GPIOF_OSPEEDR             *((uint32_t*)(GPIOF_Base_Address + 0x08))
#define GPIOF_PUPDR               *((uint32_t*)(GPIOF_Base_Address + 0x0C))
#define GPIOF_IDR                 *((uint32_t*)(GPIOF_Base_Address + 0x10))
#define GPIOF_ODR                 *((uint32_t*)(GPIOF_Base_Address + 0x14))
#define GPIOF_BSRR                 *((uint32_t*)(GPIOF_Base_Address + 0x18))
#define GPIOF_BRR                 *((uint32_t*)(GPIOF_Base_Address + 0x28))
#define GPIOF_AFRL                *((uint32_t*)(GPIOA_Base_Address + 0x20))
#define GPIOF_AFRH                *((uint32_t*)(GPIOA_Base_Address + 0x24))


#endif