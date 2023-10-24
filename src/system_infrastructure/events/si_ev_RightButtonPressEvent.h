#ifndef SI_EV_RIGHTBUTTONPRESSEVENT_H
#define SI_EV_RIGHTBUTTONPRESSEVENT_H
/*............................................................................*/
typedef struct si_ev_RightButtonPressEvent si_ev_RightButtonPressEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct si_ev_RightButtonPressEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
si_ev_RightButtonPressEvent * si_ev_RightButtonPressEvent_(void);
si_ev_RightButtonPressEvent * si_ev_RightButtonPressEvent_init(
    si_ev_RightButtonPressEvent * const self
);
#endif // SI_EV_RIGHTBUTTONPRESSEVENT_H
