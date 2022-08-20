
/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "STK_interface.h"

/* SERVICES */
#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL    (void *)0

/* Array of tasks    "Array of struct" */
Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, void (*ptr)(void))
{
    OS_Tasks[Copy_u8ID].priodicity = Copy_u16Periodicity;
    OS_Tasks[Copy_u8ID].Fptr = ptr;
}

void SOS_voidStart(void)
{
    /* Initialization */
    MSTK_voidInit();
    /* Iick => 1msec    => 1000 uSec === 1 m sec */
    MSTK_voidSetIntervalPeriodic(1000,Scheduler);

}

volatile u16 TickCounts = 0;
void Scheduler(void)
{
    for(u8 i=0; i<NUMBER_OF_TASKS ; i++)
    {
        if((TickCounts % OS_Tasks[i].priodicity) == 0)
        {
            OS_Tasks[i].Fptr();
        }

    }
    TickCounts++;
}