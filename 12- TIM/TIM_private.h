/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef TIM_PRIVATE_H
#define TIM_PRIVATE_H


typedef struct
{
  volatile uint32_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
  volatile uint32_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
  volatile uint32_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
  volatile uint32_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
  volatile uint32_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
  volatile uint32_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
  volatile uint32_t CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
  volatile uint32_t CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
  volatile uint32_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
  volatile uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
  volatile uint32_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
  volatile uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
  volatile uint32_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
  volatile uint32_t CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
  volatile uint32_t CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
  volatile uint32_t CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
  volatile uint32_t CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
  volatile uint32_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
  volatile uint32_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
  volatile uint32_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
  volatile uint32_t OR;          /*!< TIM option register,                 Address offset: 0x50 */
  volatile uint32_t CCMR3;       /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
  volatile uint32_t CCR5;        /*!< TIM capture/compare register5,       Address offset: 0x58 */
  volatile uint32_t CCR6;        /*!< TIM capture/compare register 4,      Address offset: 0x5C */
} TIM_TypeDef;


#define TIM20       ((TIM_TypeDef * )0x40015000)
#define TIM17       ((TIM_TypeDef * )0x40014800)
#define TIM16       ((TIM_TypeDef * )0x40014400)
#define TIM15       ((TIM_TypeDef * )0x40014000)
#define TIM8        ((TIM_TypeDef * )0x40013400)
#define TIM1        ((TIM_TypeDef * )0x40012C00)
#define TIM2        ((TIM_TypeDef * )0x40000000)
#define TIM3        ((TIM_TypeDef * )0x40000400)
#define TIM4        ((TIM_TypeDef * )0x40000800)
#define TIM6        ((TIM_TypeDef * )0x40001000)
#define TIM7        ((TIM_TypeDef * )0x40001400)







#endif

