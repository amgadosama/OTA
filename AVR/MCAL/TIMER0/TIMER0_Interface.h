/*
 * TIMER0_Interface.h
 *
 *  Created on: Mar 17, 2023
 *      Author: aaa
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


enum TIMER0_PRESCALARS
{
	PRESCALAR_1 = 1,
	PRESCALAR_8,
	PRESCALAR_64,
	PRESCALAR_256,
	PRESCALAR_1024
};

enum TIMER0_OC0_Pin_Values
{
	Clear,
	Set,
	Toggle
};
void TIMER0_Init(void);

void TIMER0_SetTime(u32 Disered_Time);

void TIMER0_CallBack(void(*PF)(void));

void TIMER0_Start(u16 Prescalar);// change to void

void TIMER0_Stop();

void TIMER0_Set_OC0_Pin(u8 Pin_Value);

void TIMER0_Set_CTC(u8 CTC_Value);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
