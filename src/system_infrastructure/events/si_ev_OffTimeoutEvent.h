#ifndef SI_EV_OFFTIMEOUTEVENT_H
#define SI_EV_OFFTIMEOUTEVENT_H
/*............................................................................*/
typedef struct si_ev_OffTimeoutEvent si_ev_OffTimeoutEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct si_ev_OffTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
si_ev_OffTimeoutEvent * si_ev_OffTimeoutEvent_(void);
si_ev_OffTimeoutEvent * si_ev_OffTimeoutEvent_init(
    si_ev_OffTimeoutEvent * const self
);
#endif // SI_EV_OFFTIMEOUTEVENT_H
