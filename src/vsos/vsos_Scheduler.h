#ifndef VSOS_SCHEDULER_H
#define VSOS_SCHEDULER_H
#include "../utl/utl_Array.h"
#include "vsos_Task.h"

typedef struct vsos_Scheduler vsos_Scheduler;
typedef void (*vsos_Scheduler_onIdleFun)(void);

vsos_Scheduler * vsos_Scheduler_(void);
vsos_Scheduler * vsos_Scheduler_init(
    vsos_Scheduler * const self,
    vsos_Scheduler_onIdleFun const onIdle,
    utl_Array * const taskArray
);
void vsos_Scheduler_start(vsos_Scheduler * const self);

#endif // VSOS_SCHEDULER_H
