#include "vsk_Event.h"

vsk_Event * vsk_Event_init(vsk_Event * const self, vsk_EventDispatch const dispatch) {
    self->dispatch = dispatch;
    return self;
}

void vsk_Event_dispatch(vsk_Event * const self) {
    self->dispatch(self);
}
