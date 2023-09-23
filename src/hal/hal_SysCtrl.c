#include "hal_SysCtrl.h"

void hal_SysCtrl_waitForInt(void) {
    __asm("wfi");
}
