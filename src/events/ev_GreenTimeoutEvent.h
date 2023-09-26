#ifndef EV_GREENTIMEOUTEVENT_H
#define EV_GREENTIMEOUTEVENT_H
#include "../very_simple_kernel/vsk_Event.h"

typedef struct ev_GreenTimeoutEvent ev_GreenTimeoutEvent;

ev_GreenTimeoutEvent * ev_GreenTimeoutEvent_(void);
ev_GreenTimeoutEvent * ev_GreenTimeoutEvent_init(ev_GreenTimeoutEvent * const self);

#endif // EV_GREENTIMEOUTEVENT_H
