#ifndef APP_EV_RIGHTBUTTONPRESSEVENT_H
#define APP_EV_RIGHTBUTTONPRESSEVENT_H
#include "../../very_simple_kernel/vsk_Event.h"

typedef struct app_ev_RightButtonPressEvent app_ev_RightButtonPressEvent;

app_ev_RightButtonPressEvent * app_ev_RightButtonPressEvent_(void);
app_ev_RightButtonPressEvent * app_ev_RightButtonPressEvent_init(app_ev_RightButtonPressEvent * const self);

#endif // APP_EV_RIGHTBUTTONPRESSEVENT_H
