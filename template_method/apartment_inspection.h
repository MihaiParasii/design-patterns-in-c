#ifndef APARTMENT_INSPECTION_H
#define APARTMENT_INSPECTION_H
#include "../defines.h"
#include "house_inspection.h"
#include "../models/apartment.h"

class_(apartment_inspection) {
    extends_(house_inspection);
    apartment *__target;
};

constructor(apartment_inspection, apartment *apt);

#endif //APARTMENT_INSPECTION_H
