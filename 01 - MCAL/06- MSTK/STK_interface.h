/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : STK                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : AUG   8, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _STK_INTERFACE_H_
#define _STK_INTERFACE_H_


/* Applay Clock Choice From Configuration file 
Disable SysTick INTERRUPT 
Disable Systick */
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);



#endif
