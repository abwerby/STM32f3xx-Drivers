
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct
{
  volatile uint32_t CR1;    /*!< USART Control register 1,                 Address offset: 0x00 */
  volatile uint32_t CR2;    /*!< USART Control register 2,                 Address offset: 0x04 */
  volatile uint32_t CR3;    /*!< USART Control register 3,                 Address offset: 0x08 */
  volatile uint32_t BRR;    /*!< USART Baud rate register,                 Address offset: 0x0C */
  volatile uint32_t GTPR;   /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
  volatile uint32_t RTOR;   /*!< USART Receiver Time Out register,         Address offset: 0x14 */
  volatile uint32_t RQR;    /*!< USART Request register,                   Address offset: 0x18 */
  volatile uint32_t ISR;    /*!< USART Interrupt and status register,      Address offset: 0x1C */
  volatile uint32_t ICR;    /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
  volatile uint16_t RDR;    /*!< USART Receive Data register,              Address offset: 0x24 */
  uint16_t  RESERVED1;  	/*!< Reserved, 0x26                                                 */
  volatile uint16_t TDR;    /*!< USART Transmit Data register,             Address offset: 0x28 */
  uint16_t  RESERVED2;  	/*!< Reserved, 0x2A                                                 */
} USART_Typedef;


#define 	USART1 		((USART_Typedef *) 0x40013800)
#define 	USART2 		((USART_Typedef *) 0x40004400)
#define 	USART3 		((USART_Typedef *) 0x40004800)
#define 	USART4 		((USART_Typedef *) 0x40004C00)
#define 	USART5 		((USART_Typedef *) 0x40005000)


#endif