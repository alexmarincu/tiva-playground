#ifndef APP_EV_RIGHTBUTTONINTEVENT_H
#define APP_EV_RIGHTBUTTONINTEVENT_H
/*............................................................................*/
typedef struct app_ev_RightButtonIntEvent app_ev_RightButtonIntEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct app_ev_RightButtonIntEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
app_ev_RightButtonIntEvent * app_ev_RightButtonIntEvent_(void);
app_ev_RightButtonIntEvent * app_ev_RightButtonIntEvent_init(
    app_ev_RightButtonIntEvent * const self
);
#endif // APP_EV_RIGHTBUTTONINTEVENT_H
