#include "RButtonReleaseEvent.h"

struct RButtonReleaseEvent {
    vsk_Event event;
};

RButtonReleaseEvent * RButtonReleaseEvent_(void) {
    static RButtonReleaseEvent self;
    return &self;
}

RButtonReleaseEvent * RButtonReleaseEvent_init(RButtonReleaseEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
