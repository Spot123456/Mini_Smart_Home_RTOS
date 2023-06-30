/*
 * IncFile1.h
 *
 * Created: 2/28/2023 8:08:49 PM
 *  Author: yahia
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "DIO_REG.h"
/*************************************************/
/*				 AVR REG                         */
/*************************************************/

/******************************************/
/*              GPIO REG                  */
/******************************************/

#define PORTA_REG *((volatile uint8*) 0x3B)
#define DDRA_REG  *((volatile uint8*) 0x3A)
#define PINA_REG  *((volatile uint8*) 0x39)

#define PORTB_REG *((volatile uint8*) 0x38)
#define DDRB_REG  *((volatile uint8*) 0x37)
#define PINB_REG  *((volatile uint8*) 0x36)

#define PORTC_REG *((volatile uint8*) 0x35)
#define DDRC_REG  *((volatile uint8*) 0x34)
#define PINC_REG  *((volatile uint8*) 0x33)

#define PORTD_REG *((volatile uint8*) 0x32)
#define DDRD_REG  *((volatile uint8*) 0x31)
#define PIND_REG  *((volatile uint8*) 0x30)

/******************************************/
/*              ADC REG                  */
/******************************************/

#define ADMUX_REG			*((volatile uint8*) 0x27)
#define REFS1		7       //this two bit Responsible for Vref of ADC
#define REFS0		6
#define ADLAR		5		// set (1) when work at 8 bit (read conversation) | set(0)for 10 bit
#define MUX4		4
#define MUX3		3
#define MUX2		2		// these 5 bit responsible for analog channel and Gain selection Bits
#define MUX1		1
#define MUX0		0


#define ADCSRA_REG			*((volatile uint8*)0x26)
#define ADEN		7		// ADC Enable
#define ADSC		6		// ADC Star Conversion
#define ADATE		5		// ADC Auto Trigger Enable (we don t need now)
#define ADIF		4		// ADC Interrupt Flag (clear by set it one manually or use interrupt for clear Auto)
#define ADIE		3		// ADC Interrupt Enable
#define ADPS2		2
#define ADPS1		1		// Prescaler Select Bits
#define ADPS0		0

#define SFIOR		*((volatile uint8*)0x50)					// special Function Register
#define ADTS2		7
#define ADTS1		6		//	ADC Auto trigger source (we don't use this now)
#define ADTS0		5

//for reading from ADLAR
#define ADCH		*((volatile uint8*)0x25)
#define ADCL		*((volatile uint8*)0x24)

#define ADC_T		*((volatile uint16*)0x24)


/************************************************************************/
/*                           TIMER0 REG                                 */
/************************************************************************/

#define TCCR0_REG				*((volatile uint8*)0x53)
#define TCCR0_FCO0			7					// bit must =0 when operating in PWM mode , 1 for compare match
#define TCCR0_COM01			5					/*Compare match output mode bit 1*/
#define TCCR0_COM00			4					/*Compare match output mode bit 0*/
#define TCCR0_WGM00			6					/*Waveform generation mode bit 0*/
#define TCCR0_WGM01			3					/*Waveform generation mode bit 1*/
#define TCCR0_CS02			2
#define TCCR0_CS01			1
#define TCCR0_CS00			0

#define OCR0_REG			*((volatile uint8*)0x5C)			/*Output compare match register*/
#define TCNT0_REG           *((volatile uint8*)0x52)			/*Timer counter 0 register*/
#define TIFR0_REG			*((volatile uint8*)0x58)

#define TIMSK_REG			*((volatile uint8*)0x59)			/*Timer mask register*/
#define TIMSK_TOIE0		0								/*Timer0 overflow interrupt enable*/
#define TIMSK_OCIE0		1								/*Timer0 compare match interrupt enable*/
/************************************************************************/
/*                                 EXT interrupt                                     */
/************************************************************************/

#define GICR_REG	*((volatile uint8*) 0x5B)
#define GICR_INT1	7
#define GICR_INT0	6
#define GICR_INT2	5

#define GIFR_REG	*((volatile uint8*) 0x5A)
#define GIFR_INT1	7
#define GIFR_INT0	6
#define GIFR_INT2	5
#define MCUCR_REG	*((volatile uint8*) 0x55)

#define MCUCR_ISC11 3
#define MCUCR_ISC10 2		//select sensing of Ext interrupt
#define MCUCR_ISC01 1
#define MCUCR_ISC00 0



#define MCUCSR_REG	*((volatile uint8*) 0x54)
#define SREG_REG    *((volatile uint8*) 0x5F)

/************************************************************************/
/*                    TIMER1 REG                                        */
/************************************************************************/

#define TCCR1A_REG   *((volatile uint8*)0x4F)    /*Timer1 Control registerA*/
#define TCCR1A_COM1A1 7							/*ChannelA compare match output mode bit 1 */
#define TCCR1A_COM1A0 6							/*ChannelA compare match output mode bit 0 */
#define TCCR1A_WGM11  1							/*wave form generation mode bit1 */
#define TCCR1A_WGM10  0							/*wave form generation mode bit0 */


