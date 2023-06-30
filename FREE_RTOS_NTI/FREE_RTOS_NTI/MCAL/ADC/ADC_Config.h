/*
 * config.h
 *
 * Created: 3/1/2023 9:45:28 PM
 *  Author: yahia
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

/************************************************************************/
/*                       ADC prescaler (MUST XTAL)                                              */
/************************************************************************/
#define ADCSRA_MASK  0b11111000  //to Sure the last 3 bit is zero before select Prescaler
#define division_0		0
#define division_2		1
#define division_4		2
#define division_8		3
#define division_16		4
#define division_32		5
#define division_64		6
#define division_128	7

/************************************************************************/
/*                                     Select Vref                                 */
/************************************************************************/

#define Vref_off  0
#define AVCC	  1
#define Reserved  2
#define V_init	  3			//v_init=2.56V

/*				select channel				*/
#define ADMUX_MASK		0b11100000   

#define SINGLE_CONVERSION   0
#define CHAIN_CONVERSION	1
/* struct for chain conv */
typedef struct 
{
	uint8 * ChainChannel; // ptr to array  (channel)
	uint16* ChainResult;	//(result)
	uint8	ChainSize;   // we need to know no of channel (no.of channel)
	void (*ChainNotificationFunc)(void);
}Chain_t;

#endif /* CONFIG_H_ */