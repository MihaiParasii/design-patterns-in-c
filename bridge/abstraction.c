#include "abstraction.h"

#include <stdio.h>
#include <stdlib.h>

static void call_print_something_from_impl__abstraction(void *self) {
    const abstraction *s = self;
    printf("Calling print_something from base abstraction\n");
    call(s->__impl, print_something);
}

static abstraction__vtable abstraction_vtable__abstraction = {
    .call_print_something_from_impl = call_print_something_from_impl__abstraction
};

_constructor(abstraction, i_abstraction_impl *impl) {
    abstraction *a = malloc(sizeof(abstraction));
    if (a == NULL) {
        return NULL;
    }
    a->__impl = impl;
    a->vtable = &abstraction_vtable__abstraction;
    return a;
}
