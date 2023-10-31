/*............................................................................*/
#ifndef SI_EV_BUTTONDEBOUNCETIMEOUTEVENT_H
#define SI_EV_BUTTONDEBOUNCETIMEOUTEVENT_H
/*............................................................................*/
typedef struct si_ev_ButtonDebounceTimeoutEvent
    si_ev_ButtonDebounceTimeoutEvent;
/*............................................................................*/
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct si_ev_ButtonDebounceTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
si_ev_ButtonDebounceTimeoutEvent * si_ev_ButtonDebounceTimeoutEvent_(void);
si_ev_ButtonDebounceTimeoutEvent * si_ev_ButtonDebounceTimeoutEvent_init(
    si_ev_ButtonDebounceTimeoutEvent * const self
);
#endif // SI_EV_BUTTONDEBOUNCETIMEOUTEVENT_H
