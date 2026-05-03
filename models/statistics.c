#include "statistics.h"

#include <stdio.h>
#include <stdlib.h>

static statistics *singleton_instance;


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

constructor(statistics) {
    statistics *s = malloc(sizeof(statistics));

    s->__created_houses_count = 0;
    s->vtable = &statistics_v_table;

    return s;
}


statistics *get_instance() {
    if (!singleton_instance) {
        singleton_instance = new(statistics);
    }
    return singleton_instance;
}


static s_statistics__s_vtable statistics_s_vtable = {
    .get_instance = get_instance
};

const s_statistics Statistics = {
    .s_vtable = &statistics_s_vtable,
};
