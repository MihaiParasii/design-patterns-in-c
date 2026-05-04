#include "apartment_collection.h"
#include "apartment_collection_iterator.h"
#include <stdlib.h>

static void add__apartment_collection(void *self, apartment *apt) {
    apartment_collection *c = self;
    if (c->__size == c->__capacity) {
        c->__capacity *= 2;
        c->__items = realloc(c->__items, c->__capacity * sizeof(apartment *));
    }
    c->__items[c->__size++] = apt;
}

static i_apartment_iterator *create_iterator__apartment_collection(void *self) {
    apartment_collection *c = self;
    apartment_collection_iterator *it = new__apartment_collection_iterator(c);
    return &it->i_apartment_iterator__iface;
}

static apartment_collection__vtable apartment_collection_vtable = {
    .add             = add__apartment_collection,
    .create_iterator = create_iterator__apartment_collection,
};

constructor(apartment_collection) {
    apartment_collection *c = malloc(sizeof(apartment_collection));
    c->vtable     = &apartment_collection_vtable;
    c->__capacity = 4;
    c->__size     = 0;
    c->__items    = malloc(c->__capacity * sizeof(apartment *));
    return c;
}
