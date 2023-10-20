/*............................................................................*/
#include "app_ev_BlinkTimeoutEvent.h"
/*............................................................................*/
app_ev_BlinkTimeoutEvent * app_ev_BlinkTimeoutEvent_(void) {
    static app_ev_BlinkTimeoutEvent self;
    return &self;
}
/*............................................................................*/
app_ev_BlinkTimeoutEvent * app_ev_BlinkTimeoutEvent_init(
    app_ev_BlinkTimeoutEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
