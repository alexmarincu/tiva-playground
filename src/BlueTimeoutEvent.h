#ifndef BLUETIMEOUTEVENT_H
#define BLUETIMEOUTEVENT_H
#include "vsk/vsk_Event.h"

typedef struct BlueTimeoutEvent BlueTimeoutEvent;

BlueTimeoutEvent * BlueTimeoutEvent_(void);
BlueTimeoutEvent * BlueTimeoutEvent_init(BlueTimeoutEvent * const self);

#endif // BLUETIMEOUTEVENT_H
