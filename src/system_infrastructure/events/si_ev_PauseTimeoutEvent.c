/*............................................................................*/
#include "si_ev_PauseTimeoutEvent.h"
/*............................................................................*/
si_ev_PauseTimeoutEvent * si_ev_PauseTimeoutEvent_(void) {
    static si_ev_PauseTimeoutEvent self;
    return &self;
}
/*............................................................................*/
si_ev_PauseTimeoutEvent * si_ev_PauseTimeoutEvent_init(
    si_ev_PauseTimeoutEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
