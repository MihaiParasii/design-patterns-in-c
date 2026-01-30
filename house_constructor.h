//
// Created by Mihai Parasii on 30.01.2026.
//

#ifndef HOUSE_CONSTRUCTOR_H
#define HOUSE_CONSTRUCTOR_H
#include "base_house.h"

typedef struct HouseConstructor_VTable {
    base_house * (*construct_house)();
} house_constructor_vtable;

typedef struct HouseConstructor {
    const house_constructor_vtable *vtable;
} house_constructor;

#endif //HOUSE_CONSTRUCTOR_H
