/*
 * Stepper.c
 *
 *  Created on: Feb 25, 2023
 *      Author: amres
 */

//#include"../../STD_LIB/STD_TYPES.h"
//#include"../../MCAL/DIO/DIO_Interface.h"
//#include"Stepper_Interface.h"
//#include"Stepper_Config.h"
//#include<avr/delay.h>
//
//u8 z=0;
//void Stepper_stop()
//{
//	 DIO_SetPortValue(STEPPER_PORT,0x00);
//}
//
//void Stepper_INTI()
//{
//DIO_SetPinDirection(STEPPER_PORT,COIL_1,OUTPUT);
//DIO_SetPinDirection(STEPPER_PORT,COIL_2,OUTPUT);
//DIO_SetPinDirection(STEPPER_PORT,COIL_3,OUTPUT);
//DIO_SetPinDirection(STEPPER_PORT,COIL_4,OUTPUT);
//
//
//}
//void STEPPER_ClockWiseFullStep()
//{
//for(u8 i=1;i<=4;i++)
//{
//	Stepper_step(i,FULL);
//}
//
//}
//void STEPPER_UntiClockWiseFullStep()
//{
//	for(u8 i=4;i>=1;i--)
//	{
//		Stepper_step(i,FULL);
//	}
//}
//
//void Stepper_step(u8 step_num,u8 step_style)
//{
//
// if(step_style==FULL)
// {
//         switch(step_num)
//         {
//         case 1:
//                DIO_SetPortValue(STEPPER_PORT,0x01);
//        		_delay_ms(10);break;
//         case 2:
//    	 	    DIO_SetPortValue(STEPPER_PORT,0x02);
//        	 	_delay_ms(10);break;
//         case 3:
//                DIO_SetPortValue(STEPPER_PORT,0x04);
//      		    _delay_ms(10);break;
//
//         case 4:
//             DIO_SetPortValue(STEPPER_PORT,0x08);
//        		_delay_ms(10);break;
//
//         }
//
//	  }
//
//
// else if(step_style==HALF)
// {
//	         switch(step_num)
//	         {
//	         case 1: // AC COIL 1
//	        	 DIO_SetPortValue(STEPPER_PORT,0x01);
//	        		break;
//
//	         case 2: //COIL 1&2
//	        	 	 DIO_SetPortValue(STEPPER_PORT,0x03);
//	        	 	 _delay_ms(5);break;
//
//	         case 3: // COIL 2
//	        	 	 DIO_SetPortValue(STEPPER_PORT,0x02);
//	        	 	 _delay_ms(5);break;
//	         case 4:  // COIL 2&3
//	        	 	 DIO_SetPortValue(STEPPER_PORT,0x06);
//	        	 	 _delay_ms(5);break;
//
//	         case 5: // COIL 3
//					 DIO_SetPortValue(STEPPER_PORT,0x04);
//					 _delay_ms(5);break;
//	         case 6: // COIL 3&4
//				 DIO_SetPortValue(STEPPER_PORT,0x0C);
//				 _delay_ms(5);break;
//	         case 7: // COIL 4
//				 DIO_SetPortValue(STEPPER_PORT,0x08);
//				 _delay_ms(5);
//				 break;
//	         case 8: // COIL 4&1
//				 DIO_SetPortValue(STEPPER_PORT,0x09);
//				 _delay_ms(5);
//				 break;
//
//	         }
//
// }
//
//
//
//}
//
//void STEPPER_ClockWiseHalfSTEP()
//{
//	for(u8 i=1;i<=8;i++)
//	{
//		Stepper_step(i,HALF);
//	}
//}
//void STEPPER_UntiClockWiseHalfSTEP()
//{
//
//	for(u8 i=8;i>0;i--)
//	{
//		Stepper_step(i,HALF);
//	}
//}
//
//void Stepper_GoTostep(u8 step_num,u8 step_style)
//{
//	for(u8 i=1;i<=step_num;i++)
//			{
//		_delay_ms(5);
//		Stepper_step(i,step_style);
//			}
//
//}
