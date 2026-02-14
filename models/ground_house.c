#include <stdio.h>
#include <stdlib.h>
#include "ground_house.h"

#include <string.h>

#include "statistics.h"

void _update_statistics_for_new_ground_house(void) {
    statistics *statistics = Statistics.s_vtable->get_instance();
    call(statistics, increase_created_houses);
}

void print_myself_ground_house(void *self) {
    if (((ground_house *) self)->has_fantana) {
        printf("I'm a simple house on the ground with %d rooms and I have fantana.\n",
               ((ground_house *) self)->base_house__base.number_of_rooms);
    } else {
        printf("I'm a simple house on the ground with %d rooms and I don't have fantana.\n",
               ((ground_house *) self)->base_house__base.number_of_rooms);
    }
}

void *ground_house_clone(void *self) {
    ground_house *s = self;
    ground_house *new_gh = new(ground_house, s);

    return new_gh;
}

char *ground_house_to_json(void *self) {
    ground_house *gh = container_of(container_of(self, base_house, i_as_json), ground_house, base_house__base);
    char *json = malloc(256 * sizeof(char));
    sprintf(json, "{ \"number_of_rooms\": %d, \"has_fantana\": %s }",
            gh->base_house__base.number_of_rooms,
            gh->has_fantana ? "true" : "false");

    return json;
}

base_house__vtable ground_house_v_table = {
    .print_myself = print_myself_ground_house
};

i_prototype__vtable ground_house_prototype_v_table = {
    .clone = ground_house_clone
};

i_as_json__vtable ground_house_as_json_v_table = {
    .to_json = ground_house_to_json
};

void _init_v_tables_gh(ground_house *a) {
    if (a == NULL) {
        return;
    }

    a->base_house__base.vtable = &ground_house_v_table;
    a->base_house__base.i_prototype.vtable = &ground_house_prototype_v_table;
    a->base_house__base.i_as_json.vtable = &ground_house_as_json_v_table;
}


ground_house *new__ground_house0() {
    base_house *bh = _new(base_house);
    ground_house *gh = realloc(bh, sizeof(ground_house));
    _init_v_tables_gh(gh);

    gh->base_house__base.number_of_rooms = 4;
    gh->has_fantana = true;

    // For singleton
    _update_statistics_for_new_ground_house();

    return gh;
}

ground_house *new__ground_house1_bool(const bool has_fantana) {
    base_house *bh = _new(base_house);
    ground_house *gh = realloc(bh, sizeof(ground_house));
    _init_v_tables_gh(gh);

    gh->has_fantana = has_fantana;

    // For singleton
    _update_statistics_for_new_ground_house();

    return gh;
}

ground_house *new__ground_house2_int_bool(const int number_of_rooms, const bool has_fantana) {
    base_house *bh = _new(base_house, number_of_rooms);
    ground_house *gh = realloc(bh, sizeof(ground_house));
    _init_v_tables_gh(gh);

    gh->has_fantana = has_fantana;

    // For singleton
    _update_statistics_for_new_ground_house();

    return gh;
}

ground_house *new__ground_house1_ground_house(ground_house *gh) {
    base_house *bh = _new(base_house, (base_house*)gh);
    ground_house *new_gh = realloc(bh, sizeof(ground_house));
    _init_v_tables_gh(new_gh);

    new_gh->has_fantana = gh->has_fantana;

    // For singleton
    _update_statistics_for_new_ground_house();

    return new_gh;
}


ground_house *new__ground_house1_json(char *json) {
    ground_house *gh = new(ground_house);
    char has_fantana_buffer[5];
    sscanf(json, "{ \"number_of_rooms\": %d, \"has_fantana\": %s }",
           &gh->base_house__base.number_of_rooms,
           has_fantana_buffer);

    gh->has_fantana = strcmp(has_fantana_buffer, "true") == 0;


    return gh;
}
