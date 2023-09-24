#include "RButtonPressEvent.h"

struct RButtonPressEvent {
    vsk_Event event;
};

RButtonPressEvent * RButtonPressEvent_(void) {
    static RButtonPressEvent self;
    return &self;
}

RButtonPressEvent * RButtonPressEvent_init(RButtonPressEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
