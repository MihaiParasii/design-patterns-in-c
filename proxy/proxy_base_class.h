#ifndef LAB2_PROXY_BASE_CLASS_H
#define LAB2_PROXY_BASE_CLASS_H
#include "../defines.h"
#include "i_proxy_example.h"

class_(proxy_base_class) {
    implements_(i_proxy_example);
};

proxy_base_class *new__proxy_base_class();

#endif //LAB2_PROXY_BASE_CLASS_H
