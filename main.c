#include <stdlib.h>

#include "observer/apartment_listing_subject.h"
#include "observer/tenant_observer.h"
#include "observer/real_estate_agent_observer.h"
#include "command/apartment_booking_receiver.h"
#include "command/apartment_command_invoker.h"
#include "command/reserve_apartment_command.h"
#include "command/cancel_reservation_command.h"
#include "state/apartment_rental_context.h"
#include "chain/repair_handler.h"
#include "iterator/apartment_collection.h"
#include "iterator/apartment_collection_iterator.h"
#include "template_method/apartment_inspection.h"
#include "template_method/ground_house_inspection.h"
#include "visitor/visitable_apartment.h"
#include "visitor/visitable_ground_house.h"
#include "visitor/tax_calculator_visitor.h"
#include "visitor/area_report_visitor.h"
#include "memento/apartment_listing.h"
#include "memento/listing_history.h"
#include "mediator/apartment_deal_mediator.h"
#include "mediator/buyer.h"
#include "mediator/seller.h"
#include "interpreter/and_expression.h"
#include "interpreter/or_expression.h"
#include "interpreter/floor_gt_expression.h"
#include "interpreter/rooms_gte_expression.h"
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
#include "flyweight/flyweight_context.h"
#include "flyweight/flyweight_extrinsic.h"
#include "flyweight/flyweight_factory.h"
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

void flyweight_show();

void strategy();

void observer();

void command();

void state();

void chain();

void iterator();

void template_method();

void visitor();

void memento();

void mediator();

void interpreter();


int main() {
    chain();
    // iterator();
    // template_method();
    // visitor();
    // memento();
    // mediator();
    // interpreter();
    // observer();
    // command();
    // state();
    // strategy();
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
    builder = (i_statistics_saver_builder *) new(en_statistics_saver_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_short, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);

    builder = (i_statistics_saver_builder *) new(ro_statistics_saver_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_short, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);

    builder = (i_statistics_saver_builder *) new(ru_statistics_saver_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_short, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);


    printf("--->>> Long versions <<<---\n");
    builder = (i_statistics_saver_builder *) new(en_statistics_saver_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_long, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);

    builder = (i_statistics_saver_builder *) new(ro_statistics_saver_builder);
    director = new(statistics_saver_director, builder);

    call(director, construct_long, created_houses_count);
    result = call(builder, get);
    printf("%s\n\n", result);

    builder = (i_statistics_saver_builder *) new(ru_statistics_saver_builder);
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
    printf("Bridge pattern:\n\n");
    macos_abstraction_impl *macos_impl = new(macos_abstraction_impl);
    windows_abstraction_impl *windows_impl = new(windows_abstraction_impl);

    printf("MacOS implementation:\n");
    concrete_abstraction *ca = new(concrete_abstraction, &macos_impl->i_abstraction_impl__iface);
    call(&ca->abstraction__base, call_print_something_from_impl);

    printf("\nWindows implementation:\n");
    ca = new(concrete_abstraction, &windows_impl->i_abstraction_impl__iface);
    call(&ca->abstraction__base, call_print_something_from_impl);
}

