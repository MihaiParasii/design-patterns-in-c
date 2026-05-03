#include "dynamic_array_house_component.h"

#include <stdlib.h>

static void add_back__dynamic_array_house_component(void *self, i_house_component *object) {
    dynamic_array_house_component *array = self;
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity * sizeof(i_house_component *));
    }

    array->data[array->size++] = object;
}

static void remove_back__dynamic_array_house_component(void *self) {
    dynamic_array_house_component *array = self;
    if (array->size > 0) {
        free(array->data[array->size - 1]);
        array->data[array->size - 1] = NULL;
        array->size--;
    }
}

static dynamic_array_house_component__vtable dynamic_array_house_component__v_table = {
    .add_back = add_back__dynamic_array_house_component,
    .remove_back = remove_back__dynamic_array_house_component,
};

constructor(dynamic_array_house_component, const size_t default_size) {
    dynamic_array_house_component *array = calloc(1, sizeof(dynamic_array_house_component));

    array->vtable = &dynamic_array_house_component__v_table;
    array->size = 0;
    array->capacity = default_size;
    array->data = calloc(default_size, sizeof(i_house_component *) * default_size);

    return array;
}
