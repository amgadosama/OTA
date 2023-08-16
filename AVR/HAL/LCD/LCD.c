/*
 * LCD.c
 *
 *  Created on: Feb 18, 2023
 *      Author: amres
 */

#include"config.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"../../STD_LIB/STD_TYPES.h"
#include<avr/delay.h>
#include"LCD_Interface.h"
void LCD_Instruction(u8 inst)
{
	DIO_SetPinValue(Control_Port,RS,LOW);

	DIO_SetPinValue(Control_Port,RW,LOW);

    DIO_SetPortValue(Data_PORT,inst);// YOU FORGET THIS LINE AND ENQUIRE ABOUT THE POSITION OF (inst)

	DIO_SetPinValue(Control_Port,E,HIGH);
	_delay_ms(5);
	DIO_SetPinValue(Control_Port,E,LOW);
	_delay_ms(5);

}
void LCD_INIT()
{
	_delay_ms(35);
	LCD_Instruction(Funtion_Set);
	_delay_ms(1);
	LCD_Instruction(Display_ONOFF);
	_delay_ms(1);
	LCD_Instruction(Clear_Display);
	_delay_ms(2);
	LCD_Instruction(Entry_Mode);
	_delay_ms(1);


}
void LCD_Displaychar(u8 data)
{
	DIO_SetPinValue(Control_Port,RS,HIGH);//Remember you must set RS To high to write on LCD
	DIO_SetPinValue(Control_Port,RW,LOW);

	DIO_SetPortValue(Data_PORT,data);
	DIO_SetPinValue(Control_Port,E,HIGH);
		_delay_ms(5);
		DIO_SetPinValue(Control_Port,E,LOW);
		_delay_ms(5);
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
		_delay_ms(5);
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
	_delay_ms(5);
	top--;
}
}
void LCD_Write_FLOAT_NUMBER(f64 num)//12.3566
{

 u32 w=num;//w=12
 LCD_WriteNUMBER(w);
 LCD_Displaychar('.');
 f32 y;
 y=num-w;//0.3566 //error here

 s32 f;
 while(y!=((u32)y))
 {
	 y=y*10;
	 f=y;
 }
 LCD_WriteNUMBER(f);

/* while(yy!=0)
 {

	 y=y*z;//3.566,5.66,6.6,6
     f=y;//f=3 ,5,6,6
     LCD_WriteNUMBER(f);
   yy=y-f; //yy=0.566,0.6
    y=yy;// y=0.566,0.66,0.6


	 u32 p=y;
	 f32 ww=y-p;
	 if(num>y)
	 {
		 z*=10;
	 }*/
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









