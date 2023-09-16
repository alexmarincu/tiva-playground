#include "BlueEvent.h"
#include "led.h"

struct BlueEvent {
    vsos_Event event;
};

static void BlueEvent_dispatch(BlueEvent * const self);

BlueEvent * BlueEvent_(void) {
    static BlueEvent self;
    return &self;
}

BlueEvent * BlueEvent_init(BlueEvent * const self) {
    vsos_Event_init(&self->event, (vsos_Event_dispatchFun)BlueEvent_dispatch);
    return self;
}

static void BlueEvent_dispatch(BlueEvent * const self) {
    LedSetBlue();
}
