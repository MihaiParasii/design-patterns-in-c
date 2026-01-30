#include "apartment.h"

#include <stdio.h>
#include <stdlib.h>

void print_myself_apartment(void *self) {
    printf("I'm an apartment with %d rooms and at %d floor.\n", ((apartment *) self)->base.number_of_rooms,
           ((apartment *) self)->floor);
}

 house_v_table apartment_v_table = {
    .print_myself = print_myself_apartment
};

apartment *new_apartment() {
    apartment *a = malloc(sizeof(apartment));
    a->base.vtable = &apartment_v_table;
    a->base.number_of_rooms = 4;
    a->floor = 10;

    return a;
}
