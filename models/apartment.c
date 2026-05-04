#include "apartment.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "statistics.h"

// int _get_rooms_count__apartment(void *self) {
//     apartment *s = self;
//
//     return s->base_house__base.number_of_rooms;
// }
//
// double _get_area__apartment(void *self) {
//     apartment *s = self;
//     const double median_of_room_surface = 12.5;
//
//     return s->base_house__base.number_of_rooms * median_of_room_surface;
// }
//
// i_house_component__vtable house_component_vtable__apartment = {
//     .get_rooms_count = _get_rooms_count__apartment,
//     .get_area = _get_area__apartment
// };

static void _update_statistics_for_new_apartment(void) {
    statistics *statistics = s_call(Statistics, get_instance);
    call(statistics, increase_created_houses);
}

static void print_myself(void *self) {
    printf("I'm an apartment with %d rooms and at %d floor.\n", ((apartment *) self)->base_house__base.number_of_rooms,
           ((apartment *) self)->floor);
}

static void *clone(void *self) {
    apartment *s = self;
    apartment *new_apartment = new(apartment, s);

    return new_apartment;
}

static char *to_json(void *self) {
    apartment *a = container_of(container_of(self, base_house, i_as_json__iface), apartment, base_house__base);
    
    char *json = malloc(100);
    sprintf(json, "{ \"number_of_rooms\": %d, \"floor\": %d }",
            a->base_house__base.number_of_rooms,
            a->floor);

    return json;
}

static base_house__vtable v_table = {
    .print_myself = print_myself,
};

static i_prototype__vtable prototype_v_table = {
    .clone = clone
};

static i_as_json__vtable as_json_v_table = {
    .to_json = to_json
};

static void _init_v_tables_a(apartment *a) {
    if (a == NULL) {
        return;
    }

    a->base_house__base.vtable = &v_table;
    a->base_house__base.i_prototype__iface.vtable = &prototype_v_table;
    a->base_house__base.i_as_json__iface.vtable = &as_json_v_table;
}

apartment *new__apartment0(void) {
    base_house *bh = _new(base_house);
    apartment *a = realloc(bh, sizeof(apartment));
    _init_v_tables_a(a);

    a->base_house__base.number_of_rooms = 4;
    a->floor = 10;

    // For singleton
    _update_statistics_for_new_apartment();

    return a;
}

apartment *new__apartment1_int(const int floor) {
    base_house *bh = _new(base_house);
    apartment *a = realloc(bh, sizeof(apartment));
    _init_v_tables_a(a);

    a->floor = floor;

    // For singleton
    _update_statistics_for_new_apartment();

    return a;
}

apartment *new__apartment2_int_int(const int number_of_rooms, const int floor) {
    base_house *bh = _new(base_house, number_of_rooms);
    apartment *a = realloc(bh, sizeof(apartment));
    _init_v_tables_a(a);

    a->floor = floor;

    // For singleton
    _update_statistics_for_new_apartment();

    return a;
}


apartment *new__apartment1_apartment(apartment *a) {
    base_house *bh = _new(base_house, (base_house*)a);
    apartment *new_a = realloc(bh, sizeof(apartment));
    _init_v_tables_a(new_a);

    new_a->floor = a->floor;

    // For singleton
    _update_statistics_for_new_apartment();

    return new_a;
}

apartment *new__apartment1_json(char *json) {
    apartment *a = new(apartment);

    sscanf(json, "{ \"number_of_rooms\": %d, \"floor\": %d }",
           &a->base_house__base.number_of_rooms,
           &a->floor);

    return a;
}
