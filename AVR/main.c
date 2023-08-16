/*
 * main.c
 *
 *  Created on: Feb 10, 2023
 *      Author: aaa
 */
#include "STD_LIB/STD_TYPES.h"
#include "STD_LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include"HAL/KEYPAD/KEYBAD_Interface.h"
#include"MCAL/GI/GI_Interface.h"
#include <util/delay.h>
#include"HAL/Stepper_MOTOR/Stepper_Interface.h"
#include"HAL/Stepper_MOTOR/Stepper_Config.h"
#include"MCAL/ADC/ADC_interface.h"
#include"MCAL/EXT_INT/EXT_INT_Interface.h"
#include "MCAL/TIMER0/TIMER0_Interface.h"
#include"HAL/BUZZER/BUZZER_Interface.h"
#include"HAL/LDR/LDR_interface.h"
#include "MCAL/TIMER1/TIMER1_Interface.h"
#include"MCAL/WDT/WDT_interface.h"
#include"MCAL/TIMER0/TIMER0_Registers.h"
#include"MCAL/TIMER1/TIMER1_Registers.h"
#include "MCAL/ICU/ICU_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/TWI/TWI_Interface.h"
#include "MCAL/TWI/TWI_Registers.h"
#include"HAL/SERVO_MOTOR/SERVO_Interface.h"
#include"HAL/EEPROM/EEPROM_Interface.h"


u32 amgad=1;
u32 fawzy=2;
u32 gmal=4;
u32 amr=3;
u8 get_start='a';
u8 checkPassword[16]={0};
#define Forward  0
#define reverse  1
#define motor_off  2
u32 Digit(u32 NumberofDigit,u8* Numbers);
void motor(u8 FR);
u32 password();
int main()
{
	u32 Passwordreturn2=0;
	u8 ID='a';
//////////////////////////////////////////////////////////////////////
	DIO_INIT();
	KEYPAD_INIT();
	UART_Init();
    LCD_INIT();

/*
 * Some things to Edit
 * ID of every person
 * ID:
 *Amgad ->1
 *fawzy->2
 *Gamal->3
 *Amr->4
 * */
    u8 Dc=0;
//////////////////////////////////////////////////////////////////////


			for(;;)
				{

					LCD_Instruction(Clear_Display);
					LCD_DisplayString((u8 *)"OFFLINE OFF :");
						while(get_start!='o')
						{
							Dc=UART_Recieve();
							get_start=KEYPAD_GetPressed();
							if(Dc=='1')
							{
								motor(Forward);
								_delay_ms(2000);
								motor(reverse);
								_delay_ms(2000);
								motor(motor_off);
							}
							if(get_start=='o')
							   {
								UART_Transimit_char('a');
							   }

						}
						LCD_Instruction(Clear_Display);
				LCD_DisplayString((u8 *)"1-Amgad 2-fawzy");
				LCD_GoTo(2,2);
				LCD_DisplayString((u8 *)"3-Amr 4-Mohamed");
				while(ID=='a'&&ID!='o')
				{/*1234->*/
					ID=KEYPAD_GetPressed();
				}

						if(ID=='1')
						{
							Passwordreturn2=password();
							if(Passwordreturn2==amgad)
							{
								LCD_Instruction(Clear_Display);
								LCD_DisplayString((u8 *)"Hello amgad");
								motor(Forward);
								UART_Transimit_char('1');
								_delay_ms(2000);
								motor(reverse);
								_delay_ms(2000);
								motor(motor_off);
								UART_Transimit_char('a');
								_delay_ms(2700);
								LCD_Instruction(Clear_Display);
							}
							else
							{
								LCD_Instruction(Clear_Display);
								LCD_GoTo(1,1);
								LCD_DisplayString((u8 *)"Wrong Password");
								UART_Transimit_char('a');
								_delay_ms(1000);
								LCD_Instruction(Clear_Display);
							}
						}
						else if(ID=='2')
						{
							Passwordreturn2=password();
							if(Passwordreturn2==fawzy)
							{
							LCD_Instruction(Clear_Display);
							LCD_DisplayString((u8 *)"Hello fawzy");
							UART_Transimit_char('2');
							_delay_ms(2000);
							motor(reverse);
							_delay_ms(2000);
							motor(motor_off);
							UART_Transimit_char('a');
							_delay_ms(2700);

							}
							else
							{
								LCD_Instruction(Clear_Display);
								LCD_GoTo(1,1);
								LCD_DisplayString((u8 *)"Wrong Password");
								UART_Transimit_char('a');
								_delay_ms(1000);
								LCD_Instruction(Clear_Display);
							}
						}

						else if(ID=='3')
						{
							Passwordreturn2=password();
							if(Passwordreturn2==amr)
							{
							LCD_Instruction(Clear_Display);
							LCD_DisplayString((u8 *)"Hello Amr");
							UART_Transimit_char('3');
							_delay_ms(2000);
							motor(reverse);
							_delay_ms(2000);
							motor(motor_off);
							UART_Transimit_char('a');
							_delay_ms(2700);
							}
							else
							{
								LCD_Instruction(Clear_Display);
								LCD_GoTo(1,1);
								LCD_DisplayString((u8 *)"Wrong Password");
								UART_Transimit_char('a');
								_delay_ms(1000);
								LCD_Instruction(Clear_Display);
							}
						}
						else if(ID=='4')
						{
							Passwordreturn2=password();
							if(Passwordreturn2==gmal)
							{
							LCD_Instruction(Clear_Display);
							LCD_DisplayString((u8 *)"Hello Mohamed");
							UART_Transimit_char('4');
							_delay_ms(2000);
							motor(reverse);
							_delay_ms(2000);
							motor(motor_off);
							UART_Transimit_char('a');
							_delay_ms(2700);
							}
							else
							{
								LCD_Instruction(Clear_Display);
								LCD_GoTo(1,1);
								LCD_DisplayString((u8 *)"Wrong Password");
								UART_Transimit_char('a');
								_delay_ms(1000);
								LCD_Instruction(Clear_Display);
							}
						}


ID='a';
get_start='a';

				}

}/*1234*/


