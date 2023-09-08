#include "os_Scheduler.h"
// #include <stddef.h>

typedef struct Scheduler Scheduler;
struct Scheduler {
    os_Task * tasks;
    uint8_t count;
};

static Scheduler self = {
    .tasks = 0,
    .count = 0
};

void os_Scheduler_setTasks(os_Task * const tasks, uint8_t const count) {
    self.tasks = tasks;
    self.count = count;
}

void os_Scheduler_main(void) {
    for (uint8_t i = 0; i < self.count; i++) {
        os_Task_main(&self.tasks[i]);
    }
}
