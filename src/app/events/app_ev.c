/*............................................................................*/
#include "app_ev.h"
#include "app_ev_BlinkTimeoutEvent.h"
#include "app_ev_LeftButtonDebounceTimeoutEvent.h"
#include "app_ev_LeftButtonIntEvent.h"
#include "app_ev_LeftButtonPressEvent.h"
#include "app_ev_OffTimeoutEvent.h"
#include "app_ev_OnTimeoutEvent.h"
#include "app_ev_PauseTimeoutEvent.h"
#include "app_ev_RightButtonDebounceTimeoutEvent.h"
#include "app_ev_RightButtonIntEvent.h"
#include "app_ev_RightButtonPressEvent.h"
/*............................................................................*/
void app_ev_initEvents(void) {
    app_ev_BlinkTimeoutEvent_init(app_ev_BlinkTimeoutEvent_());
    app_ev_LeftButtonPressEvent_init(app_ev_LeftButtonPressEvent_());
    app_ev_LeftButtonIntEvent_init(app_ev_LeftButtonIntEvent_());
    app_ev_LeftButtonDebounceTimeoutEvent_init(
        app_ev_LeftButtonDebounceTimeoutEvent_()
    );
    app_ev_PauseTimeoutEvent_init(app_ev_PauseTimeoutEvent_());
    app_ev_RightButtonPressEvent_init(app_ev_RightButtonPressEvent_());
    app_ev_RightButtonIntEvent_init(app_ev_RightButtonIntEvent_());
    app_ev_RightButtonDebounceTimeoutEvent_init(
        app_ev_RightButtonDebounceTimeoutEvent_()
    );
    app_ev_OnTimeoutEvent_init(app_ev_OnTimeoutEvent_());
    app_ev_OffTimeoutEvent_init(app_ev_OffTimeoutEvent_());
}
