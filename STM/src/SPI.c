/*
 * SPI.c
 *
 *  Created on: Jun 19, 2023
 *      Author: amres
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"
#include"TFT_Config.h"


void SPI_voidinti(void){
    SPI1->SPI_CR1=0x0347;
}
void SPI_voidTransceive(u8 copy_u8TransmitedData,u8* u8_ReceivedData){
    //while (GET_BIT(SPI1->SPI_SR,7)==1);
    SPI1->SPI_DR=copy_u8TransmitedData;
    while (GET_BIT(SPI1->SPI_SR,7)==1);
    *u8_ReceivedData=(u8)SPI1->SPI_DR;

}
