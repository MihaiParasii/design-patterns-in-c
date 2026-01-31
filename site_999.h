#ifndef SITE_999_H
#define SITE_999_H
#include "dynamic_array.h"
#include "house_constructor.h"


typedef struct Site_999_VTable {
    void (*print_houses)(void *self);

    void (*add_house)(void *self, const house_constructor *constructor);
} site_999_v_table;


typedef struct Site_999 {
    const site_999_v_table *vtable;
    dynamic_array *_houses;
} site_999;

site_999 *new_site_999();

#endif //SITE_999_H
