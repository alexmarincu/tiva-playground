#ifndef APP_EV_LEFTBUTTONDEBOUNCETIMEOUTEVENT_H
#define APP_EV_LEFTBUTTONDEBOUNCETIMEOUTEVENT_H
/*............................................................................*/
typedef struct app_ev_LeftButtonDebounceTimeoutEvent
    app_ev_LeftButtonDebounceTimeoutEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct app_ev_LeftButtonDebounceTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
app_ev_LeftButtonDebounceTimeoutEvent *
app_ev_LeftButtonDebounceTimeoutEvent_(void);
app_ev_LeftButtonDebounceTimeoutEvent *
app_ev_LeftButtonDebounceTimeoutEvent_init(
    app_ev_LeftButtonDebounceTimeoutEvent * const self
);
#endif // APP_EV_LEFTBUTTONDEBOUNCETIMEOUTEVENT_H
