#ifndef LAB2_I_PROXY_EXAMPLE_H
#define LAB2_I_PROXY_EXAMPLE_H
#include "../defines.h"

vtable_for(i_proxy_example) {
    method_(void, print_something);
};

class_(i_proxy_example) {
    i_proxy_example__vtable *vtable;
};

#endif //LAB2_I_PROXY_EXAMPLE_H
