#ifndef APARTMENT_H
#define APARTMENT_H
#include "base_house.h"

typedef struct Apartment {
    base_house base;
    int floor;
} apartment;

apartment *new_apartment();

#endif //APARTMENT_H
