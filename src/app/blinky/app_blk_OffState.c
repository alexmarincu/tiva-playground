/*............................................................................*/
#include "app_blk_OffState.h"
#include "app_blk_BlinkyActObj.h"
#include "app_blk_OnState.h"
/*............................................................................*/
static void app_blk_OffState_onEnter(app_blk_OffState * const self);
static void app_blk_OnState_onOffTimeout(app_blk_OffState * const self);
/*............................................................................*/
app_blk_OffState * app_blk_OffState_(void) {
    static app_blk_OffState self;
    return &self;
}
/*............................................................................*/
app_blk_OffState * app_blk_OffState_init(
    app_blk_OffState * const self, vsk_StateContext * const stateContext
) {
    app_blk_BlinkyState_init((app_blk_BlinkyState *)self, stateContext);
    ((vsk_State *)self)->_onEnter = (vsk_StateOnEnter)app_blk_OffState_onEnter;
    ((app_blk_BlinkyState *)self)->_onOffTimeout =
        (app_blk_BlinkyStateHandler)app_blk_OnState_onOffTimeout;
    return self;
}
/*............................................................................*/
static void app_blk_OffState_onEnter(app_blk_OffState * const self) {
    app_blk_BlinkyActObj * blinky =
        (app_blk_BlinkyActObj *)((vsk_State *)self)->_stateContext;
    vsk_Timer_start((vsk_Timer *)&blinky->eventTimers.offTimeout);
}
/*............................................................................*/
static void app_blk_OnState_onOffTimeout(app_blk_OffState * const self) {
    vsk_StateContext_transition(
        ((vsk_State *)self)->_stateContext, (vsk_State *)app_blk_OnState_()
    );
}
