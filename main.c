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
#include "adapter/external_flat_provider.h"
#include "adapter/external_flat_json_adapter.h"
#include "models/apartment_building.h"
#include "models/block_of_apartment_buildings.h"
#include "models/statistics.h"

void abstract_factory();

void factory_method();

void builder_pattern(int created_houses_count);

void prototype();

void adapter();

void composite();


int main() {
    // adapter();
    // prototype();
    composite();

    // abstract_factory();

    // statistics *statistics = Statistics.s_vtable->get_instance();

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

    base_house *template_houses[6] = {
        &a1->base_house__base, &a2->base_house__base, &a3->base_house__base, &gh1->base_house__base,
        &gh2->base_house__base, &gh3->base_house__base
    };
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

void adapter() {
    apartment *a1 = new(apartment, 4);
    apartment *a2 = new(apartment, 4, 7);
    ground_house *gh1 = new(ground_house);
    ground_house *gh2 = new(ground_house, TRUE);

    external_flat **flats = s_call(ExternalFlatProvider, get_external_flats);
    external_flat_json_adapter *adapter = new(external_flat_json_adapter, flats[0]);


    i_as_json *json_data[5] = {
        &a1->base_house__base.i_as_json,
        &a2->base_house__base.i_as_json,
        &gh1->base_house__base.i_as_json,
        &gh2->base_house__base.i_as_json,
        &adapter->i_as_json
    };

    // client code
    for (int i = 0; i < 5; ++i) {
        printf("json: %s\n", call(json_data[i], to_json));
    }
}


void composite() {
    ground_house *gh = new(ground_house, 10, FALSE);

    int rooms_count = call(&gh->base_house__base.i_house_component, get_rooms_count);
    double total_area = call(&gh->base_house__base.i_house_component, get_area);

    printf("1 ground house:: -> %d rooms \t||\t %f m2.\n", rooms_count, total_area);

    apartment_building *ab = new(apartment_building);
    call(ab, add_child, &new(apartment, 10, 13)->base_house__base.i_house_component);
    call(ab, add_child, &new(apartment, 11, 13)->base_house__base.i_house_component);
    call(ab, add_child, &new(apartment, 12, 13)->base_house__base.i_house_component);

    apartment_building *ab2 = new(apartment_building);
    call(ab2, add_child, &new(apartment, 4, 13)->base_house__base.i_house_component);
    call(ab2, add_child, &new(apartment, 3, 12)->base_house__base.i_house_component);
    call(ab2, add_child, &ab->i_house_component);


    apartment_building *ab3 = new(apartment_building);
    call(ab3, add_child, &new(apartment, 2, 13)->base_house__base.i_house_component);
    call(ab3, add_child, &new(apartment, 1, 12)->base_house__base.i_house_component);
    call(ab3, add_child, &ab2->i_house_component);

    block_of_apartment_buildings *block = new(block_of_apartment_buildings);
    call(block, add_child, &new(apartment, 1, 12)->base_house__base.i_house_component);
    call(block, add_child, &new(ground_house, 7, TRUE)->base_house__base.i_house_component);
    call(block, add_child, &ab3->i_house_component);


    rooms_count = call(&ab3->i_house_component, get_rooms_count);
    total_area = call(&ab3->i_house_component, get_area);
    printf("1 block with apartments buildings:: -> %d rooms \t||\t %f m2.\n", rooms_count, total_area);

    rooms_count = call(&block->i_house_component, get_rooms_count);
    total_area = call(&block->i_house_component, get_area);
    printf("1 block with apartments buildings:: -> %d rooms \t||\t %f m2.\n", rooms_count, total_area);
}
