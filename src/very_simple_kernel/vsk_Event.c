/*............................................................................*/
#include "vsk_Event.h"
/*............................................................................*/
vsk_Event * vsk_Event_init(
    vsk_Event * const self
) {
    vsk_LinkedList_init(&self->_eventSubscriptions);
    return self;
}
/*............................................................................*/
static bool postMessage(void * const item, void * const data) {
    vsk_EventSubscription * const subscription = item;
    (void)data;
    vsk_Task_postMessage(
        vsk_EventSubscription_getTask(subscription),
        vsk_EventSubscription_getMessage(subscription)
    );
    return false;
}
/*............................................................................*/
void vsk_Event_raise(
    vsk_Event * const self
) {
    vsk_LinkedList_forEach(&self->_eventSubscriptions, postMessage, NULL);
}
/*............................................................................*/
void vsk_Event_subscribe(
    vsk_Event * const self,
    vsk_EventSubscription * const subscription
) {
    vsk_LinkedList_addFirst(&self->_eventSubscriptions, subscription);
}
