#include "real_proxy.h"

#include <stdio.h>
#include <stdlib.h>

#include "proxy_base_class.h"


void print_something__real_proxy(void *self) {
    const real_proxy *s = container_of(self, real_proxy, i_proxy_example__iface);

    printf("PROXY: LOL KEK CHEBUREK\n");
    call(&(s->__real_subject)->i_proxy_example__iface, print_something);
    printf("PROXY: END PROXY :)\n");
}

i_proxy_example__vtable real_proxy_vtable = {
    .print_something = print_something__real_proxy
};

real_proxy *new__real_proxy(proxy_base_class *real_subject) {
    real_proxy *instance = malloc(sizeof(real_proxy));

    if (instance == NULL) {
        return NULL;
    }

    instance->i_proxy_example__iface.vtable = &real_proxy_vtable;
    instance->__real_subject = real_subject;
    return instance;
}
