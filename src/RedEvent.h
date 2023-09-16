#ifndef REDEVENT_H
#define REDEVENT_H
#include "vsos/vsos_Event.h"

typedef struct RedEvent RedEvent;

RedEvent * RedEvent_(void);
RedEvent * RedEvent_init(RedEvent * const self);

#endif // REDEVENT_H
