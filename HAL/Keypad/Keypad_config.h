/*
 * Keypad_config.h
 *
 *  Created on: Jul 16, 2024
 *      Author: Osama
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_u8COL_PORT   DIO_u8PORTD
#define KEYPAD_u8ROW_PORT   DIO_u8PORTC

#define KEYPAD_u8COL1_PIN   DIO_u8PIN0
#define KEYPAD_u8COL2_PIN   DIO_u8PIN1
#define KEYPAD_u8COL3_PIN   DIO_u8PIN2
#define KEYPAD_u8COL4_PIN   DIO_u8PIN3

#define KEYPAD_u8ROW1_PIN   DIO_u8PIN0
#define KEYPAD_u8ROW2_PIN   DIO_u8PIN1
#define KEYPAD_u8ROW3_PIN   DIO_u8PIN2
#define KEYPAD_u8ROW4_PIN   DIO_u8PIN3

#define KEYPAD_au8_BUTTON_ARRAY    {{'1','2','3','/'},{'4','5','6','*'},{'7','8','9','-'},{'C','0','=','+'}}


#endif /* KEYPAD_CONFIG_H_ */
