#include "vsk_Event.h"

vsk_Event * vsk_Event_init(vsk_Event * const self) {
    self->_eventSubscriberHead = 0;
    return self;
}

void vsk_Event_raise(vsk_Event * const self) {
    for (vsk_EventSubscriber * subscriber = self->_eventSubscriberHead; (subscriber != 0); subscriber = subscriber->next) {
        vsk_Task_postMessage(subscriber->task, &subscriber->message);
    }
}

void vsk_Event_subscribe(vsk_Event * const self, vsk_EventSubscriber * const subscriber) {
    subscriber->next = self->_eventSubscriberHead;
    self->_eventSubscriberHead = subscriber;
}
