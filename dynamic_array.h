#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdio.h>

#include "base_house.h"

typedef struct dynamic_array_vtable {
    void (*add_back)(void *self, base_house *base_house);

    void (*remove_back)(void *self);

    void (*print)(void *self);
} dynamic_array_vtable;

typedef struct dynamic_array {
    dynamic_array_vtable *vtable;
    size_t size;
    size_t capacity;
    base_house **data;
} dynamic_array;

dynamic_array *new_dynamic_array(size_t default_size);


#endif //DYNAMIC_ARRAY_H
