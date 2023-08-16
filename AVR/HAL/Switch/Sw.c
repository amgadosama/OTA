/*
 * SW.c
 *
 *  Created on: Feb 15, 2023
 *      Author: amres
 */
#include"Sw.h"
#include "../../MCAL/DIO/DIO_Interface.h"
u8 SW_READ(u8 PORT_ID,u8 PIN_REG_ID,u8 PIN_N)
	{
		          DIO_SetPinDirection(PORT_ID,PIN_REG_ID,INPUT);

		          u8 x= (PIN_REG_ID>>PIN_N)&1; // Note while using switch U USE PIN(A,B,C,D) NOT DDR(A,B,C,D) NOT PORT(A,B,C,D)
		        return x;
   }
