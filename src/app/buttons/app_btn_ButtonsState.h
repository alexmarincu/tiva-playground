/*----------------------------------------------------------------------------*/
#ifndef APP_BTN_BUTTONSSTATE_H
#define APP_BTN_BUTTONSSTATE_H
/*----------------------------------------------------------------------------*/
typedef struct app_btn_ButtonsState app_btn_ButtonsState;
/*----------------------------------------------------------------------------*/
#include "../../very_simple_kernel/vsk_State.h"
/*----------------------------------------------------------------------------*/
typedef void (*app_btn_ButtonsStateHandler)(
    app_btn_ButtonsState * const self
);
/*----------------------------------------------------------------------------*/
struct app_btn_ButtonsState {
    struct {
        vsk_State state;
    } _super;
    app_btn_ButtonsStateHandler _onLeftButtonInt;
    app_btn_ButtonsStateHandler _onRightButtonInt;
    app_btn_ButtonsStateHandler _onDebounceTimeout;
};
/*----------------------------------------------------------------------------*/
app_btn_ButtonsState * app_btn_ButtonsState_init(
    app_btn_ButtonsState * const self, vsk_StateContext * const stateContext
);
void app_btn_ButtonsState_onLeftButtonInt(app_btn_ButtonsState * const self);
void app_btn_ButtonsState_onRightButtonInt(app_btn_ButtonsState * const self);
void app_btn_ButtonsState_onDebounceTimeout(app_btn_ButtonsState * const self);
#endif // APP_TMB_TIMEBOMBSTATE_H
