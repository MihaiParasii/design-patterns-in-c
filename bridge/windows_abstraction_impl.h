#ifndef LAB2_WINDOWS_ABSTRACTION_IMPL_H
#define LAB2_WINDOWS_ABSTRACTION_IMPL_H
#include "../defines.h"
#include "i_abstraction_impl.h"

class_(windows_abstraction_impl) {
    implements_(i_abstraction_impl);
};

windows_abstraction_impl *new__windows_abstraction_impl();

#endif //LAB2_WINDOWS_ABSTRACTION_IMPL_H
