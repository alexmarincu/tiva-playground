#ifndef APP_EV_LEFTBUTTONPRESSEVENT_H
#define APP_EV_LEFTBUTTONPRESSEVENT_H
#include "../../very_simple_kernel/vsk_Event.h"

typedef struct app_ev_LeftButtonPressEvent app_ev_LeftButtonPressEvent;

app_ev_LeftButtonPressEvent * app_ev_LeftButtonPressEvent_(void);
app_ev_LeftButtonPressEvent * app_ev_LeftButtonPressEvent_init(app_ev_LeftButtonPressEvent * const self);

#endif // APP_EV_LEFTBUTTONPRESSEVENT_H