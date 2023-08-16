/*
 * TIMER1_Interface.h
 *
 *  Created on: Mar 24, 2023
 *      Author: aaa
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


void TIMER1_Init_NormalMode();
void TIMER1_Start();
void TIMER1_SetTime(u32 Disered_Time);
void TIMER0_CallBack(void(*PF)(void));

//PWM-Type / PWM-Mode
void PWM1_Init();

//set CTC register
void PWM1_SetDutyCycle(f32 DutyCycle);


void PWM1_SetFrequency(u8 Freq);

//set prescalar
void PWM1_Start();

//clear prescalar
void PWM1_Stop();


#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
