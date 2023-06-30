/*
 * Timer_Config.h
 *
 * Created: 3/7/2023 4:26:28 PM
 *  Author: yahia
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
#include "../../utilities/Error_State.h"
#include "../../utilities/BIT_MATH.h"
#include "../../utilities/Data_Type.h"
#include "../../utilities/DIO_REG.h"


#define mode 1

#define OCR0_val 250
#define	time_preload_val  48
#define timer0_prescaler_mask 0b11111000
#define timer_8prescaler 2
#define timer_1024 5
#endif /* TIMER_CONFIG_H_ */