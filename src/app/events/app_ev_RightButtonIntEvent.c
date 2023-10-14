/*............................................................................*/
#include "app_ev_RightButtonIntEvent.h"
/*............................................................................*/
app_ev_RightButtonIntEvent * app_ev_RightButtonIntEvent_(void) {
    static app_ev_RightButtonIntEvent self;
    return &self;
}
/*............................................................................*/
app_ev_RightButtonIntEvent * app_ev_RightButtonIntEvent_init(
    app_ev_RightButtonIntEvent * const self
) {
    vsk_Event_init(&self->_super.event);
    return self;
}
