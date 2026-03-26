#ifndef LAB2_CONCRETE_ABSTRACTION_H
#define LAB2_CONCRETE_ABSTRACTION_H

#include "../defines.h"
#include "abstraction.h"

class_(concrete_abstraction) {
    extends_(abstraction);
};

concrete_abstraction *new__concrete_abstraction(i_abstraction_impl *impl);

#endif //LAB2_CONCRETE_ABSTRACTION_H
