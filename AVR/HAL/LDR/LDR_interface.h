/*
 * LDR_interface.h
 *
 *  Created on: Mar 23, 2023
 *      Author: amres
 */

#ifndef LDR_INTERFACE_H_
#define LDR_INTERFACE_H_

u16 LDR_Reading(u8 ADC_Channel);
f64 LDR_Reading2(u8 ADC_Channel);
u8 LDR_Intensity_Level(u8 ADC_Channel);


enum LDR_Level
{
	Level1,
	Level2,
	Level3,
	Level4,
	Level5,
	UnValid
};
#endif /* HAL_LDR_LDR_INTERFACE_H_ */
