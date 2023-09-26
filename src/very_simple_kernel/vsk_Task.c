#include "vsk_Task.h"
#include "vsk_SysTime.h"

vsk_Task * vsk_Task_init(
    vsk_Task * const self,
    ut_Queue * const messageQueue
) {
    self->messageQueue = messageQueue;
    return self;
}

bool vsk_Task_isReady(vsk_Task * const self) {
    return (ut_Queue_isEmpty(self->messageQueue) == false);
}

void vsk_Task_run(vsk_Task * const self) {
    vsk_TaskMessage * message = ut_Queue_dequeue(self->messageQueue);
    message->handler(self);
}

void vsk_Task_postMessage(vsk_Task * const self, vsk_TaskMessage * const message) {
    ut_Queue_enqueue(self->messageQueue, message);
}
