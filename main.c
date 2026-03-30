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
#include "bridge/concrete_abstraction.h"
#include "bridge/macos_abstraction_impl.h"
#include "bridge/windows_abstraction_impl.h"
#include "decorator/apartment_repository.h"
#include "decorator/apartment_repository_logger_decorator.h"
#include "facade/house_operations_facade.h"
#include "facade/i_house_operations_facade.h"
#include "models/apartment_building.h"
#include "models/block_of_apartment_buildings.h"
#include "proxy/i_proxy_example.h"
#include "proxy/proxy_base_class.h"
#include "proxy/real_proxy.h"
#include "strategy/concrete_strategy_1.h"
#include "strategy/concrete_strategy_2.h"
#include "strategy/strategy_context.h"

void abstract_factory();

void factory_method();

void builder_pattern(int created_houses_count);

void prototype();

void adapter();

void composite();

void facade();

void decorator();

void proxy();

void bridge();

void strategy();


int main() {
    strategy();
    // bridge();
    // proxy();
    // adapter();
    // prototype();
    // composite();
    // decorator();

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
        cloned_houses[i] = (base_house *) call(&template_houses[i]->i_prototype__iface, clone);
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
        &a1->base_house__base.i_as_json__iface,
        &a2->base_house__base.i_as_json__iface,
        &gh1->base_house__base.i_as_json__iface,
        &gh2->base_house__base.i_as_json__iface,
        &adapter->i_as_json__iface
    };

    // client code
    for (int i = 0; i < 5; ++i) {
        printf("json: %s\n", call(json_data[i], to_json));
    }
}

void composite() {
    ground_house *gh = new(ground_house, 10, FALSE);

    int rooms_count = call(&gh->base_house__base.i_house_component__iface, get_rooms_count);
    double total_area = call(&gh->base_house__base.i_house_component__iface, get_area);

    printf("1 ground house:: -> %d rooms \t||\t %f m2.\n", rooms_count, total_area);

    apartment_building *ab = new(apartment_building);
    call(ab, add_child, &new(apartment, 10, 13)->base_house__base.i_house_component__iface);
    call(ab, add_child, &new(apartment, 11, 13)->base_house__base.i_house_component__iface);
    call(ab, add_child, &new(apartment, 12, 13)->base_house__base.i_house_component__iface);

    apartment_building *ab2 = new(apartment_building);
    call(ab2, add_child, &new(apartment, 4, 13)->base_house__base.i_house_component__iface);
    call(ab2, add_child, &new(apartment, 3, 12)->base_house__base.i_house_component__iface);
    call(ab2, add_child, &ab->i_house_component__iface);


    apartment_building *ab3 = new(apartment_building);
    call(ab3, add_child, &new(apartment, 2, 13)->base_house__base.i_house_component__iface);
    call(ab3, add_child, &new(apartment, 1, 12)->base_house__base.i_house_component__iface);
    call(ab3, add_child, &ab2->i_house_component__iface);

    block_of_apartment_buildings *block = new(block_of_apartment_buildings);
    call(block, add_child, &new(apartment, 1, 12)->base_house__base.i_house_component__iface);
    call(block, add_child, &new(ground_house, 7, TRUE)->base_house__base.i_house_component__iface);
    call(block, add_child, &ab3->i_house_component__iface);


    rooms_count = call(&ab3->i_house_component__iface, get_rooms_count);
    total_area = call(&ab3->i_house_component__iface, get_area);
    printf("1 block with apartments buildings:: -> %d rooms \t||\t %f m2.\n", rooms_count, total_area);

    rooms_count = call(&block->i_house_component__iface, get_rooms_count);
    total_area = call(&block->i_house_component__iface, get_area);
    printf("1 block with apartments buildings:: -> %d rooms \t||\t %f m2.\n", rooms_count, total_area);
}

void facade() {
    // client code simulate that user want to buy a apartment
    i_house_operations_facade *facade = &new(house_operations_facade)->i_house_operations_facade__iface;
    call(facade, buy_apartment, 1, 12);
}

void decorator() {
    apartment *a1 = new(apartment, 1, 12);
    apartment *a2 = new(apartment, 2, 12);

    apartment_repository *ar = new(apartment_repository, new(app_db_context));

    call(&ar->i_apartment_repository__iface, add_apartment, a1);
    dynamic_array *result = call(&ar->i_apartment_repository__iface, get_apartments);
    printf("Number of apartments: %lu\n", result->size);

    apartment_repository_logger_decorator *ar_decorator = new(apartment_repository_logger_decorator,
                                                              &ar->i_apartment_repository__iface);
    result = call(&ar_decorator->i_apartment_repository__iface, get_apartments);

    printf("Number of apartments: %lu\n", result->size);


    // apartment_repository_logger_decorator *logger = new(apartment_repository_logger_decorator, ar);
}

void proxy() {
    proxy_base_class *base = new(proxy_base_class);

    call(&base->i_proxy_example__iface, print_something);
    printf("\n\n");

    real_proxy *proxy = new(real_proxy, base);

    call(&proxy->i_proxy_example__iface, print_something);
}

void bridge() {
    macos_abstraction_impl *macos_impl = new(macos_abstraction_impl);
    windows_abstraction_impl *windows_impl = new(windows_abstraction_impl);

    printf("Bridge pattern:\n\n");
    printf("MacOS implementation:\n");
    concrete_abstraction *ca = new(concrete_abstraction, &macos_impl->i_abstraction_impl__iface);
    call(&ca->abstraction__base, call_print_something_from_impl);

    printf("\nWindows implementation:\n");
    ca = new(concrete_abstraction, &windows_impl->i_abstraction_impl__iface);
    call(&ca->abstraction__base, call_print_something_from_impl);
}

void strategy() {
    concrete_strategy_1 *cs1 = new(concrete_strategy_1);
    concrete_strategy_2 *cs2 = new(concrete_strategy_2);

    strategy_context *sc = new(strategy_context, &cs1->i_strategy__iface);
    call(sc, execute_strategy, 1, 2);
    printf("\n\n");
    sc = new(strategy_context, &cs2->i_strategy__iface);
    call(sc, execute_strategy, 1, 2);
}
