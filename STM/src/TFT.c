/*
 * TFT.c
 *
 *  Created on: Jun 20, 2023
 *      Author: amres
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TFT_Interface.h"
#include "TFT_Private.h"
#include "TFT_Config.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include"SPI_Interface.h"
void init(u8 Copy_u8PortId,u8 Copy_u8PinId);
void TFT_voidINIT()
{
    init(TFT_RST_PIN);
    init(TFT_CS_PIN);
    init(TFT_A0_PIN);
    GPIO_voidSetPinMode(GPIOA, PIN5,  AF);
	GPIO_voidSetPinMode(GPIOA, PIN6, AF);
	GPIO_voidSetPinMode(GPIOA, PIN7, AF);

	GPIO_voidSetAFPinConfig(GPIOA, PIN5, AF5);
	GPIO_voidSetAFPinConfig(GPIOA, PIN6, AF5);
	GPIO_voidSetAFPinConfig(GPIOA, PIN7, AF5);
	//Reset Pulse sequence
	sendresetpulse();
	/* Sleep out command   */
	PRIVATE_voidSenfCMD(SLP_OUT_CMD);
	// delay 10ms
	MSTK_voidSetBusyWait(10000);

	//4-Colored Mode

	PRIVATE_voidSenfCMD(0x3A);

	//4.2  RGB565 SELECTION
	PRIVATE_voidSendata(0x05);

	//5-DisplayON
	PRIVATE_voidSenfCMD(0x29);
}

void TFT_voidDisplayimage(u16 *Image)
{
	u32 localcounter_array;
	/*Set x Dimentions */
	PRIVATE_voidSenfCMD(0x2A);
	/*start of x*/
	PRIVATE_voidSendata(0);
	PRIVATE_voidSendata(0);
	/*end of x*/
	PRIVATE_voidSendata(0);
	PRIVATE_voidSendata(127);

	/*Set y Dimentions */
	PRIVATE_voidSenfCMD(0x2B);
	/*start of y*/
	PRIVATE_voidSendata(0);
	PRIVATE_voidSendata(0);
	/*end of y*/
	PRIVATE_voidSendata(0);
	PRIVATE_voidSendata(159);

	/*RAm memory write Send Data*/
	PRIVATE_voidSenfCMD(0x2C);

	/*write on tft pixel by pixel MSB each pixel us 2B at each time send 1B*/
    for(localcounter_array=0; localcounter_array<20480;localcounter_array++)
    {
    	u8 Localu8low=(u8)Image[localcounter_array];
    	u8 Localu8High=(u8)(Image[localcounter_array]>>8);
    	PRIVATE_voidSendata(Localu8High);
    	PRIVATE_voidSendata(Localu8low);

    }

}
static void PRIVATE_voidSenfCMD(u8 Command)
{
	u8 Local_u8Temp=0;
	/*Select Command mode*/
	GPIO_voidSetPinValueDirectAccess(TFT_CS_PIN, PIN_RST);
	GPIO_voidSetPinValueDirectAccess(TFT_A0_PIN, PIN_RST);
	/*Send Command*/
	SPI_voidTransceive(Command, &Local_u8Temp);
	//(void)SPI_voidTranceive(Copy_u8Command);
	GPIO_voidSetPinValueDirectAccess(TFT_CS_PIN, PIN_SET);

}

static void PRIVATE_voidSendata(u8 DATA)
{
	u8 Local_u8Temp=0;
	/*Select Data mode*/
	GPIO_voidSetPinValueDirectAccess(TFT_CS_PIN, PIN_RST);
	GPIO_voidSetPinValueDirectAccess(TFT_A0_PIN, PIN_SET);
	/*Send Data*/
	SPI_voidTransceive(DATA, &Local_u8Temp);
	//(void)SPI_voidTranceive(Copy_u8Command);
	GPIO_voidSetPinValueDirectAccess(TFT_CS_PIN, PIN_SET);



}







static void sendresetpulse ()
{
	   GPIO_voidSetPinValueDirectAccess(TFT_RST_PIN,PIN_SET);
	   MSTK_voidSetBusyWait(1000);
	    GPIO_voidSetPinValueDirectAccess(TFT_RST_PIN,PIN_RST);
	    MSTK_voidSetBusyWait(10);
	    GPIO_voidSetPinValueDirectAccess(TFT_RST_PIN,PIN_SET);
	    MSTK_voidSetBusyWait(1000);
	    GPIO_voidSetPinValueDirectAccess(TFT_RST_PIN,PIN_RST);
	    MSTK_voidSetBusyWait(100000);
	    GPIO_voidSetPinValueDirectAccess(TFT_RST_PIN,PIN_SET);
	    MSTK_voidSetBusyWait(120000);
}

void init(u8 Copy_u8PortId,u8 Copy_u8PinId)
{
    GPIO_voidSetPinMode (Copy_u8PortId, Copy_u8PinId, OUTPUT);
    GPIO_voidSetPinType (Copy_u8PortId, Copy_u8PinId,OUTPUT_PP);
    GPIO_voidSetPinSpeed(Copy_u8PortId,Copy_u8PinId,OUTPUT_LS);
}
