#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

void CLCD_voidSendCmd(uint8 Copy_u8Cmd);

void CLCD_voidSendData(uint8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_u8ClearDisplay(void);

uint8 CLCD_u8SendString(const char* Copy_pchString);

void CLCD_voidSendNumber(sint32 Copy_s32Number);

void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos);

uint8 CLCD_u8SendSpecialCharacter(uint8 Copy_u8LocationNum, uint8* Copy_pu8Pattern, uint8 Copy_u8XPos, uint8 Copy_u8YPos);

void CLCD_voidSendFloat(f32 Copy_f32Number);

#endif
