/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/


#ifndef TIM_INTERFACE_H
#define TIM_INTERFACE_H


typedef struct 
{
    uint32_t Prescaller;
    uint32_t Period;
    uint8_t AutoReloadPreload;
    uint8_t InterruptState;
    uint8_t DMAState;
}TIM_Base_InitTypeDef;






#define TIM_AUTORELOAD_PRELOAD_DISABLE                (0x00)        /*!< TIMx_ARR register is not buffered */
#define TIM_AUTORELOAD_PRELOAD_ENABLE                 (0x01)        /*!< TIMx_ARR register is buffered */


#define TIM_DMA_STATE_ENABLE     (0x01)
#define TIM_DMA_STATE_DISABLE    (0x00)

#define TIM_INT_STATE_ENABLE     (0x01)
#define TIM_INT_STATE_DISABLE    (0x00)




#endif


