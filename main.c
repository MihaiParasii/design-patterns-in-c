#include <stdlib.h>

#include "apartment_constructor.h"
#include "ground_house_constructor.h"
#include "dynamic_array.h"
#include "en_statistics_saver_builder.h"
#include "house_constructor.h"
#include "i_statistics_saver_builder.h"
#include "ro_statistics_saver_builder.h"
#include "ru_statistics_saver_builder.h"
#include "site_999.h"
#include "statistics.h"
#include "statistics_saver_director.h"

void abstract_factory();

void factory_method();

void builder_pattern(int created_houses_count);

int main() {
    abstract_factory();

    statistics *statistics = get_static_statistics();
    statistics = statistics->static_vtable->get_instance(statistics);

    const int created_houses_count = statistics->vtable->get_created_houses_count(statistics);
    builder_pattern(created_houses_count);
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

void builder_pattern(const int created_houses_count) {
    i_statistics_saver_builder *builder;
    statistics_saver_director *director;
    char *result;

    printf("--->>> Short versions <<<---\n");
    builder = (i_statistics_saver_builder *) new__en_full_statistics_builder();
    director = new__statistics_saver_director(builder);

    director->vtable->construct_short(director, created_houses_count);
    result = builder->vtable->get(builder);
    printf("%s\n\n", result);

    builder = (i_statistics_saver_builder *) new__ro_full_statistics_builder();
    director = new__statistics_saver_director(builder);

    director->vtable->construct_short(director, created_houses_count);
    result = builder->vtable->get(builder);
    printf("%s\n\n", result);
    
    builder = (i_statistics_saver_builder *) new__ru_full_statistics_builder();
    director = new__statistics_saver_director(builder);

    director->vtable->construct_short(director, created_houses_count);
    result = builder->vtable->get(builder);
    printf("%s\n\n", result);

    
    printf("--->>> Long versions <<<---\n");
    builder = (i_statistics_saver_builder *) new__en_full_statistics_builder();
    director = new__statistics_saver_director(builder);

    director->vtable->construct_long(director, created_houses_count);
    result = builder->vtable->get(builder);
    printf("%s\n\n", result);

    builder = (i_statistics_saver_builder *) new__ro_full_statistics_builder();
    director = new__statistics_saver_director(builder);

    director->vtable->construct_long(director, created_houses_count);
    result = builder->vtable->get(builder);
    printf("%s\n\n", result);
    
    builder = (i_statistics_saver_builder *) new__ru_full_statistics_builder();
    director = new__statistics_saver_director(builder);

    director->vtable->construct_long(director, created_houses_count);
    result = builder->vtable->get(builder);
    printf("%s\n\n", result);
}
