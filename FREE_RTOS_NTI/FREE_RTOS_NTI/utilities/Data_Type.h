/*
 * Data_Type.h
 *
 * Created: 2/28/2023 8:17:14 PM
 *  Author: yahia
 */ 


#ifndef DATA_TYPE_H_
#define DATA_TYPE_H_

typedef unsigned char   uint8 ;
typedef unsigned short  uint16;
typedef unsigned long	uint32;

typedef signed char     int8 ;
typedef signed short    int16;
typedef signed long     int32;

typedef enum
{
	LOW,
	HIGH
}EN_Dio_Value;
typedef enum
{
	input,
	output
}EN_Dio_Direction;

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
}DIO_PORT_ID;
typedef enum
{ pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
pin7}DIO_Pin_ID;


#endif /* DATA_TYPE_H_ */