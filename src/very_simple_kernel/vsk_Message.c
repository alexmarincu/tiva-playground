#include "vsk_Message.h"

vsk_Message * vsk_Message_init(
    vsk_Message * const self,
    void * const recipient,
    vsk_MessageHandler const handler
) {
    self->_recipient = recipient;
    self->_handler = handler;
    return self;
}

void vsk_Message_dispatch(vsk_Message * const self) {
    self->_handler(self->_recipient);
}
