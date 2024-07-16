# Microcontroller-Based-Calculator
### Project Description

This project is a simple calculator implemented on an 8-bit microcontroller. It can perform basic arithmetic operations (addition, subtraction, multiplication, and division) with user inputs through a keypad, and displays the results on a character LCD (CLCD). The project uses a layered architecture with distinct responsibilities assigned to the Application (APP), Hardware Abstraction Layer (HAL), and Microcontroller Abstraction Layer (MCAL).

### Layer Components

#### Application Layer (APP): Calculator
- **Main Function**: 
  - Initializes ports and CLCD.
  - Continuously processes keypad input.
- **Functions**:
  - `processInput(uint8 key)`: Handles and categorizes input (numbers, operators, commands).
  - `calculateResult()`: Executes arithmetic operations based on user input.
  - `clearCalculator()`: Resets all variables and clears the display.
  - `displayError(const char *errorMessage)`: Displays error messages on CLCD.

#### Hardware Abstraction Layer (HAL): CLCD, Keypad
- **CLCD**:
  - `CLCD_voidInit()`: Initializes the CLCD.
  - `CLCD_voidSendData(uint8 data)`: Sends data (characters) to the CLCD.
  - `CLCD_voidSendFloat(f64 number)`: Displays floating-point numbers.
  - `CLCD_u8ClearDisplay()`: Clears the CLCD display.
  - `CLCD_voidGoToXY(uint8 x, uint8 y)`: Sets the cursor position on the CLCD.

- **Keypad**:
  - `Keypad_u8GetPressedKey()`: Detects and returns the key pressed by the user.

#### Microcontroller Abstraction Layer (MCAL): PORT, DIO
- **PORT**:
  - `PORT_voidInit()`: Configures microcontroller ports for connected peripherals.
  
- **DIO (Digital Input/Output)**:
  - Handles low-level digital input and output operations for port configurations and data handling.

### Project Flow

1. **Initialization**: 
   - Set up the microcontroller ports and CLCD.
   
2. **Main Loop**: 
   - Continuously check for keypad input.
   - Process inputs to build operands and identify operators.

3. **Input Handling**:
   - Append numbers and handle decimal points to form operands.
   - Identify operators to separate first and second operands.
   - Calculate results when the equal sign is pressed.

4. **Calculation**:
   - Execute the appropriate arithmetic operation.
   - Display the result on the CLCD.

5. **Error Handling**:
   - Display error messages (e.g., division by zero).
   - Reset the calculator after showing an error.

This organization ensures modularity, making the system easy to manage, extend, and debug.
