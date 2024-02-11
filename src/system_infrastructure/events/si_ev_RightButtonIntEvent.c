/*----------------------------------------------------------------------------*/
#include "si_ev_RightButtonIntEvent.h"
/*----------------------------------------------------------------------------*/
si_ev_RightButtonIntEvent * si_ev_RightButtonIntEvent_(void) {
    static si_ev_RightButtonIntEvent self;
    return &self;
}
/*----------------------------------------------------------------------------*/
si_ev_RightButtonIntEvent * si_ev_RightButtonIntEvent_init(
    si_ev_RightButtonIntEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
