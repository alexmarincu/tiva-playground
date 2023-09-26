#ifndef EV_BLUETIMEOUTEVENT_H
#define EV_BLUETIMEOUTEVENT_H
#include "../very_simple_kernel/vsk_Event.h"

typedef struct ev_BlueTimeoutEvent ev_BlueTimeoutEvent;

ev_BlueTimeoutEvent * ev_BlueTimeoutEvent_(void);
ev_BlueTimeoutEvent * ev_BlueTimeoutEvent_init(ev_BlueTimeoutEvent * const self);

#endif // EV_BLUETIMEOUTEVENT_H
