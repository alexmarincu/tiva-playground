#ifndef VSK_TASK_H
#define VSK_TASK_H
#include "../utl/utl_Queue.h"
#include "vsk_Event.h"
#include <stdint.h>

typedef struct vsk_Task vsk_Task;
typedef void (*vsk_TaskOperation)(vsk_Task * const self, vsk_Event * const event);
struct vsk_Task {
    vsk_TaskOperation operation;
    utl_Queue * eventQueue;
};

vsk_Task * vsk_Task_init(
    vsk_Task * const self,
    vsk_TaskOperation const operation,
    utl_Queue * const eventQueue
);
bool vsk_Task_isReady(vsk_Task * const self);
void vsk_Task_operation(vsk_Task * const self);
void vsk_Task_postEvent(vsk_Task * const self, vsk_Event * const event);

#endif // VSK_TASK_H
