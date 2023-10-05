#ifndef APP_EV_BLINKTIMEOUTEVENT_H
#define APP_EV_BLINKTIMEOUTEVENT_H
/*............................................................................*/
typedef struct app_ev_BlinkTimeoutEvent app_ev_BlinkTimeoutEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct app_ev_BlinkTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
app_ev_BlinkTimeoutEvent * app_ev_BlinkTimeoutEvent_(void);
app_ev_BlinkTimeoutEvent * app_ev_BlinkTimeoutEvent_init(
    app_ev_BlinkTimeoutEvent * const self
);
#endif // APP_EV_BLINKTIMEOUTEVENT_H
