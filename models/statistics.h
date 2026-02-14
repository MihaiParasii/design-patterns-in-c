#ifndef STATISTICS_H
#define STATISTICS_H
#include "../defines.h"

typedef struct statistics statistics;
typedef struct s_statistics s_statistics;

vtable_for(statistics) {
    method_(void, print_created_houses_count);

    method_(int, get_created_houses_count);

    method_(void, increase_created_houses);
};

s_vtable_(s_statistics) {
    static_method_(statistics *, get_instance);
};

class_(statistics) {
    statistics__vtable *vtable;
    int __created_houses_count;
};

static_class_(statistics) {
    s_statistics__s_vtable *s_vtable;
};

extern const s_statistics Statistics;


#endif //STATISTICS_H
