/*............................................................................*/
#include "vsk_Assert.h"
/*............................................................................*/
vsk_Assert * vsk_Assert_(void) {
    static vsk_Assert self;
    return &self;
}
/*............................................................................*/
vsk_Assert * vsk_Assert_init(
    vsk_Assert * const self,
    vsk_AssertOnAssert const onAssert
) {
    self->_onAssert = onAssert;
    return self;
}
/*............................................................................*/
void vsk_Assert_check(
    vsk_Assert * const self,
    bool const condition
) {
    if (condition == false) {
        self->_onAssert();
    }
}
