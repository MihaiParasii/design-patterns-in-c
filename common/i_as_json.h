#ifndef I_AS_JSON_H
#define I_AS_JSON_H
#include "../defines.h"

vtable_(i_as_json) {
    method_(char *, to_json);
};

class_(i_as_json) {
    i_as_json__vtable *vtable;
};

#endif //I_AS_JSON_H
