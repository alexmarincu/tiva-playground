#ifndef APP_BLK_BLINKYTASK_H
#define APP_BLK_BLINKYTASK_H
#include "../../very_simple_kernel/vsk_Task.h"

typedef struct app_blk_BlinkyTask app_blk_BlinkyTask;

app_blk_BlinkyTask * app_blk_BlinkyTask_(void);
app_blk_BlinkyTask * app_blk_BlinkyTask_init(
    app_blk_BlinkyTask * const self,
    ut_Queue * const messageQueue
);

#endif // APP_BLK_BLINKYTASK_H