#define TCCR1B_REG   *((volatile uint8*)0x4E)
#define TCCR1B_WGM13  4							/*wave form generation mode bit3 */
#define TCCR1B_WGM12  3							/*wave form generation mode bit4 */
#define TCCR1B_CS12	  2							/*Prescaler bit 2*/
#define TCCR1B_CS11	  1							/*Prescaler bit 1*/
#define TCCR1B_CS10	  0							/*Prescaler bit 0*/


#define ICR1_REG     *((volatile uint16*)0x46)	/*channelA output compare match register  (16 bit bec the output 16 bit to take the two reg : high & low)*/ 
#define OCR1AH_REG    *((volatile uint8*)0x4B)
#define OCR1Al_REG    *((volatile uint8*)0x4A)

#define OCR1A_REG    *((volatile uint16*)0x4A)	/*Input capture register */
#define TIFR1_REG    *((volatile uint16*)0x58)	/*Input capture reg flags */

/************************************************************************/
/*                        UART REG                                              */
/************************************************************************/

#define UDR_REG		*((volatile uint8*)0x2C)

#define UCSRA_REG	*((volatile uint8*)0x2B)

#define UCSRA_RXC	7
#define UCSRA_TXC	6
#define UCSRA_UDRE	5
#define	UCSRA_FE	4
#define	UCSRA_DOR	3
#define	UCSRA_PE	2
#define	UCSRA_U2X	1

#define UCSRB_REG	*((volatile uint8*)0x2A)

#define UCSRB_RXEN	4
#define UCSRB_TXEN	3
#define UCSRB_UCSZ2	2

#define UBRRL_REG	*((volatile uint8*)0x29)
#define UBRRH_REG	*((volatile uint8*)0x40)
#define UBRRH_URSEL		7  /*select between UCSRC/UBRRH*/
#define UBRRH_UBRR11	3
#define UBRRH_UBRR10	2
#define UBRRH_UBRR9		1
#define UBRRH_UBRR8		0

#define UCSRC_REG	*((volatile uint8*)0x40)            // its the same reg of UBRRH
#define UCSRC_URSEL	7   /*select between UCSRC/UBRRH*/
#define UCSRC_UMSEL	6
#define UCSRC_UPM1	5
#define UCSRC_UPM0	4
#define UCSRC_USBS	3  //stop bit
#define UCSRC_UCSZ1	2
#define UCSRC_UCSZ0	1
#define	UCSRC_UCPOL	0

/************************************************************************/
/*                          SPI REG                                     */
/************************************************************************/

#define SPDR_REG	*((volatile uint8*)0x2F)

#define SPSR_REG	*((volatile uint8*)0x2E)
#define SPSR_SPIF	7
#define SPSR_WCOL	6	/*write collision flag*/
#define SPSR_SPI2X	0	/*prescaler and double speed*/
#define SPCR_REG	*((volatile uint8*)0x2D)

#define SPCR_SPIE	7	/*interrupt enable*/
#define SPCR_SPE	6	/*spi enable*/
#define SPCR_DORD	5	/*data order : send LSB or MSB first*/
#define SPCR_MSTR	4	/*select master or slave*/
#define SPCR_CPOL	3	/*CLK polarity*/
#define SPCR_CPHA	2	/*CLK phase:send-receive or receive-send*/
#define SPCR_SPR1	1	/*Prescaler selection*/
#define SPCR_SPR0	0	/**/

/************************************************************************/
/*                        TWI REG                                       */
/************************************************************************/
#define TWCR_REG	*((volatile uint8*)0x56) /*TWI Control Register*/

#define TWCR_TWINT	7		/*Interrupt Flag*/
#define TWCR_TWEA	6		/*Enable Acknoledge*/
#define TWCR_TWSTA	5		/*Start Condition*/
#define TWCR_TWSTO	4		/*Stop condition*/
#define TWCR_TWWC	3		/*write collision*/
#define TWCR_TWEN	2		/*enable*/
#define TWCR_TWIE	0		/*interrupt Enable*/

#define TWDR_REG	*((volatile uint8*)0x23)	/*TWI Data Register*/

#define TWAR_REG	*((volatile uint8*)0x22)	/*TWI Address Register*/
#define TWAR_TWGCE	0							/*General Call recognition Enable*/

#define TWSR_REG	*((volatile uint8*)0x21)	/*TWI Status Register*/
#define TWSR_TWPS0	0							/*Prescaler Bit0*/
#define TWSR_TWPS1	1							/*Prescaler Bit1*/

#define TWBR_REG	*((volatile uint8*)0x20)	/*TWI Bit Rate Register*/

#endif /* INCFILE1_H_ */