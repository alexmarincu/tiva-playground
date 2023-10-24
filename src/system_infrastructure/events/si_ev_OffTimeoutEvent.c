/*............................................................................*/
#include "si_ev_OffTimeoutEvent.h"
/*............................................................................*/
si_ev_OffTimeoutEvent * si_ev_OffTimeoutEvent_(void) {
    static si_ev_OffTimeoutEvent self;
    return &self;
}
/*............................................................................*/
si_ev_OffTimeoutEvent * si_ev_OffTimeoutEvent_init(
    si_ev_OffTimeoutEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
