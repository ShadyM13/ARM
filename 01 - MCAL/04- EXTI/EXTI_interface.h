 /*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : EXTI                 */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : JULY 26, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef     EXTI_INTERFACE_H
#define     EXTI_INTERFACE_H

/* Line and Mode with configuration*/
void    MEXTI_voidInit         ();
void    MEXTI_voidEnableEXTI   (u8 copy_u8Line);
void    MEXTI_voidDisableEXTI  (u8 copy_u8Line);
void    MEXTI_voidSwTrigger    (u8 copy_u8Line);        //Software Trigger
void    MEXTI_voidSetSignalLatch(u8 copy_u8Line, u8 copy_u8Mode);

#define