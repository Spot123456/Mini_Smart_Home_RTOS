/*
 * BIT_MATH.h
 *
 * Created: 2/28/2023 8:24:11 PM
 *  Author: yahia
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define  Set_Bit(PORT_ID,PIN_ID)          PORT_ID |= (1<<PIN_ID)
#define  Clear_Bit(PORT_ID,PIN_ID)        PORT_ID &= ~(1<<PIN_ID)
#define  Toggle_Bit(PORT_ID,PIN_ID)       PORT_ID ^= (1<<PIN_ID)
#define  Get_Bit(PORT_ID,PIN_ID)		  (((PORT_ID)>>(PIN_ID)) & 0x01)


#endif /* BIT_MATH_H_ */