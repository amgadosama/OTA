/*
 * TIMER1_Config.h
 *
 *  Created on: Mar 24, 2023
 *      Author: aaa
 */

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#define TIMER1_MODE					FAST_PWM_MODE
//PRESCALAR Options (1 / 8 / 64 / 256 / 1024)
#define TIMER1_PRESCALAR				8
#define TIMER1_CLK						8
#define TIMER1_RESLOUTION				256

#define PWM1_MODE					FAST_PWM_MODE
#define COMPARE_OUTPUT_MATCH		NON_INVERTING


#define NON_INVERTING		0
#define INVERTING			1

//#define TIMER0_CTC_VALUE			200

#define NORMAL_MODE 				0
#define CTC_MODE					1
#define PHASE_CORRECT_PWM_MODE		2
#define FAST_PWM_MODE				3

#endif /* MCAL_TIMER1_TIMER1_CONFIG_H_ */
