/*............................................................................*/
#include "app_ev_OnTimeoutEvent.h"
/*............................................................................*/
app_ev_OnTimeoutEvent * app_ev_OnTimeoutEvent_(void) {
    static app_ev_OnTimeoutEvent self;
    return &self;
}
/*............................................................................*/
app_ev_OnTimeoutEvent * app_ev_OnTimeoutEvent_init(
    app_ev_OnTimeoutEvent * const self
) {
    vsk_Event_init(&self->_super.event);
    return self;
}
