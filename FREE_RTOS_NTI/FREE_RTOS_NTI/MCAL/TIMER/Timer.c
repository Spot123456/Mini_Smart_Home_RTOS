/*
 * Timer.c
 *
 * Created: 3/7/2023 4:24:28 PM
 *  Author: yahia
 */ 
#include "Timer.h"
/*global pointer to function  to hold the callback address function */
static void(* timer0_pCallbackFunc)(void) = NULL; // we don't know the address so we must set it (NULL)
/*global pointer to function to hold the compare callback address function */
static void(*timer0_pCompareCallbaxkFunc)(void)=NULL;  //if we don't know the address so we must set it (NULL)

void Timer0_init()
{

#if mode==1
	/*init waveform generation mode work as normal mode*/ 
	Clear_Bit(TCCR0_REG,TCCR0_WGM00);
	Clear_Bit(TCCR0_REG,TCCR0_WGM01);
	
	/*set the required preload */
	TCNT0_REG=time_preload_val ;                           
	/*timer0 overflow interrupt enable*/
	Set_Bit(TIMSK_REG,TIMSK_TOIE0);
	/*set the req prescaler*/
	TCCR0_REG &=  timer0_prescaler_mask;
	TCCR0_REG|=timer_8prescaler;
	
#elif mode==2
	/*init waveform generation mode work as CTC mode*/
	Clear_Bit(TCCR0_REG,TCCR0_WGM00);
	Set_Bit(TCCR0_REG,TCCR0_WGM01);
	/*set ocr value*/
	OCR0_REG= OCR0_val;
	
	/*timer0 compare interrupt enable*/
	Set_Bit(TIMSK_REG,TIMSK_OCIE0);
	/*set the req prescaler*/
	TCCR0_REG &=  timer0_prescaler_mask;
	TCCR0_REG|=timer_8prescaler;
#elif mode==3
 /*init waveform generation mode work as fast PWM mode*/
	Set_Bit(TCCR0_REG,TCCR0_WGM00);
	Set_Bit(TCCR0_REG,TCCR0_WGM01);
	/*set compare output mode fast PWM*/
	Set_Bit(TCCR0_REG,TCCR0_COM01);
	Clear_Bit(TCCR0_REG,TCCR0_COM00);
	
	/*set prescaler */
	TCCR0_REG &=  timer0_prescaler_mask;
	TCCR0_REG|=timer_1024;
	

#endif
} 

void timer0_start_Preload(uint8 value)
{
	TCNT0_REG=value; //start from (value) to overflow
}

void Timer_stop()
{
	TCCR0_REG =0x00;
}

void timer0_Get_busywait(uint8 * value)
{
	while((TIFR0_REG & (1<<0))==0); // loop 48ala l8ayt lma y7sel OVF (i.e TIFR0 =0x01)
	*value =1 ;
}

uint8 timer0_setCallBack(void(*callBackFunc)(void))
{
	uint8 local_error_state=OK;
	if(callBackFunc==NULL)
	{
		local_error_state= NULL_POINTER;
	}
	else
	{
		timer0_pCallbackFunc = callBackFunc;  // global pointer = local address of func to go to ISR
	}
	return local_error_state;
}


uint8 timer0_ComparaMatch_setCallBack(void(*ComparecallBackFunc)(void))
{
	uint8 local_errorState=OK;
	if(ComparecallBackFunc!=NULL)
	{
		timer0_pCompareCallbaxkFunc=ComparecallBackFunc;
	}
	else
	{
		local_errorState=NULL_POINTER;
	}
	return local_errorState;
}

/*timer0 overflow ISR*/
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(timer0_pCallbackFunc!=NULL)
	{
		timer0_pCallbackFunc();
	}
	else
	{
		/*do nothing*/
	}
	
}
/*compare mode*/




void Timer1_init()
{
	/*compare match output mode : set on top clear on compare (non inverted)*/
	Set_Bit(TCCR1A_REG,TCCR1A_COM1A1);
	Clear_Bit(TCCR1A_REG,TCCR1A_COM1A0);
	
	/*waveForm generation mode: Fast PWM With ICR1 as  top value*/
	Clear_Bit(TCCR1A_REG,TCCR1A_WGM10);
	Set_Bit(TCCR1A_REG,TCCR1A_WGM11);
	Set_Bit(TCCR1B_REG,TCCR1B_WGM12);  // 5ly balk tccr1b
	Set_Bit(TCCR1B_REG,TCCR1B_WGM13);
	
	/*set top value */
	
	ICR1_REG= 20000;  // time over flow
	
	/* compare match value : range between 750 to 2500*/
	OCR1A_REG=1000;
	/*set Prescaler : divide by 8*/
	Clear_Bit(TCCR1B_REG,TCCR1B_CS12);
	Set_Bit(TCCR1B_REG,TCCR1B_CS11);
	Clear_Bit(TCCR1B_REG,TCCR1B_CS10);
}
void Timer1_voidSetChannelACompValue(uint16 copy_u16Value)
{
	OCR1A_REG= copy_u16Value;
}

/*
void __vector_10 (void)  __attribute__((signal));
void __vector_10(void)
{
	if((timer0_pCompareCallbaxkFunc)!=NULL)
	{
		timer0_pCompareCallbaxkFunc();
	}
	else
	{
		//nothing
	}
}


void Timer0_pwm(uint8 Copy_PWM)
{
	OCR0_REG = Copy_PWM;
}
*/