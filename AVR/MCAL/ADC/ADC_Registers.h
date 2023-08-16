/*
 * ADC_Registers.h
 *
 *  Created on: Mar 10, 2023
 *      Author: aaa
 */

#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_

#define ADMUX_REG	*((volatile u8*)0x27)
#define ADCSRA_REG	*((volatile u8*)0x26)
#define ADCDATA_REG	*((volatile u16*)0x24)
#define ADCL_REG	*((volatile u8*)0x24)
#define ADCH_REG	*((volatile u8*)0x25)
#endif /* MCAL_ADC_ADC_REGISTERS_H_ */
