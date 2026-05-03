#include "flyweight_factory.h"

#include <stdlib.h>

static flyweight *get_flyweight__flyweight_factory(void *self, int color_hex) {
    flyweight_factory *s = self;
    flyweight_da *da = s->__da;

    for (int i = 0; i < da->size; i++) {
        if (da->data[i]->__color_hex == color_hex) {
            return da->data[i];
        }
    }

    flyweight *nf = new__flyweight(color_hex);
    call(da, add_back, nf);

    return nf;
}

static flyweight_factory__vtable flyweight_factory_vtable = {
    .get_flyweight = get_flyweight__flyweight_factory
};

constructor(flyweight_factory) {
    flyweight_factory *factory = malloc(sizeof(flyweight_factory));
    
    factory->__da = new__flyweight_da(10);
    factory->vtable = &flyweight_factory_vtable;
    
    return factory;
}
