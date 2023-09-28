#ifndef APP_EV_LEFTBUTTONRELEASEEVENT_H
#define APP_EV_LEFTBUTTONRELEASEEVENT_H
#include "../../very_simple_kernel/vsk_Event.h"

typedef struct app_ev_LeftButtonReleaseEvent app_ev_LeftButtonReleaseEvent;

app_ev_LeftButtonReleaseEvent * app_ev_LeftButtonReleaseEvent_(void);
app_ev_LeftButtonReleaseEvent * app_ev_LeftButtonReleaseEvent_init(app_ev_LeftButtonReleaseEvent * const self);

#endif // APP_EV_LEFTBUTTONRELEASEEVENT_H
