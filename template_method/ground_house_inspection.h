#ifndef GROUND_HOUSE_INSPECTION_H
#define GROUND_HOUSE_INSPECTION_H
#include "../defines.h"
#include "house_inspection.h"
#include "../models/ground_house.h"

class_(ground_house_inspection) {
    extends_(house_inspection);
    ground_house *__target;
};

constructor(ground_house_inspection, ground_house *gh);

#endif //GROUND_HOUSE_INSPECTION_H
