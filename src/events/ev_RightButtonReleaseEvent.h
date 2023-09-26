#ifndef EV_RIGHTBUTTONRELEASEEVENT_H
#define EV_RIGHTBUTTONRELEASEEVENT_H
#include "../very_simple_kernel/vsk_Event.h"

typedef struct ev_RightButtonReleaseEvent ev_RightButtonReleaseEvent;

ev_RightButtonReleaseEvent * ev_RightButtonReleaseEvent_(void);
ev_RightButtonReleaseEvent * ev_RightButtonReleaseEvent_init(ev_RightButtonReleaseEvent * const self);

#endif // EV_RIGHTBUTTONRELEASEEVENT_H
