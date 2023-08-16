/*
 * HLED_MATRIX_Interface.h
 *
 *  Created on: Aug 28, 2022
 *      Author: ahmed.hammad
 */

#ifndef HLED_MATRIX_INTERFACE_H_
#define HLED_MATRIX_INTERFACE_H_

void LEDMX_voidInit(void);

void LEDMX_voidDisplay(u8* Copy_u8Frame);

void LEDMX_voidDisplayLine(u8* Copy_u8Frame,u8 Copy_u8Length,u32 Copy_u32MoveDelay);
void displayName(u8 *array,u8 size_ofarray);

void LEDMX_voidClearDisplay(void);
void LEDM_STP(u8 *array,u8 size);

/**
 *
 * For LEDMATRIX With SR29RL
 * */


void LEDM_SR2PRL_ResetColumns();
void LEDM_STPSetColumns();
void LEDM_SR2PRL_SetRows();
void LEDM_STPvoidDisplay_Name(u8* Display_frame_data,u8 copy_u8size);
void LEDM_SR2PRLSendData(u8 Copy_u8RowData ,u8 Copy_u8ColNum);
void LEDM_SR2PRL_voidDisplay(u8* FrameData);
void SR2PRL_voidSendStoreClk();


void LEDMX_STP_voidDisplayLine(u8* Copy_u8Frame,u8 Copy_u8Length,u32 Copy_u32MoveDelay);
#endif /* HLED_MATRIX_INTERFACE_H_ */
