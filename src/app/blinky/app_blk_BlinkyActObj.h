/*----------------------------------------------------------------------------*/
#ifndef APP_BLK_BLINKYACTOBJ_H
#define APP_BLK_BLINKYACTOBJ_H
/*----------------------------------------------------------------------------*/
typedef struct app_blk_BlinkyActObj app_blk_BlinkyActObj;
/*----------------------------------------------------------------------------*/
#include "../../../very-simple-kernel/very_simple_kernel/src/vsk_ActiveObject.h"
#include "../../../very-simple-kernel/very_simple_kernel/src/vsk_EventSubscription.h"
#include "../../../very-simple-kernel/very_simple_kernel/src/vsk_EventTimer.h"
/*----------------------------------------------------------------------------*/
struct app_blk_BlinkyActObj {
    struct {
        vsk_ActiveObject actObj;
    } _super;
    struct {
        vsk_EventSubscription onTimeout;
        vsk_EventSubscription offTimeout;
    } _eventSubscriptions;
    struct {
        vsk_EventTimer on;
        vsk_EventTimer off;
    } eventTimers;
};
/*----------------------------------------------------------------------------*/
app_blk_BlinkyActObj * app_blk_BlinkyActObj_(void);
app_blk_BlinkyActObj * app_blk_BlinkyActObj_init(
    app_blk_BlinkyActObj * const self
);
#endif // APP_TMB_TIMEBOMBACTOBJ_H
