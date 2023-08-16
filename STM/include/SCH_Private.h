/*
 * SCH_Private.h
 *
 *  Created on: Jun 11, 2023
 *      Author: amres
 */

#ifndef SCH_PRIVATE_H_
#define SCH_PRIVATE_H_
#include"SCH_Config.h"
typedef struct
{
	u16 Periodicity;
	void(*fptr)(void);
}Task;

static Task OS_Task[Num_Tasks]={0};
static void scadular();
#endif /* SCH_PRIVATE_H_ */
