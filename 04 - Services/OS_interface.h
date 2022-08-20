 

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

typedef struct
{
    u16 priodicity          ;
    void (*ptr)(void)       ;
}Task;

void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, void (*ptr)(void));
void SOS_voidStart(void);

#endif