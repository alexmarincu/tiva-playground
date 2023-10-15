#ifndef APP_EV_OFFTIMEOUTEVENT_H
#define APP_EV_OFFTIMEOUTEVENT_H
/*............................................................................*/
typedef struct app_ev_OffTimeoutEvent app_ev_OffTimeoutEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct app_ev_OffTimeoutEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
app_ev_OffTimeoutEvent * app_ev_OffTimeoutEvent_(void);
app_ev_OffTimeoutEvent * app_ev_OffTimeoutEvent_init(
    app_ev_OffTimeoutEvent * const self
);
#endif // APP_EV_OFFTIMEOUTEVENT_H
