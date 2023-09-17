#include "vsos_Task.h"
#include "vsos_SysTime.h"

vsos_Task * vsos_Task_init(
    vsos_Task * const self,
    vsos_Task_operationFun const operation,
    utl_Queue * const eventQueue
) {
    self->operation = operation;
    self->eventQueue = eventQueue;
    return self;
}

bool vsos_Task_isReady(vsos_Task * const self) {
    return (utl_Queue_isEmpty(self->eventQueue) == false);
}

void vsos_Task_operation(vsos_Task * const self) {
    self->operation(self, utl_Queue_dequeue(self->eventQueue));
}

void vsos_Task_postEvent(vsos_Task * const self, vsos_Event * const event) {
    utl_Queue_enqueue(self->eventQueue, event);
}
