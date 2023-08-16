/*
 * ADC_Config.h
 *
 *  Created on: Mar 10, 2023
 *      Author: aaa
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*You can choose between : {ADC_INTERNAL_2_56_v /ADC_INTERNAL_AVCC /ADC_EXTERNAL}*/
#define ADC_VREF		ADC_INTERNAL_AVCC
#define ADC_ADJUST		ADC_RIGHT
#define ADC_PRESCALAR	ADC_PRESCALAR_128



#define ADC_PRESCALAR_2			0
#define ADC_PRESCALAR_4			1
#define ADC_PRESCALAR_8			2
#define ADC_PRESCALAR_16		3
#define ADC_PRESCALAR_32		4
#define ADC_PRESCALAR_64		5
#define ADC_PRESCALAR_128		6

#define ADC_RIGHT		0
#define ADC_LEFT		1


#define ADC_INTERNAL_2_56_v		0
#define ADC_INTERNAL_AVCC		1
#define ADC_EXTERNAL			2

//enum ADC_VREF_Options
//{
//	ADC_INTERNAL_2_56_v,
//	ADC_INTERNAL_AVCC,
//	ADC_EXTERNAL
//};

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
