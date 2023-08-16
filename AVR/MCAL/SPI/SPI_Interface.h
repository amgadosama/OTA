/*
 * SPI_Interface.h
 *
 *  Created on: Apr 4, 2023
 *      Author: amres
 */
#include "SPI_Config.h"
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

enum SPCR
{
	SPR0,
	SPR1,
	CPHA,
	CPOL,
	MSTR,
	DORD,
	SPE,
	SPIE
};
#define SPI_DATA_ORDER   SPI_DATA_LSB
#define SPI_DATA_LSB      0
#define SPI_DATA_MSB      1
//enum
//{
//	SPI2X,
//	WCOL=6,
//	SPIF
//};
//Data Order /Clock setup/prescalar/slave or master
void SPI_Init(u8 SPI_MODE);
// send and recive data at the same time
u8 SPI_TRANCEIVER(u8 data);
#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
