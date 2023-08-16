/*
 * LCD_Config.h
 *
 *  Created on: Jul 26, 2023
 *      Author: amres
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define RS		PIN8              // h:Display Data ,L:Instruction
#define RW		PIN9   				// h:Read Operation ,L:Write Operation
#define E		PIN10  			// Read data when E is HIGH

#define Data_PORT		GPIOA
#define Control_Port	GPIOB

#define Data_PORT_Start		0
#define Data_PORT_END		8
#endif /* LCD_CONFIG_H_ */
