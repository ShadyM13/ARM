/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : NVIC                 */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : JULY 24, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef _NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_

/* 0xE000E100 Base Address */
#define NVIC_ISER0      *((volatile u32*) 0xE000E100)       /* Enable External Interrupts from 0  - 31 */
#define NVIC_ISER1      *((volatile u32*) 0xE000E104)       /* Enable External Interrupts from 31 - 63 */

#define NVIC_ICER0      *((volatile u32*) 0xE000E180)       /* Disable External Interrupts from 0  - 31 */
#define NVIC_ICER1      *((volatile u32*) 0xE000E184)       /* Disable External Interrupts from 31 - 63 */

#define NVIC_ISPR0      *((volatile u32*) 0xE000E200)       /* Set Pending Flag of External Interrupts from 0  - 31 */
#define NVIC_ISPR1      *((volatile u32*) 0xE000E204)       /* Set Pending Flag of External Interrupts from 31 - 63 */

#define NVIC_ICPR0      *((volatile u32*) 0xE000E280)       /* Clear Pending Flag of External Interrupts from 0  - 31 */
#define NVIC_ICPR1      *((volatile u32*) 0xE000E284)       /* Clear Pending Flag of External Interrupts from 31 - 63 */

#define NVIC_IABR0      *((volatile u32*) 0xE000E380)       /* Read Pending Flag of External Interrupts from 0  - 31 */
#define NVIC_IABR1      *((volatile u32*) 0xE000E304)       /* Read Pending Flag of External Interrupts from 31 - 63 */

/* Software priorities registers */
#define NVIC_IPR         ((volatile u8* ) 0xE000E100 + 0x300)       /* u8 because its a pointer to array and it is byte access and we don't derefrence it */
#define SCB_AIRCR       *((volatile u32*) 0xE000ED00 + 0x0C )       /* SCB Registers that controls number of groups and sub groups */

#endif 