#include <stdlib.h>

#include "apartment_constructor.h"
#include "ground_house_constructor.h"
#include "dynamic_array.h"
#include "house_constructor.h"
#include "site_999.h"
#include "statistics.h"

void abstract_factory();

void factory_method();


int main() {
    abstract_factory();

    statistics* statistics = get_static_statistics();
    statistics = statistics->static_vtable->get_instance(statistics);

    statistics->vtable->print_created_houses_count(statistics);
}


void abstract_factory() {
    printf("Abstract factory pattern:\n");
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

    site_999->vtable->add_house(site_999, apartment_constructor);

    free(site_999);
}

void factory_method() {
    printf("Factory method pattern:\n");
    house_constructor *apartment_constructor = (house_constructor *) new_apartment_constructor();
    house_constructor *ground_house_constructor = (house_constructor *) new_ground_house_constructor();

    apartment_constructor->vtable->print_a_new_house(apartment_constructor);
    ground_house_constructor->vtable->print_a_new_house(ground_house_constructor);
}
