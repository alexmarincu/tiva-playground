#ifndef SI_EV_RIGHTBUTTONDEBOUNCETIMEOUTEVENT_H
#define SI_EV_RIGHTBUTTONDEBOUNCETIMEOUTEVENT_H
/*............................................................................*/
typedef struct si_ev_RightButtonDebounceTimeoutEvent
    si_ev_RightButtonDebounceTimeoutEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct si_ev_RightButtonDebounceTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
si_ev_RightButtonDebounceTimeoutEvent *
si_ev_RightButtonDebounceTimeoutEvent_(void);
si_ev_RightButtonDebounceTimeoutEvent *
si_ev_RightButtonDebounceTimeoutEvent_init(
    si_ev_RightButtonDebounceTimeoutEvent * const self
);
#endif // SI_EV_RIGHTBUTTONDEBOUNCETIMEOUTEVENT_H
