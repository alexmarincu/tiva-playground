#include "ha_SysCtrl.h"

void ha_SysCtrl_waitForInt(void) {
    __asm("wfi");
}