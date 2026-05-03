#include "dynamic_array.h"

#include <stdlib.h>

static void add_back(void *self, base_house *object) {
    dynamic_array *array = self;
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity * sizeof(base_house *));
    }

    array->data[array->size++] = object;
}

static void remove_back(void *self) {
    dynamic_array *array = self;
    if (array->size > 0) {
        free(array->data[array->size - 1]);
        array->data[array->size - 1] = NULL;
        array->size--;
    }
}

static void print(void *self) {
    dynamic_array *array = self;
    for (int i = 0; i < array->size; ++i) {
        call(array->data[i], print_myself);
    }
}

static dynamic_array__vtable dynamic_array__v_table = {
    .add_back = add_back,
    .remove_back = remove_back,
    .print = print
};

constructor(dynamic_array, const size_t default_size) {
    dynamic_array *array = calloc(1, sizeof(dynamic_array));

    array->vtable = &dynamic_array__v_table;
    array->size = 0;
    array->capacity = default_size;
    array->data = calloc(default_size, sizeof(base_house *) * default_size);

    return array;
}
