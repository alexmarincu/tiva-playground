#ifndef EV_REDTIMEOUTEVENT_H
#define EV_REDTIMEOUTEVENT_H
#include "../very_simple_kernel/vsk_Event.h"

typedef struct ev_RedTimeoutEvent ev_RedTimeoutEvent;

ev_RedTimeoutEvent * ev_RedTimeoutEvent_(void);
ev_RedTimeoutEvent * ev_RedTimeoutEvent_init(ev_RedTimeoutEvent * const self);

#endif // EV_REDTIMEOUTEVENT_H
