#ifndef SI_EV_PAUSETIMEOUTEVENT_H
#define SI_EV_PAUSETIMEOUTEVENT_H
/*............................................................................*/
typedef struct si_ev_PauseTimeoutEvent si_ev_PauseTimeoutEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct si_ev_PauseTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
si_ev_PauseTimeoutEvent * si_ev_PauseTimeoutEvent_(void);
si_ev_PauseTimeoutEvent * si_ev_PauseTimeoutEvent_init(
    si_ev_PauseTimeoutEvent * const self
);
#endif // SI_EV_PAUSETIMEOUTEVENT_H
