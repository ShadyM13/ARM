/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : NVIC                 */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : JULY 24, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
    #define SCB_AIRCR   *((volatile u32*) 0xE000ED0C)
    SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}


void MNVIC_voidEnableInterrupt( u8 Copy_u8IntNumber )
{
    if(Copy_u8IntNumber <= 31)
    {
        SET_BIT(NVIC_ISER0, Copy_u8IntNumber);

        /* you can also use NVIC_ISR0 = (1<<Copy_u8IntNumber);
           without using OR operator because writing zero doesn't affect the register 
           which makes it faster */

    }
    else if ( Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        SET_BIT(NVIC_ISER1, Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}

void MNVIC_voidDisableInterrupt( u8 Copy_u8IntNumber )
{
    if(Copy_u8IntNumber <= 31)
    {
        SET_BIT(NVIC_ICER0, Copy_u8IntNumber);
    }
    else if ( Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        SET_BIT(NVIC_ICER1, Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}

void MNVIC_voidSetPendingFlag ( u8 Copy_u8IntNumber )
{
    if(Copy_u8IntNumber <= 31)
    {
        SET_BIT(NVIC_ISPR0, Copy_u8IntNumber);
    }
    else if ( Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        SET_BIT(NVIC_ISPR1, Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}

void MNVIC_voidClearPendingFlag ( u8 Copy_u8IntNumber )
{
    if(Copy_u8IntNumber <= 31)
    {
        SET_BIT(NVIC_ICPR0, Copy_u8IntNumber);
    }
    else if ( Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        SET_BIT(NVIC_ICPR1, Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}

u8 MNVIC_u8GetActivePendingFlag ( u8 Copy_u8IntNumber )
{
    u8 L_u8Result = 0;

    if(Copy_u8IntNumber <= 31)
    {
        L_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
    }
    else if ( Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        L_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }

    return L_u8Result;
}


//void MNVIC_voidSetPriority(s8 copy_s8IntID , u8 copy_u8GroupPriority , u8 copy_u8SubPriority , u32 copy_u32GROUP)
//{
//    u8 Local_u8Priority = (copy_u8SubPriority | copy_u8GroupPriority<<(copy_u32GROUP - 0x05FA0300)/256);
//
//    /* Core peripheral */
//
//    /* External peripheral */
//    if( copy_s8IntID >= 0)
//    {
//        NVIC_IPR[copy_s8IntID] = (Local_u8Priority << 4);
//    }
//    SCB_AIRCR = copy_u32GROUP ; 
//}

//Assaf method
void MNVIC_voidSetPriority( u8 Copy_u8PeripheralIdx, u8 Copy_u8Priority)
{
    if( Copy_u8PeripheralIdx < 60)
    {
        NVIC_IPR[Copy_u8PeripheralIdx] = Copy_u8Priority;
    }
    else
    {
        /* Report Error */
    }
}