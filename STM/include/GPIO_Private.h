/***********************************/
/* SWC: GPIO Driver                */
/* Author: Seif Hashad             */
/* Version: V1                     */
/* Date: 30 May 2023               */
/***********************************/
/*File Gaurd*/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/*GPIO Bus: AHB*/
/*GPIOA Base Address: 0x40020000*/
#define GPIOA_MODER         *((volatile u32*)0x40020000)
#define GPIOA_TYPER         *((volatile u32*)0x40020004)
#define GPIOA_SPEEDR        *((volatile u32*)0x40020008)
#define GPIOA_PUPDR         *((volatile u32*)0x4002000C)
#define GPIOA_IDR           *((volatile u32*)0x40020010)
#define GPIOA_ODR           *((volatile u32*)0x40020014)
#define GPIOA_BSRR          *((volatile u32*)0x40020018)
#define GPIOA_AFRL          *((volatile u32*)0x40020020)
#define GPIOA_AFRH          *((volatile u32*)0x40020024)

/*GPIOB Base Address: 0x40020400*/
#define GPIOB_MODER         *((volatile u32*)0x40020400)
#define GPIOB_TYPER         *((volatile u32*)0x40020404)
#define GPIOB_SPEEDR        *((volatile u32*)0x40020408)
#define GPIOB_PUPDR         *((volatile u32*)0x4002040C)
#define GPIOB_IDR           *((volatile u32*)0x40020410)
#define GPIOB_ODR           *((volatile u32*)0x40020414)
#define GPIOB_BSRR          *((volatile u32*)0x40020418)
#define GPIOB_AFRL          *((volatile u32*)0x40020420)
#define GPIOB_AFRH          *((volatile u32*)0x40020424)

/*GPIOC Base Address: 0x40020800*/
#define GPIOC_MODER         *((volatile u32*)0x40020800)
#define GPIOC_TYPER         *((volatile u32*)0x40020804)
#define GPIOC_SPEEDR        *((volatile u32*)0x40020808)
#define GPIOC_PUPDR         *((volatile u32*)0x4002080C)
#define GPIOC_IDR           *((volatile u32*)0x40020810)
#define GPIOC_ODR           *((volatile u32*)0x40020814)
#define GPIOC_BSRR          *((volatile u32*)0x40020818)
#define GPIOC_AFRL          *((volatile u32*)0x40020820)
#define GPIOC_AFRH          *((volatile u32*)0x40020824)

/*Private Macros*/



//SAIF
/*Registers Description for GPIOA*/
#define GPIOA_MODER               *((volatile u32*)0x40020000)
#define GPIOA_OTYPER              *((volatile u32*)0x40020004)
#define GPIOA_OSPEEDR             *((volatile u32*)0x40020008)
#define GPIOA_ODR                 *((volatile u32*)0x40020014)
#define GPIOA_BSRR                *((volatile u32*)0x40020018)
#define GPIOA_IDR                 *((volatile u32*)0x40020010)
#define GPIOA_PUPDR               *((volatile u32*)0x4002000C)

/*Registers Description for GPIOB*/
#define GPIOB_MODER               *((volatile u32*)0x40020400)
#define GPIOB_OTYPER              *((volatile u32*)0x40020404)
#define GPIOB_OSPEEDR             *((volatile u32*)0x40020408)
#define GPIOB_ODR                 *((volatile u32*)0x40020414)
#define GPIOB_BSRR                *((volatile u32*)0x40020418)
#define GPIOB_IDR                 *((volatile u32*)0x40020410)
#define GPIOB_PUPDR               *((volatile u32*)0x4002040C)

/*Registers Description for GPIOC*/
#define GPIOC_MODER               *((volatile u32*)0x40020800)
#define GPIOC_OTYPER              *((volatile u32*)0x40020804)
#define GPIOC_OSPEEDR             *((volatile u32*)0x40020808)
#define GPIOC_ODR                 *((volatile u32*)0x40020814)
#define GPIOC_BSRR                *((volatile u32*)0x40020818)
#define GPIOC_IDR                 *((volatile u32*)0x40020810)
#define GPIOC_PUPDR               *((volatile u32*)0x4002080C)



#endif
