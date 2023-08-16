/*File Gaurd*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*RCC Base Address: 0x40023800*/
#define RCC_BASEADDRESS     0x40023800

#define RCC_CR              *((volatile u32*)0x40023800)
#define RCC_PLLCFGR         *((volatile u32*)0x40023804)
#define RCC_CFGR            *((volatile u32*)0x40023808)

#define RCC_AHB1ENR         *((volatile u32*)0x40023830)
#define RCC_AHB2ENR         *((volatile u32*)0x40023834)
#define RCC_APB1ENR         *((volatile u32*)0x40023840)
#define RCC_APB2ENR         *((volatile u32*)0x40023844)





#endif