void flyweight_show() {
    printf("Flyweight pattern:\n\n");

    flyweight_factory *fc = new(flyweight_factory);
    flyweight *hex_flyweight1 = call(fc, get_flyweight, 111111);
    flyweight *hex_flyweight2 = call(fc, get_flyweight, 222222);
    flyweight *hex_flyweight3 = call(fc, get_flyweight, 111111);

    flyweight_extrinsic *fe1 = new(flyweight_extrinsic, 12, hex_flyweight1);
    flyweight_extrinsic *fe2 = new(flyweight_extrinsic, 13, hex_flyweight2);
    flyweight_extrinsic *fe3 = new(flyweight_extrinsic, 14, hex_flyweight3);

    call(fe1, print_info);
    call(fe2, print_info);
    call(fe3, print_info);


    call(hex_flyweight1, print_color);
    call(hex_flyweight2, print_color);
    call(hex_flyweight3, print_color);
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

void observer() {
    printf("Observer pattern:\n\n");

    apartment_listing_subject *subject = new(apartment_listing_subject);

    tenant_observer *alice = new(tenant_observer, "Alice", 5);
    tenant_observer *bob = new(tenant_observer, "Bob", 10);
    real_estate_agent_observer *agency = new(real_estate_agent_observer, "ImmoPlus");

    call(subject, subscribe, &alice->i_apartment_observer__iface);
    call(subject, subscribe, &bob->i_apartment_observer__iface);
    call(subject, subscribe, &agency->i_apartment_observer__iface);

    call(subject, publish_new_listing, new(apartment, 3, 4));
    printf("\n");
    call(subject, publish_new_listing, new(apartment, 2, 8));
    printf("\n");

    call(subject, unsubscribe, &alice->i_apartment_observer__iface);
    printf("(Alice unsubscribed)\n\n");
    call(subject, publish_new_listing, new(apartment, 1, 2));
}

void command() {
    printf("Command pattern:\n\n");

    apartment *apt = new(apartment, 3, 7);
    apartment_booking_receiver *receiver = new(apartment_booking_receiver, apt);
    apartment_command_invoker *invoker = new(apartment_command_invoker);

    call(receiver, print_status);

    reserve_apartment_command *reserve_cmd = new(reserve_apartment_command, receiver, "Maria");
    call(invoker, execute_command, &reserve_cmd->i_apartment_command__iface);
    call(receiver, print_status);

    cancel_reservation_command *cancel_cmd =new(cancel_reservation_command, receiver);
    call(invoker, execute_command, &cancel_cmd->i_apartment_command__iface);
    call(receiver, print_status);

    printf("\n--- Undo cancel ---\n");
    call(invoker, undo_last);
    call(receiver, print_status);

    printf("\n--- Undo reserve ---\n");
    call(invoker, undo_last);
    call(receiver, print_status);
}

void state() {
    printf("State pattern:\n\n");

    apartment_rental_context *ctx = new__apartment_rental_context(101);
    call(ctx, print_state);

    printf("\n-- Try to move in without reserving --\n");
    call(ctx, move_in);

    printf("\n-- Reserve --\n");
    call(ctx, reserve);
    call(ctx, print_state);

    printf("\n-- Move in --\n");
    call(ctx, move_in);
    call(ctx, print_state);

    printf("\n-- Request maintenance --\n");
    call(ctx, request_maintenance);
    call(ctx, print_state);

    printf("\n-- Complete maintenance --\n");
    call(ctx, complete_maintenance);
    call(ctx, print_state);

    printf("\n-- Try to complete maintenance again (invalid) --\n");
    call(ctx, complete_maintenance);
}

void chain() {
    printf("Chain of Responsibility pattern:\n\n");

    repair_handler *tenant = new__repair_handler("Tenant", 50);
    repair_handler *floor_m = new__repair_handler("Floor Manager", 200);
    repair_handler *build_m = new__repair_handler("Building Manager", 1000);
    repair_handler *owner = new__repair_handler("Owner", 9999);

    call(&tenant->i_repair_handler__iface, set_next, &floor_m->i_repair_handler__iface);
    call(&floor_m->i_repair_handler__iface, set_next, &build_m->i_repair_handler__iface);
    call(&build_m->i_repair_handler__iface, set_next, &owner->i_repair_handler__iface);

    i_repair_handler *chain = &tenant->i_repair_handler__iface;
    call(chain, handle, 30, "Replace light bulb");
    call(chain, handle, 150, "Fix leaking pipe");
    call(chain, handle, 700, "Replace broken window");
    call(chain, handle, 5000, "Roof structural repair");
}

void iterator() {
    printf("Iterator pattern:\n\n");

    apartment_collection *col = new__apartment_collection();
    call(col, add, new(apartment, 3, 2));
    call(col, add, new(apartment, 1, 5));
    call(col, add, new(apartment, 4, 9));
    call(col, add, new(apartment, 2, 12));

    i_apartment_iterator *it = call(col, create_iterator);
    printf("Iterating over %lu apartments:\n", col->__size);
    while (call(it, has_next)) {
        apartment *apt = call(it, next);
        printf("  -> floor %d, %d rooms\n", apt->floor, apt->base_house__base.number_of_rooms);
    }
}

void template_method() {
    printf("Template Method pattern:\n\n");

    apartment_inspection *ai = new__apartment_inspection(new(apartment, 3, 12));
    run_inspection(&ai->house_inspection__base);

    printf("\n");

    ground_house_inspection *gi = new__ground_house_inspection(new(ground_house, 5, TRUE));
    run_inspection(&gi->house_inspection__base);
}

void visitor() {
    printf("Visitor pattern:\n\n");

    i_visitable_property *properties[4] = {
        &new__visitable_apartment(new(apartment, 3, 5))->i_visitable_property__iface,
        &new__visitable_apartment(new(apartment, 2, 11))->i_visitable_property__iface,
        &new__visitable_ground_house(new(ground_house, 4, TRUE))->i_visitable_property__iface,
        &new__visitable_ground_house(new(ground_house, 6, FALSE))->i_visitable_property__iface,
    };

    tax_calculator_visitor *tax = new__tax_calculator_visitor();
    area_report_visitor *area = new__area_report_visitor();

    printf("-- Tax calculation --\n");
    for (int i = 0; i < 4; i++) {
        call(properties[i], accept, &tax->i_property_visitor__iface);
    }
    printf("Total tax: $%.0f\n\n", tax->__total_tax);

    printf("-- Area report --\n");
    for (int i = 0; i < 4; i++) {
        call(properties[i], accept, &area->i_property_visitor__iface);
    }
    printf("Total area: %.0f m2\n", area->__total_area);
}

void memento() {
    printf("Memento pattern:\n\n");

    apartment_listing *listing = new__apartment_listing(42, 85000, "Bright 3-room flat");
    listing_history *history = new__listing_history();
    call(listing, print);

    listing_memento *snap1 = call(listing, save);
    call(history, push, snap1);

    call(listing, set_price, 92000);
    call(listing, set_description, "Renovated 3-room flat");
    call(listing, print);

    listing_memento *snap2 = call(listing, save);
    call(history, push, snap2);

    call(listing, set_price, 105000);
    call(listing, set_description, "Luxury renovated flat with parking");
    call(listing, print);

    printf("\n-- Undo last change --\n");
    listing_memento *restore1 = call(history, pop);
    call(listing, restore, restore1);
    call(listing, print);

    printf("\n-- Undo again --\n");
    listing_memento *restore2 = call(history, pop);
    call(listing, restore, restore2);
    call(listing, print);
}

void mediator() {
    printf("Mediator pattern:\n\n");

    seller *s = new__seller("Popescu Ion", 205, 75000);
    call(s, print_listing);
    printf("\n");

    apartment_deal_mediator *med = new__apartment_deal_mediator(s, NULL);
    buyer *b = new__buyer("Maria Ionescu", &med->i_negotiation_mediator__iface);
    med->__buyer = b;

    call(b, make_offer, 60000);
    printf("\n");
    call(b, make_offer, 75000);
    printf("\n");
    call(b, make_offer, 80000);
}

void interpreter() {
    printf("Interpreter pattern:\n\n");

    apartment *apartments[5] = {
        new(apartment, 2, 3),
        new(apartment, 5, 8),
        new(apartment, 1, 12),
        new(apartment, 3, 6),
        new(apartment, 4, 10),
    };

    i_apartment_expression *floor_gt_4 =
            &new__floor_gt_expression(4)->i_apartment_expression__iface;
    i_apartment_expression *rooms_gte_6 =
            &new__rooms_gte_expression(6)->i_apartment_expression__iface;
    i_apartment_expression *high_and_spacious =
            &new__and_expression(floor_gt_4, rooms_gte_6)->i_apartment_expression__iface;
    i_apartment_expression *any_big =
            &new__or_expression(
                &new__rooms_gte_expression(10)->i_apartment_expression__iface,
                floor_gt_4
            )->i_apartment_expression__iface;

    printf("Filter: floor > 4 AND rooms >= 6\n");
    for (int i = 0; i < 5; i++) {
        if (call(high_and_spacious, interpret, apartments[i])) {
            printf("  MATCH: floor %d, %d rooms\n",
                   apartments[i]->floor, apartments[i]->base_house__base.number_of_rooms);
        }
    }

    printf("\nFilter: rooms >= 10 OR floor > 4\n");
    for (int i = 0; i < 5; i++) {
        if (call(any_big, interpret, apartments[i])) {
            printf("  MATCH: floor %d, %d rooms\n",
                   apartments[i]->floor, apartments[i]->base_house__base.number_of_rooms);
        }
    }
}
