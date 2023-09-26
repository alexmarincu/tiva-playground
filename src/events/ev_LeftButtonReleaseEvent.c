#include "ev_LeftButtonReleaseEvent.h"

struct ev_LeftButtonReleaseEvent {
    vsk_Event event;
};

ev_LeftButtonReleaseEvent * ev_LeftButtonReleaseEvent_(void) {
    static ev_LeftButtonReleaseEvent self;
    return &self;
}

ev_LeftButtonReleaseEvent * ev_LeftButtonReleaseEvent_init(ev_LeftButtonReleaseEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
