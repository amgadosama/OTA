/***********************************/
/* SWC: GPIO Driver                */
/* Author: Seif Hashad             */
/* Version: V1                     */
/* Date: 30 May 2023               */
/***********************************/
/*File Gaurd*/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*Functions Prototypes*/
/****************************************************************/
/* Func. Name: GPIO_voidSetPinMode                              */
/* I/P Arg. Options: Copy_u8PortId: GPIOA, GPIOB,      GPIOC    */
/* I/P Arg. Options: Copy_u8PinId: PIN0 --> PIN15, PIN13-->PIN15*/
/* I/P Arg. Options: Copy_u8Mode: INPUT, OUTPUT, AF, ANALOG     */
/* Return: Nothing                                              */
/* Func. Desc.: This Func. sets the mode of a specific pin      */
/****************************************************************/
void GPIO_voidSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Mode);
void GPIO_voidSetPinType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Type);
void GPIO_voidSetPinSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Speed);
void GPIO_voidSetPinPUPDOption(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PuPdOption);
void GPIO_voidSetPortValue(u8 Copy_u8PortId, u32 Copy_u32Value);
void GPIO_voidSetPinValueDirectAccess(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Signal);
u8   GPIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);
void GPIO_AF(u8 Port_ID,u8 Pin_Id,u8 copy_value);
void GPIO_voidSetAFPinConfig(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8AFID);
void GPIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);
void GPIO_voidSetPinOutputConfig(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Type, u8 Copy_u8Speed);
void GPIO_voidSetPinInputConfig(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Type);
/*Interface Macros*/
#define GPIOA           0
#define GPIOB           1
#define GPIOC           2

#define PIN0            0 
#define PIN1            1 
#define PIN2            2 
#define PIN3            3 
#define PIN4            4 
#define PIN5            5 
#define PIN6            6 
#define PIN7            7 
#define PIN8            8 
#define PIN9            9 
#define PIN10           10
#define PIN11           11
#define PIN12           12
#define PIN13           13
#define PIN14           14
#define PIN15           15

#define INPUT           0
#define OUTPUT          1
#define AF              2
#define ANALOG          3

#define OUTPUT_PP       0
#define OUTPUT_OD       1


#define PIN_SET			0
#define PIN_RST			1

#define INPUT_FLOATING	0
#define INPUT_PU		1
#define INPUT_PD		2

#define AF0         0b0000
#define AF1         0b0001
#define AF2         0b0010
#define AF3         0b0011
#define AF4         0b0100
#define AF5         0b0101
#define AF6         0b0110
#define AF7         0b0111
#define AF8         0b1000
#define AF9         0b1001
#define AF10        0b1010
#define AF11        0b1011
#define AF12        0b1100
#define AF13        0b1101
#define AF14        0b1110
#define AF15        0b1111

//SAIF
#define OUTPUT_LS                 1
#define OUTPUT_MS                 2
#define OUTPUT_HS                 3
#define OUTPUT_VHS                4

#define INPUT_NOPUNOPD            0
#define INPUT_PU                  1
#define INPUT_PD                  2

#define SET                       0
#define RST                       1

#define LOW                       0
#define HIGH                      1

#endif
