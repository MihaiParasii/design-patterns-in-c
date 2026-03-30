#ifndef LAB2_FLYWEIGHT_DA_H
#define LAB2_FLYWEIGHT_DA_H
#include "../defines.h"
#include "../flyweight/flyweight.h"

vtable_for(flyweight_da) {
    method_(void, add_back, flyweight* object);

    method_(void, remove_back);
};

class_(flyweight_da) {
    flyweight_da__vtable *vtable;
    size_t size;
    size_t capacity;
    flyweight **data;
};

flyweight_da *new__flyweight_da(size_t default_size);



#endif //LAB2_FLYWEIGHT_DA_H