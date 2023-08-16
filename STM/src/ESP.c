/*
 * ESP.c
 *
 *  Created on: Jul 6, 2023
 *      Author: amres
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"ESP_Interface.h"
#include"ESP_Private.h"
#include"ESP_Config.h"
#include"USART_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "LCD_Interface.h"
u8 Translation_Complete();
void clear_buffer(void);
u8 Translation2_Complete(void);
u8 Translation3_Complete(void);
volatile u8 Data_Wifi[200];

/*
 * This function for Initialization
 * */
void ESP_Init()
{
	u8 result=0;
	/* Turn off Echo */
//	while(result==0)
//	{
//		MUSART1_VidSendStringSynch( (u8 *)"AT+RESTORE\r\n" );
//		result=Translation_Complete();
//		clear_buffer();
//	}
//
//	result=0;
//	while(result==0)
//	{
//		MUSART1_VidSendStringSynch( (u8 *)"AT+RST\r\n" );
//		result=Translation_Complete();
//		clear_buffer();
//	}
	while(result==0)
	{
		MUSART1_VidSendStringSynch( (u8 *)"ATE0\r\n" );
		result=Translation_Complete();
		clear_buffer();
	}
	MSTK_voidSetBusyWait(10000000);//WAIT 3 SEC

	result=0;
	/*Set Station mode */
	while(result==0)
		{
	MUSART1_VidSendStringSynch((u8 *)"AT+CWMODE=1\r\n");
	result=Translation_Complete();
	clear_buffer();
		}
//	MSTK_voidSetBusyWait(10000000);//WAIT 3 SEC
/*AT+CIPMODE=0*/

}


/*
 * This Function to get Connect throught Home WIfi
 * WIFI_Name:Name of network
 * Password:Password of network
 *
 * */

void Router_Connection(u8 *WIFI_Name,u8* Password)
{
	u8 recieve=0;

/*First send Command */
	while(recieve==0)
	{
	MUSART1_VidSendStringSynch((u8 *)"AT+CWJAP_CUR=\"");
	MUSART1_VidSendStringSynch((u8 *)WIFI_Name);
	MUSART1_VidSendStringSynch((u8 *)"\",\"" );
	MUSART1_VidSendStringSynch((u8 *)Password);
	MUSART1_VidSendStringSynch((u8 *)"\"\r\n");
	recieve=Translation_Complete();
	clear_buffer();
	}
	/*wait for 8 sec*/
//	for(u8 l=0;l<8;l++)
//	{
//		MSTK_voidSetBusyWait((10000000/3));//WAIT 3 SEC
//	}
}


/*
 * This Function to get Connect With Website
 * IP:IP of My Website
 * PORT:port value must be 80
 *  IP: is IP of my Website
 *
 * */
void ConnectToServer(u8 * IP,u8 *PORT)
{
	u8 recieve=0;
	while(recieve==0)
	{
	MUSART1_VidSendStringSynch((u8 *)"AT+CIPSTART=\"TCP\",\"" );
	MUSART1_VidSendStringSynch((u8 *)IP);
	MUSART1_VidSendStringSynch((u8 *)"\",");
	MUSART1_VidSendStringSynch((u8 *)PORT);
	MUSART1_VidSendStringSynch((u8 *)"\r\n");
	recieve=Translation3_Complete();
	clear_buffer();
	}
	MSTK_voidSetBusyWait((10000000)/3);
	MSTK_voidSetBusyWait((10000000)/3);
	MSTK_voidSetBusyWait((10000000)/3);
}
/*
 * This Function to get Connect With Website
 * WebAddress:LIKE amr.essam.freevar.com
 * Length:number of words in this  WebAddress
 *  IP: is IP of my Website
 *
 * */

u8 SendLength(u8 *Length)
{
	clear_buffer();
	u8 recieve=0;

	while(recieve==0)
	{
    MUSART1_VidSendStringSynch((u8 *)"AT+CIPSEND=" );
	MUSART1_VidSendStringSynch((u8 *)Length);
	MUSART1_VidSendStringSynch((u8 *)"\r\n");
	recieve=Translation2_Complete();
	}
	MSTK_voidSetBusyWait(10000000);

	return recieve;
 }




