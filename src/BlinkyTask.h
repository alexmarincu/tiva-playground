#ifndef BLINKYTASK_H
#define BLINKYTASK_H
#include "vsk/vsk_Task.h"

typedef struct BlinkyTask BlinkyTask;
struct BlinkyTask {
    vsk_Task task;
};

BlinkyTask * BlinkyTask_(void);
BlinkyTask * BlinkyTask_init(
    BlinkyTask * const self,
    utl_Queue * const messageQueue
);

#endif // BLINKYTASK_H
