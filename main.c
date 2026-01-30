#include <stdlib.h>

#include "apartment_constructor.h"
#include "ground_house_constructor.h"
#include "base_house.h"
#include "dynamic_array.h"
#include "house_constructor.h"


typedef struct Site_999_VTable {
    void (*print_houses)(void *self);

    void (*add_house)(void *self, const house_constructor* constructor);
} site_999_v_table;


typedef struct Site_999 {
    const site_999_v_table *vtable;
    dynamic_array *_houses;
} site_999;

void add_house_site_999(void *self, const house_constructor* constructor) {
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


int main() {
    site_999 *site_999 = new_site_999();

    const house_constructor *apartment_constructor = (house_constructor *) new_apartment_constructor();
    const house_constructor *ground_house_constructor = (house_constructor *) new_ground_house_constructor();

    site_999->vtable->add_house(site_999, apartment_constructor);
    site_999->vtable->add_house(site_999, apartment_constructor);
    site_999->vtable->add_house(site_999, apartment_constructor);
    site_999->vtable->add_house(site_999, ground_house_constructor);
    site_999->vtable->add_house(site_999, apartment_constructor);
    site_999->vtable->add_house(site_999, apartment_constructor);
    site_999->vtable->add_house(site_999, apartment_constructor);
    site_999->vtable->add_house(site_999, ground_house_constructor);
    site_999->vtable->add_house(site_999, apartment_constructor);
    site_999->vtable->print_houses(site_999);

    site_999->vtable->add_house(site_999, ground_house_constructor);
    site_999->vtable->add_house(site_999, ground_house_constructor);
    site_999->vtable->add_house(site_999, ground_house_constructor);
    site_999->vtable->add_house(site_999, ground_house_constructor);
    site_999->vtable->add_house(site_999, apartment_constructor);
    site_999->vtable->add_house(site_999, apartment_constructor);
    site_999->vtable->print_houses(site_999);
    
    // site_999->vtable->add_house(site_999, apartment_constructor);

    free(site_999);
}
