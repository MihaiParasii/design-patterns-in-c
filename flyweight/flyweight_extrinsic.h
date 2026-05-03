#ifndef LAB2_FLYWEIGHT_EXTRINSIC_H
#define LAB2_FLYWEIGHT_EXTRINSIC_H
#include "../defines.h"
#include "flyweight.h"

vtable_for(flyweight_extrinsic) {
    method_(void, print_info);
};

class_(flyweight_extrinsic) {
    flyweight_extrinsic__vtable *vtable;
    int not_shared_info;
    flyweight *__flyweight;
};

constructor(flyweight_extrinsic, int not_shared_info, flyweight *flyweight);


#endif //LAB2_FLYWEIGHT_EXTRINSIC_H
