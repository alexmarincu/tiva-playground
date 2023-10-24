/*............................................................................*/
#include "si_ev_RightButtonDebounceTimeoutEvent.h"
/*............................................................................*/
si_ev_RightButtonDebounceTimeoutEvent *
si_ev_RightButtonDebounceTimeoutEvent_(void) {
    static si_ev_RightButtonDebounceTimeoutEvent self;
    return &self;
}
/*............................................................................*/
si_ev_RightButtonDebounceTimeoutEvent *
si_ev_RightButtonDebounceTimeoutEvent_init(
    si_ev_RightButtonDebounceTimeoutEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
