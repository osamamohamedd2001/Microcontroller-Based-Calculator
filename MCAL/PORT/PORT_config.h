/*
 * PORT_config.h
 *
 *  Created on: Jul 11, 2024
 *      Author: Osama
 */

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/********************************************************** Direction Configuration *************************************************************/

/*
 * Configure the direction for each pin.
 * Options:
 * - INPUT
 * - OUTPUT
 */

#define PORTA_PIN0_DIR   OUTPUT
#define PORTA_PIN1_DIR   OUTPUT
#define PORTA_PIN2_DIR   OUTPUT
#define PORTA_PIN3_DIR   OUTPUT
#define PORTA_PIN4_DIR   OUTPUT
#define PORTA_PIN5_DIR   OUTPUT
#define PORTA_PIN6_DIR   OUTPUT
#define PORTA_PIN7_DIR   OUTPUT

#define PORTB_PIN0_DIR   OUTPUT
#define PORTB_PIN1_DIR   OUTPUT
#define PORTB_PIN2_DIR   OUTPUT
#define PORTB_PIN3_DIR   OUTPUT
#define PORTB_PIN4_DIR   OUTPUT
#define PORTB_PIN5_DIR   OUTPUT
#define PORTB_PIN6_DIR   OUTPUT
#define PORTB_PIN7_DIR   OUTPUT

#define PORTC_PIN0_DIR   INPUT
#define PORTC_PIN1_DIR   INPUT
#define PORTC_PIN2_DIR   INPUT
#define PORTC_PIN3_DIR   INPUT
#define PORTC_PIN4_DIR   INPUT
#define PORTC_PIN5_DIR   INPUT
#define PORTC_PIN6_DIR   INPUT
#define PORTC_PIN7_DIR   INPUT

#define PORTD_PIN0_DIR   OUTPUT
#define PORTD_PIN1_DIR   OUTPUT
#define PORTD_PIN2_DIR   OUTPUT
#define PORTD_PIN3_DIR   OUTPUT
#define PORTD_PIN4_DIR   OUTPUT
#define PORTD_PIN5_DIR   OUTPUT
#define PORTD_PIN6_DIR   OUTPUT
#define PORTD_PIN7_DIR   OUTPUT

/************************************************************************************************************************************************/

/******************************************************** Initial Value Configuration ***********************************************************/

/*
 * Configure the initial value for each pin based on its direction.
 *
 * In case of input direction, options:
 * - FLOATING
 * - PULLED_UP
 *
 * In case of output direction, options:
 * - HIGH
 * - LOW
 */

#define PORTA_PIN0_INIT_VAL   HIGH
#define PORTA_PIN1_INIT_VAL   HIGH
#define PORTA_PIN2_INIT_VAL   HIGH
#define PORTA_PIN3_INIT_VAL   HIGH
#define PORTA_PIN4_INIT_VAL   HIGH
#define PORTA_PIN5_INIT_VAL   HIGH
#define PORTA_PIN6_INIT_VAL   HIGH
#define PORTA_PIN7_INIT_VAL   HIGH

#define PORTB_PIN0_INIT_VAL   HIGH
#define PORTB_PIN1_INIT_VAL   HIGH
#define PORTB_PIN2_INIT_VAL   HIGH
#define PORTB_PIN3_INIT_VAL   HIGH
#define PORTB_PIN4_INIT_VAL   HIGH
#define PORTB_PIN5_INIT_VAL   HIGH
#define PORTB_PIN6_INIT_VAL   HIGH
#define PORTB_PIN7_INIT_VAL   HIGH

#define PORTC_PIN0_INIT_VAL   PULLED_UP
#define PORTC_PIN1_INIT_VAL   PULLED_UP
#define PORTC_PIN2_INIT_VAL   PULLED_UP
#define PORTC_PIN3_INIT_VAL   PULLED_UP
#define PORTC_PIN4_INIT_VAL   PULLED_UP
#define PORTC_PIN5_INIT_VAL   PULLED_UP
#define PORTC_PIN6_INIT_VAL   PULLED_UP
#define PORTC_PIN7_INIT_VAL   PULLED_UP

#define PORTD_PIN0_INIT_VAL   HIGH
#define PORTD_PIN1_INIT_VAL   HIGH
#define PORTD_PIN2_INIT_VAL   HIGH
#define PORTD_PIN3_INIT_VAL   HIGH
#define PORTD_PIN4_INIT_VAL   HIGH
#define PORTD_PIN5_INIT_VAL   HIGH
#define PORTD_PIN6_INIT_VAL   HIGH
#define PORTD_PIN7_INIT_VAL   HIGH

/************************************************************************************************************************************************/

#endif /* PORT_CONFIG_H_ */
