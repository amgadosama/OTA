/*
 * temp.c
 *
 *  Created on: Mar 13, 2023
 *      Author: amres
 */
#include"../../STD_LIB/STD_TYPES.h"
#include"../../MCAL/ADC/ADC_Interface.h"
#include "temp.h"
u16 temp_read(u8 ADCN)
{
	u16 ADC_Reading=ADC_READ(ADCN);
	f32 volt=((u32)ADC_Reading*5000)/1024.0;
f64 temp=volt/10.0;
				return temp;
}
