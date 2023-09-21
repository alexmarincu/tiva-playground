#include "RedEvent.h"
#include "hal/hal_Led.h"

struct RedEvent {
    vsk_Event event;
};

static void RedEvent_dispatch(RedEvent * const self);

RedEvent * RedEvent_(void) {
    static RedEvent self;
    return &self;
}

RedEvent * RedEvent_init(RedEvent * const self) {
    vsk_Event_init(&self->event, (vsk_EventDispatch)RedEvent_dispatch);
    return self;
}

static void RedEvent_dispatch(RedEvent * const self) {
    hal_Led_setRed();
}
