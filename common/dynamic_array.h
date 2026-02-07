#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdio.h>

#include "../models/base_house.h"
#include "../defines.h"

vtable_(dynamic_array) {
    method_(void, add_back, base_house* base_house);

    method_(void, remove_back);

    method_(void, print);
};

class_(dynamic_array) {
    dynamic_array__vtable *vtable;
    size_t size;
    size_t capacity;
    base_house **data;
};

dynamic_array *new__dynamic_array(size_t default_size);


#endif //DYNAMIC_ARRAY_H
