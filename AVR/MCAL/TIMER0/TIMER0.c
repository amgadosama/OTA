/*
 * TIMER0.c
 *
 *  Created on: Mar 17, 2023
 *      Author: aaa
 */


#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "../GI/GI_Interface.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Registers.h"
#include "TIMER0_Config.h"

u32 TIMER0_Num_Of_OVF = 0;
u32 TIMER0_PreLoad_Value = 0;
void(*TIMER0_CALL_BACK_PF)(void);
void TIMER0_Init(void)
{
	//select Timer Mode (Normal / CTC / Phase corect PWM / Fast PWM)
#if TIMER0_MODE == NORMAL_MODE
	CLR_BIT(TCCR0_REG,3);
	CLR_BIT(TCCR0_REG,6);
#elif TIMER0_MODE == CTC_MODE
	CLR_BIT(TCCR0_REG,3);
	SET_BIT(TCCR0_REG,6);
#endif

#if TIMER0_MODE == NORMAL_MODE
	//enable TIMER Interrupt for OVF
	SET_BIT(TIMSK_REG,0);
#elif TIMER0_MODE == CTC_MODE
	SET_BIT(TIMSK_REG,1);
#endif
	//enable Global Interrupt
	GI_Enable();
}


void TIMER0_Start(u16 Prescalar)
{
	switch(Prescalar)
	{
	case PRESCALAR_1:SET_BIT(TCCR0_REG,0);CLR_BIT(TCCR0_REG,1);CLR_BIT(TCCR0_REG,2);break;
	case PRESCALAR_8:CLR_BIT(TCCR0_REG,0);SET_BIT(TCCR0_REG,1);CLR_BIT(TCCR0_REG,2);break;
	case PRESCALAR_64:SET_BIT(TCCR0_REG,0);SET_BIT(TCCR0_REG,1);CLR_BIT(TCCR0_REG,2);break;
	case PRESCALAR_256:CLR_BIT(TCCR0_REG,0);CLR_BIT(TCCR0_REG,1);SET_BIT(TCCR0_REG,2);break;
	case PRESCALAR_1024:SET_BIT(TCCR0_REG,0);CLR_BIT(TCCR0_REG,1);SET_BIT(TCCR0_REG,2);break;
	default:CLR_BIT(TCCR0_REG,0);CLR_BIT(TCCR0_REG,1);CLR_BIT(TCCR0_REG,2);break;
	}
}

void TIMER0_Stop()
{
	CLR_BIT(TCCR0_REG,0);
	CLR_BIT(TCCR0_REG,1);
	CLR_BIT(TCCR0_REG,2);
}

//Disered Time in ms.
void TIMER0_SetTime(u32 Disered_Time)
{
	//ms to micro-sec
	Disered_Time *= 1000;
	//TIMER Freq
	f32 TIMER0_FREQ = (f32)TIMER0_CLK/TIMER0_PRESCALAR;
	//Tick Time
	f32 TIMER0_TICK_TIME = 1/TIMER0_FREQ;
#if TIMER0_MODE == NORMAL_MODE
	//Number of Ticks
	u32 NUM_Of_Ticks = TIMER0_RESLOUTION;
	//OverFlow Time
	f64 TIMER0_OVF_TIME = TIMER0_TICK_TIME * NUM_Of_Ticks;
	//Number of OverFlows
	TIMER0_Num_Of_OVF = (Disered_Time)/TIMER0_OVF_TIME;
	//Pre-load Value
	if(Disered_Time % (u32)TIMER0_OVF_TIME != 0)
	{
		//f32 Remider = ((f64)(Disered_Time/TIMER0_OVF_TIME)) - ((u32)(Disered_Time/TIMER0_OVF_TIME));
		f32 Remider = (Disered_Time % (u32)TIMER0_OVF_TIME)/TIMER0_OVF_TIME;
		TIMER0_PreLoad_Value = TIMER0_RESLOUTION - (TIMER0_RESLOUTION*Remider);
		TCNT0_REG = TIMER0_PreLoad_Value;
		TIMER0_Num_Of_OVF++;
	}
#elif TIMER0_MODE == CTC_MODE
	//load CTC Value to OCR0 Register
	u8 TIMER0_CTC_VALUE = 255;
	//Number of Ticks
	u32 NUM_Of_Ticks = TIMER0_CTC_VALUE;
	//OverFlow Time
	f64 TIMER0_OVF_TIME = TIMER0_TICK_TIME * NUM_Of_Ticks;
	//Number of OverFlows
	TIMER0_Num_Of_OVF = (Disered_Time)/TIMER0_OVF_TIME;
	//customize for CTC Value
	while(Disered_Time % (u32)TIMER0_OVF_TIME != 0)
	{
		TIMER0_CTC_VALUE--;
		//Number of Ticks
		NUM_Of_Ticks = TIMER0_CTC_VALUE;
		//OverFlow Time
		TIMER0_OVF_TIME = TIMER0_TICK_TIME * NUM_Of_Ticks;
		//Number of OverFlows
		TIMER0_Num_Of_OVF = (Disered_Time)/TIMER0_OVF_TIME;
	}
	OCR0_REG = TIMER0_CTC_VALUE;

#endif
}


void TIMER0_CallBack(void(*PF)(void))
{
	TIMER0_CALL_BACK_PF = PF;
}


void TIMER0_Set_OC0_Pin(u8 Pin_Value)
{
	switch(Pin_Value)
	{
	case Toggle:CLR_BIT(TCCR0_REG,4);SET_BIT(TCCR0_REG,5);break;
	case Set:SET_BIT(TCCR0_REG,4);SET_BIT(TCCR0_REG,5);break;
	case Clear:SET_BIT(TCCR0_REG,4);CLR_BIT(TCCR0_REG,5);break;
	default:CLR_BIT(TCCR0_REG,4);CLR_BIT(TCCR0_REG,5);break;
	}
}

void TIMER0_Set_CTC(u8 CTC_Value)
{
	OCR0_REG = CTC_Value;
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	//DIO_SetPinValue(PORTA,PIN0,HIGH);
	static u32 counter = 0;
	counter++;
	if(counter == TIMER0_Num_Of_OVF)
	{
		//action
		TIMER0_CALL_BACK_PF();
		counter = 0;
		TCNT0_REG = TIMER0_PreLoad_Value;
	}
}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	//DIO_SetPinValue(PORTA,PIN0,HIGH);
	static u32 counter = 0;
	counter++;
	if(counter == TIMER0_Num_Of_OVF)
	{
		//action
		TIMER0_CALL_BACK_PF();
		counter = 0;
		//TCNT0_REG = TIMER0_PreLoad_Value;
	}
}
