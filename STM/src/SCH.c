/*
 * SCH.c
 *
 *  Created on: Jun 11, 2023
 *      Author: amres
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"SCH_Interface.h"
#include"SCH_Private.h"
#include"SCH_Config.h"
#include"STK_Interface.h"
volatile u16 counter=0;
void OS_CreatTask( u8 Periority , u16 Periodicity, void (*ptr)(void) )
{
 OS_Task[Periority].Periodicity=Periodicity;
 OS_Task[Periority].fptr=ptr;

}
void OS_Start()
{

	STK_voidInit();

	STK_voidSetIntervalPeriodic(1000,scadular);

}


static void scadular()
{
	for(int i=0;i<Num_Tasks;i++)
	{
		if((counter%OS_Task[i].Periodicity)==0)
		{
			OS_Task[i].fptr();
		}
		counter++;
	}

}
