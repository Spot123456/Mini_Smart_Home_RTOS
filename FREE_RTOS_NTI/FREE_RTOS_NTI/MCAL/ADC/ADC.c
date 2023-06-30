/*
 * ADC.c
 *
 * Created: 3/1/2023 9:44:51 PM
 *  Author: Ahmed Nour
 */ 
#include "ADC.h"


/*Global pointer to hold the conversion result accessed by the ISR
 *static :bec the var used only in this file 
 */
static uint16* ADC_ConversionResult = NULL; 

/*Global variable to indicate for the ADC peripheral state*/
uint8 ADC_State =empty;
/*Global pointer to function to hold the notification function called by the ISR*/
static void(*ADC_NotificationFunc)(void)= NULL;

/*global flag to indicate for the reason why ISR comes*/
uint8 ADC_ISR_Source;
/*global pointer to carry the channel array*/
uint8 *ADC_ChainChannel=NULL;
/*global var to carry the current conversion index*/
static uint8 ADC_ChainIndex;
/*global var to carry the chain number of channel*/
static uint8 ADC_ChainSize;

void ADC_init()
{
	/*1- Vref selection select 5v*/
	Set_Bit(ADMUX_REG,REFS0);
	Clear_Bit(ADMUX_REG,REFS1);
	
	/*2- we work at 8 bit */
	//Set_Bit(ADMUX_REG,ADLAR);
	//Clear_Bit(ADMUX_REG,ADLAR);
	/*3- select Prescaler*/
	ADCSRA_REG&= ADCSRA_MASK ;  //we need to sure the last 3 bit =0
	ADCSRA_REG|=division_8;
	/*4- enable ADC */
	Set_Bit(ADCSRA_REG,ADEN);
}

uint8 ADC_Start_Conversion(uint8 channel)
{
	uint8 ADC;
	/*1- select the channel*/
	ADMUX_REG &= ADMUX_MASK;   
	ADMUX_REG|= channel;
	/*2- start conversion */
	Set_Bit(ADCSRA_REG,ADSC);
	/*3- to read the ADC wait the conversion to end*/
	while((Get_Bit(ADCSRA_REG,ADIF))==0); //Busy waiting (polling) until the conversion is complete
	/*4- we need to clear flag manually BEC we don't use interrupt*/
	Set_Bit(ADCSRA_REG,ADIF);
	/* read result*/
	ADC= ADCH;
	return ADC;
}


uint8 ADC_Start_Conversion_SYN(uint8 channel,uint8*reading)
{
	uint8 local_error_state=OK;
	uint8 local_counter =0 ;
	if(reading!=NULL)  //5lyha 3ada twl ma al fun btst2bl pointer must right this for safety
	{ 
		if(ADC_State==empty)
		{
			/*select channel*/
			ADC_State=busy ;
			ADMUX_REG&=ADMUX_MASK;
			ADMUX_REG=channel;
			/*start conv*/ 
			Set_Bit(ADCSRA_REG,ADSC);
			while((Get_Bit(ADCSRA_REG,ADIF)==0) &&(local_counter<ADC_TimeOut))
			{
				local_counter++;
			}
			if(local_counter==ADC_TimeOut)
			{
				/*Loop is broken because Timeout is reached*/
				local_error_state=TIMEOUT_STATE;
			}
			else
			{
				/*Loop is broken because conversion complete flag is raised*/
				/*Clear the conversion complete flag*/
				Set_Bit(ADCSRA_REG,ADIF);
				*reading=ADCH;
			
			}
			/*release the ADC state, ADC is now Idle*/
			ADC_State=empty;
		}
		else
		{
			local_error_state=busy;
		}
	}
	else
	{
		local_error_state = NULL_POINTER;
	}
	return local_error_state;
}


uint8 ADC_Start_Conversion_ASYN(uint8 channel,uint16*reading,void(*notificationfun)(void))
{
	uint8 local_error_state=OK;
	if((reading!=NULL)&&(notificationfun!=NULL))
	{
		if(ADC_State==empty)
		{
			/*ADC is now busy*/
			ADC_State=busy;
			/*ISR will work bec of single conversion function or chain conv : (in this case it was single ) */
			ADC_ISR_Source= SINGLE_CONVERSION;
			/*Initialize the global pointer to point to the result address*/
			ADC_ConversionResult=reading;
			/*Initialize the global pointer to function to point to the notification function address*/
			ADC_NotificationFunc=notificationfun;
			/*select channel */ 
			ADMUX_REG&=ADMUX_MASK;
			ADMUX_REG|=channel;
			/*start conversion*/
			Set_Bit(ADCSRA_REG,ADSC);
			/*Enable ADC conversion complete interrupt*/
			Set_Bit(ADCSRA_REG,ADIE);
		}
		else
		{
			local_error_state=busy;
		}
	}
	else
	{
		local_error_state=NULL_POINTER;
	}
	return local_error_state;
}

