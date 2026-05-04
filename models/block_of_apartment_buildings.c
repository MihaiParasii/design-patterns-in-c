#include "block_of_apartment_buildings.h"

#include <stdlib.h>

static int get_rooms_count(void *self) {
    const block_of_apartment_buildings *s = container_of(self, block_of_apartment_buildings, i_house_component__iface);
    const int rooms_for_cleaning = 3;
    int total_rooms = 0;

    for (int i = 0; i < s->children->size; ++i) {
        total_rooms += call(s->children->data[i], get_rooms_count);
    }

    total_rooms += rooms_for_cleaning;

    return total_rooms;
}

static double get_area(void *self) {
    const block_of_apartment_buildings *s = container_of(self, block_of_apartment_buildings, i_house_component__iface);
    const double median_of_room_surface = 12.5;
    const int rooms_for_cleaning = 3;
    const double area_of_cleaning_rooms = rooms_for_cleaning * median_of_room_surface;
    double total_area = 0;

    for (int i = 0; i < s->children->size; ++i) {
        total_area += call(s->children->data[i], get_area);
    }

    total_area += area_of_cleaning_rooms;

    return total_area;
}

static i_house_component__vtable house_component_vtable = {
    .get_rooms_count = get_rooms_count,
    .get_area = get_area
};


static void add_new(void *_self, i_house_component *component) {
    SELF(block_of_apartment_buildings);

    call(self->children, add_back, component);
}

static block_of_apartment_buildings__vtable block_of_apartment_building_vtable = {
    .add_child = add_new
};

constructor(block_of_apartment_buildings) {
    block_of_apartment_buildings *ab = malloc(sizeof(block_of_apartment_buildings));

    ab->i_house_component__iface.vtable = &house_component_vtable;
    ab->vtable = &block_of_apartment_building_vtable;
    ab->children = new(dynamic_array_house_component, 10);

    return ab;
}
