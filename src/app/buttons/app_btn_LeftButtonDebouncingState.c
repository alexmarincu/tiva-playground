/*----------------------------------------------------------------------------*/
#include "app_btn_LeftButtonDebouncingState.h"
/*----------------------------------------------------------------------------*/
#include "../../hw_abstraction/ha_LeftButton.h"
#include "../../system_infrastructure/events/si_ev_LeftButtonPressEvent.h"
#include "app_btn_WaitForButtonIntState.h"
/*----------------------------------------------------------------------------*/
static void app_btn_LeftButtonDebouncingState_onDebounceTimeout(
    app_btn_LeftButtonDebouncingState * const self
);
/*----------------------------------------------------------------------------*/
app_btn_LeftButtonDebouncingState * app_btn_LeftButtonDebouncingState_(void) {
    static app_btn_LeftButtonDebouncingState self;
    return &self;
}
/*----------------------------------------------------------------------------*/
app_btn_LeftButtonDebouncingState * app_btn_LeftButtonDebouncingState_init(
    app_btn_LeftButtonDebouncingState * const self,
    vsk_StateContext * const stateContext
) {
    app_btn_DebouncingState_init((app_btn_DebouncingState *)self, stateContext);
    ((app_btn_ButtonsState *)self)->_onDebounceTimeout =
        (app_btn_ButtonsStateHandler)
            app_btn_LeftButtonDebouncingState_onDebounceTimeout;
    return self;
}
/*----------------------------------------------------------------------------*/
static void app_btn_LeftButtonDebouncingState_onDebounceTimeout(
    app_btn_LeftButtonDebouncingState * const self
) {
    if (ha_LeftButton_isPressed(ha_LeftButton_())) {
        vsk_Event_raise((vsk_Event *)si_ev_LeftButtonPressEvent_());
    }
    vsk_StateContext_transition(
        ((vsk_State *)self)->_stateContext,
        (vsk_State *)app_btn_WaitForButtonIntState_()
    );
}
