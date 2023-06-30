/*
 * EXTI.h
 *
 * Created: 3/7/2023 11:18:01 PM
 *  Author: yahia
 */ 


#ifndef EXTI_H_
#define EXTI_H_
#include "../../utilities/Error_State.h"
#include "../../utilities/BIT_MATH.h"
#include "../../utilities/Data_Type.h"
#include "../../utilities/DIO_REG.h"

#define EXTI_INT_0  __vector_1
#define EXTI_INI_1  __vector_2
#define EXTI_INI_2  __vector_3

void global_inti_Enable();
void EXT0_Interrupt_enable();
void EXT1_Interrupt_enable();
  

#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

#endif /* EXTI_H_ */