#ifndef GREENTIMEOUTEVENT_H
#define GREENTIMEOUTEVENT_H
#include "vsk/vsk_Event.h"

typedef struct GreenTimeoutEvent GreenTimeoutEvent;

GreenTimeoutEvent * GreenTimeoutEvent_(void);
GreenTimeoutEvent * GreenTimeoutEvent_init(GreenTimeoutEvent * const self);

#endif // GREENTIMEOUTEVENT_H
