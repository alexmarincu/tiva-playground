#include "vsk_Task.h"
#include "vsk_SysTime.h"

vsk_Task * vsk_Task_init(
    vsk_Task * const self,
    vsk_Task_operationFun const operation,
    utl_Queue * const eventQueue
) {
    self->operation = operation;
    self->eventQueue = eventQueue;
    return self;
}

bool vsk_Task_isReady(vsk_Task * const self) {
    return (utl_Queue_isEmpty(self->eventQueue) == false);
}

void vsk_Task_operation(vsk_Task * const self) {
    self->operation(self, utl_Queue_dequeue(self->eventQueue));
}

void vsk_Task_postEvent(vsk_Task * const self, vsk_Event * const event) {
    utl_Queue_enqueue(self->eventQueue, event);
}
