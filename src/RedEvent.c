#include "RedEvent.h"
#include "led.h"

struct RedEvent {
    vsos_Event event;
};

static void RedEvent_dispatch(RedEvent * const self);

RedEvent * RedEvent_(void) {
    static RedEvent self;
    return &self;
}

RedEvent * RedEvent_init(RedEvent * const self) {
    vsos_Event_init(&self->event, (vsos_Event_dispatchFun)RedEvent_dispatch);
    return self;
}

static void RedEvent_dispatch(RedEvent * const self) {
    LedSetRed();
}
