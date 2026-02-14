#include "apartment_building.h"

#include <stdlib.h>


int _get_rooms_count__apartment_building(void *self) {
    const apartment_building *s = self;
    const int rooms_for_cleaning = 3;
    int total_rooms = 0;

    for (int i = 0; i < s->children->size; ++i) {
        total_rooms += call(s->children->data[i], get_rooms_count);
    }

    total_rooms += rooms_for_cleaning;

    return total_rooms;
}

double _get_area__apartment_building(void *self) {
    const apartment_building *s = self;
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

i_house_component__vtable house_component_vtable__apartment_building = {
    .get_rooms_count = _get_rooms_count__apartment_building,
    .get_area = _get_area__apartment_building
};


void _add_new_apartment_building(void *self, i_house_component *component) {
    const apartment_building *s = self;

    call(s->children, add_back, component);
}

apartment_building__vtable apartment_building_vtable = {
    .add_child = _add_new_apartment_building
};

apartment_building *new__apartment_building() {
    apartment_building *ab = malloc(sizeof(apartment_building));

    ab->children = new(dynamic_array_house_component, 10);
    ab->i_house_component.vtable = &house_component_vtable__apartment_building;
    ab->vtable = &apartment_building_vtable;

    return ab;
}
