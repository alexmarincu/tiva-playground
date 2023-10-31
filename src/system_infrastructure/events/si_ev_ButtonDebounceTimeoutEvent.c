/*............................................................................*/
#include "si_ev_ButtonDebounceTimeoutEvent.h"
/*............................................................................*/
si_ev_ButtonDebounceTimeoutEvent * si_ev_ButtonDebounceTimeoutEvent_(void) {
    static si_ev_ButtonDebounceTimeoutEvent self;
    return &self;
}
/*............................................................................*/
si_ev_ButtonDebounceTimeoutEvent * si_ev_ButtonDebounceTimeoutEvent_init(
    si_ev_ButtonDebounceTimeoutEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
