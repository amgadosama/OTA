/*
 * LCD_Interface.h
 *
 *  Created on: Feb 18, 2023
 *      Author: amres
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include"../../STD_LIB/STD_TYPES.h"

#define Clear_Display    0b00000001//0x01
#define Return_Home      0b00000010
#define Entry_Mode       0b00000110 //try 0b00000101
#define Funtion_Set      0b00111000		//try 0b00111000
#define Display_ONOFF    0b00001111
#define First_Line       128 // 1xxxxxxx 2->power(7)
#define DDRAM       128 // 1xxxxxxx 2->power(7)
#define Second_Line      191 // 11xxxxxx 2->power(7)+2->power(6)
#define Go_ToCGRAM       64 //01xxxxxx 2->power(7)



void LCD_Instruction(u8 inst);
void LCD_INIT();
void LCD_Displaychar(u8 data);
void LCD_DisplayString(u8 *string);
void LCD_GoTo(u8 x,u8 y);

void LCD_WriteCustomChar(u8 *CustomArray);
void LCD_WriteNUMBER(u16 num);
void LCD_Write_FLOAT_NUMBER(f64 num);
void LCD_WriteIntNumber_s(f64 number);
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
