/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : DIO                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : JULY 18, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

//#define     GPIOA_BASE_ADDRESS   0x40011000
//#define     GPIOB_BASE_ADDRESS   0x40010C00
//#define     GPIOC_BASE_ADDRESS   0x40010800

typedef struct
{
	volatile u32 CRL ; 
	volatile u32 CRH ; 
	volatile u32 IDR ; 
	volatile u32 ODR ; 
	volatile u32 BSRR ;
    volatile u32 BRR  ;
    volatile u32 LCKR ;
}GPIO_st;

#define GPIOA	((volatile GPIO_st*)0x40010800)
#define	GPIOB	((volatile GPIO_st*)0x40010C00)
#define	GPIOC   ((volatile GPIO_st*)0x40011000)


#endif 
