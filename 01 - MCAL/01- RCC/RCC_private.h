/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : RCC                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : JULY 7, 2022         */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_


/* Register Definition */
#define RCC_CR          *((volatile u32*)0x40021000)        //clock
#define RCC_CFGR        *((volatile u32*)0x40021004)        //clock
#define RCC_CIR         *((volatile u32*)0x40021008)
#define RCC_APB2RSTR    *((volatile u32*)0x4002100C)
#define RCC_APB1RSTS    *((volatile u32*)0x40021010)
#define RCC_AHBENR      *((volatile u32*)0x40021014)        //clock
#define RCC_APB2ENR     *((volatile u32*)0x40021018)        //clock
#define RCC_APB1ENR     *((volatile u32*)0x4002101C)        //clock
#define RCC_BDCR        *((volatile u32*)0x40021020)
#define RCC_CSR         *((volatile u32*)0x40021024)

/*      CLOCK TYPES      */
#define        RCC_HSE_CRYSTAL      0
#define        RCC_HSE_RC           1
#define        RCC_HSI              2
#define        RCC_PLL              3

/*      PLL INPUT OPTIONS     */
#define        RCC_PLL_IN_HSI_DIV_2        0
#define        RCC_PLL_IN_HSE_DIV_2        1
#define        RCC_PLL_IN_HSE              2

#endif