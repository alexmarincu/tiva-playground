#ifndef APP_EV_BLUETIMEOUTEVENT_H
#define APP_EV_BLUETIMEOUTEVENT_H
#include "../../very_simple_kernel/vsk_Event.h"

typedef struct app_ev_BlueTimeoutEvent app_ev_BlueTimeoutEvent;

app_ev_BlueTimeoutEvent * app_ev_BlueTimeoutEvent_(void);
app_ev_BlueTimeoutEvent * app_ev_BlueTimeoutEvent_init(app_ev_BlueTimeoutEvent * const self);

#endif // APP_EV_BLUETIMEOUTEVENT_H
