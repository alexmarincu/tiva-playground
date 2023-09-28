#ifndef APP_EV_GREENTIMEOUTEVENT_H
#define APP_EV_GREENTIMEOUTEVENT_H
#include "../../very_simple_kernel/vsk_Event.h"

typedef struct app_ev_GreenTimeoutEvent app_ev_GreenTimeoutEvent;

app_ev_GreenTimeoutEvent * app_ev_GreenTimeoutEvent_(void);
app_ev_GreenTimeoutEvent * app_ev_GreenTimeoutEvent_init(app_ev_GreenTimeoutEvent * const self);

#endif // APP_EV_GREENTIMEOUTEVENT_H
