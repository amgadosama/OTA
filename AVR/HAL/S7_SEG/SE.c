/*
 * SE.c
 *
 *  Created on: Feb 13, 2023
 *      Author: amres
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Registers.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "SE.h"
#include<avr/delay.h>
#define Zero		0b0111111
#define One			0b0000110
#define Two			0b1011011
#define Three		0b1001111
#define Four		0b1100110
#define Five		0b1101101
#define Six			0b1111101
#define Seven		0b0000111
#define Eight		0b1111111
#define Nine		0b1101111
void SEV_SEG_INIT(u8 PORT_ID)
{
  switch(PORT_ID)
  {
  case DIO_PORTA: DIO_SetPortDirection(DDRA_REG,OUTPUT);break;
  case DIO_PORTB: DIO_SetPortDirection(DDRB_REG,OUTPUT);break;
  case DIO_PORTC: DIO_SetPortDirection(DDRC_REG,OUTPUT);break;
  case DIO_PORTD: DIO_SetPortDirection(DDRD_REG,OUTPUT);break;
  }
}
void SEV_COUNT_UP(u8 ns,u8 nf,u8 Port_ID,u16 delay)
{
	if(ns>=0 && nf<=9)
	{
		for(u8 i=ns;i<=nf;i++)
		{
			switch(i)
			{
			            case 0:DIO_SetPortValue(Port_ID,Zero);break;
						case 1:DIO_SetPortValue(Port_ID,One);break;
						case 2:DIO_SetPortValue(Port_ID,Two);break;
						case 3:DIO_SetPortValue(Port_ID,Three);break;
						case 4:DIO_SetPortValue(Port_ID,Four);break;
						case 5:DIO_SetPortValue(Port_ID,Five);break;
						case 6:DIO_SetPortValue(Port_ID,Six);break;
						case 7:DIO_SetPortValue(Port_ID,Seven);break;
						case 8:DIO_SetPortValue(Port_ID,Eight);break;
						case 9:DIO_SetPortValue(Port_ID,Nine);break;
			}
			_delay_ms(delay);
		}
	}

}
void SEV_COUNT_DOWN(u8 ns,u8 nf,u8 Port_ID,u16 delay)
{
	if(ns>=0 && nf<=9)
	{
		for(u8 i=nf;i>=ns;i--)
		{
			switch(i)
			{
			 	 	    case 0:DIO_SetPortValue(Port_ID,Zero);break;
						case 1:DIO_SetPortValue(Port_ID,One);break;
						case 2:DIO_SetPortValue(Port_ID,Two);break;
						case 3:DIO_SetPortValue(Port_ID,Three);break;
						case 4:DIO_SetPortValue(Port_ID,Four);break;
						case 5:DIO_SetPortValue(Port_ID,Five);break;
						case 6:DIO_SetPortValue(Port_ID,Six);break;
						case 7:DIO_SetPortValue(Port_ID,Seven);break;
						case 8:DIO_SetPortValue(Port_ID,Eight);break;
						case 9:DIO_SetPortValue(Port_ID,Nine);break;
			}
			_delay_ms(delay);
		}
	}

}
void disp_number(u8 number,u8 Port_ID)
{
	if(number>=0 && number<=9)

	{
		   switch(number)
				{
				 	 	    case 0:DIO_SetPortValue(Port_ID,Zero); break;
							case 1:DIO_SetPortValue(Port_ID,One);  break;
							case 2:DIO_SetPortValue(Port_ID,Two);  break;
							case 3:DIO_SetPortValue(Port_ID,Three);break;
							case 4:DIO_SetPortValue(Port_ID,Four); break;
							case 5:DIO_SetPortValue(Port_ID,Five); break;
							case 6:DIO_SetPortValue(Port_ID,Six);  break;
							case 7:DIO_SetPortValue(Port_ID,Seven);break;
							case 8:DIO_SetPortValue(Port_ID,Eight);break;
							case 9:DIO_SetPortValue(Port_ID,Nine); break;
				}

			}

}
void clr_port(u8 port_id)
{
	switch(port_id)
	  {
	  case DIO_PORTA: DIO_TogglePort(PORTA_REG);break;
	  case DIO_PORTB: DIO_TogglePort(PORTB_REG);break;
	  case DIO_PORTC: DIO_TogglePort(PORTC_REG);break;
	  case DIO_PORTD: DIO_TogglePort(PORTD_REG);break;
	  }

}
