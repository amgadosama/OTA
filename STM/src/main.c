#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include"HLED_MATRIX_Interface.h"
#include"HLED_MATRIX_Config.h"
#include"ESP_Interface.h"
#include"STK_Interface.h"
#include"NVIC_Interface.h"
#include"LCD_Interface.h"
#include"TFT_Interface.h"
#include"delay.h"
#include"STP_Interface.h"
#include"USART_Interface.h"
#include"USART2_Interface.h"
#include "Image1.h"
#include "Image2.h"
void Display_data(u8 Number);

//
//int main (void)
//{
//	/*RCC Init*/
//	RCC_voidInitSysClk();
//
//	/*GPIOA*/
//	RCC_voidEnablePeripheralClk(AHB1,0);
//	RCC_voidEnablePeripheralClk(AHB1,1);
//   /*SPI_INIT_CLOCK*/
//    RCC_voidEnablePeripheralClk(APB2, 12);
////	/*USART1*/
//	RCC_voidEnablePeripheralClk(APB2,4);
//	/*USART2*/
//	RCC_voidEnablePeripheralClk(APB1,17);
//
//	/*STK Init*/
//	MSTK_voidInit();
//
//
//
//	/*USART2 init*/
//	GPIO_voidSetPinMode(GPIOA,PIN2,OUTPUT);
//	GPIO_voidSetPinType(GPIOA,PIN2,OUTPUT_PP);
//	GPIO_voidSetPinSpeed(GPIOA,PIN2,OUTPUT_LS);
//
//
//
//	GPIO_voidSetPinMode(GPIOA,PIN2,AF);
//	GPIO_voidSetAFPinConfig(GPIOA,PIN2,AF7);
//
//	GPIO_voidSetPinMode(GPIOA,PIN3,AF);
//	GPIO_voidSetAFPinConfig(GPIOA,PIN3,AF7);
//
//	/*USART1 init*/
//USART2_voidInit();
////	USART2_voidInit();
//for(int i=0;i<8;i++)
//{
//	GPIO_voidSetPinMode(GPIOB,i,OUTPUT);
//	GPIO_voidSetPinType(GPIOB,i,OUTPUT_PP);
//	GPIO_voidSetPinSpeed(GPIOB,i,OUTPUT_LS);
//}
//
//u8 recieve=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	while(1)
//	{
//		GPIO_voidSetPinValue(GPIOB,PIN1,PIN_SET);
//		recieve=USART2_u8ReturnReceive();
//if(recieve==1)
//{
//	GPIO_voidSetPinValue(GPIOB,PIN0,PIN_SET);
//
//}
//if(recieve==0)
//{
//	GPIO_voidSetPinValue(GPIOB,PIN0,PIN_RST);
//
//}
//
//	}
//
//
//
//}




















//#include "Image3.h"
//#include "Image4.h"
//#include"WiFi_interface.h"
u8 arr=1;
u8 recive;
u8 AMR[] = {0, 0, 127, 136, 136, 136, 127, 0,0, 0, 127, 32, 16, 32, 127, 0,0, 127, 72, 72, 72, 55, 0, 0};
u8 AMGAD[] = { 0, 0, 127, 136, 136, 136, 127, 0,0, 0, 127, 32, 16, 32, 127, 0,0, 62, 65, 73, 73, 70, 0, 0,0, 0, 127, 136, 136, 136, 127, 0,0, 0, 127, 65, 65, 65, 62, 0};
u8 Mohamed[]={0, 0, 127, 32, 16, 32, 127, 0, 0, 62, 65, 65, 65, 65, 62, 0, 0, 255, 16, 16, 16, 16, 255, 0, 0, 0, 127, 32, 16, 32, 127, 0, 0, 127, 73, 73, 73, 73, 0, 0, 0, 0, 127, 65, 65, 65, 62, 0};
u8 Fawzy[]={0, 0, 127, 72, 72, 72, 64, 0,0, 0, 127, 136, 136, 136, 127, 0,0, 127, 2, 4, 2, 127, 0, 0,0, 67, 69, 73, 81, 97, 0, 0,0, 0, 96, 16, 15, 16, 96, 0};






