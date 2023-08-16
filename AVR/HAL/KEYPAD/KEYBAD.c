/*
 * KEYBAD.c
 *
 *  Created on: Feb 20, 2023
 *      Author: amres
 */

#include"KEYBAD_Config.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"../../STD_LIB/STD_TYPES.h"
#include"KEYBAD_Interface.h"
#include<avr/delay.h>
u8 SwitchValue[4][4]={{'7','8','9','/'},
		              {'4','5','6','*'},
                      {'1','2','3','-'},
                      {'o','0','=','+'},
                     };
void KEYPAD_INIT()
{
	DIO_SetPortDirection(KEYPAD_PORT,0xf0);
    DIO_SetPortValue(KEYPAD_PORT,0xff);
}


u8 KEYPAD_GetPressed()
{
  u8 KeyPressed='a';
  u8 GetPinReading;
   for(u8 i=C1;i<=C4;i++)
   {
     DIO_SetPinValue(KEYPAD_PORT,i,LOW);
     for(u8 j=R1;j<=R4;j++)
     {   DIO_ReadPin(KEYPAD_PORT,j,&GetPinReading);
    	 if(GetPinReading==LOW)
    	 {
    		 KeyPressed=SwitchValue[j][i-C1];
            _delay_ms(20);
            while(GetPinReading==LOW)
            {
            	DIO_ReadPin(KEYPAD_PORT,j,&GetPinReading);

            }

    	 }
     }
     DIO_SetPinValue(KEYPAD_PORT,i,HIGH);

   }
   return KeyPressed;
}
