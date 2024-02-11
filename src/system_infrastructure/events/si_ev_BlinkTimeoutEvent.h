/*----------------------------------------------------------------------------*/
#ifndef SI_EV_BLINKTIMEOUTEVENT_H
#define SI_EV_BLINKTIMEOUTEVENT_H
/*----------------------------------------------------------------------------*/
typedef struct si_ev_BlinkTimeoutEvent si_ev_BlinkTimeoutEvent;
/*----------------------------------------------------------------------------*/
#include "../../../very-simple-kernel/very_simple_kernel/src/vsk_Event.h"
/*----------------------------------------------------------------------------*/
struct si_ev_BlinkTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*----------------------------------------------------------------------------*/
si_ev_BlinkTimeoutEvent * si_ev_BlinkTimeoutEvent_(void);
si_ev_BlinkTimeoutEvent * si_ev_BlinkTimeoutEvent_init(
    si_ev_BlinkTimeoutEvent * const self
);
#endif // SI_EV_BLINKTIMEOUTEVENT_H
