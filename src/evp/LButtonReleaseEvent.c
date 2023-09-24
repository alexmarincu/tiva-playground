#include "LButtonReleaseEvent.h"

struct LButtonReleaseEvent {
    vsk_Event event;
};

LButtonReleaseEvent * LButtonReleaseEvent_(void) {
    static LButtonReleaseEvent self;
    return &self;
}

LButtonReleaseEvent * LButtonReleaseEvent_init(LButtonReleaseEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
