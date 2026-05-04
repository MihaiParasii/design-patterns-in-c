#include "apartment_building.h"

#include <stdlib.h>


static int _get_rooms_count(void *self) {
    const apartment_building *s = container_of(self, apartment_building, i_house_component__iface);
    const int rooms_for_cleaning = 3;
    int total_rooms = 0;

    for (int i = 0; i < s->children->size; ++i) {
        total_rooms += call(s->children->data[i], get_rooms_count);
    }

    total_rooms += rooms_for_cleaning;

    return total_rooms;
}

static double _get_area(void *self) {
    const apartment_building *s = container_of(self, apartment_building, i_house_component__iface);
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
    .get_rooms_count = _get_rooms_count,
    .get_area = _get_area
};


static void add_child(void *self, i_house_component *component) {
    const apartment_building *s = self;

    call(s->children, add_back, component);
}

static apartment_building__vtable vtable = {
    .add_child = add_child
};

constructor(apartment_building) {
    apartment_building *ab = malloc(sizeof(apartment_building));

    ab->children = new(dynamic_array_house_component, 10);
    ab->i_house_component__iface.vtable = &house_component_vtable;
    ab->vtable = &vtable;

    return ab;
}
