//
// Created by Mihai Parasii on 30.01.2026.
//

#include "ground_house.h"

#include <stdio.h>
#include <stdlib.h>

#include "statistics.h"

void print_myself_ground_house(void *self) {
    if (((ground_house *) self)->has_fantana) {
        printf("I'm a simple house on the ground with %d rooms and I have fantana.\n",
               ((ground_house *) self)->base.number_of_rooms);
    } else {
        printf("I'm a simple house on the ground with %d rooms and I don't have fantana.\n",
               ((ground_house *) self)->base.number_of_rooms);
    }
}

house_v_table ground_house_v_table = {
    .print_myself = print_myself_ground_house
};

ground_house *new_ground_house() {
    ground_house *gh = malloc(sizeof(ground_house));
    gh->base.vtable = &ground_house_v_table;
    gh->base.number_of_rooms = 4;
    gh->has_fantana = true;

    // For singleton
    statistics* statistics = get_static_statistics();
    statistics = statistics->static_vtable->get_instance(statistics);
    statistics->vtable->increate_created_houses(statistics);

    return gh;
}
