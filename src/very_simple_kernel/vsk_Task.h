#ifndef VSK_TASK_H
#define VSK_TASK_H
#include "vsk_Message.h"

#include "../utils/ut_Queue.h"

#include <stdint.h>

typedef struct vsk_Task vsk_Task;
struct vsk_Task {
    ut_Queue * messageQueue;
};

vsk_Task * vsk_Task_init(
    vsk_Task * const self,
    ut_Queue * const messageQueue
);
bool vsk_Task_isReady(vsk_Task * const self);
void vsk_Task_run(vsk_Task * const self);
void vsk_Task_postMessage(vsk_Task * const self, vsk_Message * const message);

#endif // VSK_TASK_H
