/*............................................................................*/
#include "ut_Array.h"
/*............................................................................*/
ut_Array * ut_Array_init(
    ut_Array * const self,
    void ** const items,
    size_t const length
) {
    self->_items = items;
    self->_length = length;
    ut_Array_clear(self);
    return self;
}
/*............................................................................*/
void ut_Array_insert(
    ut_Array * const self,
    void * const item,
    size_t const index
) {
    self->_items[index] = item;
}
/*............................................................................*/
void * ut_Array_get(
    ut_Array * const self,
    uint8_t const index
) {
    return self->_items[index];
}
/*............................................................................*/
void * ut_Array_remove(
    ut_Array * const self,
    uint8_t const index
) {
    void * item = self->_items[index];
    self->_items[index] = 0;
    return item;
}
/*............................................................................*/
void ut_Array_clear(
    ut_Array * const self
) {
    for (size_t i = 0; i < self->_length; i++) {
        self->_items[i] = 0;
    }
}
/*............................................................................*/
size_t ut_Array_length(
    ut_Array * const self
) {
    return self->_length;
}
