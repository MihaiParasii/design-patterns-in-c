#include "proxy_base_class.h"

#include <stdio.h>
#include <stdlib.h>

void print_something__proxy_base_class(void *self) {
    printf("something\n");
}


i_proxy_example__vtable proxy_base_class__vtable = {
    .print_something = print_something__proxy_base_class
};


proxy_base_class *new__proxy_base_class() {
    proxy_base_class *instance = malloc(sizeof(proxy_base_class));

    if (instance == NULL) {
        return NULL;
    }
    instance->i_proxy_example__iface.vtable = &proxy_base_class__vtable;
    return instance;
}

proxy_base_class *new__proxy_base_class();
