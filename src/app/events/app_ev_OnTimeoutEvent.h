#ifndef APP_EV_ONTIMEOUTEVENT_H
#define APP_EV_ONTIMEOUTEVENT_H
/*............................................................................*/
typedef struct app_ev_OnTimeoutEvent app_ev_OnTimeoutEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct app_ev_OnTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
app_ev_OnTimeoutEvent * app_ev_OnTimeoutEvent_(void);
app_ev_OnTimeoutEvent * app_ev_OnTimeoutEvent_init(
    app_ev_OnTimeoutEvent * const self
);
#endif // APP_EV_ONTIMEOUTEVENT_H
