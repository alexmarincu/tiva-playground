#ifndef VSK_TASKSCHEDULER_H
#define VSK_TASKSCHEDULER_H
#include "../utils/ut_Array.h"
#include "vsk_Task.h"

typedef struct vsk_TaskScheduler vsk_TaskScheduler;
typedef void (*vsk_TaskSchedulerOnIdle)(void);

vsk_TaskScheduler * vsk_TaskScheduler_(void);
vsk_TaskScheduler * vsk_TaskScheduler_init(
    vsk_TaskScheduler * const self,
    vsk_TaskSchedulerOnIdle const onIdle,
    ut_Array * const taskArray
);
void vsk_TaskScheduler_start(vsk_TaskScheduler * const self);

#endif // VSK_TASKSCHEDULER_H
