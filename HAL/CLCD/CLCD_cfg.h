#ifndef CLCD_CFG_H
#define CLCD_CFG_H

/*configure the lcd bit mode, options are :		1- FOUR_BIT
 * 												2- EIGHT_BIT
 * 	*/
#define CLCD_u8BIT_MODE			EIGHT_BIT

/*Configure whether the CLCD RW pin is connected to a DIO pin or directly to the gnd, options:
 * 												1- GND_CONNECTED
 * 												2- DIO_CONNECTED
 * 	*/
#define CLCD_u8RW_CONN_STS		DIO_CONNECTED

#define CLCD_u8CTRL_PORT		DIO_u8PORTD

#define CLCD_u8RS_PIN			DIO_u8PIN0

#if CLCD_u8RW_CONN_STS == DIO_CONNECTED
#define CLCD_u8RW_PIN			DIO_u8PIN1
#endif

#define CLCD_u8E_PIN			DIO_u8PIN2

#define CLCD_u8DATA_PORT		DIO_u8PORTC

#if CLCD_u8BIT_MODE == FOUR_BIT
#define CLCD_u8D4_PIN			DIO_u8PIN0
#define CLCD_u8D5_PIN			DIO_u8PIN1
#define CLCD_u8D6_PIN			DIO_u8PIN2
#define CLCD_u8D7_PIN			DIO_u8PIN3
#endif

#endif
