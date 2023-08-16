#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "HLED_MATRIX_Private.h"
#include "HLED_MATRIX_Interface.h"
#include "STP_Interface.h"
#include "HLED_MATRIX_Config.h"
#include "STP_Config.h"



void LEDMX_voidClearColumns(){
		GPIO_voidSetPinValueDirectAccess(LEDMX_Column1,PIN_SET);
		GPIO_voidSetPinValueDirectAccess(LEDMX_Column2,PIN_SET);
		GPIO_voidSetPinValueDirectAccess(LEDMX_Column3,PIN_SET);
		GPIO_voidSetPinValueDirectAccess(LEDMX_Column4,PIN_SET);
		GPIO_voidSetPinValueDirectAccess(LEDMX_Column5,PIN_SET);
		GPIO_voidSetPinValueDirectAccess(LEDMX_Column6,PIN_SET);
		GPIO_voidSetPinValueDirectAccess(LEDMX_Column7,PIN_SET);
		GPIO_voidSetPinValueDirectAccess(LEDMX_Column8,PIN_SET);
}

 void LEDMX_voidClearRows(){
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW1,PIN_RST);
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW2,PIN_RST);
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW3,PIN_RST);
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW4,PIN_RST);
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW5,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(LEDMX_ROW6,PIN_RST);
  	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW7,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(LEDMX_ROW8,PIN_RST);


}


 void LEDMX_voidSetRowValue(u8 Copy_u8RowValue){
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW1,!(GET_BIT(Copy_u8RowValue,0)));
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW2,!(GET_BIT(Copy_u8RowValue,1)));
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW3,!(GET_BIT(Copy_u8RowValue,2)));
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW4,!(GET_BIT(Copy_u8RowValue,3)));
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW5,!(GET_BIT(Copy_u8RowValue,4)));
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW6,!(GET_BIT(Copy_u8RowValue,5)));
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW7,!(GET_BIT(Copy_u8RowValue,6)));
	GPIO_voidSetPinValueDirectAccess(LEDMX_ROW8,!(GET_BIT(Copy_u8RowValue,7)));
}


void LEDMX_voidDisplayLine(u8* Copy_u8Frame,u8 Copy_u8Length,u32 Copy_u32MoveDelay){
	u8 strs[8];
	u32 temp_lcdFrame=0;
	while(temp_lcdFrame<Copy_u8Length){
	for(u8 temp_counter3=0;temp_counter3<8;temp_counter3++){
					strs[temp_counter3]=Copy_u8Frame[(temp_lcdFrame+temp_counter3)%Copy_u8Length];
				}

				//LEDMX_voidDisplay(ab+8);
				for(u8 temp_counter=0;temp_counter<Copy_u32MoveDelay;temp_counter++)
				{

					//LEDMX_voidDisplay(&strm[0]+(temp_lcdFrame%8));
					LEDMX_voidDisplay(&strs[0]);

				}
				temp_lcdFrame++;

	}
}


void LEDMX_voidDisplay(u8* Copy_u8Frame){

	//LEDMX_voidClearDisplay();

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[0]);
	GPIO_voidSetPinValueDirectAccess(LEDMX_Column1,PIN_RST);
	MSTK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[1]);
	GPIO_voidSetPinValueDirectAccess(LEDMX_Column2,PIN_RST);
	MSTK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[2]);
	GPIO_voidSetPinValueDirectAccess(LEDMX_Column3,PIN_RST);
	MSTK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[3]);
	GPIO_voidSetPinValueDirectAccess(LEDMX_Column4,PIN_RST);
	MSTK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[4]);
	GPIO_voidSetPinValueDirectAccess(LEDMX_Column5,PIN_RST);
	MSTK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[5]);
	GPIO_voidSetPinValueDirectAccess(LEDMX_Column6,PIN_RST);
	MSTK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[6]);
	GPIO_voidSetPinValueDirectAccess(LEDMX_Column7,PIN_RST);
	MSTK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[7]);
	GPIO_voidSetPinValueDirectAccess(LEDMX_Column8,PIN_RST);
	MSTK_voidSetBusyWait(2500);




}
//void displayName(u8 *array,u8 size_ofarray)
//{
//	 u16 x=0;
//	for(int i=0;i<size_ofarray/8;i++)
//	{
//		while(flag!=1)
//			for(int j=0;j<8;j++)
//		{
//
//			LEDMX_voidClearColumns();
//			if(i==0)
//			LEDMX_voidSetRowValue(array[j]);
//			else
//			LEDMX_voidSetRowValue(array[j+x]);
//			GPIO_voidSetPinValueDirectAccess(GPIOA,j,PIN_RST);
//			x++;
//			MSTK_voidSetBusyWait(2500);}
//	    }
//}


