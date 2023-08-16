/*
 * BUZZER.c
 *
 *  Created on: Mar 22, 2023
 *      Author: amres
 */
#include"BUZZER_Interface.h"
#include"BUZZER.Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"
void BUZZER_INT()
{
	DIO_SetPinDirection(BUZZER_PORT,BUZZER_PIN,OUTPUT);
}
void BUZZER_ON()
{
DIO_SetPinValue(BUZZER_PORT,BUZZER_PIN,HIGH);
}
void BUZZER_OFF()
{
	DIO_SetPinValue(BUZZER_PORT,BUZZER_PIN,LOW);
}
