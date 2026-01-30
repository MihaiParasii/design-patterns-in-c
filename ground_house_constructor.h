#ifndef GROUND_HOUSE_CONSTRUCTOR_H
#define GROUND_HOUSE_CONSTRUCTOR_H
#include "house_constructor.h"


typedef struct GroundHouseConstructor {
    house_constructor base;
} ground_house_constructor;

ground_house_constructor *new_ground_house_constructor();

#endif //GROUND_HOUSE_CONSTRUCTOR_H
