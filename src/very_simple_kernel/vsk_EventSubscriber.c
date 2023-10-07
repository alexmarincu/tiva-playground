/*............................................................................*/
#include "vsk_Event.h"
/*............................................................................*/
vsk_EventSubscriber * vsk_EventSubscriber_init(
    vsk_EventSubscriber * const self,
    vsk_Task * const task,
    void * const recipient,
    vsk_MessageHandler const handler
) {
    self->_task = task;
    vsk_Message_init(&self->_message, recipient, handler);
    self->_next = NULL;
    return self;
}
/*............................................................................*/
vsk_Task * vsk_EventSubscriber_getTask(
    vsk_EventSubscriber * const self
) {
    return self->_task;
}
/*............................................................................*/
vsk_Message * vsk_EventSubscriber_getMessage(
    vsk_EventSubscriber * const self
) {
    return &self->_message;
}
/*............................................................................*/
vsk_EventSubscriber * vsk_EventSubscriber_getNext(
    vsk_EventSubscriber * const self
) {
    return self->_next;
}
/*............................................................................*/
void vsk_EventSubscriber_setNext(
    vsk_EventSubscriber * const self,
    vsk_EventSubscriber * const next
) {
    self->_next = next;
}
