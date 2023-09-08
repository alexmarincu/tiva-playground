#ifndef OS_TASK_h
#define OS_TASK_h
#include <stdint.h>

typedef struct os_Task os_Task;
typedef void (*os_Task_operationFun)(void);
struct os_Task {
    uint32_t startTimeAtLastRunMillis;
    uint32_t runRateMillis;
    os_Task_operationFun operation;
};

os_Task * os_Task_init(os_Task * const self, uint32_t const runRateMillis, os_Task_operationFun const operation);
void os_Task_main(os_Task * const self);

#endif // OS_TASK_h
