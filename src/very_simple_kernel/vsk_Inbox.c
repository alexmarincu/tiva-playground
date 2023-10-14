/*............................................................................*/
#include "vsk_Inbox.h"
#include "vsk_CriticalSection.h"
/*............................................................................*/
vsk_Inbox * vsk_Inbox_init(
    vsk_Inbox * const self
) {
    vsk_Queue_init(&self->_messageQueue);
    return self;
}
/*............................................................................*/
bool vsk_Inbox_isEmpty(
    vsk_Inbox * const self
) {
    bool isEmpty;
    vsk_CriticalSection_onEnter(vsk_CriticalSection_());
    isEmpty = vsk_Queue_isEmpty(&self->_messageQueue);
    vsk_CriticalSection_onExit(vsk_CriticalSection_());
    return isEmpty;
}
/*............................................................................*/
void vsk_Inbox_postMessage(
    vsk_Inbox * const self,
    vsk_Message * const message
) {
    vsk_CriticalSection_onEnter(vsk_CriticalSection_());
    vsk_Queue_enqueue(&self->_messageQueue, message);
    vsk_CriticalSection_onExit(vsk_CriticalSection_());
}
/*............................................................................*/
vsk_Message * vsk_Inbox_readMessage(
    vsk_Inbox * const self
) {
    vsk_Message * message;
    vsk_CriticalSection_onEnter(vsk_CriticalSection_());
    message = vsk_Queue_dequeue(&self->_messageQueue);
    vsk_CriticalSection_onExit(vsk_CriticalSection_());
    return message;
}
/*............................................................................*/
void vsk_Inbox_clear(
    vsk_Inbox * const self
) {
    vsk_CriticalSection_onEnter(vsk_CriticalSection_());
    vsk_Queue_clear(&self->_messageQueue);
    vsk_CriticalSection_onExit(vsk_CriticalSection_());
}
