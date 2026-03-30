#ifndef LAB2_FLYWEIGHT_CONTEXT_H
#define LAB2_FLYWEIGHT_CONTEXT_H
#include "../defines.h"

vtable_for(flyweight_context) {
    method_(void, add_color, int color_hex);

    method_(void, print_colors);
};

class_(flyweight_context) {
    flyweight_context__vtable *vtable;
};


flyweight_context *new__flyweight_context();


#endif //LAB2_FLYWEIGHT_CONTEXT_H
