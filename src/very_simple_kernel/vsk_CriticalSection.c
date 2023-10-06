/*............................................................................*/
#include "vsk_CriticalSection.h"
/*............................................................................*/
vsk_CriticalSection * vsk_CriticalSection_(void) {
    static vsk_CriticalSection self;
    return &self;
}
/*............................................................................*/
vsk_CriticalSection * vsk_CriticalSection_init(
    vsk_CriticalSection * const self,
    vsk_CriticalSectionDisableInt const disableInt,
    vsk_CriticalSectionEnableInt const enableInt
) {
    self->_disableInt = disableInt;
    self->_enableInt = enableInt;
    self->_nestingLevels = 0;
    return self;
}
/*............................................................................*/
void vsk_CriticalSection_enter(
    vsk_CriticalSection * const self
) {
    self->_disableInt();
    self->_nestingLevels++;
}
/*............................................................................*/
void vsk_CriticalSection_exit(
    vsk_CriticalSection * const self
) {
    if (self->_nestingLevels > 0) {
        self->_nestingLevels--;
        if (self->_nestingLevels == 0) {
            self->_enableInt();
        }
    }
}
