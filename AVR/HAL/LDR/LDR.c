/*
 * LDR.c
 *
 *  Created on: Mar 23, 2023
 *      Author: amres
 */

#include"../../STD_LIB/STD_TYPES.h"
#include"LDR_interface.h"
#include"../../MCAL/ADC/ADC_Interface.h"


u16 LDR_Reading(u8 ADC_Channel)
{

	u16 ADC_Reading=ADC_READ(ADC_Channel);
	u16 volt=((u32)(ADC_Reading*5000))/1024;
	return volt;
}




f64 LDR_Reading2(u8 ADC_Channel)
{
	u16 ADC_Reading=ADC_READ(ADC_Channel);
	f64 volt=(5000*(1000/ADC_Reading+1000));
	return volt;
}












u8 LDR_Intensity_Level(u8 ADC_Channel)
{
	u16 LDR_Reading_Value=LDR_Reading(ADC_Channel);

	if(LDR_Reading_Value>=0 && LDR_Reading_Value<=1000)
	{
	return Level5;
	}
else if(LDR_Reading_Value>1000 && LDR_Reading_Value<=2000)
	{
	return Level4;
	}
else if(LDR_Reading_Value>2000 && LDR_Reading_Value<=3000)
	{
	return Level3;
	}
else if(LDR_Reading_Value>3000 && LDR_Reading_Value<=4000)
	{
	return Level2;
	}
else if(LDR_Reading_Value>4000 && LDR_Reading_Value<=5000)
	{
	return Level1;
	}
else
{
	return UnValid;
}
}
