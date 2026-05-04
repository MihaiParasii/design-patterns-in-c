#include "listing_memento.h"
#include <stdlib.h>

constructor(listing_memento, int price, char *description) {
    listing_memento *m = malloc(sizeof(listing_memento));
    m->__price       = price;
    m->__description = description;
    return m;
}
