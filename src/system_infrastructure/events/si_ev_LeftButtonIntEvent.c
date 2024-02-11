/*----------------------------------------------------------------------------*/
#include "si_ev_LeftButtonIntEvent.h"
/*----------------------------------------------------------------------------*/
si_ev_LeftButtonIntEvent * si_ev_LeftButtonIntEvent_(void) {
    static si_ev_LeftButtonIntEvent self;
    return &self;
}
/*----------------------------------------------------------------------------*/
si_ev_LeftButtonIntEvent * si_ev_LeftButtonIntEvent_init(
    si_ev_LeftButtonIntEvent * const self
) {
    vsk_Event_init((vsk_Event *)self);
    return self;
}
