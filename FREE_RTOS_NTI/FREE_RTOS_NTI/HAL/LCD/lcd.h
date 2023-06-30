/*
 * lcd.h
 *
 * Created: 2/22/2023 2:24:38 AM
 *  Author: Ahmed Nour
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "../../utilities/Data_Type.h"
#include "../../MCAL/DIO/dio.h"

void LCD_Send_Command(uint8 command);

void LCD_Send_Data(uint8 Data);

void LCD_INIT();

void LCD_sendString(const char* string);

void LCD_ChangePOS_XY(uint8 POSX,uint8 POSY);

void LCD_sendSpecial_char(uint8* pattern_Data_Array,uint8 pattern_no,uint8 XPOS,uint8 YPOS);  //when we use array we must assign by (*)

void LCD_INIT_DIR();

void LCD_Clear();

void LCD_VoidIntgerToString (uint16 num);

void LCD_voidWriteNumber(uint16 Copy_u16Number);

static uint16 Private_u16GetPower(uint8 Copy_u8Number1, uint8 Copy_u8Number2);

#endif /* LCD_H_ */