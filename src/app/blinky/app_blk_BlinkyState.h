/*----------------------------------------------------------------------------*/
#ifndef APP_BLK_BLINKYSTATE_H
#define APP_BLK_BLINKYSTATE_H
/*----------------------------------------------------------------------------*/
typedef struct app_blk_BlinkyState app_blk_BlinkyState;
/*----------------------------------------------------------------------------*/
#include "../../../very-simple-kernel/very_simple_kernel/src/vsk_State.h"
/*----------------------------------------------------------------------------*/
typedef void (*app_blk_BlinkyStateHandler)(app_blk_BlinkyState * const self);
/*----------------------------------------------------------------------------*/
struct app_blk_BlinkyState {
    struct {
        vsk_State state;
    } _super;
    app_blk_BlinkyStateHandler _onOnTimeout;
    app_blk_BlinkyStateHandler _onOffTimeout;
};
/*----------------------------------------------------------------------------*/
app_blk_BlinkyState * app_blk_BlinkyState_init(
    app_blk_BlinkyState * const self, vsk_StateContext * const stateContext
);
/*----------------------------------------------------------------------------*/
void app_blk_BlinkyState_onOnTimeout(app_blk_BlinkyState * const self);
/*----------------------------------------------------------------------------*/
void app_blk_BlinkyState_onOffTimeout(app_blk_BlinkyState * const self);
#endif // APP_BLK_BLINKYSTATE_H
