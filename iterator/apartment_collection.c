#include "apartment_collection.h"
#include "apartment_collection_iterator.h"
#include <stdlib.h>

static void add(void *self, apartment *apt) {
    apartment_collection *c = self;
    if (c->__size == c->__capacity) {
        c->__capacity *= 2;
        c->__items = realloc(c->__items, c->__capacity * sizeof(apartment *));
    }
    c->__items[c->__size++] = apt;
}

static i_apartment_iterator *create_iterator(void *_self) {
    SELF(apartment_collection);
    apartment_collection_iterator *it = new(apartment_collection_iterator, self);
    return &it->i_apartment_iterator__iface;
}

static apartment_collection__vtable vtable = {
    .add = add,
    .create_iterator = create_iterator,
};

constructor(apartment_collection) {
    apartment_collection *c = malloc(sizeof(apartment_collection));
    c->vtable = &vtable;
    c->__capacity = 4;
    c->__size = 0;
    c->__items = malloc(c->__capacity * sizeof(apartment *));

    return c;
}