void LEDM_voidDisplay_NAME(u8* Display_frame_data,u8 copy_u8size){
static u8 counter_letters=0;
for(counter_letters=0;counter_letters<(copy_u8size);){
	static u8 Frame=0;
	LEDMX_voidDisplay(Display_frame_data+counter_letters);
	Frame++;
	if(Frame==250){
		counter_letters++;
		Frame=0;
	}
}
}
void LEDM_STP(u8 *array,u8 size)
{
for(int i=0;i<size;i++)
{
//send columns value
STP_voidSendSynch(0xAA);
MSTK_voidSetBusyWait(2500);
//send Rows value
   LEDMX_voidSetRowValue(array[i]);
   STP_voidSendSynch((0b11111111)<<(i+1));
	MSTK_voidSetBusyWait(2500);
}
}
void LEDMX_voidInit(){
	GPIO_voidSetPinMode(LEDMX_ROW1   ,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_ROW2   ,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_ROW3   ,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_ROW4   ,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_ROW5   ,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_ROW6   ,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_ROW7   ,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_ROW8   ,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_Column1,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_Column2,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_Column3,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_Column4,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_Column5,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_Column6,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_Column7,OUTPUT);
	GPIO_voidSetPinMode(LEDMX_Column8,OUTPUT);

	GPIO_voidSetPinPUPDOption(LEDMX_ROW1   ,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_ROW2   ,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_ROW3   ,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_ROW4   ,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_ROW5   ,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_ROW6   ,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_ROW7   ,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_ROW8   ,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_Column1,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_Column2,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_Column3,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_Column4,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_Column5,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_Column6,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_Column7,OUTPUT_PP);
	GPIO_voidSetPinPUPDOption(LEDMX_Column8,OUTPUT_PP);


	GPIO_voidSetPinSpeed(LEDMX_ROW1   ,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_ROW2   ,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_ROW3   ,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_ROW4   ,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_ROW5   ,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_ROW6   ,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_ROW7   ,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_ROW8   ,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_Column1,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_Column2,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_Column3,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_Column4,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_Column5,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_Column6,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_Column7,OUTPUT_LS);
	GPIO_voidSetPinSpeed(LEDMX_Column8,OUTPUT_LS);

	LEDMX_voidClearDisplay();


}







void LEDMX_voidClearDisplay(void){
	LEDMX_voidClearColumns();
	LEDMX_voidClearRows();

}



/*
 * LEDMATRIX WITH SR2PRL
 * */

void SR2PRL_voidSendStoreClk()
{
	GPIO_voidSetPinValue(STP_STORE_CLK_PIN,PIN_SET);
	MSTK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(STP_STORE_CLK_PIN,PIN_RST);
	MSTK_voidSetBusyWait(1);

}
void SR2PRL_voidSendShiftClk()
{


	GPIO_voidSetPinValue(STP_SHIFT_CLK_PIN, PIN_SET);
	MSTK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(STP_SHIFT_CLK_PIN, PIN_RST);
	MSTK_voidSetBusyWait(1);

}


