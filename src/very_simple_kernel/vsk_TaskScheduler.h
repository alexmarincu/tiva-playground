#ifndef VSK_TASKSCHEDULER_H
#define VSK_TASKSCHEDULER_H
/*............................................................................*/
typedef struct vsk_TaskScheduler vsk_TaskScheduler;
typedef void (*vsk_TaskSchedulerOnIdle)(void);
#include "vsk_LinkedList.h"
#include "vsk_Task.h"
/*............................................................................*/
struct vsk_TaskScheduler {
    vsk_LinkedList _tasks;
    vsk_TaskSchedulerOnIdle _onIdle;
};
/*............................................................................*/
vsk_TaskScheduler * vsk_TaskScheduler_(void);
vsk_TaskScheduler * vsk_TaskScheduler_init(
    vsk_TaskScheduler * const self,
    vsk_TaskSchedulerOnIdle const onIdle
);
void vsk_TaskScheduler_start(
    vsk_TaskScheduler * const self
);
void vsk_TaskScheduler_register(
    vsk_TaskScheduler * const self,
    vsk_Task * const task
);
#endif // VSK_TASKSCHEDULER_H
