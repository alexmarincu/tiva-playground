/*............................................................................*/
#include "vsk_Event.h"
/*............................................................................*/
vsk_EventSubscription * vsk_EventSubscription_init(
    vsk_EventSubscription * const self,
    vsk_Task * const task,
    void * const recipient,
    vsk_MessageHandler const handler
) {
    self->_task = task;
    vsk_Message_init(&self->_message, recipient, handler);
    return self;
}
/*............................................................................*/
vsk_Task * vsk_EventSubscription_getTask(
    vsk_EventSubscription * const self
) {
    return self->_task;
}
/*............................................................................*/
vsk_Message * vsk_EventSubscription_getMessage(
    vsk_EventSubscription * const self
) {
    return &self->_message;
}
