/*
 * config.h
 *
 *  Created on: Feb 18, 2023
 *      Author: amres
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define RS		PIN0               // h:Display Data ,L:Instruction
#define RW		PIN1   				// h:Read Operation ,L:Write Operation
#define E		PIN2  			// Read data when E is HIGH

#define Data_PORT		DIO_PORTA
#define Control_Port	DIO_PORTC

#endif /* HAL_LCD_CONFIG_H_ */
