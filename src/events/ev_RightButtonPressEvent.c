#include "ev_RightButtonPressEvent.h"

struct ev_RightButtonPressEvent {
    vsk_Event event;
};

ev_RightButtonPressEvent * ev_RightButtonPressEvent_(void) {
    static ev_RightButtonPressEvent self;
    return &self;
}

ev_RightButtonPressEvent * ev_RightButtonPressEvent_init(ev_RightButtonPressEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
