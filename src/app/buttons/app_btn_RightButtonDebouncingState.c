/*----------------------------------------------------------------------------*/
#include "app_btn_RightButtonDebouncingState.h"
/*----------------------------------------------------------------------------*/
#include "../../hw_abstraction/ha_RightButton.h"
#include "../../system_infrastructure/events/si_ev_RightButtonPressEvent.h"
#include "app_btn_WaitForButtonIntState.h"
/*----------------------------------------------------------------------------*/
static void app_btn_RightButtonDebouncingState_onDebounceTimeout(
    app_btn_RightButtonDebouncingState * const self
);
/*----------------------------------------------------------------------------*/
app_btn_RightButtonDebouncingState * app_btn_RightButtonDebouncingState_(void) {
    static app_btn_RightButtonDebouncingState self;
    return &self;
}
/*----------------------------------------------------------------------------*/
app_btn_RightButtonDebouncingState * app_btn_RightButtonDebouncingState_init(
    app_btn_RightButtonDebouncingState * const self,
    vsk_StateContext * const stateContext
) {
    app_btn_DebouncingState_init((app_btn_DebouncingState *)self, stateContext);
    ((app_btn_ButtonsState *)self)->_onDebounceTimeout =
        (app_btn_ButtonsStateHandler)
            app_btn_RightButtonDebouncingState_onDebounceTimeout;
    return self;
}
/*----------------------------------------------------------------------------*/
static void app_btn_RightButtonDebouncingState_onDebounceTimeout(
    app_btn_RightButtonDebouncingState * const self
) {
    if (ha_RightButton_isPressed(ha_RightButton_())) {
        vsk_Event_raise((vsk_Event *)si_ev_RightButtonPressEvent_());
    }
    vsk_StateContext_transition(
        ((vsk_State *)self)->_stateContext,
        (vsk_State *)app_btn_WaitForButtonIntState_()
    );
}
