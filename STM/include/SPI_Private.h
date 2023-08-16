/*
 * SPI_Private.h
 *
 *  Created on: Jun 19, 2023
 *      Author: amres
 */

#ifndef SPI_Private_H_
#define SPI_Private_H_
typedef struct
{
volatile u32 SPI_CR1;
volatile u32 SPI_CR2;
volatile u32 SPI_SR;
volatile u32 SPI_DR;
}
SPI_t;

#define SPI1 ((volatile SPI_t*)  0x40013000)
#define SPI4 ((volatile SPI_t*)  0x40013400)
#define SPI3 ((volatile SPI_t*)  0x40003C00 )
#define SPI2 ((volatile SPI_t*)  0x40003800 )
#endif
