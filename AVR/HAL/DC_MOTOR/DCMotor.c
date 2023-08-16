/*
 * DCMotor.c
 *
 *  Created on: Feb 27, 2023
 *      Author: amres
 */

#include"../../STD_LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"DCMotor_Interface.h"
#include"DCMotor_config.h"
u8 DCMotor_CLOCKWISE()
{
	 u8  z=DIO_SetPinValue(DCMOTOR_PORT,DCMOTOR_ForwardPIN,HIGH);
	     z=DIO_SetPinValue(DCMOTOR_PORT,DCMOTOR_ReversePIN,LOW);
	return z;
}
u8 DCMotor_AntiCLOCKWISE()
{
 u8  z=DIO_SetPinValue(DCMOTOR_PORT,DCMOTOR_ForwardPIN,LOW);
     z=DIO_SetPinValue(DCMOTOR_PORT,DCMOTOR_ReversePIN,HIGH);
		return z;
}
u8 DCMotor_Stop()
{
	 u8  z=DIO_SetPinValue(DCMOTOR_PORT,DCMOTOR_ForwardPIN,LOW);
	     z=DIO_SetPinValue(DCMOTOR_PORT,DCMOTOR_ReversePIN,LOW);
			return z;
}
