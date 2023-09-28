#ifndef APP_EV_REDTIMEOUTEVENT_H
#define APP_EV_REDTIMEOUTEVENT_H
#include "../../very_simple_kernel/vsk_Event.h"

typedef struct app_ev_RedTimeoutEvent app_ev_RedTimeoutEvent;

app_ev_RedTimeoutEvent * app_ev_RedTimeoutEvent_(void);
app_ev_RedTimeoutEvent * app_ev_RedTimeoutEvent_init(app_ev_RedTimeoutEvent * const self);

#endif // APP_EV_REDTIMEOUTEVENT_H
