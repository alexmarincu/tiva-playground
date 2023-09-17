#ifndef GREENEVENT_H
#define GREENEVENT_H
#include "vsk/vsk_Event.h"

typedef struct GreenEvent GreenEvent;

GreenEvent * GreenEvent_(void);
GreenEvent * GreenEvent_init(GreenEvent * const self);

#endif // GREENEVENT_H
