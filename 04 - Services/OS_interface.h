 

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, void (*ptr)(void), u8 Copy_u8FirstDelay);
void SOS_voidStart(void);

#endif
