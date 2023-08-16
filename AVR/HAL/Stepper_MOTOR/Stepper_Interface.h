/*
 * Stepper_Interface.h
 *
 *  Created on: Feb 25, 2023
 *      Author: amres
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

void STEPPER_ClockWiseFullStep();
void STEPPER_ClockWiseHalfSTEP();
void STEPPER_UntiClockWiseFullStep();
void STEPPER_UntiClockWiseHalfSTEP();
void Stepper_stop();
void Stepper_INTI();
void Stepper_step(u8 step_num,u8 step_style);
void Stepper_GoTostep(u8 step_num,u8 step_style);
#endif /* HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_ */
