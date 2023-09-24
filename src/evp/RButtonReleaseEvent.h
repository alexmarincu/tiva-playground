#ifndef RBUTTONRELEASEEVENT_H
#define RBUTTONRELEASEEVENT_H
#include "../vsk/vsk_Event.h"

typedef struct RButtonReleaseEvent RButtonReleaseEvent;

RButtonReleaseEvent * RButtonReleaseEvent_(void);
RButtonReleaseEvent * RButtonReleaseEvent_init(RButtonReleaseEvent * const self);

#endif // RBUTTONRELEASEEVENT_H
