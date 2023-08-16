#include"../include/BIT_MATH.h"
#include"../include/STD_TYPES.h"
#include"../include/GPIO_Interface.h"
#include"../include/GPIO_Private.h"
#define Zero    0x7E
#define One     0x30
#define Two     0x6D
#define Three   0x79
#define Four    0x33
#define Five    0x5B
#define Six     0x5F
#define Seven   0x70
#define Eight   0x7F
#define Nine    0x7B


void Seven_segmentNUMBER_Display(u8 Port_Id,u8 Number)
{
switch(Port_Id)
	{
case GPIOA:
	switch(Number)
	  {
	case 0:GPIOA_ODR=Zero; break;
	case 1:GPIOA_ODR=One; break;
	case 2:GPIOA_ODR=Two; break;
	case 3:GPIOA_ODR=Three; break;
	case 4:GPIOA_ODR=Four; break;
	case 5:GPIOA_ODR=Five; break;
	case 6:GPIOA_ODR=Six; break;
	case 7:GPIOA_ODR=Seven; break;
	case 8:GPIOA_ODR=Eight; break;
	case 9:GPIOA_ODR=Nine; break;
	default:break;
	 }break;
	case GPIOB:
		switch(Number)
		  {
		case 0:GPIOB_BSRR=Zero; break;
		case 1:GPIOB_BSRR=One; break;
		case 2:GPIOB_BSRR=Two; break;
		case 3:GPIOB_BSRR=Three; break;
		case 4:GPIOB_BSRR=Four; break;
		case 5:GPIOB_BSRR=Five; break;
		case 6:GPIOB_BSRR=Six; break;
		case 7:GPIOB_BSRR=Seven; break;
		case 8:GPIOB_BSRR=Eight; break;
		case 9:GPIOB_BSRR=Nine; break;
		default:break;
		 }break;

	  }
}
