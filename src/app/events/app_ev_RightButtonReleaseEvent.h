#ifndef APP_EV_RIGHTBUTTONRELEASEEVENT_H
#define APP_EV_RIGHTBUTTONRELEASEEVENT_H
#include "../../very_simple_kernel/vsk_Event.h"

typedef struct app_ev_RightButtonReleaseEvent app_ev_RightButtonReleaseEvent;

app_ev_RightButtonReleaseEvent * app_ev_RightButtonReleaseEvent_(void);
app_ev_RightButtonReleaseEvent * app_ev_RightButtonReleaseEvent_init(app_ev_RightButtonReleaseEvent * const self);

#endif // APP_EV_RIGHTBUTTONRELEASEEVENT_H