int main (void)
{
	/*RCC Init*/
	RCC_voidInitSysClk();

	/*GPIOA*/
	RCC_voidEnablePeripheralClk(AHB1,0);
	RCC_voidEnablePeripheralClk(AHB1,1);
   /*SPI_INIT_CLOCK*/
    RCC_voidEnablePeripheralClk(APB2, 12);
//	/*USART1*/
	RCC_voidEnablePeripheralClk(APB2,4);
	/*USART2*/
	RCC_voidEnablePeripheralClk(APB1,17);

	/*STK Init*/
	MSTK_voidInit();



	/*USART2 init*/
	GPIO_voidSetPinMode(GPIOA,PIN2,OUTPUT);
	GPIO_voidSetPinType(GPIOA,PIN2,OUTPUT_PP);
	GPIO_voidSetPinSpeed(GPIOA,PIN2,OUTPUT_LS);
	GPIO_voidSetPinMode(GPIOA,PIN2,AF);
	GPIO_voidSetAFPinConfig(GPIOA,PIN2,AF7);

	GPIO_voidSetPinMode(GPIOA,PIN3,AF);
	GPIO_voidSetAFPinConfig(GPIOA,PIN3,AF7);

	/*USART1 init*/
	GPIO_voidSetPinMode(GPIOA,PIN9,OUTPUT);
	GPIO_voidSetPinType(GPIOA,PIN9,OUTPUT_PP);
	GPIO_voidSetPinSpeed(GPIOA,PIN9,OUTPUT_LS);
	GPIO_voidSetPinMode(GPIOA,PIN9,AF);
	GPIO_voidSetAFPinConfig(GPIOA,PIN9,AF7);

	GPIO_voidSetPinMode(GPIOA,PIN10,AF);
	GPIO_voidSetAFPinConfig(GPIOA,PIN10,AF7);
USART_voidInit();
//	USART2_voidInit();
USART2_voidInit();
SPI_voidinti();
	 STP_voidInit();
	 TFT_voidINIT();
		GPIO_voidSetPinMode(GPIOA,PIN11,OUTPUT);
		GPIO_voidSetPinType(GPIOA,PIN11,OUTPUT_PP);
		GPIO_voidSetPinSpeed(GPIOA,PIN11,OUTPUT_LS);
	u8 ReceiveData='1';
u8 ReceiveData2=0;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	while(1)
	{
/*
 * make a flag
 * */
		while(ReceiveData2!='a')
		{
		ReceiveData2=USART_voidInhanceRecieve();
		ReceiveData=USART2_voidInhanceRecieve();
		GPIO_voidSetPinValue(GPIOA,PIN11,PIN_SET);
		if(ReceiveData!=0)
			{
				Display_data(ReceiveData);
			}
		}
		ReceiveData=0;
		while(ReceiveData!='a')
			{
			GPIO_voidSetPinValue(GPIOA,PIN11,PIN_RST);
			ReceiveData=USART_voidInhanceRecieve();
			if(ReceiveData!='a')
				{
					Display_data(ReceiveData);
				}
			if(ReceiveData=='a')
				break;
			}
		ReceiveData2=0;


	}
}
void Display_data(u8 Number)
{
	if(Number=='1')
			{
				TFT_voidDisplayimage(&array_h2);
				LEDM_STPvoidDisplay_Name(AMGAD,((sizeof(AMGAD)) / (sizeof(u8)) ) + 2);

MUSART1_VidSendCharSync('1');
			}
			else if(Number=='2')
			{
				LEDM_STPvoidDisplay_Name(Fawzy,((sizeof(Fawzy)) / (sizeof(u8)) ) + 2);
				MUSART1_VidSendCharSync('1');
			}
			else if(Number=='3')
			{
				TFT_voidDisplayimage(&array_h);
				LEDM_STPvoidDisplay_Name(AMR,( (sizeof(AMR)) / (sizeof(u8)) ) + 2);
				MUSART1_VidSendCharSync('1');
			}
			else if(Number=='4')
			{
				LEDM_STPvoidDisplay_Name(Mohamed,((sizeof(Mohamed)) / (sizeof(u8)) ) + 2);
				MUSART1_VidSendCharSync('1');

			}
}




















//u8 AMR[] = { 28, 34, 34, 62, 34, 34, 34, 0,34, 54, 42, 34, 34, 34, 34, 0,30, 34, 34, 30, 34, 34, 34, 0};
//u8 AMGAD[] = { 28, 34, 34, 62, 34, 34, 34, 0, 34, 54, 42, 34, 34, 34, 34, 0,62, 2, 2, 58, 34, 34, 62, 0,28, 34, 34, 62, 34, 34, 34, 0,30, 34, 34, 34, 34, 34, 30, 0};
//u8 Mohamed[]={34, 54, 42, 34, 34, 34, 34, 0, 0, 0, 28, 34, 34, 34, 28, 0, 2, 2, 2, 62, 34, 34, 34, 0,0, 0, 28, 34, 34, 18, 44, 0,0, 0, 22, 42, 42, 34, 34, 0,0, 0, 28, 34, 30, 2, 60, 0,32, 32, 60, 34, 34, 34, 28, 0};
//u8 Fawzy[]={62, 2, 2, 30, 2, 2, 2, 0,0, 0, 28, 34, 34, 18, 44, 0,0, 0, 34, 34, 34, 42, 20, 0,0, 0, 62, 16, 8, 4, 62, 0,0, 0, 34, 34, 62, 32, 32, 62};
//void main()
//{
//		/*Init System Clock*/
//		RCC_voidInitSysClk();
//
//		/*Enable Clk for GPIOA-GPIOB-USART1*/
//		RCC_voidEnablePeripheralClk(AHB1, 0);
//		RCC_voidEnablePeripheralClk(AHB1, 1);
//	    RCC_voidEnablePeripheralClk(APB2, 12);
//		RCC_voidEnablePeripheralClk(APB2, 4);
//
//		/*Configure Tx (PA9), Rx (PA10) as AF Pins*/
//		GPIO_voidSetPinMode(GPIOA, PIN10, AF);
//		GPIO_voidSetPinMode(GPIOA, PIN9, AF);
//		/*Configure Them as UART AF Pins ==> AF7*/
//		GPIO_voidSetAFPinConfig(GPIOA, PIN10, AF7);
//		GPIO_voidSetAFPinConfig(GPIOA, PIN9, AF7);
//		for(int i=0;i<=1;i++)
//			{
//			GPIO_voidSetPinMode(GPIOB,i,OUTPUT);
//			GPIO_voidSetPinType(GPIOB,i,OUTPUT_PP);
//			GPIO_voidSetPinSpeed(GPIOB,i,OUTPUT_LS);
//			}
//
//MSTK_voidInit();
///*Intilization for STP*/
// STP_voidInit();
//		while(1)
//		{
//			LEDM_STPvoidDisplay_Name(Fawzy,42);
//		}
//
//}
//
//


