/*----------------------------------------------------------------------------*/
#include "si_ev_OnTimeoutEvent.h"
/*----------------------------------------------------------------------------*/
si_ev_OnTimeoutEvent * si_ev_OnTimeoutEvent_(void) {
    static si_ev_OnTimeoutEvent self;
    return &self;
}
/*----------------------------------------------------------------------------*/
si_ev_OnTimeoutEvent * si_ev_OnTimeoutEvent_init(
    si_ev_OnTimeoutEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
