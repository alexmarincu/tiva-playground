/*----------------------------------------------------------------------------*/
#include "si_ev_RightButtonPressEvent.h"
/*----------------------------------------------------------------------------*/
si_ev_RightButtonPressEvent * si_ev_RightButtonPressEvent_(void) {
    static si_ev_RightButtonPressEvent self;
    return &self;
}
/*----------------------------------------------------------------------------*/
si_ev_RightButtonPressEvent * si_ev_RightButtonPressEvent_init(
    si_ev_RightButtonPressEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
