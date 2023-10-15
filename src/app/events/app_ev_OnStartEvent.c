/*............................................................................*/
#include "app_ev_OnStartEvent.h"
/*............................................................................*/
app_ev_OnStartEvent * app_ev_OnStartEvent_(void) {
    static app_ev_OnStartEvent self;
    return &self;
}
/*............................................................................*/
app_ev_OnStartEvent * app_ev_OnStartEvent_init(
    app_ev_OnStartEvent * const self
) {
    vsk_Event_init(&self->_super.event);
    return self;
}