u8 SendData(void)
{
	u8 recieve=0;

	/*must wait for 4 sec try it*/
//	for(u8 l=0;l<7;l++)//need to reduce this
//	{
//		MSTK_voidSetBusyWait((10000000/3));//WAIT 4 SEC
//	}
	MSTK_voidSetBusyWait(10000000);
	MUSART1_VidSendStringSynch((u8 *)" GET http://amr.freevar.com/status.txt\r\n");
//	MUSART1_VidSendStringSynch((u8 *)WebAddress);
//	MUSART1_VidSendStringSynch((u8 *)"/state.txt\r\n" );// this is the file that have value from web
	recieve=Data_fromServer();

return recieve;
}
//	clear_buffer();
/*
 * This function To make sure that all data sent successfully by makeing sure that the resposnse is (OK)
 * */
u8 Data_fromServer(void)
{
	u8 iteration=0;
	u8 Dummy2=0;
	u8 Wifi_return=0;
	u8 flag=0;
	 clear_buffer();
	while(iteration<200)
	{
		Dummy2=USART_voidInhanceRecieve();
//		MSTK_voidSetBusyWait(10);
		Data_Wifi[iteration]=Dummy2;
		if(Data_Wifi[iteration]=='R')
		{
			MSTK_voidSetBusyWait(10);
		}
//		if(Data_Wifi[iteration]=='+')
//		{
//			iteration=0;
//		}
		iteration++;
	}

	for(u8 ch=0;ch<200;ch++)
	{
		if(Data_Wifi[ch]=='S'&&Data_Wifi[ch+1]=='E')
		  {
			for(u8 a=0;a<30;a++)
			 {
				if(Data_Wifi[ch+a]==':')
					{
							Wifi_return=Data_Wifi[ch+a+1];
							break;
					}
			 }
		  }
		else if(Data_Wifi[ch]=='E'&&Data_Wifi[ch+1]=='R')
		{
			Wifi_return=2;
			break;
		}
		else
		{
			Wifi_return=1;
		}
	}
return Wifi_return;
}
/*AT+CIPDINFO=1*/

u8 Translation_Complete()
{
	 u8 i=0;
	u8 Dummy=0;
u8 back=0;
	while(i<100)
	{
		Dummy=USART_voidInhanceRecieve();
		Data_Wifi[i]=Dummy;
		i++;
	}

	for(u8 ch=0;ch<100;ch++)
	{

		if(Data_Wifi[ch]=='O'&&Data_Wifi[ch+1]=='K')//when connect to ip //need to make for loop and check
		{

	      back=1;
	      break;
		}
	else if(Data_Wifi[ch]=='W'&&Data_Wifi[ch+1]== 'I')
		{
	      back=1;
	      break;
		}

	else if(Data_Wifi[ch]=='C'&&Data_Wifi[ch+1]=='O')
	{
	      back=1;
	      break;
	}
	else if(Data_Wifi[ch]=='A'&&Data_Wifi[ch+1]=='L')
		{
	      back=1;
	      break;
		}
	else if(Data_Wifi[ch]=='S'&&Data_Wifi[ch+1]=='E')
		{
	      back=1;
	      break;
		}
	}

return back;
}
/*
 * 1- you need to make uart_handler
 * 2- you need to do
 * */
void clear_buffer(void)
{
	for(u8 i=0;i<200;i++)

{
	Data_Wifi[i]=0;
}
}
u8 Translation3_Complete(void)
{
	 u8 i=0;
	u8 Dummy=0;
u8 back=0;
	while(i<200)
	{
		Dummy=USART_voidInhanceRecieve();
		Data_Wifi[i]=Dummy;
		if(Data_Wifi[i]=='K')
		{
			back=1;
			break;
		}
		if(Data_Wifi[i]=='D')
		{
			back=1;
			break;
		}
		i++;
	}

return back;
}
u8 Translation2_Complete(void)
{
	 u8 i=0;
	u8 Dummy=0;
u8 back=0;
	while(i<200)
	{
		Dummy=USART_voidInhanceRecieve();
		Data_Wifi[i]=Dummy;
		if(Data_Wifi[i]=='>')
		{
			MSTK_voidSetBusyWait(10000000);
			MSTK_voidSetBusyWait(10000000);
			back=SendData();

break;
		}
		else if(Data_Wifi[i]=='l')
		{
			back=1;
break;
		}
		i++;
	}

return back;
}
