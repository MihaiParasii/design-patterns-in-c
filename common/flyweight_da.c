#include "flyweight_da.h"

#include <stdlib.h>


static void add_back__flyweight_da(void *self, flyweight *object) {
    flyweight_da *array = self;
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity * sizeof(flyweight *));
    }

    array->data[array->size++] = object;
}

static void remove_back__flyweight_da(void *self) {
    flyweight_da *array = self;
    if (array->size > 0) {
        free(array->data[array->size - 1]);
        array->data[array->size - 1] = NULL;
        array->size--;
    }
}

static flyweight_da__vtable flyweight_da__v_table = {
    .add_back = add_back__flyweight_da,
    .remove_back = remove_back__flyweight_da,
};

constructor(flyweight_da, const size_t default_size) {
    flyweight_da *array = calloc(1, sizeof(flyweight_da));

    array->vtable = &flyweight_da__v_table;
    array->size = 0;
    array->capacity = default_size;
    array->data = calloc(default_size, sizeof(flyweight *) * default_size);

    return array;
}
