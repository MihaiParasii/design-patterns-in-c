#ifndef LAB2_FLYWEIGHT_H
#define LAB2_FLYWEIGHT_H
#include "../defines.h"

vtable_for(flyweight) {
    method_(void, print_color);
    method_(int, get_color);
};

class_(flyweight) {
    int __color_hex;
    flyweight__vtable *vtable;
};

flyweight *new__flyweight(int color_hex);


#endif //LAB2_FLYWEIGHT_H