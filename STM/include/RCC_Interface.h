/*File Gaurd*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void RCC_voidInitSysClk(void);
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PerId);

#define RCC_HSE_RC              0
#define RCC_HSE_CRYSTAL         1

#define HSI                     0
#define HSE                     1
#define PLL                     2

#define AHB1                     0
#define AHB2                     1
#define APB1                     2
#define APB2                     3

#endif
