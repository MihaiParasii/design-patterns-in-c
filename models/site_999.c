#include <stdlib.h>
#include "site_999.h"
#include "base_house.h"
#include "../defines.h"


void add_house_site_999(void *self, const house_creator *creator) {
    base_house *house = call(creator, construct_house);
    call(((site_999 *) self)->_houses, add_back, house);
}

void print_houses_site_999(void *self) {
    call(((site_999 *) self)->_houses, print);
    printf("\n");
}

site_999__vtable site_999_vtable = {
    .add_house = add_house_site_999,
    .print_houses = print_houses_site_999
};

site_999 *new__site_999() {
    site_999 *site_999 = malloc(sizeof(site_999));
    site_999->vtable = &site_999_vtable;
    site_999->_houses = new(dynamic_array, 10);

    return site_999;
}
