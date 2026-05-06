#include "apartment_inspection.h"
#include <stdlib.h>
#include <stdio.h>

static apartment_inspection *self_of(void *base) {
    return container_of(base, apartment_inspection, house_inspection__base);
}

static void gather_info(void *self) {
    apartment *a = self_of(self)->__target;
    printf("[Info]      Type: Apartment | Floor: %d | Rooms: %d\n",
           a->floor, a->base_house__base.number_of_rooms);
}

static void inspect_structure(void *self) {
    apartment *a = self_of(self)->__target;
    printf("[Structure] Walls and ceiling on floor %d: %s\n",
           a->floor, a->floor > 10 ? "check for moisture" : "good condition");
}

static void inspect_utilities(void *self) {
    apartment *a = self_of(self)->__target;
    printf("[Utilities] Plumbing and electrical for %d-room unit: operational\n",
           a->base_house__base.number_of_rooms);
}

static void write_conclusion(void *self) {
    apartment *a = self_of(self)->__target;
    printf("[Conclusion] Apartment on floor %d: PASSED inspection\n", a->floor);
}

static house_inspection__vtable apartment_inspection_vtable = {
    .gather_info       = gather_info,
    .inspect_structure = inspect_structure,
    .inspect_utilities = inspect_utilities,
    .write_conclusion  = write_conclusion,
};

constructor(apartment_inspection, apartment *apt) {
    apartment_inspection *ai = malloc(sizeof(apartment_inspection));
    ai->house_inspection__base.vtable = &apartment_inspection_vtable;
    ai->__target = apt;
    return ai;
}
