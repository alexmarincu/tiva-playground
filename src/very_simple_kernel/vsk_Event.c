/*............................................................................*/
#include "vsk_Event.h"
/*............................................................................*/
vsk_Event * vsk_Event_init(vsk_Event * const self) {
    vsk_LinkedList_init(&self->_eventSubscriptions);
    return self;
}
/*............................................................................*/
static void vsk_postMessage(vsk_EventSubscription * const subscription) {
    vsk_Inbox_postMessage(subscription->inbox, &subscription->message);
}
/*............................................................................*/
void vsk_Event_raise(vsk_Event * const self) {
    vsk_LinkedList_forEach(
        &self->_eventSubscriptions,
        (vsk_LinkedListForEachOperation)vsk_postMessage
    );
}
/*............................................................................*/
void vsk_Event_subscribe(
    vsk_Event * const self, vsk_EventSubscription * const subscription
) {
    vsk_LinkedList_addFirst(&self->_eventSubscriptions, subscription);
}