/*this for tft*/
//void main()
//{
//		/*Init System Clock*/
//		RCC_voidInitSysClk();
//
//		/*Enable Clk for GPIOA-GPIOB-USART1*/
//		RCC_voidEnablePeripheralClk(AHB1, 0);
//		RCC_voidEnablePeripheralClk(AHB1, 1);
//	    RCC_voidEnablePeripheralClk(APB2, 12);
//		RCC_voidEnablePeripheralClk(APB2, 4);
//
//		/*Configure Tx (PA9), Rx (PA10) as AF Pins*/
//		GPIO_voidSetPinMode(GPIOA, PIN10, AF);
//		GPIO_voidSetPinMode(GPIOA, PIN9, AF);
//		/*Configure Them as UART AF Pins ==> AF7*/
//		GPIO_voidSetAFPinConfig(GPIOA, PIN10, AF7);
//		GPIO_voidSetAFPinConfig(GPIOA, PIN9, AF7);
//		for(int i=0;i<=1;i++)
//			{
//			GPIO_voidSetPinMode(GPIOB,i,OUTPUT);
//			GPIO_voidSetPinType(GPIOB,i,OUTPUT_PP);
//			GPIO_voidSetPinSpeed(GPIOB,i,OUTPUT_LS);
//			}
//SPI_voidinti();
//
//
///*Intilization for TFT*/
//		TFT_voidINIT();
//
//
//
//		TFT_voidDisplayimage(&array_h);
//		while(1)
//		{
//
//		}
//
//}


/*
 * this for esp8266*/
//
//
//void main()
//{
//		/*Init System Clock*/
//		RCC_voidInitSysClk();
//
//		/*Enable Clk for GPIOA-GPIOB-USART1*/
//		RCC_voidEnablePeripheralClk(AHB1, 0);
//		RCC_voidEnablePeripheralClk(AHB1, 1);
//	    RCC_voidEnablePeripheralClk(APB2, 12);
//		RCC_voidEnablePeripheralClk(APB2, 4);
//
//		/*Configure Tx (PA9), Rx (PA10) as AF Pins*/
//		GPIO_voidSetPinMode(GPIOA, PIN10, AF);
//		GPIO_voidSetPinMode(GPIOA, PIN9, AF);
//		/*Configure Them as UART AF Pins ==> AF7*/
//		GPIO_voidSetAFPinConfig(GPIOA, PIN10, AF7);
//		GPIO_voidSetAFPinConfig(GPIOA, PIN9, AF7);
//		for(int i=0;i<=1;i++)
//			{
//			GPIO_voidSetPinMode(GPIOB,i,OUTPUT);
//			GPIO_voidSetPinType(GPIOB,i,OUTPUT_PP);
//			GPIO_voidSetPinSpeed(GPIOB,i,OUTPUT_LS);
//			}
////SEND OK +IPD,449
//		/*USART Init*/
//		USART_voidInit();
//		/*SYSTIC INIT*/
//		MSTK_voidInit();
////		MNVIC_voidEnablePerInt(37);
///*ESP8266 Intialization*/
//		ESP_Init();
//		Router_Connection("Wi-Fi","Eabd1234@@");
//u8 Done_Reciveing=0;
//	while(1)
//	{
///*Here function to Recieve*/
//		ConnectToServer((u8*)"23.179.32.37","80");
//			Done_Reciveing=SendLength((u8*)"38");
//
//
////		ESP_voidConnectToServer("23.179.32.37", "80");
//		/* Send the reqest as string*/
////		Done_Reciveing = ESP_u8ExecuteRequest("GET http://amr.freevar.com/state.txt");
////		    Done_Reciveing=SendData("amr.freevar.com");
//
//		if(Done_Reciveing=='1')
//		{
//			GPIO_voidSetPinValue(GPIOB,PIN0,PIN_SET);
//		}
//		else if(Done_Reciveing=='0')
//		{
//			GPIO_voidSetPinValue(GPIOB,PIN0,PIN_RST);
//		}
//
//	}
//}
