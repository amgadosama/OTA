/*
 * Bootloader.c
 *
 *  Created on: Jul 11, 2023
 *      Author: amres
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"USART_Interface.h"
#include "STK_Interface.h"
#include "RCC_Interface.h"
#include"NVIC_Interface.h"
#include"GPIO_Interface.h"
void BootLoader();
typedef void (*Function_t)(void);
Function_t addr_to_call = 0;
u8 TimeOut=0;
u8 RecieveData[100]={0};
void functiona(void)
{
#define SCB_VTOR   *((volatile u32*)0xE000ED08)

	SCB_VTOR = 0x08001000;

	addr_to_call = *(Function_t*)(0x08001004);
	addr_to_call();
}

void BootLoader()
{
	/*system initialization*/
	RCC_voidEnablePeripheralClk(AHB1,0);

	/*Need to Configure RCC For USART1 */
    /*Need to Configure RCC For PortA  */
	/*Need to Configure RCC For FPEC   */
MSTK_voidInit();
/**/

//////////////////////////////////////////////////////////////////////

 u8 UARTReturn=0;
 u8 counter=0;
 u8 ClearPage=1;
 MSTK_voidSetIntervalSingle(15000000,&functiona);

 while (TimeOut==0)
 {
	UARTReturn=USART_BTRecieve(&(RecieveData[counter]));
	 if(UARTReturn==1)
	 {
		 MSTK_voidStopInterval();

		 if(RecieveData[counter]=='\n')//means end of this line  in hex file
		 {
			 if(ClearPage==1)
			 {
				 	 /*FPEC->To Erase AppArea */
				 	  FPEC_voidEraseAppArea();
				 	 //We need to clear page at first time only so we put this to 0
				      ClearPage=0;
			 }

			 	 /*parser*/
        Parser_voidParseRecord(RecieveData);
        USART_voidTransmit("ok");
        counter=0;
		 }
		 else
		 {

			 counter++;

		 }
		 MSTK_voidSetIntervalSingle(15000000,&functiona);

	 }
 }
}
