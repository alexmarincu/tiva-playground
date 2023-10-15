#ifndef VSK_EVENTSUBSCRIPTION_H
#define VSK_EVENTSUBSCRIPTION_H
/*............................................................................*/
typedef struct vsk_EventSubscription vsk_EventSubscription;
#include "vsk_Inbox.h"
#include "vsk_Message.h"
/*............................................................................*/
struct vsk_EventSubscription {
    vsk_Inbox * inbox;
    vsk_Message message;
};
/*............................................................................*/
vsk_EventSubscription * vsk_EventSubscription_init(
    vsk_EventSubscription * const self,
    vsk_Inbox * const inbox,
    void * const recipient,
    vsk_MessageHandler const handler
);
#endif // VSK_EVENTSUBSCRIPTION_H
