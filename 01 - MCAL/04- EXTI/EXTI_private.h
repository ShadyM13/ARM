/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : EXTI                 */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : JULY 26, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef     EXTI_PRIVATE_H
#define     EXTI_PRIVATE_H

typedef struct EXTI_private
{
    volatile u32 IMR;
    volatile u32 EMR; 
    volatile u32 RSTR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;

}EXTI_t;

#define     EXTI        ((volatile EXTI_t*)0x40010400)





#endif