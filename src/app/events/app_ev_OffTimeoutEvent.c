/*............................................................................*/
#include "app_ev_OffTimeoutEvent.h"
/*............................................................................*/
app_ev_OffTimeoutEvent * app_ev_OffTimeoutEvent_(void) {
    static app_ev_OffTimeoutEvent self;
    return &self;
}
/*............................................................................*/
app_ev_OffTimeoutEvent * app_ev_OffTimeoutEvent_init(
    app_ev_OffTimeoutEvent * const self
) {
    vsk_Event_init(&self->_super.event);
    return self;
}
