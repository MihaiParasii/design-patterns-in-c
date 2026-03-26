#include "concrete_abstraction.h"

#include <stdio.h>


void call_print_something_from_impl__concrete_abstraction(void *self) {
    const abstraction *s = self;
    printf("Calling print_something from concrete abstraction\n");
    call(s->__impl, print_something);
}

abstraction__vtable abstraction__vtable__concrete_abstraction = {
    .call_print_something_from_impl = call_print_something_from_impl__concrete_abstraction,
};


concrete_abstraction *new__concrete_abstraction(i_abstraction_impl *impl) {
    abstraction *a = _new(abstraction1_i_abstraction_impl, impl);

    a->vtable = &abstraction__vtable__concrete_abstraction;

    return (concrete_abstraction *) a;
}
