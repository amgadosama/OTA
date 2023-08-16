/*
 * TIMER1.c
 *
 *  Created on: Mar 24, 2023
 *      Author: aaa
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"

#include "../TIMER1/TIMER1_Config.h"
#include "../TIMER1/TIMER1_Interface.h"
#include "../TIMER1/TIMER1_Registers.h"
void TIMER1_Init_NormalMode()
{
	CLR_BIT(TCCR1A_REG,7);
	CLR_BIT(TCCR1A_REG,6);
	//enable interrupt
	SET_BIT(TIMSK_REG,2);

}
void TIMER1_Start()
{
	//prescalar_8
	CLR_BIT(TCCR1B_REG,0);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);

}
void PWM1_Init()
{
#if PWM1_MODE == FAST_PWM_MODE
	CLR_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1B_REG,3);
	SET_BIT(TCCR1B_REG,4);
#elif PWM1_MODE == PHASE_CORRECT_PWM_MODE
	CLR_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1A_REG,1);
	CLR_BIT(TCCR1B_REG,3);
	SET_BIT(TCCR1B_REG,4);
#endif

#if COMPARE_OUTPUT_MATCH == INVERTING
	SET_BIT(TCCR1A_REG,6);
	SET_BIT(TCCR1A_REG,7);
#elif COMPARE_OUTPUT_MATCH == NON_INVERTING
	CLR_BIT(TCCR1A_REG,6);
	SET_BIT(TCCR1A_REG,7);
#endif

}


void PWM1_SetDutyCycle(f32 DutyCycle)
{
#if PWM1_MODE == FAST_PWM_MODE
	#if COMPARE_OUTPUT_MATCH == INVERTING
		OCR1A_REG = ICR1_REG * (1 - (DutyCycle/100.0));
	#elif COMPARE_OUTPUT_MATCH == NON_INVERTING
		OCR1A_REG = ICR1_REG * (DutyCycle/100.0);
	#endif

#elif  PWM1_MODE == PHASE_CORRECT_PWM_MODE
	#if COMPARE_OUTPUT_MATCH == INVERTING
		OCR1A_REG = ICR1_REG * (1 - (DutyCycle/100.0));
	#elif COMPARE_OUTPUT_MATCH == NON_INVERTING
		OCR1A_REG = ICR1_REG/((DutyCycle/100.0)+1);
	#endif
#endif

}

void PWM1_SetFrequency(u8 Freq)
{
	ICR1_REG = (TIMER1_CLK*1000000UL)/(TIMER1_PRESCALAR*Freq);
}

void PWM1_Start()
{
	//prescalar_8
	CLR_BIT(TCCR1B_REG,0);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);

//	//prescalar_64
//	SET_BIT(TCCR1B_REG,0);
//	SET_BIT(TCCR1B_REG,1);
//	CLR_BIT(TCCR1B_REG,2);
}

void PWM1_Stop()
{
	CLR_BIT(TCCR1B_REG,0);
	CLR_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);
}
