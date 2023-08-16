/*
 * SERVO.c
 *
 *  Created on: Apr 16, 2023
 *      Author: amressam
 */

#include"../../STD_LIB/STD_TYPES.h"
#include"../../STD_LIB/BIT_MATH.h"
#include"SERVO_Interface.h"
#include"../../MCAL/TIMER1/TIMER1_Interface.h"

void Servo_Init()
{
	PWM1_Init();
	PWM1_SetFrequency(50);
	PWM1_Start();
}

u8 Servo_Angle(u8 Angle)
{
if(Angle<=180)
{
    f32 End=((f32)Angle/36.0)+5.0;
	PWM1_SetDutyCycle(End);
	return 0;
}
else
{
	//wrong angle
	return 1;
}


}
