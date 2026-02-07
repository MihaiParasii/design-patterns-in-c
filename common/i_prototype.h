#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#include "../defines.h"

vtable_(i_prototype) {
    method_(void*, clone);
};

class_(i_prototype) {
    i_prototype__vtable *vtable;
};

#endif //PROTOTYPE_H
