#include "BlueTimeoutEvent.h"
#include "hal/hal_Led.h"

struct BlueTimeoutEvent {
    vsk_Event event;
};

BlueTimeoutEvent * BlueTimeoutEvent_(void) {
    static BlueTimeoutEvent self;
    return &self;
}

BlueTimeoutEvent * BlueTimeoutEvent_init(BlueTimeoutEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
