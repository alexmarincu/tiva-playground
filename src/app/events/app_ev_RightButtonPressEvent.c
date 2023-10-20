/*............................................................................*/
#include "app_ev_RightButtonPressEvent.h"
/*............................................................................*/
app_ev_RightButtonPressEvent * app_ev_RightButtonPressEvent_(void) {
    static app_ev_RightButtonPressEvent self;
    return &self;
}
/*............................................................................*/
app_ev_RightButtonPressEvent * app_ev_RightButtonPressEvent_init(
    app_ev_RightButtonPressEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
