#include "vsk_Task.h"
#include "vsk_CriticalSection.h"
#include "vsk_Time.h"

vsk_Task * vsk_Task_init(
    vsk_Task * const self,
    ut_Queue * const messageQueue
) {
    self->messageQueue = messageQueue;
    return self;
}

bool vsk_Task_isReady(vsk_Task * const self) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    bool isReady = (ut_Queue_isEmpty(self->messageQueue) == false);
    vsk_CriticalSection_exit(vsk_CriticalSection_());
    return isReady;
}

void vsk_Task_run(vsk_Task * const self) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    vsk_TaskMessage * message = ut_Queue_dequeue(self->messageQueue);
    vsk_CriticalSection_exit(vsk_CriticalSection_());
    message->handler(self);
}

void vsk_Task_postMessage(vsk_Task * const self, vsk_TaskMessage * const message) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    ut_Queue_enqueue(self->messageQueue, message);
    vsk_CriticalSection_exit(vsk_CriticalSection_());
}
