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


void    MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode)
{
    switch(Copy_u8PORT)
    {
        case GPIOA  :
                    if(copy_u8PIN <= 7) 
                    {   
                        GPIOA_CRL &= ~((0b1111)<<(copy_u8PIN * 4));
                        GPIOA_CRL |=  ((copy_u8Mode)<<(copy_u8PIN * 4));
                    }
                    else if (copy_u8PIN <= 15)
                    {   
                        copy_u8PIN = copy_u8PIN - 8;
                        GPIOA_CRH &= ~((0b1111)<<(copy_u8PIN * 4));
                        GPIOA_CRH |=  ((copy_u8Mode)<<((copy_u8PIN*4)));
                    }
        break;

        case GPIOB  :
                    if(copy_u8PIN <= 7) 
                    {   
                        GPIOB_CRL &= ~((0b1111)<<(copy_u8PIN * 4));
                        GPIOB_CRL |=  ((copy_u8Mode)<<(copy_u8PIN *4 ));
                    }
                    else if (copy_u8PIN <= 15)
                    {   
                        copy_u8PIN = copy_u8PIN - 8;
                        GPIOB_CRH &= ~(0b1111<<((copy_u8PIN * 4)));
                        GPIOB_CRH |=  ((copy_u8Mode)<<((copy_u8PIN*4)));
                    }
        break;

        case GPIOC  :
                    if(copy_u8PIN <= 7) 
                    {   
                        GPIOC_CRL &= ~((0b1111)<<(copy_u8PIN * 4));
                        GPIOC_CRL |=  ((copy_u8Mode)<<(copy_u8PIN *4 ));
                    }
                    else if (copy_u8PIN <= 15)
                    {   
                        copy_u8PIN = copy_u8PIN - 8;
                        GPIOC_CRH &= ~(0b1111<<((copy_u8PIN * 4)));
                        GPIOC_CRH |=  ((copy_u8Mode)<<((copy_u8PIN*4)));
                    }
        break;

        default     : break;
    }
}

void    MGPIO_voidSetPinValue(u8 Copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
    switch(Copy_u8PORT)
    {
        case GPIOA  :
                    if(copy_u8PIN == GPIO_HIGH) 
                    {   
                        SET_BIT(GPIOA_ORD,copy_u8Value);
                    }
                    else if (copy_u8PIN == GPIO_LOW)
                    {   
                        CLR_BIT(GPIOA_ORD,copy_u8Value);
                    }
        break;

        case GPIOB  :
                    if(copy_u8PIN == GPIO_HIGH) 
                    {   
                        SET_BIT(GPIOB_ORD,copy_u8Value);
                    }
                    else if (copy_u8PIN == GPIO_LOW)
                    {   
                        CLR_BIT(GPIOB_ORD,copy_u8Value);
                    }
        break;

        case GPIOC  :
                    if(copy_u8PIN == GPIO_HIGH) 
                    {   
                        SET_BIT(GPIOC_ORD,copy_u8Value);
                    }
                    else if (copy_u8PIN == GPIO_LOW)
                    {   
                        CLR_BIT(GPIOC_ORD,copy_u8Value);
                    }
                    
        break;
    }
}

u8      MGPIO_voidGetPinValue(u8 Copy_u8PORT, u8 copy_u8PIN)
{
    u8 L_u8Result = 0;
    switch(Copy_u8PORT)
    {
        case GPIOA  :   L_u8Result = GIT_BIT(GPIOA_IRD,copy_u8Value);       break;

        case GPIOB  :   L_u8Result = GIT_BIT(GPIOB_IRD,copy_u8Value);       break;

        case GPIOC  :   L_u8Result = GIT_BIT(GPIOC_IRD,copy_u8Value);       break;
    }

    return L_u8Result;
}