#ifndef LAB2_FLYWEIGHT_FACTORY_H
#define LAB2_FLYWEIGHT_FACTORY_H
#include "../defines.h"
#include "../common/flyweight_da.h"
#include "../flyweight/flyweight.h"

vtable_for(flyweight_factory) {
    method_(flyweight*, get_flyweight, int color_hex);
};

class_(flyweight_factory) {
    flyweight_da *__da;
    flyweight_factory__vtable *vtable;
};

flyweight_factory *new__flyweight_factory();

#endif //LAB2_FLYWEIGHT_FACTORY_H
