#include "concrete_abstraction.h"

#include <stdio.h>


static void call_print_something_from_impl(void *self) {
    const abstraction *s = self;
    printf("Calling print_something from concrete abstraction\n");
    call(s->__impl, print_something);
}

static abstraction__vtable abstraction__vtable__concrete_abstraction = {
    .call_print_something_from_impl = call_print_something_from_impl,
};


constructor(concrete_abstraction, i_abstraction_impl *impl) {
    abstraction *a = _new(abstraction, impl);

    a->vtable = &abstraction__vtable__concrete_abstraction;

    return (concrete_abstraction *) a;
}
