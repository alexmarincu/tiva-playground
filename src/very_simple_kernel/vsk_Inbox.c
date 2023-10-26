/*............................................................................*/
#include "vsk_Inbox.h"
/*............................................................................*/
#include "vsk_CriticalSection.h"
/*............................................................................*/
vsk_Inbox * vsk_Inbox_init(vsk_Inbox * const self, vsk_Task * const task) {
    self->task = task;
    vsk_LinkedQueue_init(&self->_messageQueue);
    return self;
}
/*............................................................................*/
bool vsk_Inbox_isEmpty(vsk_Inbox * const self) {
    bool isEmpty;
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    isEmpty = vsk_LinkedQueue_isEmpty(&self->_messageQueue);
    vsk_CriticalSection_exit(vsk_CriticalSection_());
    return isEmpty;
}
/*............................................................................*/
void vsk_Inbox_postMessage(
    vsk_Inbox * const self, vsk_Message * const message
) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    vsk_LinkedQueue_enqueue(&self->_messageQueue, message);
    vsk_Task_activate(self->task);
    vsk_CriticalSection_exit(vsk_CriticalSection_());
}
/*............................................................................*/
vsk_Message * vsk_Inbox_readMessage(vsk_Inbox * const self) {
    vsk_Message * message;
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    message = vsk_LinkedQueue_dequeue(&self->_messageQueue);
    vsk_CriticalSection_exit(vsk_CriticalSection_());
    return message;
}
/*............................................................................*/
void vsk_Inbox_clear(vsk_Inbox * const self) {
    vsk_CriticalSection_enter(vsk_CriticalSection_());
    vsk_LinkedQueue_clear(&self->_messageQueue);
    vsk_CriticalSection_exit(vsk_CriticalSection_());
}
