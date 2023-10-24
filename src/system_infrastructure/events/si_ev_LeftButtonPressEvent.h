#ifndef SI_EV_LEFTBUTTONPRESSEVENT_H
#define SI_EV_LEFTBUTTONPRESSEVENT_H
/*............................................................................*/
typedef struct si_ev_LeftButtonPressEvent si_ev_LeftButtonPressEvent;
#include "../../very_simple_kernel/vsk_Event.h"
/*............................................................................*/
struct si_ev_LeftButtonPressEvent {
    struct {
        vsk_Event event;
    } _super;
};
/*............................................................................*/
si_ev_LeftButtonPressEvent * si_ev_LeftButtonPressEvent_(void);
si_ev_LeftButtonPressEvent * si_ev_LeftButtonPressEvent_init(
    si_ev_LeftButtonPressEvent * const self
);

#endif // SI_EV_LEFTBUTTONPRESSEVENT_H
