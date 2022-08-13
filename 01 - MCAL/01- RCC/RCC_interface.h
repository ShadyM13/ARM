/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : RCC                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : JULY 7, 2022         */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_

#define     RCC_AHB      0
#define     RCC_APB1     1
#define     RCC_APB2     2

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidInitSysClock(void);



#endif