/*
 * SPI.c
 *
 *  Created on: Apr 4, 2023
 *      Author: amres
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include"SPI_Register.h"
#include "SPI_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
u8 f=2;
void SPI_Init(u8 SPI_MODE)
{
//Data order
#if SPI_DATA_ORDER==SPI_DATA_LSB
	SET_BIT(SPCR_REG,DORD);
#elif SPI_DATA_ORDER==SPI_DATA_MSB
	CLR_BIT(SPCR_REG,DORD);

#endif
// clock shape
	CLR_BIT(SPCR_REG,CPOL);
	SET_BIT(SPCR_REG,CPHA);

// master/slave
	switch(SPI_MODE)
	{

	case MASTER:
		     SET_BIT(SPCR_REG,MSTR);//make SS INPUT and low
			//pin intiolitazion
			//MOSI
			DIO_SetPinDirection(DIO_PORTB,PIN5,OUTPUT);
		   //MISO
			DIO_SetPinDirection(DIO_PORTB,PIN6,INPUT);
			//SCK
			DIO_SetPinDirection(DIO_PORTB,PIN7,OUTPUT);
			f=1;
			break;

	case SLAVE:
	    	CLR_BIT(SPCR_REG,MSTR);
	    	//pin intiolitazion
		    //slave select
		    DIO_SetPinDirection(DIO_PORTB,PIN4,INPUT);
			//MOSI
			DIO_SetPinDirection(DIO_PORTB,PIN5,INPUT);
	        //MISO
			DIO_SetPinDirection(DIO_PORTB,PIN6,OUTPUT);
			//SCK
			DIO_SetPinDirection(DIO_PORTB,PIN7,INPUT);
			f=0;
			break;
			default:break;
	}


//	enable spi interrupt
	SET_BIT(SPCR_REG,7);
//enable spi
    SET_BIT(SPCR_REG,6);
//prescalar
    CLR_BIT(SPCR_REG,SPR1);
	SET_BIT(SPCR_REG,SPR0);
	//SPI enable
	SET_BIT(SPCR_REG,SPE);
}


u8 SPI_TRANCEIVER(u8 data)
{
SPDR_REG=data;
//wait until transmation complete
while(GET_BIT(SPSR_REG,7)==0);
//clear flag
SET_BIT(SPSR_REG,7);
return SPDR_REG;

}





