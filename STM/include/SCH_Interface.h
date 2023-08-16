/*
 * SCH_Interface.h
 *
 *  Created on: Jun 11, 2023
 *      Author: amres
 */

#ifndef SCH_INTERFACE_H_
#define SCH_INTERFACE_H_
#include"STD_TYPES.h"
void OS_CreatTask( u8 Periority , u16 Periodicity, void(*ptr)(void) );
void OS_Start();


#endif /* SCH_INTERFACE_H_ */
