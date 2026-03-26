#include "windows_abstraction_impl.h"

#include <stdio.h>
#include <stdlib.h>

void print_something__windows_abstraction_impl(void *self) {
    printf("Windows\n");
    printf("Print something\n");
}

i_abstraction_impl__vtable print_something__windows_abstraction_impl__vtable = {
    .print_something = print_something__windows_abstraction_impl
};

windows_abstraction_impl *new__windows_abstraction_impl() {
    windows_abstraction_impl *impl = malloc(sizeof(windows_abstraction_impl));

    if (impl == NULL) {
        return NULL;
    }

    impl->i_abstraction_impl__iface.vtable = &print_something__windows_abstraction_impl__vtable;
    return impl;
}
