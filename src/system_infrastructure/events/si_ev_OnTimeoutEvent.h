/*----------------------------------------------------------------------------*/
#ifndef SI_EV_ONTIMEOUTEVENT_H
#define SI_EV_ONTIMEOUTEVENT_H
/*----------------------------------------------------------------------------*/
typedef struct si_ev_OnTimeoutEvent si_ev_OnTimeoutEvent;
/*----------------------------------------------------------------------------*/
#include "../../very_simple_kernel/vsk_Event.h"
/*----------------------------------------------------------------------------*/
struct si_ev_OnTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*----------------------------------------------------------------------------*/
si_ev_OnTimeoutEvent * si_ev_OnTimeoutEvent_(void);
si_ev_OnTimeoutEvent * si_ev_OnTimeoutEvent_init(
    si_ev_OnTimeoutEvent * const self
);
#endif // SI_EV_ONTIMEOUTEVENT_H
