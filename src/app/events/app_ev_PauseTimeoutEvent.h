#ifndef APP_EV_PAUSETIMEOUTEVENT_H
#define APP_EV_PAUSETIMEOUTEVENT_H
/*............................................................................*/
typedef struct app_ev_PauseTimeoutEvent app_ev_PauseTimeoutEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct app_ev_PauseTimeoutEvent {
    vsk_Event _event;
};
/*............................................................................*/
app_ev_PauseTimeoutEvent * app_ev_PauseTimeoutEvent_(void);
app_ev_PauseTimeoutEvent * app_ev_PauseTimeoutEvent_init(
    app_ev_PauseTimeoutEvent * const self
);
#endif // APP_EV_PAUSETIMEOUTEVENT_H
