#ifndef APARTMENT_COLLECTION_H
#define APARTMENT_COLLECTION_H
#include "../defines.h"
#include "i_apartment_iterator.h"

vtable_for(apartment_collection) {
    method_(void,                 add,             apartment *apt);
    method_(i_apartment_iterator*, create_iterator);
};

class_(apartment_collection) {
    apartment_collection__vtable *vtable;
    apartment **__items;
    size_t      __size;
    size_t      __capacity;
};

constructor(apartment_collection);

#endif //APARTMENT_COLLECTION_H
