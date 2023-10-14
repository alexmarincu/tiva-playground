/*............................................................................*/
#include "vsk_Event.h"
/*............................................................................*/
vsk_EventSubscription * vsk_EventSubscription_init(
    vsk_EventSubscription * const self,
    vsk_Inbox * const inbox,
    void * const recipient,
    vsk_MessageHandler const handler
) {
    self->inbox = inbox;
    vsk_Message_init(&self->message, recipient, handler);
    return self;
}
