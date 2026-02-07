#ifndef APARTMENT_CREATOR_H
#define APARTMENT_CREATOR_H
#include "house_creator.h"

class_(apartment_creator) {
    extends_(house_creator);
};

apartment_creator *new__apartment_creator();

#endif //APARTMENT_CREATOR_H
