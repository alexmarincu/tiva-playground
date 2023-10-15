/*............................................................................*/
#include "vsk_Task.h"
#include "vsk_CriticalSection.h"
#include "vsk_TaskScheduler.h"
/*............................................................................*/
vsk_Task * vsk_Task_init(
    vsk_Task * const self
) {
    vsk_Inbox_init(&self->inbox);
    vsk_TaskScheduler_register(vsk_TaskScheduler_(), self);
    return self;
}
/*............................................................................*/
bool vsk_Task_isReady(
    vsk_Task * const self
) {
    return (vsk_Inbox_isEmpty(&self->inbox) == false);
}
/*............................................................................*/
void vsk_Task_run(
    vsk_Task * const self
) {
    vsk_Message_dispatch(vsk_Inbox_readMessage(&self->inbox));
}
