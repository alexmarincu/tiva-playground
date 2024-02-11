/*----------------------------------------------------------------------------*/
#include "si_ev_LeftButtonPressEvent.h"
/*----------------------------------------------------------------------------*/
si_ev_LeftButtonPressEvent * si_ev_LeftButtonPressEvent_(void) {
    static si_ev_LeftButtonPressEvent self;
    return &self;
}
/*----------------------------------------------------------------------------*/
si_ev_LeftButtonPressEvent * si_ev_LeftButtonPressEvent_init(
    si_ev_LeftButtonPressEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
