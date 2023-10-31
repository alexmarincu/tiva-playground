/*............................................................................*/
#include "app_btn_DebouncingState.h"
/*............................................................................*/
#include "app_btn_ButtonsActObj.h"
/*............................................................................*/
static void app_btn_DebouncingState_onEnter(
    app_btn_DebouncingState * const self
);
/*............................................................................*/
app_btn_DebouncingState * app_btn_DebouncingState_init(
    app_btn_DebouncingState * const self, vsk_StateContext * const stateContext
) {
    app_btn_ButtonsState_init((app_btn_ButtonsState *)self, stateContext);
    ((vsk_State *)self)->_onEnter =
        (vsk_StateOnEnter)app_btn_DebouncingState_onEnter;
    return self;
}
/*............................................................................*/
static void app_btn_DebouncingState_onEnter(
    app_btn_DebouncingState * const self
) {
    app_btn_ButtonsActObj * buttons =
        (app_btn_ButtonsActObj *)((vsk_State *)self)->_stateContext;
    vsk_Timer_start((vsk_Timer *)&buttons->eventTimers.buttonDebounce);
}
