/*
 * EEPROM.c
 *
 *  Created on: Apr 14, 2023
 *      Author: aaa
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Config.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
void EEPROM_WriteByte(u8 page,u8 location,u8 data)
{
	//start condition
	TWI_StartCondition();
	//SLA + W
	TWI_SendSlaveAdressWithWrite((EEPROM_FIXED_ADD)|(EEPROM_A2_Value<<2)|(page&3));
	//Send location
	TWI_MasterWriteData(location);
	//write data
	TWI_MasterWriteData(data);
	//stop condition
	TWI_StopCondition();
}

u8	 EEPROM_ReadByte(u8 page,u8 location)
{
	u8 data = 0;
	//start condition
	TWI_StartCondition();

	//SLA + W
	TWI_SendSlaveAdressWithWrite((EEPROM_FIXED_ADD)|(EEPROM_A2_Value<<2)|(page&3));

	//send location
	TWI_MasterWriteData(location);

	//Repeat Start condition with read
	TWI_RepeatedStartCondition();

	//SLA +R
	TWI_SendSlaveAdressWithRead((EEPROM_FIXED_ADD)|(EEPROM_A2_Value<<2)|(page&3));

	//receive data
	data = TWI_MasterReadData();

	//stop condition
	TWI_StopCondition();

	return data;
}
