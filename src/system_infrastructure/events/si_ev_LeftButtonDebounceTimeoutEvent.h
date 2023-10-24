#ifndef SI_EV_LEFTBUTTONDEBOUNCETIMEOUTEVENT_H
#define SI_EV_LEFTBUTTONDEBOUNCETIMEOUTEVENT_H
/*............................................................................*/
typedef struct si_ev_LeftButtonDebounceTimeoutEvent
    si_ev_LeftButtonDebounceTimeoutEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct si_ev_LeftButtonDebounceTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
si_ev_LeftButtonDebounceTimeoutEvent *
si_ev_LeftButtonDebounceTimeoutEvent_(void);
si_ev_LeftButtonDebounceTimeoutEvent *
si_ev_LeftButtonDebounceTimeoutEvent_init(
    si_ev_LeftButtonDebounceTimeoutEvent * const self
);
#endif // SI_EV_LEFTBUTTONDEBOUNCETIMEOUTEVENT_H
