/*............................................................................*/
#include "si_ev.h"
/*............................................................................*/
#include "si_ev_BlinkTimeoutEvent.h"
#include "si_ev_ButtonDebounceTimeoutEvent.h"
#include "si_ev_LeftButtonIntEvent.h"
#include "si_ev_LeftButtonPressEvent.h"
#include "si_ev_OffTimeoutEvent.h"
#include "si_ev_OnTimeoutEvent.h"
#include "si_ev_PauseTimeoutEvent.h"
#include "si_ev_RightButtonIntEvent.h"
#include "si_ev_RightButtonPressEvent.h"
/*............................................................................*/
void si_ev_init(void) {
    si_ev_LeftButtonIntEvent_init(si_ev_LeftButtonIntEvent_());
    si_ev_LeftButtonPressEvent_init(si_ev_LeftButtonPressEvent_());
    si_ev_RightButtonIntEvent_init(si_ev_RightButtonIntEvent_());
    si_ev_RightButtonPressEvent_init(si_ev_RightButtonPressEvent_());
    si_ev_ButtonDebounceTimeoutEvent_init(si_ev_ButtonDebounceTimeoutEvent_());
    si_ev_BlinkTimeoutEvent_init(si_ev_BlinkTimeoutEvent_());
    si_ev_PauseTimeoutEvent_init(si_ev_PauseTimeoutEvent_());
    si_ev_OnTimeoutEvent_init(si_ev_OnTimeoutEvent_());
    si_ev_OffTimeoutEvent_init(si_ev_OffTimeoutEvent_());
}
