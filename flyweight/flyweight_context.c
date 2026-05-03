#include "flyweight_context.h"

#include <stdlib.h>

static void print_colors(void *self) {
    flyweight_context *s = self;

    call(s, print_colors);
}

static flyweight_context__vtable flyweight_context_vtable = {
    .print_colors = print_colors
};


constructor(flyweight_context) {
    flyweight_context *context = malloc(sizeof(flyweight_context));
    context->vtable = &flyweight_context_vtable;

    return context;
}
