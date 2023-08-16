/*
 * DCMotor_Interface.h
 *
 *  Created on: Feb 27, 2023
 *      Author: amres
 */
#include<stdlib.h>
#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_
 enum motorstate
{
	motor_ok,
	motor_NOTok,
	motor_OC,
	motor_SC,
};

u8 DCMotor_CLOCKWISE();
u8 DCMotor_AntiCLOCKWISE();
u8 DCMotor_Stop();
#endif /* HAL_DC_MOTOR_DCMOTOR_INTERFACE_H_ */
