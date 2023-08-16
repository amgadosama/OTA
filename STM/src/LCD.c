/*
 * LCD.c
 *
 *  Created on: Jul 26, 2023
 *      Author: amres
 */


#include"STD_TYPES.h"
#include"LCD_Interface.h"
#include"LCD_Config.h"
#include"GPIO_Interface.h"
#include "STK_Interface.h"
static u8 flag=0;

void App_delayMs(u32 Copy_u32Delay);
void LCD_Instruction(u8 inst)

{
/************************************************************/
	if(flag==0)
	/*INIT for PINS AS OUTPUT*/
	{GPIO_voidSetPinMode(Control_Port,RS,OUTPUT);
	GPIO_voidSetPinType(Control_Port,RS,OUTPUT_PP);
	GPIO_voidSetPinSpeed(Control_Port,RS,OUTPUT_MS);



	GPIO_voidSetPinMode(Control_Port,RW,OUTPUT);
	GPIO_voidSetPinType(Control_Port,RW,OUTPUT_PP);
	GPIO_voidSetPinSpeed(Control_Port,RW,OUTPUT_MS);

	GPIO_voidSetPinMode(Control_Port,E,OUTPUT);
	GPIO_voidSetPinType(Control_Port,E,OUTPUT_PP);
	GPIO_voidSetPinSpeed(Control_Port,E,OUTPUT_MS);
	/******INIT FOR DATA_PORT******/
	for(int i=Data_PORT_Start;i<Data_PORT_END;i++)
	{
		GPIO_voidSetPinMode(Data_PORT,i,OUTPUT);
		GPIO_voidSetPinType(Data_PORT,i,OUTPUT_PP);
		GPIO_voidSetPinSpeed(Data_PORT,i,OUTPUT_MS);
	}
	flag=1;
	}
/*--------------------------------------------------------*/

	GPIO_voidSetPinValue(Control_Port, RS, PIN_RST);
	GPIO_voidSetPinValue(Control_Port,RW, PIN_RST);

	  GPIO_voidSetPortValue(Data_PORT,inst);
	GPIO_voidSetPinValue(Control_Port,E, PIN_SET);

	App_delayMs(50);

	GPIO_voidSetPinValue(Control_Port,E, PIN_RST);
	App_delayMs(50);

/***********************************************************/

}


void LCD_INIT()
{
	App_delayMs(350);
	LCD_Instruction(Funtion_Set);
	App_delayMs(10);
	LCD_Instruction(Display_ONOFF);
	App_delayMs(10);
	LCD_Instruction(Clear_Display);
	App_delayMs(20);
	LCD_Instruction(Entry_Mode);
	App_delayMs(10);


}

void LCD_Displaychar(u8 data)
{
	GPIO_voidSetPinValue(Control_Port,RS,PIN_SET);//Remember you must set RS To high to write on LCD
	GPIO_voidSetPinValue(Control_Port,RW,PIN_RST);
	GPIO_voidSetPortValue(Data_PORT,data);
	GPIO_voidSetPinValue(Control_Port,RS,PIN_SET);

	GPIO_voidSetPinValue(Control_Port,E, PIN_SET);
	App_delayMs(500);
	GPIO_voidSetPinValue(Control_Port,E, PIN_RST);
	App_delayMs(500);
}

void LCD_DisplayString(u8 *string)
{
	u8 iteration=0;
	while(string[iteration]!='\0')
	{
		LCD_Displaychar(string[iteration]);
		iteration++;
	}
}

void LCD_GoTo(u8 x,u8 y)
{
	if(x>=0 && x<16)
	{
		switch(y)
		{
		case 1:
			LCD_Instruction(First_Line+x);break;
		case 2:
					LCD_Instruction(Second_Line+x);break;
		}
	}

}

void LCD_WriteCustomChar(u8 *CustomArray)//not working
{
	LCD_Instruction(Go_ToCGRAM);
	for(u8 i=0;i<16;i++)
	{
		LCD_Displaychar(CustomArray[i]);
	}
	LCD_Instruction(DDRAM);
	for(u8 i=0;i<8;i++)
		{
		LCD_Displaychar(i); //we use (i) because we save data in DDRAM so we need to access location
		App_delayMs(20000);
		}
}

void LCD_WriteNUMBER(u16 num)
{
 s16 top=-1;
 u8 w;
u8 d[10];
if(num<0)
{
	LCD_Displaychar('-');
	num=num*-1;
}
 while(num>0)
 {
	 top++;
	w=num%10;
	d[top]=w;
	num=num/10;
 }

while(top>=0)
{
	LCD_Displaychar(48+d[top]);
	App_delayMs(50);
	top--;
}
}
void LCD_WriteIntNumber_s(f64 number)
{
	s8 i=0,j=0;
	u32 x=number;
	u8 base_NUM[10]={0};
	f64 y=0;
	if (number<0)
	{
		number*=-1;
		x=number;
		LCD_Displaychar('-');
	}
	y=(((number+1.0)-x)*10000000);
	while(x !=0)
	{
		base_NUM[i++] = x % 10;
		x/=10;
	}
	u8 k=i--;
	while(i>=0)
	{
		LCD_Displaychar(base_NUM[i--]+48);
	}
	u8 F_NUM[10]={0};
	i=0;
	u32 z=y;
	LCD_Displaychar('.');
	while(z !=0)
	{
		F_NUM[i++] = z % 10;
		z/=10;
	}
	i-=2;
	for(j=0;j<10;j++)
	{
		if(F_NUM[j]==0)
		{
			F_NUM[j]='k';
		}
		else
		{
			break;
		}
	}
	while(F_NUM[i]!='k'&& k!=7)
	{
		LCD_Displaychar(F_NUM[i--]+48);
		k++;
	}

}



































void App_delayMs(u32 Copy_u32Delay)
{
	for(u32 Local_u32Counter = 0; Local_u32Counter < Copy_u32Delay*300; Local_u32Counter++)
	{
		asm("NOP");
	}
}
