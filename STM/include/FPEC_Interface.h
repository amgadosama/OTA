/*
 * FPEC_Interface.h
 *
 *  Created on: Jul 11, 2023
 *      Author: amres
 */

#ifndef FPEC_INTERFACE_H_
#define FPEC_INTERFACE_H_
void FPEC_voidEraseAppArea(void);

void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber);

void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);


#endif /* FPEC_INTERFACE_H_ */
