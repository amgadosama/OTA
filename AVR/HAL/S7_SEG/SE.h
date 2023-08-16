/*
 * SE_Interface.h
 *
 *  Created on: Feb 13, 2023
 *      Author: amres
 */

#ifndef HAL_S7_SEG_SE_H_
#define HAL_S7_SEG_SE_H_

void SEV_SEG_INIT(u8 PORT_ID);
void SEV_COUNT_UP(u8 ns,u8 nf,u8 Port_ID,u16 delay);
void SEV_COUNT_DOWN(u8 ns,u8 nf,u8 PORT_ID,u16 delay);
void disp_number(u8 number,u8 Port_ID);
void clr_port(u8 port_id);
#endif /* HAL_S7_SEG_SE_H_ */
