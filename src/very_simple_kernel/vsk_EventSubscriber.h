#ifndef VSK_EVENTSUBSCRIBER_H
#define VSK_EVENTSUBSCRIBER_H
/*............................................................................*/
typedef struct vsk_EventSubscriber vsk_EventSubscriber;
#include "vsk_Message.h"
#include "vsk_Task.h"
/*............................................................................*/
struct vsk_EventSubscriber {
    vsk_Task * _task;
    vsk_Message _message;
    vsk_EventSubscriber * _next;
};
/*............................................................................*/
vsk_EventSubscriber * vsk_EventSubscriber_init(
    vsk_EventSubscriber * const self,
    vsk_Task * const task,
    void * const recipient,
    vsk_MessageHandler const handler
);
/*............................................................................*/
vsk_Task * vsk_EventSubscriber_getTask(
    vsk_EventSubscriber * const self
);
/*............................................................................*/
vsk_Message * vsk_EventSubscriber_getMessage(
    vsk_EventSubscriber * const self
);
/*............................................................................*/
vsk_EventSubscriber * vsk_EventSubscriber_getNext(
    vsk_EventSubscriber * const self
);
/*............................................................................*/
void vsk_EventSubscriber_setNext(
    vsk_EventSubscriber * const self,
    vsk_EventSubscriber * const next
);
#endif // VSK_EVENTSUBSCRIBER_H
