#include "ev_LeftButtonPressEvent.h"

struct ev_LeftButtonPressEvent {
    vsk_Event event;
};

ev_LeftButtonPressEvent * ev_LeftButtonPressEvent_(void) {
    static ev_LeftButtonPressEvent self;
    return &self;
}

ev_LeftButtonPressEvent * ev_LeftButtonPressEvent_init(ev_LeftButtonPressEvent * const self) {
    vsk_Event_init(&self->event);
    return self;
}
