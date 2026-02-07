#include "base_house.h"

#include <stdlib.h>

base_house *_new__base_house0(void) {
    base_house *bh = malloc(sizeof(base_house));

    bh->number_of_rooms = 0;

    return bh;
}

base_house *_new__base_house1_int(const int number_of_rooms) {
    base_house *bh = _new(base_house);

    bh->number_of_rooms = number_of_rooms;

    return bh;
}

base_house *_new__base_house1_base_house(base_house *bh) {
    base_house *new_bh = _new(base_house);

    new_bh->number_of_rooms = bh->number_of_rooms;

    return new_bh;
}
