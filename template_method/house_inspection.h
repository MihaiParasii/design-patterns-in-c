#ifndef HOUSE_INSPECTION_H
#define HOUSE_INSPECTION_H
#include "../defines.h"

vtable_for(house_inspection) {
    method_(void, gather_info);
    method_(void, inspect_structure);
    method_(void, inspect_utilities);
    method_(void, write_conclusion);
};

class_(house_inspection) {
    house_inspection__vtable *vtable;
};

void run_inspection(house_inspection *inspection);

#endif //HOUSE_INSPECTION_H
