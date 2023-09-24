#ifndef REDTIMEOUTEVENT_H
#define REDTIMEOUTEVENT_H
#include "../vsk/vsk_Event.h"

typedef struct RedTimeoutEvent RedTimeoutEvent;

RedTimeoutEvent * RedTimeoutEvent_(void);
RedTimeoutEvent * RedTimeoutEvent_init(RedTimeoutEvent * const self);

#endif // REDTIMEOUTEVENT_H
