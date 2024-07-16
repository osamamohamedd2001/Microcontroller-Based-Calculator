/*
 * PORT_reg.h
 *
 *  Created on: Jul 11, 2024
 *      Author: Osama
 */

#ifndef PORT_REG_H_
#define PORT_REG_H_


/* PORTA */
#define PORTA   *((volatile uint8*)0x3B)
#define DDRA    *((volatile uint8*)0x3A)
#define PINA    *((volatile uint8*)0x39)

/* PORTB */
#define PORTB   *((volatile uint8*)0x38)
#define DDRB    *((volatile uint8*)0x37)
#define PINB    *((volatile uint8*)0x36)

/* PORTC */
#define PORTC   *((volatile uint8*)0x35)
#define DDRC    *((volatile uint8*)0x34)
#define PINC    *((volatile uint8*)0x33)

/* PORTD */
#define PORTD   *((volatile uint8*)0x32)
#define DDRD    *((volatile uint8*)0x31)
#define PIND    *((volatile uint8*)0x30)


#endif /* PORT_REG_H_ */
