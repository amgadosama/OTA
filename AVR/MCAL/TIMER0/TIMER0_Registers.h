/*
 * TIMER0_Registers.h
 *
 *  Created on: Mar 17, 2023
 *      Author: aaa
 */

#ifndef TIMER0_REGISTERS_H_
#define TIMER0_REGISTERS_H_

#define TCCR0_REG	*((volatile u8*)0x53)
#define TCNT0_REG	*((volatile u8*)0x52)
#define OCR0_REG	*((volatile u8*)0x5C)
#define TIMSK_REG	*((volatile u8*)0x59)
#define TIFR_REG	*((volatile u8*)0x58)

#endif /* MCAL_TIMER0_TIMER0_REGISTERS_H_ */
