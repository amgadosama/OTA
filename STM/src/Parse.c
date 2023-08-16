/*
 * Parser.c
 *
 *  Created on: Jul 11, 2023
 *      Author: amres
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FPEC_Interface.h"

u16 ReciveData[100] = {0};
u32 Address= 0x08000000;

u8 AsciToHex(u8 Copy_u8Asci)
{
	u8 Result;
	if ( (Copy_u8Asci >= 48) && (Copy_u8Asci <= 57) )
	{
		Result = Copy_u8Asci - 48;
	}

	else
	{
		Result = Copy_u8Asci - 55;
	}

	return Result;
}


void ParseReciveData(u8* Copy_u8BufReciveData)
{
	u8 DigitLow,DigitHigh,CC,i;
	u8 ReciveDataDigit0,ReciveDataDigit1,ReciveDataDigit2,ReciveDataDigit3;
	u8 ReciveDataCounter = 0;

	/* Get Character Count */
	DigitHigh = AsciToHex (Copy_u8BufReciveData[1]);
	DigitLow  = AsciToHex (Copy_u8BufReciveData[2]);
	CC        = (DigitHigh<<4) | DigitLow ;

	/* Get Address */
	ReciveDataDigit0 = AsciToHex (Copy_u8BufReciveData[3]);
	ReciveDataDigit1 = AsciToHex (Copy_u8BufReciveData[4]);
	ReciveDataDigit2 = AsciToHex (Copy_u8BufReciveData[5]);
	ReciveDataDigit3 = AsciToHex (Copy_u8BufReciveData[6]);

	/* Clear Low Part of Address */
	Address = Address & 0xFFFF0000;
	Address = Address | (ReciveDataDigit3) | (ReciveDataDigit2 << 4) | (ReciveDataDigit1 << 8) | (ReciveDataDigit0<<12);

	for (i=0;i<CC/2; i++)
	{
		ReciveDataDigit0 = AsciToHex (Copy_u8BufReciveData[4*i+9 ]);
		ReciveDataDigit1 = AsciToHex (Copy_u8BufReciveData[4*i+10]);
		ReciveDataDigit2 = AsciToHex (Copy_u8BufReciveData[4*i+11]);
		ReciveDataDigit3 = AsciToHex (Copy_u8BufReciveData[4*i+12]);

		ReciveData[ReciveDataCounter] = (ReciveDataDigit3 << 8) | (ReciveDataDigit2 << 12) | (ReciveDataDigit1) | (ReciveDataDigit0<<4);
		ReciveDataCounter++;
	}

	FPEC_voidFlashWrite(Address,ReciveData,CC/2);
}

void ParseUpperAddress(u8* Copy_u8BufReciveData)
{
	u8 ReciveDataDigit0,ReciveDataDigit1,ReciveDataDigit2,ReciveDataDigit3;

	/* Get Address */
	ReciveDataDigit0 = AsciToHex (Copy_u8BufReciveData[3]);
	ReciveDataDigit1 = AsciToHex (Copy_u8BufReciveData[4]);
	ReciveDataDigit2 = AsciToHex (Copy_u8BufReciveData[5]);
	ReciveDataDigit3 = AsciToHex (Copy_u8BufReciveData[6]);

	/* Clear Low Part of Address */
	Address = Address & (u32)0x0000FFFF;
	Address = Address | (u32)((u32)(ReciveDataDigit3 << 28) | (u32)(ReciveDataDigit2 << 24) | (u32)(ReciveDataDigit1 << 20) | (u32)(ReciveDataDigit0 << 16));
}

void Parser_voidParseRecord(u8* Copy_u8BufReciveData)
{
	switch (Copy_u8BufReciveData[8])
	{
	case '0': ParseReciveData(Copy_u8BufReciveData); break;
	case '4': ParseUpperAddress(Copy_u8BufReciveData); break;
	}
}
