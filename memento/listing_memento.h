#ifndef LISTING_MEMENTO_H
#define LISTING_MEMENTO_H
#include "../defines.h"

class_(listing_memento) {
    int   __price;
    char *__description;
};

constructor(listing_memento, int price, char *description);

#endif //LISTING_MEMENTO_H
