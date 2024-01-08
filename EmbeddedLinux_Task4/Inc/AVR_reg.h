/*
 * AVR_reg.h
 *
 * Created: 03-Dec-23 9:44:11 PM
 *  Author: Yasmin
 */ 


#ifndef AVR_REG_H_
#define AVR_REG_H_

/***		DIO registers		***/

#define DDRA_REG	((u8*)0x3A)
#define DDRB_REG	((u8*)0x37)
#define DDRC_REG	((u8*)0x34)
#define DDRD_REG	((u8*)0x31)

#define PORTA_REG	((u8*)0x3B)
#define PORTB_REG	((u8*)0x38)
#define PORTC_REG	((u8*)0x35)
#define PORTD_REG	((u8*)0x32)

#define PINA_REG	((u8*)0x39)
#define PINB_REG	((u8*)0x36)
#define PINC_REG	((u8*)0x33)
#define PIND_REG	((u8*)0x30)

#endif /* AVR_REG_H_ */