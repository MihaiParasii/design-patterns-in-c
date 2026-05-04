#ifndef VISITABLE_APARTMENT_H
#define VISITABLE_APARTMENT_H
#include "../defines.h"
#include "i_visitable_property.h"

class_(visitable_apartment) {
    implements_(i_visitable_property);
    apartment *__apartment;
};

constructor(visitable_apartment, apartment *apt);

#endif //VISITABLE_APARTMENT_H
