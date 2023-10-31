/*............................................................................*/
#include "app_btn_WaitForButtonIntState.h"
/*............................................................................*/
#include "app_btn_LeftButtonDebouncingState.h"
#include "app_btn_RightButtonDebouncingState.h"
/*............................................................................*/
static void app_btn_WaitForButtonIntState_onLeftButtonInt(
    app_btn_WaitForButtonIntState * const self
);
static void app_btn_WaitForButtonIntState_onRightButtonInt(
    app_btn_WaitForButtonIntState * const self
);
/*............................................................................*/
app_btn_WaitForButtonIntState * app_btn_WaitForButtonIntState_(void) {
    static app_btn_WaitForButtonIntState self;
    return &self;
}
/*............................................................................*/
app_btn_WaitForButtonIntState * app_btn_WaitForButtonIntState_init(
    app_btn_WaitForButtonIntState * const self,
    vsk_StateContext * const stateContext
) {
    app_btn_ButtonsState_init((app_btn_ButtonsState *)self, stateContext);
    ((app_btn_ButtonsState *)self)->_onLeftButtonInt =
        (app_btn_ButtonsStateHandler)
            app_btn_WaitForButtonIntState_onLeftButtonInt;
    ((app_btn_ButtonsState *)self)->_onRightButtonInt =
        (app_btn_ButtonsStateHandler)
            app_btn_WaitForButtonIntState_onRightButtonInt;
    return self;
}
/*............................................................................*/
static void app_btn_WaitForButtonIntState_onLeftButtonInt(
    app_btn_WaitForButtonIntState * const self
) {
    vsk_StateContext_transition(
        ((vsk_State *)self)->_stateContext,
        (vsk_State *)app_btn_LeftButtonDebouncingState_()
    );
}
/*............................................................................*/
static void app_btn_WaitForButtonIntState_onRightButtonInt(
    app_btn_WaitForButtonIntState * const self
) {
    vsk_StateContext_transition(
        ((vsk_State *)self)->_stateContext,
        (vsk_State *)app_btn_RightButtonDebouncingState_()
    );
}
