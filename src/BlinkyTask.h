#ifndef BLINKYTASK_H
#define BLINKYTASK_H
#include "vsos/vsos_Task.h"

typedef struct BlinkyTask BlinkyTask;
struct BlinkyTask {
    vsos_Task task;
};

BlinkyTask * BlinkyTask_(void);
BlinkyTask * BlinkyTask_init(
    BlinkyTask * const self,
    utl_Queue * const eventQueue
);

#endif // BlinkyTask_H
