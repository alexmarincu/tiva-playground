/*............................................................................*/
#include "vsk_Task.h"
#include "vsk_CriticalSection.h"
#include "vsk_TaskScheduler.h"
/*............................................................................*/
vsk_Task * vsk_Task_init(
    vsk_Task * const self
) {
    vsk_Queue_init(&self->messageQueue);
    vsk_TaskScheduler_register(vsk_TaskScheduler_(), self);
    return self;
}
/*............................................................................*/
bool vsk_Task_isReady(
    vsk_Task * const self
) {
    vsk_CriticalSection_onEnter(vsk_CriticalSection_());
    bool isReady = (vsk_Queue_isEmpty(&self->messageQueue) == false);
    vsk_CriticalSection_onExit(vsk_CriticalSection_());
    return isReady;
}
/*............................................................................*/
void vsk_Task_run(
    vsk_Task * const self
) {
    vsk_CriticalSection_onEnter(vsk_CriticalSection_());
    vsk_Message * message = vsk_Queue_dequeue(&self->messageQueue);
    vsk_CriticalSection_onExit(vsk_CriticalSection_());
    vsk_Message_dispatch(message);
}
/*............................................................................*/
void vsk_Task_postMessage(
    vsk_Task * const self,
    vsk_Message * const message
) {
    vsk_CriticalSection_onEnter(vsk_CriticalSection_());
    vsk_Queue_enqueue(&self->messageQueue, message);
    vsk_CriticalSection_onExit(vsk_CriticalSection_());
}
