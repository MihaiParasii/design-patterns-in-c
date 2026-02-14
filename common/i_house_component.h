#ifndef I_HOUSE_COMPONENT_H
#define I_HOUSE_COMPONENT_H
#include "../defines.h"

vtable_for(i_house_component) {
    method_(int, get_rooms_count);
    method_(double, get_area);
};


class_(i_house_component) {
    i_house_component__vtable *vtable;
};

#endif //I_HOUSE_COMPONENT_H
