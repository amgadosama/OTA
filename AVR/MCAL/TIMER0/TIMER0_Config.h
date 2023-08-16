/*
 * TIMER0_Config.h
 *
 *  Created on: Mar 17, 2023
 *      Author: aaa
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


#define TIMER0_MODE					NORMAL_MODE
//PRESCALAR Options (1 / 8 / 64 / 256 / 1024)
#define TIMER0_PRESCALAR				8
#define TIMER0_CLK						8
#define TIMER0_RESLOUTION				256



//#define TIMER0_CTC_VALUE			200

#define NORMAL_MODE 				0
#define CTC_MODE					1
#define PHASE_CORRECT_PWM_MODE		2
#define FAST_PWM_MODE				3


#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
