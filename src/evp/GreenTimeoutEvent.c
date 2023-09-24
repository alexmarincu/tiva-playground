#include "GreenTimeoutEvent.h"

struct GreenTimeoutEvent {
    vsk_Event event;
};

GreenTimeoutEvent * GreenTimeoutEvent_(void) {
    static GreenTimeoutEvent self;
    return &self;
}

GreenTimeoutEvent * GreenTimeoutEvent_init(GreenTimeoutEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
