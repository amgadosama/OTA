/*
 * UART.c
 *
 *  Created on: Apr 2, 2023
 *      Author: amressam
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include"UART_Interface.h"
#include"UART_Register.h"

void UART_Init()
{
	//select UCSRC register
		SET_BIT(UCSRC_REG,7);
		//select stop bits(2 bits)
		SET_BIT(UCSRC_REG,3);
		//select parity check(Disable)
		CLR_BIT(UCSRC_REG,4);
		CLR_BIT(UCSRC_REG,5);
		//select character size (8bit)
		SET_BIT(UCSRC_REG,1);
		SET_BIT(UCSRC_REG,2);
		CLR_BIT(UCSRB_REG,2);
		//select Asynchronous Mode
		CLR_BIT(UCSRC_REG,6);

		//Set Baud Rate to 9600
		UBRRL_REG = 51;

		//enable for Tx Circuit
		SET_BIT(UCSRB_REG,3);

		//enable for Rx Cirucit
		SET_BIT(UCSRB_REG,4);


}


void UART_Transimit_char(u8 Data)
{
	//wait until UDR is empty
	while(GET_BIT(UCSRA_REG,5)==0);

	//put data in UDR
	UDR_REG=Data;

	//wait until transmitting is compelet
	while(GET_BIT(UCSRA_REG,6)==0);

}
void UART_Transimit_string(u8 *string)
{
	//wait until UDR is empty
	while(GET_BIT(UCSRA_REG,5)==0);

	//put data in UDR
	while(*string!='\0')
	{
		UART_Transimit_char(*string);
		string++;
	}

	//wait until transmitting is compelet
	while(GET_BIT(UCSRA_REG,6)==0);

}
u8 UART_Recieve()
{
	//wait until receive is complete
	while(GET_BIT(UCSRA_REG,7)==0);
	//return data
	return UDR_REG;

}
u8 UART_Recieve_string(u8 *string)
{
u8 i=0;
string[i]=UART_Recieve();
while(string[i]!='\0')//error here
{
	i++;
	string[i]=UART_Recieve();
}


return i;
}



