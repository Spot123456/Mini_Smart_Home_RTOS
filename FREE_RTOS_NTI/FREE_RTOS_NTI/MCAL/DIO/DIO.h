/*
 * DIO.h
 *
 * Created: 2/28/2023 8:06:46 PM
 *  Author: yahia
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../utilities/BIT_MATH.h"
#include "../../utilities/Data_Type.h"
#include "../../utilities/DIO_REG.h"



void DIO_set_port_direction(DIO_PORT_ID port_id,EN_Dio_Direction direction);
void DIO_set_port_data(DIO_PORT_ID port_id,EN_Dio_Value val);

void DIO_set_pin_direction(DIO_PORT_ID port_id,DIO_Pin_ID pin_id,EN_Dio_Direction direction);
void DIO_set_pin_value(DIO_PORT_ID port_id,DIO_Pin_ID pin_id,EN_Dio_Value val);
void DIO_get_pin_value(DIO_PORT_ID port_id,DIO_Pin_ID pin_id,EN_Dio_Value *val);
void DIO_toggle_pin();
void DIO_set_port_char(DIO_PORT_ID port_id,EN_Dio_Value val);

void DIO_set_port_dir(DIO_PORT_ID port_id,EN_Dio_Value val);


















#endif /* DIO_H_ */