/*............................................................................*/
#include "app_ev_PauseTimeoutEvent.h"
/*............................................................................*/
app_ev_PauseTimeoutEvent * app_ev_PauseTimeoutEvent_(void) {
    static app_ev_PauseTimeoutEvent self;
    return &self;
}
/*............................................................................*/
app_ev_PauseTimeoutEvent * app_ev_PauseTimeoutEvent_init(
    app_ev_PauseTimeoutEvent * const self
) {
    vsk_Event_init(&self->_super.event);
    return self;
}