uint8 ADC_Start_Chain_Conversion_ASYN(Chain_t * Copy_chain)
{
	uint8 local_errorState= OK;
	
	if((Copy_chain!=NULL)&&(Copy_chain->ChainChannel!=NULL)&&(Copy_chain->ChainResult!=NULL)
	&&(Copy_chain->ChainNotificationFunc !=NULL))
	{
		/*check the ADC Busy State*/
		if(ADC_State==empty)
		{
			/*now ADC is BUSY*/
			ADC_State=busy;
			/*=ISR will come because of chain of conversion */
			ADC_ISR_Source=CHAIN_CONVERSION;
			/*initialize the chain globally for (isr)*/
			ADC_ChainChannel=Copy_chain->ChainChannel;
			ADC_ConversionResult= Copy_chain->ChainResult;
			ADC_ChainSize = Copy_chain->ChainSize;
			ADC_NotificationFunc = Copy_chain->ChainNotificationFunc;
			
			ADC_ChainIndex=0;
			/*set required channel */
			ADMUX_REG &= ADMUX_MASK;
			ADMUX_REG |=ADC_ChainChannel[ADC_ChainIndex];
			
			/*start conversion*/
			Set_Bit(ADCSRA_REG,ADSC);
			/*enable ADC conversion complete Interrupt*/
			Set_Bit(ADCSRA_REG,ADIE);
			
		}
		else
		{
			local_errorState=busy;
		}
	}
	else
	{
		local_errorState = NULL_POINTER;
	}
	return local_errorState;
}








/*ADC ISR  (Number of ISR -1)----> 17 - 1 = 16 */

void __vector_16 (void)  __attribute__((signal));
void __vector_16(void)
{
	if(ADC_ISR_Source==SINGLE_CONVERSION)
	{
		
			//Read the conversion result
			*ADC_ConversionResult=ADC_T;
			//release the ADC busy State ,ADC is now empty
			ADC_State=empty;
			//Disable the ADC conversion complete interrupt
			Clear_Bit(ADCSRA_REG,ADIE);
			//Invoke the callback notification function
			if(ADC_NotificationFunc!=NULL)
			{
				ADC_NotificationFunc();
			}	
	}
	else // ISR source is chain conversion
	{
		//read the conversion result
		ADC_ConversionResult[ADC_ChainIndex]=ADC_T;
		
		// inc the index to get the next channel result
		ADC_ChainIndex++;
		
		//check if the ADC chain == index : its finished the chain
		if(ADC_ChainIndex==ADC_ChainSize)
		{
			//chain is finished & adc is empty
			ADC_State=empty;
			//Disable the ADC conversion complete interrupt
			Clear_Bit(ADCSRA_REG,ADIE);
			//Invoke the callback notification function
			if(ADC_NotificationFunc!=NULL)
			{
				ADC_NotificationFunc();
			}
		}
		else
		{
			//chain isn't finished
			//set required channel
			ADMUX_REG&= ADMUX_MASK;
			ADMUX_REG|=ADC_ChainChannel[ADC_ChainIndex];
			//Start conversion
			Set_Bit(ADCSRA_REG,ADSC);
		}
	}
}



/////////////////////////////////////////////////////////////////////////////////////// Dr fahd
void (*ADC_CallBack)(void) = NULL;

void ADC_voidStartConversionWithInterrupt(uint8 Copy_u8ChannelNumber)
{

	/* channel number must be from A0 --> A7 */
	Copy_u8ChannelNumber &= ADMUX_MASK;

	/* Clear the MUX bits in ADMUX register */
	ADMUX_REG &= ADMUX_MASK;

	/* Set the required channel into the MUX bits */
	ADMUX_REG |= Copy_u8ChannelNumber;

	/* Start conversion */
	Set_Bit(ADCSRA_REG, ADSC);

}


void ADC_voidSetCallBack(void(*Copy_Fptr)(void)){

	ADC_CallBack = Copy_Fptr;

}

uint16 ADC_u16ADCRead(void)
{
	return ADC_T;
}


void ADC_voidInterruptEnable(void){

	/* ADC interrupt Enable */
	Set_Bit(ADCSRA_REG, ADIE);
}


ISR( ADC_VECTOR ){

	if(ADC_CallBack != NULL){

		ADC_CallBack();
	}
	else{ /* Return error */ }

}

