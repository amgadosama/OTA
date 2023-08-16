/*
 * ICU_Interface.h
 *
 *  Created on: Mar 25, 2023
 *      Author: aaa
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#define FALLING_EDGE	0
#define RISING_EDGE		1

void ICU_Init();

void ICU_SetTrigger(u8 TriggerType);

u16 ICU_GetValue();

void ICU_DisplayPWM(u8 * freq,u8 * DutyCycle);



#endif /* MCAL_ICU_ICU_INTERFACE_H_ */
