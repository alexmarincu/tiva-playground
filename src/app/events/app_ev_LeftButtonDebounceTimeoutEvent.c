/*............................................................................*/
#include "app_ev_LeftButtonDebounceTimeoutEvent.h"
/*............................................................................*/
app_ev_LeftButtonDebounceTimeoutEvent *
app_ev_LeftButtonDebounceTimeoutEvent_(void) {
    static app_ev_LeftButtonDebounceTimeoutEvent self;
    return &self;
}
/*............................................................................*/
app_ev_LeftButtonDebounceTimeoutEvent *
app_ev_LeftButtonDebounceTimeoutEvent_init(
    app_ev_LeftButtonDebounceTimeoutEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
