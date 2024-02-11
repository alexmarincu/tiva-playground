/*----------------------------------------------------------------------------*/
#include "app_blk_OnState.h"
/*----------------------------------------------------------------------------*/
#include "../../hw_abstraction/ha_RgbLed.h"
#include "app_blk_BlinkyActObj.h"
#include "app_blk_OffState.h"
/*----------------------------------------------------------------------------*/
static void app_blk_OnState_onEnter(app_blk_OnState * const self);
static void app_blk_OnState_onExit(app_blk_OnState * const self);
static void app_blk_OnState_onOnTimeout(app_blk_OnState * const self);
/*----------------------------------------------------------------------------*/
app_blk_OnState * app_blk_OnState_(void) {
    static app_blk_OnState self;
    return &self;
}
/*----------------------------------------------------------------------------*/
app_blk_OnState * app_blk_OnState_init(
    app_blk_OnState * const self, vsk_StateContext * const stateContext
) {
    app_blk_BlinkyState_init((app_blk_BlinkyState *)self, stateContext);
    ((vsk_State *)self)->_onEnter = (vsk_StateOnEnter)app_blk_OnState_onEnter;
    ((vsk_State *)self)->_onExit = (vsk_StateOnExit)app_blk_OnState_onExit;
    ((app_blk_BlinkyState *)self)->_onOnTimeout =
        (app_blk_BlinkyStateHandler)app_blk_OnState_onOnTimeout;
    return self;
}
/*----------------------------------------------------------------------------*/
static void app_blk_OnState_onEnter(app_blk_OnState * const self) {
    ha_RgbLed_setBlue();
    app_blk_BlinkyActObj * blinky =
        (app_blk_BlinkyActObj *)((vsk_State *)self)->_stateContext;
    vsk_Timer_start((vsk_Timer *)&blinky->eventTimers.on);
}
/*----------------------------------------------------------------------------*/
static void app_blk_OnState_onExit(app_blk_OnState * const self) {
    ha_RgbLed_setOff();
}
/*----------------------------------------------------------------------------*/
static void app_blk_OnState_onOnTimeout(app_blk_OnState * const self) {
    vsk_StateContext_transition(
        ((vsk_State *)self)->_stateContext, (vsk_State *)app_blk_OffState_()
    );
}
