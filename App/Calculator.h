#ifndef CALCULATOR_H
#define CALCULATOR_H

void processInput(uint8 key);
void calculateResult(void);
void clearCalculator(void);
void displayError(const char *errorMessage);

#endif // CALCULATOR_H
