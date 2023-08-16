/*
 * STP.c
 *
 *  Created on: Jun 19, 2023
 *      Author: amres
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include "GPIO_Interface.h"
#include"STK_Interface.h"
#include"STP_Interface.h"
#include"STP_Private.h"
#include"STP_Config.h"




void STP_voidInit()
{
    /*Configure Pins A0, A1, A2 as O/P PP LS Pins*/


    /*Configure Pins A0, A1, A2 as O/P PP LS Pins*/
	GPIO_voidSetPinMode(STP_SERIAL_PIN,OUTPUT);
	GPIO_voidSetPinSpeed(STP_SERIAL_PIN, OUTPUT_LS);
	GPIO_voidSetPinType(STP_SERIAL_PIN, OUTPUT_PP);

	//ST_Pin
	GPIO_voidSetPinMode(STP_STORE_CLK_PIN ,OUTPUT);
	GPIO_voidSetPinSpeed(STP_STORE_CLK_PIN , OUTPUT_LS);
	GPIO_voidSetPinType(STP_STORE_CLK_PIN , OUTPUT_PP);

	//SH_Pin
	GPIO_voidSetPinMode(STP_SHIFT_CLK_PIN,OUTPUT);
	GPIO_voidSetPinSpeed(STP_SHIFT_CLK_PIN, OUTPUT_LS);
	GPIO_voidSetPinType(STP_SHIFT_CLK_PIN, OUTPUT_PP);
}

void STP_voidSendSynch(u8 Copy_u8Data)
{
	//Copy_u8Data ==> 8 bit ==> b7 b6    b0
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for(Local_s8Counter = 7; Local_s8Counter >= 0; Local_s8Counter--)
	{
		Local_u8Bit = 	GET_BIT(Copy_u8Data, Local_s8Counter);
		/*Send Data bit by bit*/
		GPIO_voidSetPinValue(STP_SERIAL_PIN, Local_u8Bit);
		/*Send Pulse on Shift Clk Pin*/
		GPIO_voidSetPinValue(STP_SHIFT_CLK_PIN, HIGH);
		MSTK_voidSetBusyWait(5);
		GPIO_voidSetPinValue(STP_SHIFT_CLK_PIN, LOW);
		MSTK_voidSetBusyWait(5);
	}
	/*Send Pulse on Store Clk Pin*/
	GPIO_voidSetPinValue(STP_STORE_CLK_PIN, HIGH);
	MSTK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(STP_STORE_CLK_PIN, LOW);
	MSTK_voidSetBusyWait(1);
}

void STP_voidSendData(u8 Send_Data)
{

	//Copy_u8Data ==> 8 bit ==> b7 b6    b0
		s8 Local_s8Counter;
		u8 Local_u8Bit;
		for(Local_s8Counter = 7; Local_s8Counter >= 0; Local_s8Counter--)
		{
			Local_u8Bit = 	GET_BIT(Send_Data, Local_s8Counter);
			/*Send Data bit by bit*/
			GPIO_voidSetPinValue(STP_SERIAL_PIN, Local_u8Bit);
			/*Send Pulse on Shift Clk Pin*/
			GPIO_voidSetPinValue(STP_SHIFT_CLK_PIN, PIN_SET);
			MSTK_voidSetBusyWait(1);
			GPIO_voidSetPinValue(STP_SHIFT_CLK_PIN, PIN_RST);
			MSTK_voidSetBusyWait(1);
		}
		/*Send Pulse on Store Clk Pin*/
		GPIO_voidSetPinValue(STP_STORE_CLK_PIN, PIN_SET);
		MSTK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(STP_STORE_CLK_PIN, PIN_RST);
		MSTK_voidSetBusyWait(1);
	}


