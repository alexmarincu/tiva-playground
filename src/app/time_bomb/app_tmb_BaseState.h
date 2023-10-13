#ifndef APP_TMB_BASESTATE_H
#define APP_TMB_BASESTATE_H
/*............................................................................*/
typedef struct app_tmb_BaseState app_tmb_BaseState;
typedef void (*app_tmb_BaseStateHandler)(
    app_tmb_BaseState * const self
);
#include "../../very_simple_kernel/vsk_State.h"
/*............................................................................*/
struct app_tmb_BaseState {
    struct {
        vsk_State state;
    } _super;
    app_tmb_BaseStateHandler _onBlinkTimeout;
    app_tmb_BaseStateHandler _onPauseTimeout;
    app_tmb_BaseStateHandler _onRightButtonPress;
    app_tmb_BaseStateHandler _onLeftButtonPress;
};
/*............................................................................*/
app_tmb_BaseState * app_tmb_BaseState_init(
    app_tmb_BaseState * const self,
    vsk_StateMachine * const stateMachine
);
void app_tmb_BaseState_onBlinkTimeout(
    app_tmb_BaseState * const self
);
void app_tmb_BaseState_onPauseTimeout(
    app_tmb_BaseState * const self
);
void app_tmb_BaseState_onRightButtonPress(
    app_tmb_BaseState * const self
);
void app_tmb_BaseState_onLeftButtonPress(
    app_tmb_BaseState * const self
);
#endif // APP_BLK_BASESTATE_H
