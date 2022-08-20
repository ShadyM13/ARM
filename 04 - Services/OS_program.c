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


void Scheduler(void);

/* Array of tasks    "Array of struct" */
Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, void (*ptr)(void), u8 Copy_u8FirstDelay)
{
    OS_Tasks[Copy_u8ID].priodicity = Copy_u16Periodicity;
    OS_Tasks[Copy_u8ID].Fptr = ptr;
    OS_Tasks[Copy_u8ID].firstDelay = Copy_u8FirstDelay;
    OS_Tasks[Copy_u8ID].State = TASK_READY;
}

void SOS_voidStart(void)
{
    /* Initialization */
    MSTK_voidInit();
    /* Iick => 1msec    => 1000 uSec === 1 m sec */
    MSTK_voidSetIntervalPeriodic(1000,Scheduler);

}


void Scheduler(void)
{
    for(u8 i=0; i<NUMBER_OF_TASKS ; i++)
    {
        if((OS_Tasks[i].Fptr != NULL) && (OS_Tasks[i].State == TASK_READY))
        {
            if(OS_Tasks[i].firstDelay == 0)
            {
                OS_Tasks[i].firstDelay = OS_Tasks[i].priodicity-1;
                OS_Tasks[i].Fptr();
            }
            else
            {
                OS_Tasks[i].firstDelay--;
            }
        }

    }

}
