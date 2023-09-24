#ifndef LBUTTONRELEASEEVENT_H
#define LBUTTONRELEASEEVENT_H
#include "../vsk/vsk_Event.h"

typedef struct LButtonReleaseEvent LButtonReleaseEvent;

LButtonReleaseEvent * LButtonReleaseEvent_(void);
LButtonReleaseEvent * LButtonReleaseEvent_init(LButtonReleaseEvent * const self);

#endif // LBUTTONRELEASEEVENT_H
