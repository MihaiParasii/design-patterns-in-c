#include "apartment_collection_iterator.h"
#include <stdlib.h>

static int has_next(void *_self) {
    SELF_OF(apartment_collection_iterator, i_apartment_iterator__iface);
    
    return self->__index < self->__collection->__size;
}

static apartment *next(void *_self) {
    SELF_OF(apartment_collection_iterator, i_apartment_iterator__iface);
    
    return self->__collection->__items[self->__index++];
}

static i_apartment_iterator__vtable vtable = {
    .has_next = has_next,
    .next = next,
};

constructor(apartment_collection_iterator, apartment_collection *collection) {
    apartment_collection_iterator *it = malloc(sizeof(apartment_collection_iterator));
    it->i_apartment_iterator__iface.vtable = &vtable;
    it->__collection = collection;
    it->__index = 0;
    return it;
}
