/*
 * UART_Register.h
 *
 *  Created on: Apr 2, 2023
 *      Author: amres
 */

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UDR_REG  	*((volatile u8*)0x2C)
#define UCSRA_REG	*((volatile u8*)0x2B)
#define UCSRB_REG	*((volatile u8*)0x2A)
#define UCSRC_REG	*((volatile u8*)0x40)
#define UBRRL_REG	*((volatile u8*)0x29)


#endif /* MCAL_UART_UART_REGISTER_H_ */
