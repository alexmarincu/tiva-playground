#ifndef EV_LEFTBUTTONRELEASEEVENT_H
#define EV_LEFTBUTTONRELEASEEVENT_H
#include "../very_simple_kernel/vsk_Event.h"

typedef struct ev_LeftButtonReleaseEvent ev_LeftButtonReleaseEvent;

ev_LeftButtonReleaseEvent * ev_LeftButtonReleaseEvent_(void);
ev_LeftButtonReleaseEvent * ev_LeftButtonReleaseEvent_init(ev_LeftButtonReleaseEvent * const self);

#endif // EV_LEFTBUTTONRELEASEEVENT_H
