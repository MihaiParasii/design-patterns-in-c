#include "macos_abstraction_impl.h"

#include <stdio.h>
#include <stdlib.h>

static void print_something(void *self) {
    printf("macOS\n");
    printf("Print something\n");
}

i_abstraction_impl__vtable print_something__macos_abstraction_impl__vtable = {
    .print_something = print_something
};

constructor(macos_abstraction_impl) {
    macos_abstraction_impl *impl = malloc(sizeof(macos_abstraction_impl));

    if (impl == NULL) {
        return NULL;
    }

    impl->i_abstraction_impl__iface.vtable = &print_something__macos_abstraction_impl__vtable;
    return impl;
}
