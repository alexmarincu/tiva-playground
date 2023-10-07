#ifndef VSK_EVENT_H
#define VSK_EVENT_H
/*............................................................................*/
typedef struct vsk_Event vsk_Event;
#include "vsk_EventSubscriber.h"
#include "vsk_LinkedList.h"
/*............................................................................*/
struct vsk_Event {
    vsk_LinkedList _eventSubscribers;
};
/*............................................................................*/
vsk_Event * vsk_Event_init(
    vsk_Event * const self
);
void vsk_Event_raise(
    vsk_Event * const self
);
void vsk_Event_subscribe(
    vsk_Event * const self,
    vsk_EventSubscriber * const subscriber
);

#endif // VSK_EVENT_H
