#ifndef INTERFACE_H_
#define INTERFACE_H_

/* Ports Macros */
#define DIO_u8PORTA  ((uint8)0)
#define DIO_u8PORTB  ((uint8)1)
#define DIO_u8PORTC  ((uint8)2)
#define DIO_u8PORTD  ((uint8)3)

/* Pins Macros */
#define DIO_u8PIN0   ((uint8)0)
#define DIO_u8PIN1   ((uint8)1)
#define DIO_u8PIN2   ((uint8)2)
#define DIO_u8PIN3   ((uint8)3)
#define DIO_u8PIN4   ((uint8)4)
#define DIO_u8PIN5   ((uint8)5)
#define DIO_u8PIN6   ((uint8)6)
#define DIO_u8PIN7   ((uint8)7)

/* Values Macros */
#define DIO_u8PIN_LOW    ((uint8)0)
#define DIO_u8PIN_HIGH   ((uint8)1)
#define DIO_u8PORT_HIGH  ((uint8)0xff)
#define DIO_u8PORT_LOW   ((uint8)0x00)

/* Directions Macros */
#define DIO_u8PIN_INPUT   ((uint8)0)
#define DIO_u8PIN_OUTPUT  ((uint8)1)
#define DIO_u8PORT_OUTPUT ((uint8)0xff)
#define DIO_u8PORT_INPUT  ((uint8)0x00)

/* Functions Prototypes */
uint8 DIO_u8SetPinDirection  (uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction);
uint8 DIO_u8SetPinValue      (uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value);
uint8 DIO_u8ReadPinValue     (uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8* Copy_pu8Value);

uint8 DIO_u8SetPortDirection (uint8 Copy_u8Port, uint8 Copy_u8Direction);
uint8 DIO_u8SetPortValue     (uint8 Copy_u8Port, uint8 Copy_u8Value);

uint8 DIO_u8TogglePinValue   (uint8 Copy_u8Port, uint8 Copy_u8Pin);

#endif
