#ifndef APP_BLK_BLINKYACTOBJ_H
#define APP_BLK_BLINKYACTOBJ_H
/*............................................................................*/
typedef struct app_blk_BlinkyActObj app_blk_BlinkyActObj;
#include "../../very_simple_kernel/vsk_ActiveObject.h"
#include "../../very_simple_kernel/vsk_EventSubscription.h"
#include "../../very_simple_kernel/vsk_EventTimer.h"
/*............................................................................*/
struct app_blk_BlinkyActObj {
    struct {
        vsk_ActiveObject actObj;
    } _super;
    struct {
        vsk_EventSubscription onTimeout;
        vsk_EventSubscription offTimeout;
    } _eventSubscriptions;
    struct {
        vsk_EventTimer onTimeout;
        vsk_EventTimer offTimeout;
    } eventTimers;
};
/*............................................................................*/
app_blk_BlinkyActObj * app_blk_BlinkyActObj_(void);
app_blk_BlinkyActObj * app_blk_BlinkyActObj_init(
    app_blk_BlinkyActObj * const self
);
#endif // APP_TMB_TIMEBOMBACTOBJ_H
