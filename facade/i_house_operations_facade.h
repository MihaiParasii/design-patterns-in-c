#ifndef LAB2_I_HOUSE_OPERATIONS_FACADE_H
#define LAB2_I_HOUSE_OPERATIONS_FACADE_H

#include "../defines.h"

vtable_for(i_house_operations_facade) {
    method_(void, buy_apartment, int user_id, int apartment_id);
};

class_(i_house_operations_facade) {
    i_house_operations_facade__vtable *vtable;
};

#endif //LAB2_I_HOUSE_OPERATIONS_FACADE_H
