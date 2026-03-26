#ifndef LAB2_REAL_PROXY_H
#define LAB2_REAL_PROXY_H

#include "i_proxy_example.h"
#include "proxy_base_class.h"
#include "../defines.h"

class_(real_proxy) {
    implements_(i_proxy_example);
    proxy_base_class *__real_subject;
};

real_proxy *new__real_proxy(proxy_base_class *real_subject);

#endif //LAB2_REAL_PROXY_H
