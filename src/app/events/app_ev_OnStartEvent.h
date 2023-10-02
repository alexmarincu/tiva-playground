#ifndef APP_EV_ONSTARTEVENT_H
#define APP_EV_ONSTARTEVENT_H
typedef struct app_ev_OnStartEvent app_ev_OnStartEvent;

#include "../../very_simple_kernel/vsk_Event.h"

struct app_ev_OnStartEvent {
    vsk_Event _event;
};

app_ev_OnStartEvent * app_ev_OnStartEvent_(void);
app_ev_OnStartEvent * app_ev_OnStartEvent_init(app_ev_OnStartEvent * const self);

#endif // APP_EV_ONSTARTEVENT_H
