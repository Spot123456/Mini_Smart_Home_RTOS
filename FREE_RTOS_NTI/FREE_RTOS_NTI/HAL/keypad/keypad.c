/*
 * keypad.c
 *
 * Created: 4/22/2023 9:21:22 AM
 *  Author: yahia
 */ 
#include "keypad.h"
uint8 rowpins[rows]={0,1,2,3};
uint8 colpins[rows]={4,5,6,7};
uint8 keypadmap[rows][cols]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

void keypad_init()
{
	//row as output
	DDRD_REG|=(1<<0) | (1<<1)|(1<<2)|(1<<3);
	//set the col input
	DDRD_REG&=~((1<<4) | (1<<5) | (1 << 6) | (1<<7));
	//set col init high : pull up res
	PORTD_REG|=((1<<4) | (1<<5) | (1 << 6) | (1<<7));
}

uint8 keypad_scan()
{
	uint8 i,j;
	for(i=0 ; i< rows ; i++)
	{
		//activate the row 
		PORTD_REG&=~(1<<i);
		for(j=0;j<cols;j++)
		{
			if((PIND_REG&(1<<colpins[j]))==0)
			{
				while((PIND_REG&(1<<colpins[j]))==0);
				return keypadmap[i][j];
			}
		}
		//deactivate the current row 
		PORTD_REG|=(1<<i);
	}
	return 0;
}




