/*****************************************/
/* Author  :  Seif Hashad                */
/* Version :  V01                        */
/* Date    : 18 May 2023                 */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
void (*EXT0_CALLBACKFUNC)(void);
void (*EXT11_CALLBACKFUNC)(void);
void EXTI_voidInit()
{
	#if		EXTI_SENSE_CONTROL	== FALLING_EDGE
			SET_BIT(EXTI_FTSR, EXTI_LINE);
			CLR_BIT(EXTI_RTSR, EXTI_LINE);
	#elif	EXTI_SENSE_CONTROL	== RISING_EDGE
			CLR_BIT(EXTI_FTSR, EXTI_LINE);
			SET_BIT(EXTI_RTSR, EXTI_LINE);
	#elif	EXTI_SENSE_CONTROL	== ON_CHANGE
			SET_BIT(EXTI_FTSR, EXTI_LINE);
			SET_BIT(EXTI_RTSR, EXTI_LINE);
	#else
			#error "Not a valid Configuration!"
	#endif
}

/*Copy_u8LineId Options: EXTI_LINE_0 --> EXTI_LINE_15*/
void EXTI_voidSetExtiLineEnable(u8 Copy_u8LineId)
{
	SET_BIT(EXTI_IMR, Copy_u8LineId);
}

/*Copy_u8LineId Options: EXTI_LINE_0 --> EXTI_LINE_15*/
void EXTI_voidSetExtiLineDisable(u8 Copy_u8LineId)
{
	CLR_BIT(EXTI_IMR, Copy_u8LineId);
}

/*Copy_u8SenseControl: FALLING_EDGE, RISING_EDGE, ON_CHANGE*/
/*Copy_u8LineId Options: EXTI_LINE_0 --> EXTI_LINE_15*/
void EXTI_voidSetSenseControl(u8 Copy_u8SenseControl, u8 Copy_u8LineId)
{
	switch(Copy_u8SenseControl)
	{
		case FALLING_EDGE:	SET_BIT(EXTI_FTSR, Copy_u8LineId);
							CLR_BIT(EXTI_RTSR, Copy_u8LineId);
							break;
		case RISING_EDGE:	CLR_BIT(EXTI_FTSR, Copy_u8LineId);
							SET_BIT(EXTI_RTSR, Copy_u8LineId);
							break;
		case ON_CHANGE:		SET_BIT(EXTI_FTSR, Copy_u8LineId);
							SET_BIT(EXTI_RTSR, Copy_u8LineId);
							break;
		default:			break;
	}
}

/*Copy_u8PortId Options: EXTI_PA, EXTI_PB, EXTI_PC*/
/*Copy_u8LineId Options: EXTI_LINE_0 --> EXTI_LINE_15*/
void EXTI_voidSetEXTIpinConfig(u8 Copy_u8PortId, u8 Copy_u8LineId)
{
	if(Copy_u8LineId <= EXTI_LINE_3)
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR1 = ((0b0000) << (Copy_u8LineId*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR1 = ((0b0001) << (Copy_u8LineId*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR1 = ((0b0010) << (Copy_u8LineId*4));
							break;
			default:		break;
		}
	}
	else if (Copy_u8LineId <= EXTI_LINE_7)
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR2 = ((0b0000) << ((Copy_u8LineId-4)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR2 = ((0b0001) << ((Copy_u8LineId-4)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR2 = ((0b0010) << ((Copy_u8LineId-4)*4));
							break;
			default:		break;
		}
	}
	else if (Copy_u8LineId <= EXTI_LINE_11)
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR3 = ((0b0000) << ((Copy_u8LineId-8)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR3 = ((0b0001) << ((Copy_u8LineId-8)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR3 = ((0b0010) << ((Copy_u8LineId-8)*4));
							break;
			default:		break;
		}
	}
	else
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR4 = ((0b0000) << ((Copy_u8LineId-12)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR4 = ((0b0001) << ((Copy_u8LineId-12)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR4 = ((0b0010) << ((Copy_u8LineId-12)*4));
							break;
			default:		break;
		}
	}
}
void EXT0_CALLBACK(void (*ptr)(void))
{
	EXT0_CALLBACKFUNC=ptr;

}

void EXT11_CALLBACK(void (*ptr2)(void))
{
	EXT11_CALLBACKFUNC=ptr2;

}
void EXTI0_IRQHandler (void)
{

	EXT0_CALLBACKFUNC();
    /*  clear pending flag */
	SET_BIT(EXTI_PR, 0);

}
void EXTI11_IRQHandler (void)
{

	EXT11_CALLBACKFUNC();
    /*  clear pending flag */
	SET_BIT(EXTI_PR, 0);
}