u32 password()
{
	u8 x=0;
	u8 iteration=0;
	u8 Passwordreturn=0;
	LCD_Instruction(Clear_Display);
	LCD_DisplayString((u8 *)"Enter Password :");
	LCD_GoTo(1,2);

	while(x!='=')
	{/*1234->*/
		x=KEYPAD_GetPressed();
		if(x!='a'&&x!='=')
		{/*LCD_Displaychar('*');*/
		checkPassword[iteration]=x-48;
		LCD_WriteNUMBER(x-48);
		iteration++;}
	}
	Passwordreturn=Digit(iteration,checkPassword);
	return Passwordreturn;

}
u32 Digit(u32 NumberofDigit, u8* Numbers)
{
	u32 q = 1;
	u32 password = 0;
	                    //3
	for (u32 i = 0; i < NumberofDigit-1; i++)
	{
		q *= 10;
		//q=10,q=100,q=1000
	}
	//5123
	//1000       0,1,2,3 4
	for (u32 i = 0; i < NumberofDigit; i++)
	{
		password += q * Numbers[i];
		//5000+100+20+3
		q /= 10;//q=100
	}
	return password;
}
void motor(u8 FR)
{

	if(FR==0)
	{
		DIO_SetPinValue(DIO_PORTD,PIN2,HIGH);
		DIO_SetPinValue(DIO_PORTD,PIN3,LOW);
	}

	else if(FR==1)
	{
		DIO_SetPinValue(DIO_PORTD,PIN2,LOW);
		DIO_SetPinValue(DIO_PORTD,PIN3,HIGH);
	}
	else if(FR==2)
	{
		DIO_SetPinValue(DIO_PORTD,PIN2,LOW);
		DIO_SetPinValue(DIO_PORTD,PIN3,LOW);
	}
}
