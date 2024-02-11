/*----------------------------------------------------------------------------*/
#ifndef SI_EV_LEFTBUTTONINTEVENT_H
#define SI_EV_LEFTBUTTONINTEVENT_H
/*----------------------------------------------------------------------------*/
typedef struct si_ev_LeftButtonIntEvent si_ev_LeftButtonIntEvent;
/*----------------------------------------------------------------------------*/
#include "../../very_simple_kernel/vsk_Event.h"
/*----------------------------------------------------------------------------*/
struct si_ev_LeftButtonIntEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*----------------------------------------------------------------------------*/
si_ev_LeftButtonIntEvent * si_ev_LeftButtonIntEvent_(void);
si_ev_LeftButtonIntEvent * si_ev_LeftButtonIntEvent_init(
    si_ev_LeftButtonIntEvent * const self
);
#endif // SI_EV_LEFTBUTTONINTEVENT_H
