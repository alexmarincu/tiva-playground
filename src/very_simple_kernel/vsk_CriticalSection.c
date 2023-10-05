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
    vsk_CriticalSectionOnEnter const onEnter,
    vsk_CriticalSectionOnExit const onExit
) {
    self->_onEnter = onEnter;
    self->_onExit = onExit;
    return self;
}
/*............................................................................*/
void vsk_CriticalSection_enter(
    vsk_CriticalSection * const self
) {
    self->_onEnter();
}
/*............................................................................*/
void vsk_CriticalSection_exit(
    vsk_CriticalSection * const self
) {
    self->_onExit();
}
