/*
 * EXTI.c
 *
 * Created: 3/7/2023 11:10:01 PM
 *  Author: Ahmed Nour
 */ 
#include "Interrupt.h"

void global_inti_Enable()
{
	SREG_REG|=(1<<7); // for global interrupt
	
}

void EXT0_Interrupt_enable()
{
	/*select sensing signal : we select rising edge */
	Set_Bit(MCUCR_REG,MCUCR_ISC00);
	Set_Bit(MCUCR_REG,MCUCR_ISC01);
	/*we should clear flag of interrupt 0 by (set 1 on it )*/
	Set_Bit(GIFR_REG,GIFR_INT0);
	/*External interrupt request enable*/
	Set_Bit(GICR_REG,GICR_INT0);
	
}

void EXT1_Interrupt_enable()
{
	/*select sensing signal : we select rising edge */
	Set_Bit(MCUCR_REG,MCUCR_ISC10); 
	Set_Bit(MCUCR_REG,MCUCR_ISC11);
	/*we should clear flag of interrupt 0 by (set 1 on it )*/
	Set_Bit(GIFR_REG,GIFR_INT1);
	/*External interrupt request enable*/
	Set_Bit(GICR_REG,GICR_INT1);
}