#ifndef VSK_TASKSCHEDULER_H
#define VSK_TASKSCHEDULER_H
/*............................................................................*/
typedef struct vsk_TaskScheduler vsk_TaskScheduler;
typedef void (*vsk_TaskSchedulerOnIdle)(void);
#include "../utils/ut_Array.h"
#include "vsk_Task.h"
/*............................................................................*/
struct vsk_TaskScheduler {
    ut_Array * _taskArray;
    vsk_TaskSchedulerOnIdle _onIdle;
};
/*............................................................................*/
vsk_TaskScheduler * vsk_TaskScheduler_(void);
vsk_TaskScheduler * vsk_TaskScheduler_init(
    vsk_TaskScheduler * const self,
    vsk_TaskSchedulerOnIdle const onIdle
);
void vsk_TaskScheduler_start(
    vsk_TaskScheduler * const self,
    ut_Array * const taskArray
);
#endif // VSK_TASKSCHEDULER_H
