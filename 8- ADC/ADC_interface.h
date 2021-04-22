/*********************************************************************************/
/* Author    : Abdelrhman                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC_IN1        (1)
#define ADC_IN2        (2)
#define ADC_IN3        (3)
#define ADC_IN4        (4)
#define ADC_IN5        (5)
#define ADC_IN6        (6)
#define ADC_IN7        (7)
#define ADC_IN8        (8)
#define ADC_IN9        (9)
#define ADC_IN10      (10)
#define ADC_IN11      (11)
#define ADC_IN12      (12)
#define ADC_IN13      (13)
#define ADC_IN14      (14)
#define ADC_IN15      (15)
#define ADC_IN16      (16)
#define ADC_IN17      (17)
#define ADC_IN18      (18)

// the resolution of the conversion
#define ADC_DATA_RES_12     0x00
#define ADC_DATA_RES_10     0x01
#define ADC_DATA_RES_8      0x02
#define ADC_DATA_RES_6      0x03



void ADC_Init(ADC_TypeDef * ADCx, uint8_t line, uint8_t data_res);
void ADC_Deinit(ADC_TypeDef * ADCx);
uint16_t ADC_Read(ADC_TypeDef * ADCx);

#endif