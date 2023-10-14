#ifndef APP_EV_LEFTBUTTONINTEVENT_H
#define APP_EV_LEFTBUTTONINTEVENT_H
/*............................................................................*/
typedef struct app_ev_LeftButtonIntEvent app_ev_LeftButtonIntEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct app_ev_LeftButtonIntEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
app_ev_LeftButtonIntEvent * app_ev_LeftButtonIntEvent_(void);
app_ev_LeftButtonIntEvent * app_ev_LeftButtonIntEvent_init(
    app_ev_LeftButtonIntEvent * const self
);
#endif // APP_EV_LEFTBUTTONINTEVENT_H
