/*............................................................................*/
#include "app_ev_LeftButtonPressEvent.h"
/*............................................................................*/
app_ev_LeftButtonPressEvent * app_ev_LeftButtonPressEvent_(void) {
    static app_ev_LeftButtonPressEvent self;
    return &self;
}
/*............................................................................*/
app_ev_LeftButtonPressEvent * app_ev_LeftButtonPressEvent_init(
    app_ev_LeftButtonPressEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
