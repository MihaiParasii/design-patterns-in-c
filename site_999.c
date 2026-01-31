//
// Created by Mihai Parasii on 31.01.2026.
//

#include "site_999.h"
#include <stdlib.h>


void add_house_site_999(void *self, const house_constructor *constructor) {
    base_house *house = constructor->vtable->construct_house();
    ((site_999 *) self)->_houses->vtable->add_back(((site_999 *) self)->_houses, house);
}

void print_houses_site_999(void *self) {
    ((site_999 *) self)->_houses->vtable->print(((site_999 *) self)->_houses);
    printf("\n");
}

site_999_v_table site_999_vtable = {
    .add_house = add_house_site_999,
    .print_houses = print_houses_site_999
};

site_999 *new_site_999() {
    site_999 *site_999 = malloc(sizeof(site_999));
    site_999->vtable = &site_999_vtable;
    site_999->_houses = new_dynamic_array(10);

    return site_999;
}
