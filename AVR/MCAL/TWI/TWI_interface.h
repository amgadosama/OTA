/*
 * TWI_interface.h
 *
 *  Created on: Apr 8, 2023
 *      Author: aaa
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_



void TWI_MasterInit();

void TWI_SlaveInit(u8 address);

void TWI_StartCondition();

void TWI_StopCondition();

void TWI_SendSlaveAdressWithWrite(u8 SlaveAdress);

void TWI_SendSlaveAdressWithRead(u8 SlaveAdress);

void TWI_MasterWriteData(u8 Data);

u8 	 TWI_MasterReadData();

void TWI_RepeatedStartCondition();

u8   TWI_SlaveReceiveData();

u8   TWI_ReadStatusCode();

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
