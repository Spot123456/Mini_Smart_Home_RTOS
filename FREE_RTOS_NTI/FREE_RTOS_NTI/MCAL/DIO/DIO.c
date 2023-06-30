/*
 * DIO.c
 *
 * Created: 2/28/2023 8:06:08 PM
 *  Author: yahia
 */ 

#include "DIO.h"

void DIO_set_port_direction(DIO_PORT_ID port_id,EN_Dio_Direction direction)
{
	if(port_id<=PORTD)
	{
		if(direction==output)
		{
			switch(port_id)
			{
				case PORTA:    DDRA_REG=0xff     ; break;
				case PORTB:    DDRB_REG=0xff     ; break;
				case PORTC:    DDRC_REG=0xff     ; break;
				case PORTD:    DDRD_REG=0xff     ; break;
				
			}
			
		}
		
			if(direction==input)
			{
				switch(port_id)
				{
					case PORTA:    DDRA_REG=0x00     ; break;
					case PORTB:    DDRB_REG=0x00     ; break;
					case PORTC:    DDRC_REG=0x00     ; break;
					case PORTD:    DDRD_REG=0x00     ; break;
					
				}
			}
	}
}


void DIO_set_port_data(DIO_PORT_ID port_id,EN_Dio_Value val)
{
	if(port_id<=PORTD)
	{
		if(val==HIGH)
		{
			switch(port_id)
			{
				case PORTA: PORTA_REG=0xff         ;    break;
				case PORTB: PORTB_REG=0xff         ;    break;
				case PORTC: PORTC_REG=0xff         ;    break;
				case PORTD: PORTD_REG=0xff         ;    break;
			}
		}
		if(val==LOW)
		{
			switch(port_id)
			{
				case PORTA: PORTA_REG=0x00         ;    break;
				case PORTB: PORTB_REG=0x00         ;    break;
				case PORTC: PORTC_REG=0x00         ;    break;
				case PORTD: PORTD_REG=0x00         ;    break;
			}
		}
	}
	
}



void DIO_set_pin_direction(DIO_PORT_ID port_id,DIO_Pin_ID pin_id,EN_Dio_Direction direction)
{
	if((pin_id<=pin7)&&(port_id<=PORTD))
	{
		if(direction==output)
		{
	
			switch(port_id)
			{
				case PORTA: Set_Bit(DDRA_REG,pin_id);  break;
				case PORTB: Set_Bit(DDRB_REG,pin_id);  break;
				case PORTC: Set_Bit(DDRC_REG,pin_id);  break;
				case PORTD: Set_Bit(DDRD_REG,pin_id);  break;
			}
		}
		if(direction==input)
		{
			
			switch(port_id)
			{
				case PORTA: Clear_Bit(DDRA_REG,pin_id);  break;
				case PORTB: Clear_Bit(DDRB_REG,pin_id);  break;
				case PORTC: Clear_Bit(DDRC_REG,pin_id);  break;
				case PORTD: Clear_Bit(DDRD_REG,pin_id);  break;
			}
		}
	}
}

void DIO_set_pin_value(DIO_PORT_ID port_id,DIO_Pin_ID pin_id,EN_Dio_Value val)
{
	if(port_id<=PORTD && pin_id<=pin7)
	{
		if (val==LOW)
		{
			switch (port_id)
			{
			case  PORTA : Clear_Bit(PORTA_REG,pin_id)        ; break;
			case  PORTB : Clear_Bit(PORTB_REG,pin_id)        ; break;
			case  PORTC : Clear_Bit(PORTC_REG,pin_id)        ; break;
			case  PORTD : Clear_Bit(PORTD_REG,pin_id)        ; break;
			}
		}
		if (val==HIGH)
		{
			switch (port_id)
			{
				case  PORTA : Set_Bit(PORTA_REG,pin_id)        ; break;
				case  PORTB : Set_Bit(PORTB_REG,pin_id)        ; break;
				case  PORTC : Set_Bit(PORTC_REG,pin_id)        ; break;
				case  PORTD : Set_Bit(PORTD_REG,pin_id)        ; break;
			}
		}
	}
	
}

void DIO_get_pin_value(DIO_PORT_ID port_id,DIO_Pin_ID pin_id,EN_Dio_Value *val)
{
	if(port_id<=PORTD && pin_id<=pin7)
	{
		switch(port_id)
		{
			case PORTA: *val= Get_Bit(PINA_REG,pin_id)  ;    break;
			case PORTB: *val= Get_Bit(PINB_REG,pin_id)  ;    break;
			case PORTC: *val= Get_Bit(PINC_REG,pin_id)  ;    break;
			case PORTD: *val= Get_Bit(PIND_REG,pin_id)  ;    break;
		}
	}
	
}


void DIO_set_port_char(DIO_PORT_ID port_id,EN_Dio_Value val)
{
	if(port_id<=PORTD)
	{
			switch(port_id)
			{
				case PORTA: PORTA_REG=val         ;    break;
				case PORTB: PORTB_REG=val         ;    break;
				case PORTC: PORTC_REG=val         ;    break;
				case PORTD: PORTD_REG=val         ;    break;
			}
	}
}
	
	
void DIO_set_port_dir(DIO_PORT_ID port_id,EN_Dio_Value val)
{
	if(port_id<=PORTD)
	{
		switch(port_id)
		{
			case PORTA: DDRA_REG=val         ;    break;
			case PORTB: DDRB_REG=val         ;    break;
			case PORTC: DDRC_REG=val         ;    break;
			case PORTD: DDRD_REG=val         ;    break;
		}
	}
}

