/*............................................................................*/
#include "si_ev_BlinkTimeoutEvent.h"
/*............................................................................*/
si_ev_BlinkTimeoutEvent * si_ev_BlinkTimeoutEvent_(void) {
    static si_ev_BlinkTimeoutEvent self;
    return &self;
}
/*............................................................................*/
si_ev_BlinkTimeoutEvent * si_ev_BlinkTimeoutEvent_init(
    si_ev_BlinkTimeoutEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
