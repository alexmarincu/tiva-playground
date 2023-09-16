#include "vsos_Event.h"

vsos_Event * vsos_Event_init(vsos_Event * const self, vsos_Event_dispatchFun const dispatch) {
    self->dispatch = dispatch;
    return self;
}

void vsos_Event_dispatch(vsos_Event * const self) {
    self->dispatch(self);
}
