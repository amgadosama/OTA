/*
 * UART_Interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: amres
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
 /*stop bit/parity check/ Synch orAsynch / baud rate/ enable for transimetr and receiver circuits  */
void UART_Init();

void UART_Transimit_char(u8 Data);
void UART_Transimit_string(u8 *string);

u8 UART_Recieve();
u8 UART_Recieve_string(u8 *string);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
