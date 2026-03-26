#ifndef LAB2_MACOS_ABSTRACTION_IMPL_H
#define LAB2_MACOS_ABSTRACTION_IMPL_H
#include "../defines.h"
#include "i_abstraction_impl.h"

class_(macos_abstraction_impl) {
    implements_(i_abstraction_impl);
};

macos_abstraction_impl *new__macos_abstraction_impl();


#endif //LAB2_MACOS_ABSTRACTION_IMPL_H
