/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : AFIO                 */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : AUGUST   2, 2022     */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef     AFIO_PRIVATE_H
#define     AFIO_PRIVATE_H

typedef struct EXTI_private
{
    volatile u32 EVCR;
    volatile u32 EXTICR[4];
    volatile u32 MAPR2;

}AFIO_t;

#define     AFIO         ((volatile EXTI_t*)0x40010000)





#endif