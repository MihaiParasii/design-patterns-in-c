#ifndef LAB2_HOUSE_OPERATIONS_FACADE_H
#define LAB2_HOUSE_OPERATIONS_FACADE_H
#include "i_house_operations_facade.h"
#include "../defines.h"


class_(house_operations_facade) {
    implements_(i_house_operations_facade);
};

house_operations_facade * new__house_operations_facade();

#endif //LAB2_HOUSE_OPERATIONS_FACADE_H
