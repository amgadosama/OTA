/*
 * SERVO_Interface.h
 *
 *  Created on: Apr 16, 2023
 *      Author: amres
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_



// USE PORTD PIN5 AS Non inverting   and fast pwm

void Servo_Init();
u8 Servo_Angle(u8 Angle);


#endif /* HAL_SERVO_MOTOR_SERVO_INTERFACE_H_ */
