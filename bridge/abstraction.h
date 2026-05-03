#ifndef LAB2_ABSTRACTION_H
#define LAB2_ABSTRACTION_H
#include "i_abstraction_impl.h"
#include "../defines.h"

vtable_for(abstraction) {
    method_(void, call_print_something_from_impl);
};

class_(abstraction) {
    i_abstraction_impl *__impl;
    abstraction__vtable *vtable;
};

_constructor(abstraction, i_abstraction_impl *impl);


#endif //LAB2_ABSTRACTION_H
