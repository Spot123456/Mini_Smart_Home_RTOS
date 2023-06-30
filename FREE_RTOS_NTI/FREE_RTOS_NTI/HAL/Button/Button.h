/*
 * Button.h
 *
 * Created: 1/25/2023 9:28:51 PM
 *  Author: yahia
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"

void Button_Init(uint8 pin_id, uint8 port_id);
uint8 Button_read(uint8 pin_id, uint8 port_id );


#endif /* BUTTON_H_ */