/*
 * UART.c
 *
 * Created: 3/21/2023 3:27:53 PM
 *  Author: Ahmed Nour
 */ 
#include "UART.h"
void UART_init()
{
	/*local variable to hold the required value of UCSRC register */
	uint8 local_UCSRCVsl= 0;
	/*choose the UCSRC REG */ 
	Set_Bit(local_UCSRCVsl,UCSRC_URSEL);
	/*choose the character size : 8 bit size*/
	Set_Bit(UCSRC_REG,UCSRC_UCSZ0);
	Set_Bit(UCSRC_REG,UCSRC_UCSZ1);
	Clear_Bit(UCSRB_REG,UCSRB_UCSZ2);
	
	/*we need to set boud rate: for sys 8 MHz & boud rate 9600 we set boud =51 */
	UBRRL_REG = 51;
	/*enable TX*/
	Set_Bit(UCSRB_REG,UCSRB_TXEN);
	/*enable RX*/
	Set_Bit(UCSRB_REG,UCSRB_RXEN);
}

void UART_SendData(uint8 data)
{
	while((Get_Bit(UCSRA_REG,UCSRA_UDRE)==0));
	/*send the data*/
	UDR_REG= data;  //buffer
}

uint8 UART_ReceivedData()
{
	/*wait until receive complete event happens*/
	while((Get_Bit(UCSRA_REG,UCSRA_RXC))==0);
	
	/*return the data*/
	return UDR_REG; //buffer
}

void UART_voidSendStringBlocking(char *Copy_u8Data){

	while(*Copy_u8Data != NULL){

		UART_SendData(*Copy_u8Data);
		*Copy_u8Data++;
	}
}



void UART_voidWriteDecimalNumber(uint32 Copy_u32Number){

	uint32 Local_u8Reversed = 1;

	if(0 == Copy_u32Number){
		UART_SendData('0');
	}
	while(0 != Copy_u32Number){

		Local_u8Reversed = ((Local_u8Reversed * 10) + (Copy_u32Number % 10));
		Copy_u32Number /= 10;
	}
	while(1 != Local_u8Reversed){

		UART_SendData((Local_u8Reversed % 10 ) + 48);
		Local_u8Reversed /= 10;
	}

}
