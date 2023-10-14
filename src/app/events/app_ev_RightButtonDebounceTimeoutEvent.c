/*............................................................................*/
#include "app_ev_RightButtonDebounceTimeoutEvent.h"
/*............................................................................*/
app_ev_RightButtonDebounceTimeoutEvent *
app_ev_RightButtonDebounceTimeoutEvent_(void) {
    static app_ev_RightButtonDebounceTimeoutEvent self;
    return &self;
}
/*............................................................................*/
app_ev_RightButtonDebounceTimeoutEvent *
app_ev_RightButtonDebounceTimeoutEvent_init(
    app_ev_RightButtonDebounceTimeoutEvent * const self
) {
    vsk_Event_init(&self->_super.event);
    return self;
}
