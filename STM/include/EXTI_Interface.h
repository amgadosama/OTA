/*****************************************/
/* Author  :  Seif Hashad                */
/* Version :  V01                        */
/* Date    : 18 May 2023                 */
/*****************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void EXTI_voidInit();
void EXTI_voidSetExtiLineEnable(u8 Copy_u8LineId);
void EXTI_voidSetExtiLineDisable(u8 Copy_u8LineId);
void EXTI_voidSetSenseControl(u8 Copy_u8SenseControl, u8 Copy_u8LineId);
void EXTI_voidSetEXTIpinConfig(u8 Copy_u8PortId, u8 Copy_u8LineId);
void EXT0_CALLBACK(void (*ptr)(void));
void EXT11_CALLBACK(void (*ptr2)(void));
#endif
