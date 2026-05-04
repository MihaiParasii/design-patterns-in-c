#ifndef I_APARTMENT_ITERATOR_H
#define I_APARTMENT_ITERATOR_H
#include "../defines.h"
#include "../models/apartment.h"

vtable_for(i_apartment_iterator) {
    method_(int,       has_next);
    method_(apartment*, next);
};

class_(i_apartment_iterator) {
    i_apartment_iterator__vtable *vtable;
};

#endif //I_APARTMENT_ITERATOR_H
