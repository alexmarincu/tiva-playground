#ifndef BLUEEVENT_H
#define BLUEEVENT_H
#include "vsk/vsk_Event.h"

typedef struct BlueEvent BlueEvent;

BlueEvent * BlueEvent_(void);
BlueEvent * BlueEvent_init(BlueEvent * const self);

#endif // BLUEEVENT_H
