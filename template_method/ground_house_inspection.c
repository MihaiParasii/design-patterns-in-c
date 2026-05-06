#include "ground_house_inspection.h"
#include <stdlib.h>
#include <stdio.h>

static ground_house_inspection *self_of(void *base) {
    return container_of(base, ground_house_inspection, house_inspection__base);
}

static void gather_info(void *self) {
    ground_house *gh = self_of(self)->__target;
    printf("[Info]      Type: Ground House | Rooms: %d | Well: %s\n",
           gh->base_house__base.number_of_rooms,
           gh->has_fantana ? "yes" : "no");
}

static void inspect_structure(void *self) {
    ground_house *gh = self_of(self)->__target;
    printf("[Structure] Foundation and roof of %d-room house: good condition\n",
           gh->base_house__base.number_of_rooms);
}

static void inspect_utilities(void *self) {
    ground_house *gh = self_of(self)->__target;
    if (gh->has_fantana) {
        printf("[Utilities] Well water quality: requires lab test\n");
    } else {
        printf("[Utilities] Municipal water and electrical: operational\n");
    }
}

static void write_conclusion(void *self) {
    ground_house *gh = self_of(self)->__target;
    printf("[Conclusion] Ground house (%d rooms): PASSED inspection\n",
           gh->base_house__base.number_of_rooms);
}

static house_inspection__vtable ground_house_inspection_vtable = {
    .gather_info       = gather_info,
    .inspect_structure = inspect_structure,
    .inspect_utilities = inspect_utilities,
    .write_conclusion  = write_conclusion,
};

constructor(ground_house_inspection, ground_house *gh) {
    ground_house_inspection *gi = malloc(sizeof(ground_house_inspection));
    gi->house_inspection__base.vtable = &ground_house_inspection_vtable;
    gi->__target = gh;
    return gi;
}
