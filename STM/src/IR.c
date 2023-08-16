/*
 * IR.c

 *
 *  Created on: Jun 13, 2023
 *      Author: amressam
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI_Interface.h"
#include"EXTI_Private.h"
#include"RCC_Interface.h"
#include"NVIC_Interface.h"
#include"GPIO_Interface.h"
#include"IR_Interface.h"
#include"IR_Private.h"
#include"IR_Config.h"
u32 Reading[33]={0};
u8 Data=0;
u8 flag_x=0;
u32 TIME=0;
 static u8 counter=0;
void func();
void func2();
void IR_Init(u8 RCC_BusID)
{

#if IR_PORT==GPIOA
 RCC_voidEnablePeripheralClk(RCC_BusID,0);
#elif IR_PORT==GPIOB
 RCC_voidEnablePeripheralClk(RCC_BusID,1);
#elif IR_PORT==GPIOB
 RCC_voidEnablePeripheralClk(RCC_BusID,2);
#endif
//Gpio init
 	GPIO_voidSetPinPUPDOption(GPIOA,IR_InputPin, INPUT_FLOATING);


	//EXT_INIT
	EXTI_voidInit();
	EXTI_voidSetSenseControl(FALLING_EDGE,0);


	//this line for EXT only
	NVIC_voidEnablePerInt(6);
	//STK
	MSTK_voidInit();



}
u8 IR_ReciveData()
{

EXT0_CALLBACK(&func);

for(int i=0;i<8;i++)
{
	if(Reading[17+i]>=1000&&Reading[17+i]<=1500)
	{
		CLR_BIT(Data,i);
	}
	else if(Reading[17+i]>=2000&&Reading[17+i]<=2500)
	{
		SET_BIT(Data,i);
	}
}
return Data;

}
void func()
{
	MSTK_voidStopInterval();
		MSTK_voidInit();
	if(flag_x==0)
	{
		flag_x=1;
		MSTK_voidSetIntervalSingle(15000,&func2);
	}
	else
	{
		TIME=MSTK_u32GetElapsedTime();
		Reading[counter]=TIME;
		counter++;
	}

	flag_x=0;

}
void func2()
{

}
