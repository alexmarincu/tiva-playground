#include "hal_SysClock.h"

#include <stdbool.h>

#include "../../lib/TivaWare/driverlib/sysctl.h"

void hal_SysClock_setMaxFrequency(void) {
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
}

uint32_t hal_SysClock_getFrequency(void) {
    return SysCtlClockGet();
}
