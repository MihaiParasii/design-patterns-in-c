//
// Created by Mihai Parasii on 30.01.2026.
//

#ifndef GROUND_HOUSE_H
#define GROUND_HOUSE_H

#include <stdbool.h>
#include "base_house.h"

typedef struct GroundHouse {
    base_house base;
    bool has_fantana;
} ground_house;

ground_house *new_ground_house();

#endif //GROUND_HOUSE_H
