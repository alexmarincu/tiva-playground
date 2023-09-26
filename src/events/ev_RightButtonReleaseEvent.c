#include "ev_RightButtonReleaseEvent.h"

struct ev_RightButtonReleaseEvent {
    vsk_Event event;
};

ev_RightButtonReleaseEvent * ev_RightButtonReleaseEvent_(void) {
    static ev_RightButtonReleaseEvent self;
    return &self;
}

ev_RightButtonReleaseEvent * ev_RightButtonReleaseEvent_init(ev_RightButtonReleaseEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
