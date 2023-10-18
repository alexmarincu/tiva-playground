/*............................................................................*/
#include "vsk_EventTimer.h"
/*............................................................................*/
static void raiseEvent(vsk_EventTimer * const self) {
    vsk_Event_raise(self->_event);
}
/*............................................................................*/
vsk_EventTimer * vsk_EventTimer_init(
    vsk_EventTimer * const self,
    vsk_Event * const event
) {
    vsk_Timer_init(&self->_super.timer, (vsk_TimerCallback)raiseEvent);
    self->_event = event;
    return self;
}
