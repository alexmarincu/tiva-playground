/*............................................................................*/
#include "ha_Interrupt.h"
#include <stdbool.h>
#include <stdint.h>
//
#include "../../lib/TivaWare/driverlib/interrupt.h"
/*............................................................................*/
void ha_Interrupt_enableAll(void) {
    IntMasterEnable();
}
/*............................................................................*/
void ha_Interrupt_disableAll(void) {
    IntMasterDisable();
}
