
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct
{
    u16 priodicity          ;
    void (*Fptr)(void)       ;
}Task;

#endif
