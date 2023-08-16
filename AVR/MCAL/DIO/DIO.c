/*
 * DIO.c
 *
 *  Created on: Feb 10, 2023
 *      Author: aaa
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Registers.h"
#include "DIO_Config.h"

void DIO_INIT(void)
{

	DDRA_REG = Conc(DIO_PORTA_PIN7_INIT_DIR,DIO_PORTA_PIN6_INIT_DIR,DIO_PORTA_PIN5_INIT_DIR,
					DIO_PORTA_PIN4_INIT_DIR,DIO_PORTA_PIN3_INIT_DIR,DIO_PORTA_PIN2_INIT_DIR,
					DIO_PORTA_PIN1_INIT_DIR,DIO_PORTA_PIN0_INIT_DIR);
	DDRB_REG = Conc(DIO_PORTB_PIN7_INIT_DIR,DIO_PORTB_PIN6_INIT_DIR,DIO_PORTB_PIN5_INIT_DIR,
					DIO_PORTB_PIN4_INIT_DIR,DIO_PORTB_PIN3_INIT_DIR,DIO_PORTB_PIN2_INIT_DIR,
					DIO_PORTB_PIN1_INIT_DIR,DIO_PORTB_PIN0_INIT_DIR);
	DDRC_REG = Conc(DIO_PORTC_PIN7_INIT_DIR,DIO_PORTC_PIN6_INIT_DIR,DIO_PORTC_PIN5_INIT_DIR,
					DIO_PORTC_PIN4_INIT_DIR,DIO_PORTC_PIN3_INIT_DIR,DIO_PORTC_PIN2_INIT_DIR,
					DIO_PORTC_PIN1_INIT_DIR,DIO_PORTC_PIN0_INIT_DIR);
	DDRD_REG = Conc(DIO_PORTD_PIN7_INIT_DIR,DIO_PORTD_PIN6_INIT_DIR,DIO_PORTD_PIN5_INIT_DIR,
					DIO_PORTD_PIN4_INIT_DIR,DIO_PORTD_PIN3_INIT_DIR,DIO_PORTD_PIN2_INIT_DIR,
					DIO_PORTD_PIN1_INIT_DIR,DIO_PORTD_PIN0_INIT_DIR);

	PORTA_REG = Conc(DIO_PORTA_PIN7_INIT_Val,DIO_PORTA_PIN6_INIT_Val,DIO_PORTA_PIN5_INIT_Val,
					DIO_PORTA_PIN4_INIT_Val,DIO_PORTA_PIN3_INIT_Val,DIO_PORTA_PIN2_INIT_Val,
					DIO_PORTA_PIN1_INIT_Val,DIO_PORTA_PIN0_INIT_Val);
	PORTB_REG = Conc(DIO_PORTB_PIN7_INIT_Val,DIO_PORTB_PIN6_INIT_Val,DIO_PORTB_PIN5_INIT_Val,
					DIO_PORTB_PIN4_INIT_Val,DIO_PORTB_PIN3_INIT_Val,DIO_PORTB_PIN2_INIT_Val,
					DIO_PORTB_PIN1_INIT_Val,DIO_PORTB_PIN0_INIT_Val);
	PORTC_REG = Conc(DIO_PORTC_PIN7_INIT_Val,DIO_PORTC_PIN6_INIT_Val,DIO_PORTC_PIN5_INIT_Val,
					 DIO_PORTC_PIN4_INIT_Val,DIO_PORTC_PIN3_INIT_Val,DIO_PORTC_PIN2_INIT_Val,
					 DIO_PORTC_PIN1_INIT_Val,DIO_PORTC_PIN0_INIT_Val);
	PORTD_REG = Conc(DIO_PORTD_PIN7_INIT_Val,DIO_PORTD_PIN6_INIT_Val,DIO_PORTD_PIN5_INIT_Val,
					 DIO_PORTD_PIN4_INIT_Val,DIO_PORTD_PIN3_INIT_Val,DIO_PORTD_PIN2_INIT_Val,
					 DIO_PORTD_PIN1_INIT_Val,DIO_PORTD_PIN0_INIT_Val);

}

u8 DIO_SetPinDirection(u8 Port_ID,u8 Pin_ID,u8 Pin_Dir)
{
	u8 ErrorState = DIO_OK;
	if(Pin_ID >=PIN0 && Pin_ID <= PIN7)
	{
		if(Pin_Dir == OUTPUT)
		{
			switch(Port_ID)
			{
			case DIO_PORTA:SET_BIT(DDRA_REG,Pin_ID);break;
			case DIO_PORTB:SET_BIT(DDRB_REG,Pin_ID);break;
			case DIO_PORTC:SET_BIT(DDRC_REG,Pin_ID);break;
			case DIO_PORTD:SET_BIT(DDRD_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange; break;
			}
		}
		else if (Pin_Dir == INPUT)
		{
			switch(Port_ID)
			{
			case DIO_PORTA:CLR_BIT(DDRA_REG,Pin_ID);break;
			case DIO_PORTB:CLR_BIT(DDRB_REG,Pin_ID);break;
			case DIO_PORTC:CLR_BIT(DDRC_REG,Pin_ID);break;
			case DIO_PORTD:CLR_BIT(DDRD_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange;break;
			}
		}
		else
		{
			ErrorState = DIO_DirectionNotCorrect;
		}
	}
	else
	{
		ErrorState = DIO_PinOutOfRange;
	}
	return ErrorState;
}

u8 DIO_SetPinValue(u8 Port_ID,u8 Pin_ID,u8 Pin_Val)
{
	u8 ErrorState = DIO_OK;
	if(Pin_ID >=PIN0 && Pin_ID <= PIN7)
	{
		if(Pin_Val == HIGH)
		{
			switch(Port_ID)
			{
			case DIO_PORTA:SET_BIT(PORTA_REG,Pin_ID);break;
			case DIO_PORTB:SET_BIT(PORTB_REG,Pin_ID);break;
			case DIO_PORTC:SET_BIT(PORTC_REG,Pin_ID);break;
			case DIO_PORTD:SET_BIT(PORTD_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange; break;
			}
		}
		else if (Pin_Val == LOW)
		{
			switch(Port_ID)
			{
			case DIO_PORTA:CLR_BIT(PORTA_REG,Pin_ID);break;
			case DIO_PORTB:CLR_BIT(PORTB_REG,Pin_ID);break;
			case DIO_PORTC:CLR_BIT(PORTC_REG,Pin_ID);break;
			case DIO_PORTD:CLR_BIT(PORTD_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange; break;
			}
		}
		else
		{
			ErrorState = DIO_ValueNotCorrect;
		}
	}
	else
	{
		ErrorState = DIO_PinOutOfRange;
	}
	return ErrorState;
}

u8	DIO_ReadPin(u8 Port_ID,u8 Pin_ID,u8 * PinReading)
{
	u8 ErrorState = DIO_OK;
	*PinReading = 0;
	if(Pin_ID >=PIN0 && Pin_ID <= PIN7)
	{
		switch(Port_ID)
		{
			case DIO_PORTA:*PinReading = GET_BIT(PINA_REG,Pin_ID);break;
			case DIO_PORTB:*PinReading = GET_BIT(PINB_REG,Pin_ID);break;
			case DIO_PORTC:*PinReading = GET_BIT(PINC_REG,Pin_ID);break;
			case DIO_PORTD:*PinReading = GET_BIT(PIND_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange; break;
		}
	}
	else
	{
		ErrorState = DIO_PinOutOfRange;
	}
	return ErrorState;
}


u8 DIO_TogglePin(u8 Port_ID,u8 Pin_ID)
{
	u8 ErrorState = DIO_OK;
	if(Pin_ID >=PIN0 && Pin_ID <= PIN7)
	{
		switch(Port_ID)
		{
			case DIO_PORTA:TOG_BIT(PORTA_REG,Pin_ID);break;
			case DIO_PORTB:TOG_BIT(PORTB_REG,Pin_ID);break;
			case DIO_PORTC:TOG_BIT(PORTC_REG,Pin_ID);break;
			case DIO_PORTD:TOG_BIT(PORTD_REG,Pin_ID);break;
			default:ErrorState = DIO_PortOutOfRange; break;
		}
	}
	else
	{
		ErrorState = DIO_PinOutOfRange;
	}
	return ErrorState;
}

u8 DIO_SetPortDirection(u8 Port_ID,u8 Port_Dir)
{
	u8 ErrorState = DIO_OK;
	if(Port_ID>=DIO_PORTA && Port_ID<=DIO_PORTD && Port_Dir>= 0 && Port_Dir<= 255)
	{
		if(Port_Dir == OUTPUT_PORT)
		{
			switch(Port_ID)
			{
			case DIO_PORTA:SET_REG(DDRA_REG);break;
			case DIO_PORTB:SET_REG(DDRB_REG);break;
			case DIO_PORTC:SET_REG(DDRC_REG);break;
			case DIO_PORTD:SET_REG(DDRD_REG);break;
			}
		}
		else if(Port_Dir == INPUT_PORT)
		{
			switch(Port_ID)
			{
			case DIO_PORTA:CLR_REG(DDRA_REG);break;
			case DIO_PORTB:CLR_REG(DDRB_REG);break;
			case DIO_PORTC:CLR_REG(DDRC_REG);break;
			case DIO_PORTD:CLR_REG(DDRD_REG);break;
			}
		}
		else
		{
			switch(Port_ID)
			{
			case DIO_PORTA:DDRA_REG = Port_Dir;break;
			case DIO_PORTB:DDRB_REG = Port_Dir;break;
			case DIO_PORTC:DDRC_REG = Port_Dir;break;
			case DIO_PORTD:DDRD_REG = Port_Dir;break;
			}
		}
	}
	else
	{
		ErrorState = DIO_NOTOK;
	}
	return ErrorState;
}

u8 DIO_SetPortValue(u8 Port_ID,u8 Port_Val)
{
	u8 ErrorState = DIO_OK;
	if(Port_ID>=DIO_PORTA && Port_ID<=DIO_PORTD && Port_Val>= 0 && Port_Val<= 255)
	{
		if(Port_Val == HIGH_PORT)
		{
			switch(Port_ID)
			{
			case DIO_PORTA:SET_REG(PORTA_REG);break;
			case DIO_PORTB:SET_REG(PORTB_REG);break;
			case DIO_PORTC:SET_REG(PORTC_REG);break;
			case DIO_PORTD:SET_REG(PORTD_REG);break;
			}
		}
		else if(Port_Val == LOW_PORT)
		{
			switch(Port_ID)
			{
			case DIO_PORTA:CLR_REG(PORTA_REG);break;
			case DIO_PORTB:CLR_REG(PORTB_REG);break;
			case DIO_PORTC:CLR_REG(PORTC_REG);break;
			case DIO_PORTD:CLR_REG(PORTD_REG);break;
			}
		}
		else
		{
			switch(Port_ID)
			{
			case DIO_PORTA:PORTA_REG = Port_Val;break;
			case DIO_PORTB:PORTB_REG = Port_Val;break;
			case DIO_PORTC:PORTC_REG = Port_Val;break;
			case DIO_PORTD:PORTD_REG = Port_Val;break;
			}
		}
	}
	else
	{
		ErrorState = DIO_NOTOK;
	}
	return ErrorState;
}

u8	DIO_ReadPort(u8 Port_ID,u8 * PortReading)
{
	u8 ErrorState = DIO_OK;
	*PortReading = 0;
	if(Port_ID>= DIO_PORTA && Port_ID <=DIO_PORTD)
	{
		switch(Port_ID)
		{
		case DIO_PORTA:*PortReading = GET_REG(PINA_REG);break;
		case DIO_PORTB:*PortReading = GET_REG(PINB_REG);break;
		case DIO_PORTC:*PortReading = GET_REG(PINC_REG);break;
		case DIO_PORTD:*PortReading = GET_REG(PIND_REG);break;
		default: ErrorState = DIO_PortOutOfRange;break;
		}
	}
	else
	{
		ErrorState = DIO_NOTOK;
	}
	return ErrorState;
}

u8 DIO_TogglePort(u8 Port_ID)
{
	u8 ErrorState = DIO_OK;
	if(Port_ID>= DIO_PORTA && Port_ID <=DIO_PORTD)
	{
		switch(Port_ID)
		{
		case DIO_PORTA:TOG_REG(PORTA_REG);break;
		case DIO_PORTB:TOG_REG(PORTB_REG);break;
		case DIO_PORTC:TOG_REG(PORTC_REG);break;
		case DIO_PORTD:TOG_REG(PORTD_REG);break;
		default:ErrorState = DIO_PortOutOfRange;break;
		}
	}
	else
	{
		ErrorState = DIO_NOTOK;
	}
	return ErrorState;
}
