#include "base_house.h"

#include <stdlib.h>

int _get_rooms_count__base_house(void *self) {
    const base_house *s = container_of(self, base_house, i_house_component);

    return s->number_of_rooms;
}

double _get_area__base_house(void *self) {
    const base_house *s = container_of(self, base_house, i_house_component);
    const double median_of_room_surface = 12.5;

    return s->number_of_rooms * median_of_room_surface;
}

i_house_component__vtable house_component_vtable__base_house = {
    .get_rooms_count = _get_rooms_count__base_house,
    .get_area = _get_area__base_house
};

base_house *_new__base_house0(void) {
    base_house *bh = malloc(sizeof(base_house));

    bh->number_of_rooms = 0;
    bh->i_house_component.vtable = &house_component_vtable__base_house;

    return bh;
}

base_house *_new__base_house1_int(const int number_of_rooms) {
    base_house *bh = _new(base_house);

    bh->number_of_rooms = number_of_rooms;
    bh->i_house_component.vtable = &house_component_vtable__base_house;

    return bh;
}

base_house *_new__base_house1_base_house(base_house *bh) {
    base_house *new_bh = _new(base_house);

    new_bh->number_of_rooms = bh->number_of_rooms;
    new_bh->i_house_component.vtable = &house_component_vtable__base_house;

    return new_bh;
}
