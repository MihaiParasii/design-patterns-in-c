#ifndef STATISTICS_H
#define STATISTICS_H

typedef struct statistics statistics;

typedef struct statistics_vtable {
    void (*print_created_houses_count)(void *self);

    void (*increate_created_houses)(void *self);
} statistics_vtable;

typedef struct statistics_static_vtable {
    statistics * (*get_instance)(void *self);
} statistics_static_vtable;

typedef struct statistics {
    statistics_vtable *vtable;
    statistics_static_vtable *static_vtable;
    statistics *__self;
    int __created_houses_count;
} statistics;

statistics *get_static_statistics();

#endif //STATISTICS_H
