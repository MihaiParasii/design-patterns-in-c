#include <stdlib.h>

#include "abstract_factory_method/apartment_creator.h"
#include "abstract_factory_method/ground_house_creator.h"
#include "common/dynamic_array.h"
#include "builder/en_statistics_saver_builder.h"
#include "abstract_factory_method/house_creator.h"
#include "builder/ro_statistics_saver_builder.h"
#include "builder/ru_statistics_saver_builder.h"
#include "models/site_999.h"
#include "builder/statistics_saver_director.h"
#include "defines.h"
#include "models/apartment.h"
#include "models/ground_house.h"

void abstract_factory();

void factory_method();

void builder_pattern(int created_houses_count);

void prototype();


int main() {
    prototype();

    // abstract_factory();

    // statistics *statistics = s_new__statistics();
    // statistics = s_call(statistics, get_instance);

    // const int created_houses_count = call(statistics, get_created_houses_count);
    // builder_pattern(created_houses_count);
}


void abstract_factory() {
    printf("Abstract factory pattern:\n");
    site_999 *site_999 = new(site_999);

    const house_creator *apartment_creator = (house_creator *) new(apartment_creator);
    const house_creator *ground_house_creator = (house_creator *) new(ground_house_creator);


    call(site_999, add_house, apartment_creator);
    call(site_999, add_house, apartment_creator);
    call(site_999, add_house, apartment_creator);
    call(site_999, add_house, ground_house_creator);
    call(site_999, add_house, apartment_creator);
    call(site_999, add_house, apartment_creator);
    call(site_999, add_house, apartment_creator);
    call(site_999, add_house, ground_house_creator);
    call(site_999, add_house, apartment_creator);
    call(site_999, print_houses);

    call(site_999, add_house, ground_house_creator);
    call(site_999, add_house, ground_house_creator);
    call(site_999, add_house, ground_house_creator);
    call(site_999, add_house, ground_house_creator);
    call(site_999, add_house, apartment_creator);
    call(site_999, add_house, apartment_creator);
    call(site_999, print_houses);

    call(site_999, add_house, apartment_creator);

    free(site_999);
}

void factory_method() {
    printf("Factory method pattern:\n");
    house_creator *apartment_creator = (house_creator *) new(apartment_creator);
    house_creator *ground_house_creator = (house_creator *) new(ground_house_creator);

    call(apartment_creator, print_a_new_house);
    call(ground_house_creator, print_a_new_house);
}

void builder_pattern(const int created_houses_count) {
    i_statistics_saver_builder *builder;
    statistics_saver_director *director;
    char *result;

    printf("--->>> Short versions <<<---\n");
    builder = (i_statistics_saver_builder *) new(en_full_statistics_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_short, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);

    builder = (i_statistics_saver_builder *) new(ro_full_statistics_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_short, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);

    builder = (i_statistics_saver_builder *) new(ru_full_statistics_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_short, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);


    printf("--->>> Long versions <<<---\n");
    builder = (i_statistics_saver_builder *) new(en_full_statistics_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_long, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);

    builder = (i_statistics_saver_builder *) new(ro_full_statistics_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_long, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);

    builder = (i_statistics_saver_builder *) new(ru_full_statistics_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_long, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);
}

void prototype() {
    apartment *a1 = new(apartment);
    apartment *a2 = new(apartment, 1);
    apartment *a3 = new(apartment, 12, 6);

    ground_house *gh1 = new(ground_house);
    ground_house *gh2 = new(ground_house, FALSE);
    ground_house *gh3 = new(ground_house, 3, TRUE);

    base_house *template_houses[6] = {a1, a2, a3, gh1, gh2, gh3};
    base_house *cloned_houses[6];

    for (int i = 0; i < 6; ++i) {
        cloned_houses[i] = (base_house *) call(&template_houses[i]->i_prototype, clone);
    }

    for (int i = 0; i < 6; ++i) {
        call(template_houses[i], print_myself);
        printf("NEW: ->>|");
        call(cloned_houses[i], print_myself);
        printf("\n");
    }
}
