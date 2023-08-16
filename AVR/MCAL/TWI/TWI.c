/*
 * TWI.c
 *
 *  Created on: Apr 8, 2023
 *      Author: aaa
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_Registers.h"
#include "TWI_Config.h"
#include "../DIO/DIO_Interface.h"

void TWI_MasterInit()
{
	//set clock to 200KHz
	TWBR_REG = 2;
	CLR_BIT(TWSR_REG,0);
	CLR_BIT(TWSR_REG,1);
	//enable ack
	SET_BIT(TWCR_REG,6);
	//enable TWI circuit
	SET_BIT(TWCR_REG,2);
}


void TWI_SlaveInit(u8 address)
{
	//enable ack
	SET_BIT(TWCR_REG,6);
	//set address of slave
	TWAR_REG = address<<1;

	//enable TWI circuit
	SET_BIT(TWCR_REG,2);
}

void TWI_StartCondition()
{
	//start condition
	SET_BIT(TWCR_REG,5);
	//clear the flag
	SET_BIT(TWCR_REG,7);
	//wait until the flag is set
	while(GET_BIT(TWCR_REG,7) == 0);
	//check on start condition status
	while((TWSR_REG & 0xF8) != 0x08);
}

void TWI_StopCondition()
{
	//stop condition
	SET_BIT(TWCR_REG,4);
	//clear the flag
	SET_BIT(TWCR_REG,7);

}

void TWI_SendSlaveAdressWithWrite(u8 SlaveAdress)
{
	//send SLA on TWDR
	TWDR_REG = SlaveAdress<<1;
	//write operation
	CLR_BIT(TWDR_REG,0);

	//Disable Start condition
	CLR_BIT(TWCR_REG,5);

	//clear the flag
	SET_BIT(TWCR_REG,7);

	//wait until the flag is set
	while(GET_BIT(TWCR_REG,7) == 0);

	//check on SLA_W is Transimited status
	//while((TWSR_REG & 0xF8) != 0x18);

}


void TWI_SendSlaveAdressWithRead(u8 SlaveAdress)
{
	//send SLA on TWDR
	TWDR_REG = SlaveAdress<<1;
	//Read operation
	SET_BIT(TWDR_REG,0);
	//Disable Start condition
	CLR_BIT(TWCR_REG,5);
	//clear the flag
	SET_BIT(TWCR_REG,7);
	//wait until the flag is set
	while(GET_BIT(TWCR_REG,7) == 0);

	//check on SLA_R is Transimited status
	while((TWSR_REG & 0xF8) != 0x40);
}


void TWI_MasterWriteData(u8 Data)
{
	//Write Data in TWDR register
	TWDR_REG = Data;

	//clear the flag
	SET_BIT(TWCR_REG,7);

	//wait until the flag is set
	while(GET_BIT(TWCR_REG,7) == 0);

	//check on Data is Transimited status
	//while((TWSR_REG & 0xF8) != 0x28);

}

u8 	 TWI_MasterReadData()
{
	//clear the flag
	SET_BIT(TWCR_REG,7);

	//wait until the flag is set
	while(GET_BIT(TWCR_REG,7) == 0);
	//check on Data is Received status
	while((TWSR_REG & 0xF8) != 0x50);
	return TWDR_REG;
}


void TWI_RepeatedStartCondition()
{

	//start condition
	SET_BIT(TWCR_REG,5);

	//clear the flag
	SET_BIT(TWCR_REG,7);

	//wait until the flag is set
	while(GET_BIT(TWCR_REG,7) == 0);
	//check on Re-start condition status
	while((TWSR_REG & 0xF8) != 0x10);
}

u8   TWI_SlaveReceiveData()
{
	/*Wait to receive the slave address*/
	while((TWSR_REG &0xf8 )!=0x60);
	//clear the flag
	SET_BIT(TWCR_REG,7);

	//wait until the flag is set
	while(GET_BIT(TWCR_REG,7) == 0);

	//check on Re-start condition status
	while((TWSR_REG & 0xF8) != 0x80);

	return TWDR_REG;
}

