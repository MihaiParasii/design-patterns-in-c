#ifndef STATISTICS_H
#define STATISTICS_H
#include "../defines.h"

typedef struct statistics statistics;

vtable_(statistics) {
    method_(void, print_created_houses_count);

    method_(int, get_created_houses_count);

    method_(void, increase_created_houses);
};

s_vtable_(statistics) {
    method_(statistics*, get_instance);
};

class_(statistics) {
    statistics__vtable *vtable;
    statistics__s_vtable *s_vtable;
    statistics *__self;
    int __created_houses_count;
};

statistics *s_new__statistics();

#endif //STATISTICS_H
