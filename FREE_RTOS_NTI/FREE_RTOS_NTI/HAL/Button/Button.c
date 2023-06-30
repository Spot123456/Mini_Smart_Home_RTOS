/*
 * Button.c
 *
 * Created: 1/25/2023 9:28:34 PM
 *  Author: Ahmed Nour
 */ 

#include "Button.h"

void Button_Init(uint8 pin_id, uint8 port_id)
{
	DIO_set_pin_direction(port_id,pin_id,input);
}
uint8 Button_read(uint8 pin_id, uint8 port_id )
{
	EN_Dio_Value val;
	DIO_get_pin_value(port_id,pin_id,&val);
	return val ; 
}