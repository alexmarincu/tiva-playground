#ifndef BLK_BLINKYTASK_H
#define BLK_BLINKYTASK_H
#include "../very_simple_kernel/vsk_Task.h"

typedef struct blk_BlinkyTask blk_BlinkyTask;

blk_BlinkyTask * blk_BlinkyTask_(void);
blk_BlinkyTask * blk_BlinkyTask_init(
    blk_BlinkyTask * const self,
    ut_Queue * const messageQueue
);

#endif // BLK_BLINKYTASK_H
