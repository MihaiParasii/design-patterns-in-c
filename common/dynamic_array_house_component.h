#ifndef DYNAMIC_ARRAY_HOUSE_COMPONENT_H
#define DYNAMIC_ARRAY_HOUSE_COMPONENT_H

#include <stdio.h>

#include "../common/i_house_component.h"
#include "../defines.h"

vtable_for(dynamic_array_house_component) {
    method_(void, add_back, i_house_component* object);

    method_(void, remove_back);
};

class_(dynamic_array_house_component) {
    dynamic_array_house_component__vtable *vtable;
    size_t size;
    size_t capacity;
    i_house_component **data;
};

dynamic_array_house_component *new__dynamic_array_house_component(size_t default_size);


#endif //DYNAMIC_ARRAY_HOUSE_COMPONENT_H
