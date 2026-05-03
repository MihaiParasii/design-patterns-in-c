#include "windows_abstraction_impl.h"

#include <stdio.h>
#include <stdlib.h>

static void print_something(void *self) {
    printf("Windows\n");
    printf("Print something\n");
}

static i_abstraction_impl__vtable print_something__windows_abstraction_impl__vtable = {
    .print_something = print_something
};

constructor(windows_abstraction_impl) {
    windows_abstraction_impl *impl = malloc(sizeof(windows_abstraction_impl));

    if (impl == NULL) {
        return NULL;
    }

    impl->i_abstraction_impl__iface.vtable = &print_something__windows_abstraction_impl__vtable;
    return impl;
}
