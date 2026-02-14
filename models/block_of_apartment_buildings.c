#include "block_of_apartment_buildings.h"

#include <stdlib.h>

int _get_rooms_count__block_of_apartment_buildings(void *self) {
    const block_of_apartment_buildings *s = container_of(self, block_of_apartment_buildings, i_house_component);
    const int rooms_for_cleaning = 3;
    int total_rooms = 0;

    for (int i = 0; i < s->children->size; ++i) {
        total_rooms += call(s->children->data[i], get_rooms_count);
    }

    total_rooms += rooms_for_cleaning;

    return total_rooms;
}

double _get_area__block_of_apartment_buildings(void *self) {
    const block_of_apartment_buildings *s = container_of(self, block_of_apartment_buildings, i_house_component);
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

i_house_component__vtable house_component_vtable__block_of_apartment_building = {
    .get_rooms_count = _get_rooms_count__block_of_apartment_buildings,
    .get_area = _get_area__block_of_apartment_buildings
};


void _add_new__block_of_apartment_building(void *self, i_house_component *component) {
    const block_of_apartment_buildings *s = self;

    call(s->children, add_back, component);
}

block_of_apartment_buildings__vtable block_of_apartment_building_vtable = {
    .add_child = _add_new__block_of_apartment_building
};

block_of_apartment_buildings *new__block_of_apartment_buildings() {
    block_of_apartment_buildings *ab = malloc(sizeof(block_of_apartment_buildings));

    ab->i_house_component.vtable = &house_component_vtable__block_of_apartment_building;
    ab->vtable = &block_of_apartment_building_vtable;
    ab->children = new(dynamic_array_house_component, 10);

    return ab;
}
