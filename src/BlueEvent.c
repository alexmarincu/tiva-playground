#include "BlueEvent.h"
#include "hal/hal_Led.h"

struct BlueEvent {
    vsk_Event event;
};

static void BlueEvent_dispatch(BlueEvent * const self);

BlueEvent * BlueEvent_(void) {
    static BlueEvent self;
    return &self;
}

BlueEvent * BlueEvent_init(BlueEvent * const self) {
    vsk_Event_init(&self->event, (vsk_EventDispatch)BlueEvent_dispatch);
    return self;
}

static void BlueEvent_dispatch(BlueEvent * const self) {
    hal_Led_setBlue();
}
