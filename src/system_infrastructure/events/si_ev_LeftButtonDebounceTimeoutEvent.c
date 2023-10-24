/*............................................................................*/
#include "si_ev_LeftButtonDebounceTimeoutEvent.h"
/*............................................................................*/
si_ev_LeftButtonDebounceTimeoutEvent *
si_ev_LeftButtonDebounceTimeoutEvent_(void) {
    static si_ev_LeftButtonDebounceTimeoutEvent self;
    return &self;
}
/*............................................................................*/
si_ev_LeftButtonDebounceTimeoutEvent *
si_ev_LeftButtonDebounceTimeoutEvent_init(
    si_ev_LeftButtonDebounceTimeoutEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
