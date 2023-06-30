/*
 * Timer.h
 *
 * Created: 3/7/2023 4:24:46 PM
 *  Author: yahia
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "Timer_Config.h"

void Timer0_init();
void Timer0_pwm(uint8 Copy_PWM);
uint8 timer0_setCallBack(void(*callBackFunc)(void));
void timer0_start_Preload(uint8 value);
void Timer0_stop();
void timer0_Get_busywait(uint8 * value);
uint8 timer0_ComparaMatch_setCallBack(void(*ComparecallBackFunc)(void));
void Timer1_init();
void Timer1_voidSetChannelACompValue(uint16 copy_u16Value);

#endif /* TIMER_H_ */