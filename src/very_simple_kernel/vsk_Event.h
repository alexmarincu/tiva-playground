#ifndef VSK_EVENT_H
#define VSK_EVENT_H
#include "vsk_EventSubscriber.h"

typedef struct vsk_Event vsk_Event;
struct vsk_Event {
    vsk_EventSubscriber * _eventSubscriberHead;
};

vsk_Event * vsk_Event_init(vsk_Event * const self);
void vsk_Event_raise(vsk_Event * const self);
void vsk_Event_subscribe(vsk_Event * const self, vsk_EventSubscriber * const subscriber);

#endif // VSK_EVENT_H