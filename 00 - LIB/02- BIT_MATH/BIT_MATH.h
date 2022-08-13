/*******************************************/
/*       Author     : Shady Ahmad          */
/*       Version    : 1.0                  */
/*       Date       : 6 JUL 2022           */
/*       Last Edit  : N/A                  */
/*******************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Reg, Bit)       Reg |=  (1<<Bit)
#define CLR_BIT(Reg, Bit)       Reg &= ~(1<<Bit)
#define TOG_BIT(Reg, Bit)       Reg ^=  (1<<Bit)
#define GET_BIT(Reg, Bit)       (Reg>>Bit) & 1

#endif