#ifndef APP_EV_RIGHTBUTTONDEBOUNCETIMEOUTEVENT_H
#define APP_EV_RIGHTBUTTONDEBOUNCETIMEOUTEVENT_H
/*............................................................................*/
typedef struct app_ev_RightButtonDebounceTimeoutEvent
    app_ev_RightButtonDebounceTimeoutEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct app_ev_RightButtonDebounceTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
app_ev_RightButtonDebounceTimeoutEvent *
app_ev_RightButtonDebounceTimeoutEvent_(void);
app_ev_RightButtonDebounceTimeoutEvent *
app_ev_RightButtonDebounceTimeoutEvent_init(
    app_ev_RightButtonDebounceTimeoutEvent * const self
);
#endif // APP_EV_RIGHTBUTTONDEBOUNCETIMEOUTEVENT_H
