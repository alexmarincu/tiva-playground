#ifndef VSK_EVENTSUBSCRIPTION_H
#define VSK_EVENTSUBSCRIPTION_H
/*............................................................................*/
typedef struct vsk_EventSubscription vsk_EventSubscription;
#include "vsk_Message.h"
#include "vsk_Task.h"
/*............................................................................*/
struct vsk_EventSubscription {
    vsk_Task * _task;
    vsk_Message _message;
};
/*............................................................................*/
vsk_EventSubscription * vsk_EventSubscription_init(
    vsk_EventSubscription * const self,
    vsk_Task * const task,
    void * const recipient,
    vsk_MessageHandler const handler
);
/*............................................................................*/
vsk_Task * vsk_EventSubscription_getTask(
    vsk_EventSubscription * const self
);
/*............................................................................*/
vsk_Message * vsk_EventSubscription_getMessage(
    vsk_EventSubscription * const self
);
#endif // VSK_EVENTSUBSCRIPTION_H
