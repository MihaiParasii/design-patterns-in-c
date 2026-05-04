#ifndef LISTING_HISTORY_H
#define LISTING_HISTORY_H
#include "../defines.h"
#include "listing_memento.h"

#define LISTING_HISTORY_MAX 16

vtable_for(listing_history) {
    method_(void,             push, listing_memento *m);
    method_(listing_memento*, pop);
};

class_(listing_history) {
    listing_history__vtable *vtable;
    listing_memento *__stack[LISTING_HISTORY_MAX];
    int              __top;
};

constructor(listing_history);

#endif //LISTING_HISTORY_H
