/*............................................................................*/
#include "vsk_Event.h"
/*............................................................................*/
vsk_Event * vsk_Event_init(
    vsk_Event * const self
) {
    vsk_LinkedList_init(&self->_eventSubscribers);
    return self;
}
/*............................................................................*/
static bool postMessage(void * const item, void * const data) {
    vsk_EventSubscriber * const subscriber = item;
    (void)data;
    vsk_Task_postMessage(
        vsk_EventSubscriber_getTask(subscriber),
        vsk_EventSubscriber_getMessage(subscriber)
    );
    return false;
}
/*............................................................................*/
void vsk_Event_raise(
    vsk_Event * const self
) {
    vsk_LinkedList_forEach(&self->_eventSubscribers, postMessage, NULL);
}
/*............................................................................*/
void vsk_Event_subscribe(
    vsk_Event * const self,
    vsk_EventSubscriber * const subscriber
) {
    vsk_LinkedList_addFirst(&self->_eventSubscribers, subscriber);
}
