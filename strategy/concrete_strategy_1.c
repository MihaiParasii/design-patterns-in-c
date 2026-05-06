#include "concrete_strategy_1.h"

#include <stdio.h>
#include <stdlib.h>

static void execute__concrete_strategy_1(void *self, int num1, int num2) {
    concrete_strategy_1 *s = self;

    printf("Executing concrete strategy 1: %d + %d = %d\n", num1, num2, num1 + num2);
}


static i_strategy__vtable vtable = {
    .execute = execute__concrete_strategy_1
};


constructor(concrete_strategy_1) {
    concrete_strategy_1 *s1 = malloc(sizeof(concrete_strategy_1));

    s1->i_strategy__iface.vtable = &vtable;

    return s1;
}
