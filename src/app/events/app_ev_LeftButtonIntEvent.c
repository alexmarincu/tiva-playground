/*............................................................................*/
#include "app_ev_LeftButtonIntEvent.h"
/*............................................................................*/
app_ev_LeftButtonIntEvent * app_ev_LeftButtonIntEvent_(void) {
    static app_ev_LeftButtonIntEvent self;
    return &self;
}
/*............................................................................*/
app_ev_LeftButtonIntEvent * app_ev_LeftButtonIntEvent_init(
    app_ev_LeftButtonIntEvent * const self
) {
    vsk_Event_init(&self->_super.event);
    return self;
}
