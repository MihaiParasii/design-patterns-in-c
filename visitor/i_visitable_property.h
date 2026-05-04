#ifndef I_VISITABLE_PROPERTY_H
#define I_VISITABLE_PROPERTY_H
#include "../defines.h"
#include "i_property_visitor.h"

vtable_for(i_visitable_property) {
    method_(void, accept, i_property_visitor *visitor);
};

class_(i_visitable_property) {
    i_visitable_property__vtable *vtable;
};

#endif //I_VISITABLE_PROPERTY_H
