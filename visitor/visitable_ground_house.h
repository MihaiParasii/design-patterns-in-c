#ifndef VISITABLE_GROUND_HOUSE_H
#define VISITABLE_GROUND_HOUSE_H
#include "../defines.h"
#include "i_visitable_property.h"

class_(visitable_ground_house) {
    implements_(i_visitable_property);
    ground_house *__ground_house;
};

constructor(visitable_ground_house, ground_house *gh);

#endif //VISITABLE_GROUND_HOUSE_H
