/*
 * keypad.h
 *
 * Created: 4/22/2023 9:21:34 AM
 *  Author: yahia
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../../utilities/BIT_MATH.h"
#include "../../utilities/Data_Type.h"
#include "../../utilities/DIO_REG.h"

#define NOT_PRESSED 0xff
#define rows	4
#define cols	4
void keypad_init();
uint8 keypad_scan();


#endif /* KEYPAD_H_ */