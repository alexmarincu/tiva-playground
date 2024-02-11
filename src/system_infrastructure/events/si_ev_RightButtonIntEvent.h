/*----------------------------------------------------------------------------*/
#ifndef SI_EV_RIGHTBUTTONINTEVENT_H
#define SI_EV_RIGHTBUTTONINTEVENT_H
/*----------------------------------------------------------------------------*/
typedef struct si_ev_RightButtonIntEvent si_ev_RightButtonIntEvent;
/*----------------------------------------------------------------------------*/
#include "../../../very-simple-kernel/very_simple_kernel/src/vsk_Event.h"
/*----------------------------------------------------------------------------*/
struct si_ev_RightButtonIntEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*----------------------------------------------------------------------------*/
si_ev_RightButtonIntEvent * si_ev_RightButtonIntEvent_(void);
si_ev_RightButtonIntEvent * si_ev_RightButtonIntEvent_init(
    si_ev_RightButtonIntEvent * const self
);
#endif // SI_EV_RIGHTBUTTONINTEVENT_H
