#ifndef EV_RIGHTBUTTONPRESSEVENT_H
#define EV_RIGHTBUTTONPRESSEVENT_H
#include "../very_simple_kernel/vsk_Event.h"

typedef struct ev_RightButtonPressEvent ev_RightButtonPressEvent;

ev_RightButtonPressEvent * ev_RightButtonPressEvent_(void);
ev_RightButtonPressEvent * ev_RightButtonPressEvent_init(ev_RightButtonPressEvent * const self);

#endif // EV_RIGHTBUTTONPRESSEVENT_H
