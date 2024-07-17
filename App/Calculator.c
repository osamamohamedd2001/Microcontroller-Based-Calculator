##include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_TYPES.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

#include "CLCD_interface.h"
#include "Keypad_interface.h"

#include <util/delay.h>

// Global Variables
static f64 firstOperand = 0;
static f64 secondOperand = 0;
static uint8 operator = 0;
static f64 result = 0;
static uint8 isFirstOperandComplete = 0;
static uint8 isOperatorComplete = 0;
static uint8 decimalPointFlag = 0;
static f64 decimalFactor = 1;
static uint8 errorFlag = 0;
static uint8 resultDisplayed = 0;
void processInput(uint8 key)
{
	if((key >= '0' && key <= '9') || key == '.') // Check if the key is a number or decimal point
	{
		if(resultDisplayed) // If result was just displayed, clear and start new input
		{
			clearCalculator();
		}
		if(key == '.')
		{
			decimalPointFlag = 1;
			CLCD_voidSendData(key);
		}
		else
		{
			if(!isFirstOperandComplete)
			{
				// Build the first operand
				if(decimalPointFlag)
				{
					decimalFactor /= 10;
					firstOperand += (key - '0') * decimalFactor;
				}
				else
				{
					firstOperand = firstOperand * 10 + (key - '0');
				}
				CLCD_voidSendData(key);
			}
			else
			{
				// Build the second operand
				if(decimalPointFlag)
				{
					decimalFactor /= 10;
					secondOperand += (key - '0') * decimalFactor;
				}
				else
				{
					secondOperand = secondOperand * 10 + (key - '0');
				}
				CLCD_voidSendData(key);
			}
		}
	}
	else if(key == '+' || key == '-' || key == '*' || key == '/') // Check if the key is an operator
	{
		if(resultDisplayed) // If result was just displayed, use it as the first operand
		{
			firstOperand = result;
			secondOperand = 0;
			resultDisplayed = 0;
			isFirstOperandComplete = 1;
			isOperatorComplete = 0;
			decimalPointFlag = 0;
			decimalFactor = 1;
			CLCD_u8ClearDisplay();
			CLCD_voidSendFloat(firstOperand);
		}
		if(!isOperatorComplete)
		{
			operator = key;
			isFirstOperandComplete = 1;
			isOperatorComplete = 1;
			decimalPointFlag = 0;
			decimalFactor = 1;
			CLCD_voidSendData(key);
		}
	}
	else if(key == '=') // Perform calculation
	{
		calculateResult();
	}
	else if(key == 'C') // Clear the calculator
	{
		clearCalculator();
	}
}

void calculateResult(void)
{
	if(operator && isFirstOperandComplete && isOperatorComplete)
	{
		switch(operator)
		{
		case '+':
			result = firstOperand + secondOperand;
			// Display the result
			CLCD_voidGoToXY(0u, 1u); // Move to the second line
			CLCD_voidSendNumber((sint32)result);
			break;
		case '-':
			result = firstOperand - secondOperand;
			// Display the result
			CLCD_voidGoToXY(0u, 1u); // Move to the second line
			CLCD_voidSendNumber((sint32)result);
			break;
		case '*':
			result = firstOperand * secondOperand;
			// Display the result
			CLCD_voidGoToXY(0u, 1u); // Move to the second line
			CLCD_voidSendFloat(result);
			break;
		case '/':
			if(secondOperand != 0)
			{
				result = firstOperand / secondOperand;
				// Display the result
				CLCD_voidGoToXY(0u, 1u); // Move to the second line
				CLCD_voidSendFloat(result);
			}
			else
			{
				displayError("Division by zero!");
				return;
			}
			break;
		default:
			displayError("Invalid operation!");
			return;
		}



		// Set flag indicating the result is displayed
		resultDisplayed = 1;

		// Reset for next calculation
		isFirstOperandComplete = 0;
		isOperatorComplete = 0;
		errorFlag = 0;
		decimalPointFlag = 0;
		decimalFactor = 1;
	}
}

void clearCalculator(void)
{
	firstOperand = 0;
	secondOperand = 0;
	operator = 0;
	isFirstOperandComplete = 0;
	isOperatorComplete = 0;
	errorFlag = 0;
	resultDisplayed = 0;
	decimalPointFlag = 0;
	decimalFactor = 1;
	CLCD_u8ClearDisplay();
}

void displayError(const char *errorMessage)
{
	CLCD_u8ClearDisplay();
	CLCD_u8SendString(errorMessage);
	_delay_ms(2000); // Display the error message for 2 seconds
	clearCalculator();
}
