/*
 * ICU.c
 *
 *  Created on: Mar 25, 2023
 *      Author: aaa
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include"../../MCAL/TIMER1/TIMER1_Registers.h"
#include "ICU_Interface.h"
#include "ICU_Regiters.h"
#include "ICU_Config.h"
#include "../GI/GI_Interface.h"

u16 period_ticks = 0;
u16 C2_ticks = 0;
u16 C3_Ticks = 0;
u16 TON = 0;
u16 C4_Ticks = 0;
u16 TOFF = 0;

u8 c=0;
void ICU_Init()
{
	//set trigger to rising edge
	SET_BIT(TCCR1B_REG,6);
	//Enable ICU Interrupt
	SET_BIT(TIMSK_REG,5);
	//Enable Global Interrupt
	GI_Enable();

	//start timer
	CLR_BIT(TCCR1B_REG,0);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);
}

void ICU_SetTrigger(u8 TriggerType)
{
	switch(TriggerType)
	{
	case RISING_EDGE:SET_BIT(TCCR1B_REG,6);break;
	case FALLING_EDGE:CLR_BIT(TCCR1B_REG,6);break;
	default:break;
	}
}

void ICU_DisplayPWM(u8 * freq,u8 * DutyCycle)
{
	u16 period = period_ticks*(TIMER1_PRESCALAR/TIMER1_CLK);
	*freq = (1/period)*100;
	*DutyCycle = (TON/period_ticks)*1000;
}

u16 ICU_GetValue()
{
	return ICR1_REG;
}


void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	static u8 counter = 0;
	if(counter == 0)
	{
		counter++;
	}
	else if(counter == 1)
	{
		period_ticks = ICU_GetValue();
		counter++;
	}
	else if(counter == 2)
	{
		C2_ticks = ICU_GetValue();
		ICU_SetTrigger(FALLING_EDGE);
		counter++;
	}
	else if(counter == 3)
	{
		C3_Ticks = ICU_GetValue();
		TON = C3_Ticks - C2_ticks;
		ICU_SetTrigger(RISING_EDGE);
		counter++;
	}
	else if(counter == 4)
	{
		C4_Ticks = ICU_GetValue();
		TOFF = C3_Ticks-C4_Ticks  ;
    counter=0;
	}

}
//void __vector_6 (void) __attribute__((signal));
//void __vector_6 (void)
//{
// u8 flag=0;
//if(flag==0)
//	{
//
//	ICU_SetTrigger(FALLING_EDGE);
//	TON=ICU_GetValue();
//	if(TON==65535)
//	{
//		c++;
//	}
//	flag=1;
//	}
//else if(flag==1)
//{
//	TON=ICU_GetValue();
//	ICU_SetTrigger(RISING_EDGE);
//	flag=0;
//}
//
//}
