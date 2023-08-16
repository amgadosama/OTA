/*
 * EXT_INT.c
 *
 *  Created on: Mar 4, 2023
 *      Author: aaa
 */
#include "../../STD_LIB/BIT_MATH.h"
#include "../../STD_LIB/STD_TYPES.h"
#include "EXT_INT_Interface.h"
#include "EXT_INT_Registers.h"
#include "EXT_INT_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"
void (*EXT1_PF)(void);
void (*EXT0_PF)(void);
void (*EXT2_PF)(void);
u8 fl=0;
void EXT_INT_Enable(u8 INT_ID)
{
	if(INT_ID >= EXT_INT0 && INT_ID <= EXT_INT2)
	{
		switch(INT_ID)
		{
		case EXT_INT0:SET_BIT(GICR_REG,INT0);break;
		case EXT_INT1:SET_BIT(GICR_REG,INT1);break;
		case EXT_INT2:SET_BIT(GICR_REG,INT2);break;
		default:break;
		}
	}
	else
	{
		//report an error state
	}
}

void EXT_INT_Disable(u8 INT_ID)
{
	if(INT_ID >= EXT_INT0 && INT_ID <= EXT_INT2)
	{
		switch(INT_ID)
		{
		case EXT_INT0:CLR_BIT(GICR_REG,INT0);break;
		case EXT_INT1:CLR_BIT(GICR_REG,INT1);break;
		case EXT_INT2:CLR_BIT(GICR_REG,INT2);break;
		default:break;
		}
	}
	else
	{
		//report an error state
	}
}


u8 EXT_INT_SenseControl(u8 INT_ID,u8 INT_Trigger)
{
	if(INT_Trigger >= FallingEdge && INT_Trigger <= LowLevel)
	{
		if(INT_Trigger == FallingEdge)
		{
			switch(INT_ID)
			{
			case EXT_INT0:CLR_BIT(MCUCR_REG,ISC00);
						  SET_BIT(MCUCR_REG,ISC01);
						  fl=1;
						  break;
			case EXT_INT1:CLR_BIT(MCUCR_REG,ISC10);
						  SET_BIT(MCUCR_REG,ISC11);
						  fl=1;
						  break;
			case EXT_INT2:CLR_BIT(MCUCSR_REG,ISC2);
			  fl=1; break;
			default:break;
			}
		}
		else if(INT_Trigger == RisingEdge)
		{
			switch(INT_ID)
			{
			case EXT_INT0:SET_BIT(MCUCR_REG,ISC00);
						  SET_BIT(MCUCR_REG,ISC01);
						  fl=2;
						  break;
			case EXT_INT1:SET_BIT(MCUCR_REG,ISC10);
						  SET_BIT(MCUCR_REG,ISC11);
						  fl=2;
						  break;
			case EXT_INT2:SET_BIT(MCUCSR_REG,ISC2);
			  fl=2; break;
			default:break;
			}
		}
		else if(INT_Trigger == OnChange)
		{
			switch(INT_ID)
			{
			case EXT_INT0:SET_BIT(MCUCR_REG,ISC00);
						  CLR_BIT(MCUCR_REG,ISC01);
						  break;
			case EXT_INT1:SET_BIT(MCUCR_REG,ISC10);
						  CLR_BIT(MCUCR_REG,ISC11);
						  break;
			default:break;
			}
		}
		else if(INT_Trigger == LowLevel)
		{
			switch(INT_ID)
			{
			case EXT_INT0:CLR_BIT(MCUCR_REG,ISC00);
						  CLR_BIT(MCUCR_REG,ISC01);
						  break;
			case EXT_INT1:CLR_BIT(MCUCR_REG,ISC10);
						  CLR_BIT(MCUCR_REG,ISC11);
						  break;
			default:return 0;break;
			}
		}
	}
	if(fl>0)
		return fl;
	else
		return 0;
}

void EXT_INT_ReturnFlag(u8 INT_ID, u8 * PIF)
{
	if(INT_ID >= EXT_INT0 && INT_ID <= EXT_INT2)
	{
		switch(INT_ID)
		{
		case EXT_INT0:*PIF = GET_BIT(GIFR_REG,INTF0);break;
		case EXT_INT1:*PIF = GET_BIT(GIFR_REG,INTF1);break;
		case EXT_INT2:*PIF = GET_BIT(GIFR_REG,INTF2);break;
		default:break;
		}
	}
	else
	{
		//report an error state
	}
}

void EXT_INT1_CallBack(void(*PF)(void))
{

	EXT1_PF = PF;
}

void EXT_INT0_CallBack(void(*PF)(void))
{
	EXT0_PF = PF;
}

void EXT_INT2_CallBack(void(*PF)(void))
{
	EXT2_PF = PF;
}

//ISR for INT1
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	EXT1_PF();
}
//ISR for INT0
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	EXT0_PF();

}
//ISR fir INT2
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	EXT2_PF();
}
