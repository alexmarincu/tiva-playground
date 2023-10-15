#ifndef APP_BLK_BASESTATE_H
#define APP_BLK_BASESTATE_H
/*............................................................................*/
typedef struct app_blk_BaseState app_blk_BaseState;
typedef void (*app_blk_BaseStateHandler)(
    app_blk_BaseState * const self
);
#include "../../very_simple_kernel/vsk_State.h"
/*............................................................................*/
struct app_blk_BaseState {
    struct {
        vsk_State state;
    } _super;
    app_blk_BaseStateHandler _onOnTimeout;
    app_blk_BaseStateHandler _onOffTimeout;
};
/*............................................................................*/
app_blk_BaseState * app_blk_BaseState_init(
    app_blk_BaseState * const self,
    vsk_StateMachine * const stateMachine
);
void app_blk_BaseState_onOnTimeout(
    app_blk_BaseState * const self
);
void app_blk_BaseState_onOffTimeout(
    app_blk_BaseState * const self
);
#endif // APP_BLK_BASESTATE_H
