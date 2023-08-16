/*****************************************/
/* Author  :  Seif Hashad                */
/* Version :  V01                        */
/* Date    : 18 May 2023                 */
/*****************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

//EXTI BASEADDRESS --> 0x40013C00

#define EXTI        ((EXTI_t*)0x40013C00)

typedef struct 
{
    volatile u32 MEMRMP;
    volatile u32 PMC;
    volatile u32 EXTICR1;
    volatile u32 EXTICR2;
    volatile u32 EXTICR3;
    volatile u32 EXTICR4;
    volatile u32 CMPCR;
}SYSCFG_t;

#define SYSCFG      (( SYSCFG_t*)0x40013800)

#define EXTI_IMR    *((volatile u32*)0x40010400)
#define EXTI_EMR    *((volatile u32*)0x40010404)
#define EXTI_RTSR   *((volatile u32*)0x40010408)
#define EXTI_FTSR   *((volatile u32*)0x4001040C)
#define EXTI_SWIER  *((volatile u32*)0x40010410)
#define EXTI_PR     *((volatile u32*)0x40010414)



#define FALLING_EDGE            0
#define RISING_EDGE             1
#define ON_CHANGE               2

#define EXTI_LINE_0             0 
#define EXTI_LINE_1             1 
#define EXTI_LINE_2             2 
#define EXTI_LINE_3             3 
#define EXTI_LINE_4             4 
#define EXTI_LINE_5             5 
#define EXTI_LINE_6             6 
#define EXTI_LINE_7             7 
#define EXTI_LINE_8             8 
#define EXTI_LINE_9             9 
#define EXTI_LINE_10            10
#define EXTI_LINE_11            11
#define EXTI_LINE_12            12
#define EXTI_LINE_13            13
#define EXTI_LINE_14            14
#define EXTI_LINE_15            15

/*Source Input for EXTIx*/
#define EXTI_PA                 0
#define EXTI_PB                 1
#define EXTI_PC                 2

#endif
