/*
 * Keypad_progrm.c
 *
 *  Created on: Jul 16, 2024
 *      Author: Osama
 */

#include "STD_TYPES.h"
#include "ERROR_TYPES.h"

#include "DIO_interface.h"

#include "Keypad_interface.h"
#include "Keypad_config.h"
#include "Keypad_private.h"

/*
 * Function: Keypad_u8GetPressedKey
 * ----------------------------
 *   Scans the keypad and returns the value of the pressed key, if any.
 *
 *   returns: the value of the pressed key or NO_KEY if no key is pressed.
 */
uint8 Keypad_u8GetPressedKey(void)
{
	uint8 Local_u8KeyState;
	uint8 Local_u8ColIndex, Local_u8RowIndex;

	/* Arrays to hold the column and row pin numbers */
	const uint8 Local_au8ColArray[COL_NUM] = {KEYPAD_u8COL1_PIN, KEYPAD_u8COL2_PIN, KEYPAD_u8COL3_PIN, KEYPAD_u8COL4_PIN};
	const uint8 Local_au8RowArray[ROW_NUM] = {KEYPAD_u8ROW1_PIN, KEYPAD_u8ROW2_PIN, KEYPAD_u8ROW3_PIN, KEYPAD_u8ROW4_PIN};

	/* 2D array to map the keys based on their row and column indices */
	const uint8 Local_u8ButtonArray[ROW_NUM][COL_NUM] = KEYPAD_au8_BUTTON_ARRAY;

	/* Iterate through each column */
	for(Local_u8ColIndex = 0u; Local_u8ColIndex < COL_NUM; Local_u8ColIndex++)
	{
		/* Set the current column to LOW */
		DIO_u8SetPinValue(KEYPAD_u8COL_PORT, Local_au8ColArray[Local_u8ColIndex], DIO_u8PIN_LOW);

		/* Check each row for a pressed key */
		for(Local_u8RowIndex = 0u; Local_u8RowIndex < ROW_NUM; Local_u8RowIndex++)
		{
			DIO_u8ReadPinValue(KEYPAD_u8ROW_PORT, Local_au8RowArray[Local_u8RowIndex], &Local_u8KeyState);

			/* If a key is pressed (row pin is LOW) */
			if(Local_u8KeyState == DIO_u8PIN_LOW)
			{
				/* Debounce: Wait for the key to be released */
				while(Local_u8KeyState == DIO_u8PIN_LOW)
				{
					DIO_u8ReadPinValue(KEYPAD_u8ROW_PORT, Local_au8RowArray[Local_u8RowIndex], &Local_u8KeyState);
				}

				/* Restore the current column to HIGH */
				DIO_u8SetPinValue(KEYPAD_u8COL_PORT, Local_au8ColArray[Local_u8ColIndex], DIO_u8PIN_HIGH);

				/* Return the corresponding key value */
				return Local_u8ButtonArray[Local_u8RowIndex][Local_u8ColIndex];
			}
		}

		/* Restore the current column to HIGH */
		DIO_u8SetPinValue(KEYPAD_u8COL_PORT, Local_au8ColArray[Local_u8ColIndex], DIO_u8PIN_HIGH);
	}

	/* Return NO_KEY if no key is pressed */
	return NO_KEY;
}
