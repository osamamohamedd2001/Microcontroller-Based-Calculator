/*
 * main.c
 *
 *  Created on: Jul 16, 2024
 *      Author: Osama
 */

#include "Calculator.h"


int main(void)
{
	PORT_voidInit();
	CLCD_voidInit();

	while(1)
	{
		key = Keypad_u8GetPressedKey();
		if(key != NO_KEY)
		{
			processInput(key);
		}
	}

	return 0;
}

