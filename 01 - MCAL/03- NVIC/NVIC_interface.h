/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : NVIC                 */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : JULY 24, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_

void MNVIC_voidEnableInterrupt  ( u8 Copy_u8IntNumber );
void MNVIC_voidDisableInterrupt ( u8 Copy_u8IntNumber );

void MNVIC_voidSetPendingFlag   ( u8 Copy_u8IntNumber );
void MNVIC_voidClearPendingFlag ( u8 Copy_u8IntNumber );

u8 MNVIC_u8GetActivePendingFlag ( u8 Copy_u8IntNumber );

//void MNVIC_voidSetPriority(s8 copy_s8IntID , u8 copy_u8GroupPriority , u8 copy_u8SubPriority);

void MNVIC_voidSetPriority( u8 Copy_u8PeripheralIdx, u8 Copy_u8Priority);

#define     MNVIC_GROUP_4_SUB_0      0x05FA0300          //4 bits for group and 0 bits for sub (IPR)
#define     MNVIC_GROUP_3_SUB_1      0x05FA0400          //3 bits for group and 1 bits for sub (IPR)
#define     MNVIC_GROUP_2_SUB_2      0x05FA0500          //2 bits for group and 2 bits for sub (IPR)
#define     MNVIC_GROUP_1_SUB_3      0x05FA0600          //1 bits for group and 3 bits for sub (IPR)
#define     MNVIC_GROUP_0_SUB_4      0x05FA0700          //0 bits for group and 4 bits for sub (IPR)

#endif