void LEDM_SR2PRL_SetOneCol(u8 Copy_U8ColNum)
{
	s8 Local_s8Counter;
		for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter--)
		{
			if(Local_s8Counter == Copy_U8ColNum)
			{
				GPIO_voidSetPinValue(STP_SERIAL_PIN,PIN_SET);
			}
			else
			{
				GPIO_voidSetPinValue(STP_SERIAL_PIN,PIN_RST);
			}

			SR2PRL_voidSendShiftClk();
		}
}

void LEDM_SR2PRL_ResetColumns()
{
	// disable all columns
	s8 Local_s8Counter;
		for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter--)
		{
			GPIO_voidSetPinValue(STP_SERIAL_PIN,PIN_RST);
			/*Send Pulse on Shift Clk Pin*/
			SR2PRL_voidSendShiftClk();
		}
}

void LEDM_STPSetColumns()
{
	s8 Local_s8Counter;
		for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter++)
		{
			GPIO_voidSetPinValue(STP_SERIAL_PIN,PIN_SET);
			SR2PRL_voidSendShiftClk();
		}
}

void LEDM_SR2PRL_SetRows()
{
	// set all rows
	s8 Local_s8Counter;
	for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter--)
	{
		GPIO_voidSetPinValue(STP_SERIAL_PIN,PIN_SET);
		/*Send Pulse on Shift Clk Pin*/
		SR2PRL_voidSendShiftClk();
	}
}
void LEDM_SR2PRLSendData(u8 Copy_u8RowData ,u8 Copy_u8ColNum)
{
	s8 Local_s8Counter;
	// enable column
	LEDM_SR2PRL_SetOneCol(Copy_u8ColNum) ;
	//out data on row
	for(Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter-- )
	{
		GPIO_voidSetPinValue(STP_SERIAL_PIN , GET_BIT(Copy_u8RowData,Local_s8Counter));
		SR2PRL_voidSendShiftClk();
	}
}

void LEDM_SR2PRL_voidDisplay(u8* FrameData)
{
    LEDM_SR2PRL_ResetColumns();
    LEDM_SR2PRL_SetRows();
    SR2PRL_voidSendStoreClk();

    u8 Local_u8Counter;
    for(Local_u8Counter=0 ; Local_u8Counter<8 ; Local_u8Counter++)
    {
    	LEDM_SR2PRLSendData(FrameData[Local_u8Counter] ,Local_u8Counter);
    	MSTK_voidSetBusyWait(150);
		SR2PRL_voidSendStoreClk();
		LEDM_SR2PRL_ResetColumns();
		LEDM_SR2PRL_SetRows();
		SR2PRL_voidSendStoreClk();
    }
}
void LEDM_STPvoidDisplay_Name(u8* Display_frame_data,u8 copy_u8size)
{
	static u8 LetterCount=0;
	for(LetterCount=0 ; LetterCount<(copy_u8size-8) ; )
	{
		static u8 Frame=0;
		LEDM_SR2PRL_voidDisplay(Display_frame_data + LetterCount);
		Frame++;
		if(Frame==70)
		{
			LetterCount++;
			Frame=0;
		}
	}
}

void LEDMX_STP_voidDisplayLine(u8* Copy_u8Frame,u8 Copy_u8Length,u32 Copy_u32MoveDelay){
	u8 strs[8];
	u32 temp_lcdFrame=0;
	while(temp_lcdFrame<Copy_u8Length){
	for(u8 temp_counter3=0;temp_counter3<8;temp_counter3++){
					strs[temp_counter3]=Copy_u8Frame[(temp_lcdFrame+temp_counter3)%Copy_u8Length];
				}

				//LEDMX_voidDisplay(ab+8);
				for(u8 temp_counter=0;temp_counter<Copy_u32MoveDelay;temp_counter++)
				{

					//LEDMX_voidDisplay(&strm[0]+(temp_lcdFrame%8));
					LEDM_SR2PRL_voidDisplay(&strs[0]);

				}
				temp_lcdFrame++;

	}
}

