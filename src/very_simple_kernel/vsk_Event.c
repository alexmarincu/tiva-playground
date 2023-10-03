/*............................................................................*/
#include "vsk_Event.h"
/*............................................................................*/
vsk_Event * vsk_Event_init(
    vsk_Event * const self
) {
    self->_eventSubscriberHead = 0;
    return self;
}
/*............................................................................*/
void vsk_Event_raise(
    vsk_Event * const self
) {
    for (
        vsk_EventSubscriber * subscriber = self->_eventSubscriberHead;
        (subscriber != 0);
        subscriber = vsk_EventSubscriber_getNext(subscriber)
    ) {
        vsk_Task_postMessage(
            vsk_EventSubscriber_getTask(subscriber),
            vsk_EventSubscriber_getMessage(subscriber)
        );
    }
}
/*............................................................................*/
void vsk_Event_subscribe(
    vsk_Event * const self,
    vsk_EventSubscriber * const subscriber
) {
    vsk_EventSubscriber_setNext(subscriber, self->_eventSubscriberHead);
    self->_eventSubscriberHead = subscriber;
}
