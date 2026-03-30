#include "flyweight_context.h"

#include <stdlib.h>

void print_colors(void *self) {
    flyweight_context *s = self;

    call(s, print_colors);
}

flyweight_context__vtable flyweight_context_vtable = {
    .print_colors = print_colors
};


flyweight_context *new__flyweight_context() {
    flyweight_context *context = malloc(sizeof(flyweight_context));
    context->vtable = &flyweight_context_vtable;

    return context;
}
