/*
 * ADC.h
 *
 * Created: 3/1/2023 9:45:04 PM
 *  Author: yahia
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "../../utilities/Error_State.h"
#include "../../utilities/BIT_MATH.h"
#include "../../utilities/Data_Type.h"
#include "../../utilities/DIO_REG.h"
#include "ADC_Config.h"


void ADC_init();
uint8 ADC_Start_Conversion(uint8 channel);

uint8 ADC_Start_Conversion_SYN(uint8 channel,uint8*reading);

uint8 ADC_Start_Conversion_ASYN(uint8 channel,uint16*reading,void(*notificationfun)(void));

uint8 ADC_Start_Chain_Conversion_ASYN(Chain_t* Copy_chain);

uint16 ADC_u16ADCRead(void);

//////////////////////////////////////////////////////////
void ADC_voidStartConversionWithInterrupt(uint8 Copy_u8ChannelNumber);

void ADC_voidSetCallBack(void(*Copy_Fptr)(void));

uint16 ADC_u16ADCRead(void);

void ADC_voidInterruptEnable(void);

#endif /* ADC_H_ */

