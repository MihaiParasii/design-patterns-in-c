#ifndef LAB2_I_ABSTRACTION_IMPL_H
#define LAB2_I_ABSTRACTION_IMPL_H
#include "../defines.h"


vtable_for(i_abstraction_impl) {
    method_(void, print_something);
};

class_(i_abstraction_impl) {
    i_abstraction_impl__vtable *vtable;
};


#endif //LAB2_I_ABSTRACTION_IMPL_H