#ifndef VSK_TASK_H
#define VSK_TASK_H
#include "../utl/utl_Queue.h"
#include <stdint.h>

typedef struct vsk_Task vsk_Task;
typedef void (*vsk_TaskHandler)(vsk_Task * const self);

typedef struct vsk_TaskMessage vsk_TaskMessage;
struct vsk_TaskMessage {
    vsk_Task * receiver;
    vsk_TaskHandler handler;
    vsk_TaskMessage * next;
};

struct vsk_Task {
    utl_Queue * messageQueue;
};

vsk_Task * vsk_Task_init(
    vsk_Task * const self,
    utl_Queue * const eventQueue
);
bool vsk_Task_isReady(vsk_Task * const self);
void vsk_Task_run(vsk_Task * const self);
void vsk_Task_postMessage(vsk_Task * const self, vsk_TaskMessage * const message);

#endif // VSK_TASK_H
