#include "apartment_collection_iterator.h"
#include <stdlib.h>

static int has_next__apartment_collection_iterator(void *self) {
    apartment_collection_iterator *it =
        container_of(self, apartment_collection_iterator, i_apartment_iterator__iface);
    return it->__index < it->__collection->__size;
}

static apartment *next__apartment_collection_iterator(void *self) {
    apartment_collection_iterator *it =
        container_of(self, apartment_collection_iterator, i_apartment_iterator__iface);
    return it->__collection->__items[it->__index++];
}

static i_apartment_iterator__vtable apartment_collection_iterator_vtable = {
    .has_next = has_next__apartment_collection_iterator,
    .next     = next__apartment_collection_iterator,
};

constructor(apartment_collection_iterator, apartment_collection *collection) {
    apartment_collection_iterator *it = malloc(sizeof(apartment_collection_iterator));
    it->i_apartment_iterator__iface.vtable = &apartment_collection_iterator_vtable;
    it->__collection = collection;
    it->__index      = 0;
    return it;
}
