#ifndef EV_LEFTBUTTONPRESSEVENT_H
#define EV_LEFTBUTTONPRESSEVENT_H
#include "../very_simple_kernel/vsk_Event.h"

typedef struct ev_LeftButtonPressEvent ev_LeftButtonPressEvent;

ev_LeftButtonPressEvent * ev_LeftButtonPressEvent_(void);
ev_LeftButtonPressEvent * ev_LeftButtonPressEvent_init(ev_LeftButtonPressEvent * const self);

#endif // EV_LEFTBUTTONPRESSEVENT_H
