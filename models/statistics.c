#include "statistics.h"

#include <stdio.h>
#include <stdlib.h>

static statistics *self_reference = NULL;

void print_created_houses_count(void *self) {
    const statistics *s = (statistics *) self;

    printf("In the application was created %d houses.\n", s->__created_houses_count);
}

int get_created_houses_count(void *self) {
    const statistics *s = (statistics *) self;

    return s->__created_houses_count;
}

void increase_created_houses(void *self) {
    statistics *s = self;

    ++s->__created_houses_count;
}


statistics__vtable statistics_v_table = {
    .print_created_houses_count = print_created_houses_count,
    .increase_created_houses = increase_created_houses,
    .get_created_houses_count = get_created_houses_count
};

statistics *get_instance(void *self) {
    if (self_reference == NULL) {
        statistics *statistics = self;
        statistics->vtable = &statistics_v_table;
        self_reference = statistics;
    }

    return self_reference;
}


statistics__s_vtable statistics_s_vtable = {
    .get_instance = get_instance
};

statistics *s_new__statistics() {
    statistics *s = calloc(1, sizeof(statistics));

    s->s_vtable = &statistics_s_vtable;

    return s;
}
