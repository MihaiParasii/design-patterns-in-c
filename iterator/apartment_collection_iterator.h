#ifndef APARTMENT_COLLECTION_ITERATOR_H
#define APARTMENT_COLLECTION_ITERATOR_H
#include "../defines.h"
#include "i_apartment_iterator.h"
#include "apartment_collection.h"

class_(apartment_collection_iterator) {
    implements_(i_apartment_iterator);
    apartment_collection *__collection;
    size_t                __index;
};

constructor(apartment_collection_iterator, apartment_collection *collection);

#endif //APARTMENT_COLLECTION_ITERATOR_H
