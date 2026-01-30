#ifndef APARTMENT_CONSTRUCTOR_H
#define APARTMENT_CONSTRUCTOR_H
#include "house_constructor.h"


typedef struct ApartmentConstructor {
    house_constructor base;
} apartment_constructor;

apartment_constructor *new_apartment_constructor();

#endif //APARTMENT_CONSTRUCTOR_H
