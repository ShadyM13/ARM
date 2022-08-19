/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : EXTI                 */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : JULY 26, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void (*EXTI0_CallBack)(void) = NULL;

void    MEXTI_voidInit()
{
    #if     EXTI_SENSE_MODE  ==   RISING_EDGE
    SET_BET(EXTI->RSTR, EXTI_LINE);

    #elif   EXTI_SENSE_MODE  ==   FALLING_MODE
    SET_BET(EXTI->FTSR, EXTI_LINE);

    #elif   EXTI_SENSE_MODE  ==   ON_CHANGE 
    SET_BET(EXTI->RTSR, EXTI_LINE);
    SET_BET(EXTI->FTSR, EXTI_LINE);

    #else       #error "Wrong Mode and Line Choice"
    #endif

}

void    MEXTI_voidEnableEXTI   (u8 copy_u8Line)
{
    SET_BIT(EXTI->IMR, copy_u8Line);
}

void    MEXTI_voidDisableEXTI  (u8 copy_u8Line)
{
    CLR_BIT(EXTI->IMR, copy_u8Line);
}

void    MEXTI_voidSwTrigger    (u8 copy_u8Line)
{
    SET_BIT(EXTI->SWIER, copy_u8Line)
}

void MEXTI_voidSetSignalLatch(u8 copy_u8Line, u8 copy_u8Mode)
{
    switch(copy_u8Mode)
    {
        case RISING_EDGE  :
        SET_BET(EXTI->RSTR, EXTI_LINE);
        break;

        case FALLING_EDGE :
        SET_BET(EXTI->FTSR, EXTI_LINE);
        break; 

        case ON_CHANGE    :
        SET_BET(EXTI->RTSR, EXTI_LINE);
        SET_BET(EXTI->FTSR, EXTI_LINE);
        break;        
    }
}

void    MEXTI_voidSetCallBack(void (*ptr) (void))
{
    EXTI0_CallBack = ptr;           //Recieve the user function into the EXTI0_CallBack variable
}

void EXTI0-IRQHandler (void)
{
    EXTI0_CallBack();               //perform the required function
    
    /* Clear pending bit   */
    SET_BIT(EXTI -> PR, 0);         
}