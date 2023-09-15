#ifndef VSOS_SCHEDULER_H
#define VSOS_SCHEDULER_H
#include "vsos_Task.h"
#include "vsos_TaskArray.h"

typedef struct vsos_Scheduler vsos_Scheduler;

vsos_Scheduler * vsos_Scheduler_(void);
vsos_Scheduler * vsos_Scheduler_init(vsos_Scheduler * const self);
void vsos_Scheduler_setTaskArray(vsos_Scheduler * const self, vsos_TaskArray * const taskArray);
void vsos_Scheduler_start(vsos_Scheduler * const self);

#endif // VSOS_SCHEDULER_H
