/*******************************************/
/*       Author     : Shady Ahmad          */
/*       SWC        : DIO                  */
/*       Layer      : MCAL                 */
/*       Version    : 1.0                  */
/*       Date       : JULY 18, 2022        */
/*       Last Edit  : N/A                  */
/*******************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void GPIO_voidSetPinDirection(u8 copy_u8PORT, u8 copy_u8Pin, u8 copy_u8Mode)
{
	switch(copy_u8PORT)
	{
		case GPIOA:
			if(copy_u8Pin<=7)
			{
				GPIOAP->CRL &=~ ((0b1111)<<(copy_u8Pin*4));
				GPIOAP->CRL |= ((copy_u8Mode)<<(copy_u8Pin*4));
			}
			else if(copy_u8Pin<=14)
			{
				copy_u8Pin=copy_u8Pin-8;
				GPIOAP->CRH &=~ ((0b1111)<<(copy_u8Pin*4));
				GPIOAP->CRH |= ((copy_u8Mode)<<(copy_u8Pin*4));
			}
			break;
					
		case GPIOB:
			if(copy_u8Pin<=7)
			{
				GPIOBP->CRL &=~ ((0b1111)<<(copy_u8Pin*4));
				GPIOBP->CRL |= ((copy_u8Mode)<<(copy_u8Pin*4));
			}
			else if(copy_u8Pin<=14)
			{
				copy_u8Pin=copy_u8Pin-8;
				GPIOBP->CRH &=~ ((0b1111)<<(copy_u8Pin*4));
				GPIOBP->CRH |= ((copy_u8Mode)<<(copy_u8Pin*4));
			}
			break;
		
		case GPIOC:
			if(copy_u8Pin<=7)
			{
				GPIOCP->CRL &=~ ((0b1111)<<(copy_u8Pin*4));
				GPIOCP->CRL |= ((copy_u8Mode)<<(copy_u8Pin*4));
			}
			else if(copy_u8Pin<=14)
			{
				copy_u8Pin=copy_u8Pin-8;
				GPIOCP->CRH &=~ ((0b1111)<<(copy_u8Pin*4));
				GPIOCP->CRH |= ((copy_u8Mode)<<(copy_u8Pin*4));
			}
			break;
		
		
		
	}
	
	
	
}
void GPIO_voidSetPinValue(u8 copy_u8PORT, u8 copy_u8Pin, u8 copy_u8Value)
{
	switch(copy_u8PORT)
	{
		case GPIOA:
			if(copy_u8Value==GPIO_HIGH)
			{
				SET_BIT(GPIOAP->ODR,copy_u8Pin);
			}
			else if(copy_u8Value==GPIO_LOW)
			{
				CLR_BIT(GPIOAP->ODR,copy_u8Pin);
			}
			break;
		case GPIOB:
			if(copy_u8Value==GPIO_HIGH)
			{
				SET_BIT(GPIOBP->ODR,copy_u8Pin);
			}
			else if(copy_u8Value==GPIO_LOW)
			{
				CLR_BIT(GPIOBP->ODR,copy_u8Pin);
			}
			break;
		case GPIOC:
			if(copy_u8Value==GPIO_HIGH)
			{
				SET_BIT(GPIOCP->ODR,copy_u8Pin);
			}
			else if(copy_u8Value==GPIO_LOW)
			{
				CLR_BIT(GPIOCP->ODR,copy_u8Pin);
			}
			break;
		default: break;
	
	}
	
}
void GPIO_voidSetPortDirection(u8 copy_u8PORT, u32 copy_u8Mode)
{
	switch(copy_u8PORT)
	{
		case GPIOA:
				GPIOAP->CRL &=0x00000000;
				GPIOAP->CRL |= copy_u8Mode;
				GPIOAP->CRH &=0x00000000;
				GPIOAP->CRH |= copy_u8Mode;
			break;
		case GPIOB:
				GPIOBP->CRL &=0x00000000;
				GPIOBP->CRL |= copy_u8Mode;
				GPIOBP->CRH &=0x00000000;
				GPIOBP->CRH |= copy_u8Mode;
			break;
		case GPIOC:
				GPIOCP->CRL &=0x00000000;
				GPIOCP->CRL |= copy_u8Mode;
				GPIOCP->CRH &=0x00000000;
				GPIOCP->CRH |= copy_u8Mode;
			break;
	}

}
void GPIO_voidSetFourPinsDirection(u8 copy_u8PORT, u16 copy_u8Mode)
{
	switch(copy_u8PORT)
	{
		case GPIOA:
				GPIOAP->CRL &=0xffff0000;
				GPIOAP->CRL |= copy_u8Mode;
				GPIOAP->CRH &=0xffffffff;
				GPIOAP->CRH |= copy_u8Mode;
			break;
		case GPIOB:
				GPIOBP->CRL &=0xffff0000;
				GPIOBP->CRL |= copy_u8Mode;
				GPIOBP->CRH &=0xffffffff;
				GPIOBP->CRH |= copy_u8Mode;
			break;
		case GPIOC:
				GPIOCP->CRL &=0xffff0000;
				GPIOCP->CRL |= copy_u8Mode;
				GPIOCP->CRH &=0xffffffff;
				GPIOCP->CRH |= copy_u8Mode;
			break;
	}

}


void GPIO_voidSetFourPinsValue(u8 copy_u8PORT, u8 copy_u8Value)
{
	switch(copy_u8PORT)
	{
		case GPIOA:
			
				GPIOAP->ODR |=copy_u8Value&0xf;
			break;
		case GPIOB:

				GPIOBP->ODR |=copy_u8Value&0xf;

			break;
		case GPIOC:

				GPIOCP->ODR |=copy_u8Value&0xf;

			break;
	}

}


void GPIO_voidSetPortValue(u8 copy_u8PORT, u32 copy_u8Value)
{
	switch(copy_u8PORT)
	{
		case GPIOA:
				GPIOAP->ODR|=copy_u8Value;

			break;
		case GPIOB:

				GPIOBP->ODR|=copy_u8Value;

			break;
		case GPIOC:

				GPIOCP->ODR|=copy_u8Value;

			break;
	}

}


u8 GPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8Pin)
{
	u8 LOC_u8Result=0;
	switch(copy_u8PORT)
	{
		case GPIOA:
			LOC_u8Result= GET_BIT(GPIOAP->IDR,copy_u8Pin);
			break;
		case GPIOB:
			LOC_u8Result= GET_BIT(GPIOBP->IDR,copy_u8Pin);
			break;
		case GPIOC:
			
			LOC_u8Result= GET_BIT(GPIOCP->IDR,copy_u8Pin);
			break;
			
		default: break;
	
	}
	return LOC_u8Result;	
	
}