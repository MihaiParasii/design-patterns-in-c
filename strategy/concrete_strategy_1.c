#include "concrete_strategy_1.h"

#include <stdio.h>
#include <stdlib.h>

void execute__concrete_strategy_1(void *self, int num1, int num2) {
    concrete_strategy_1 *s = self;

    printf("Executing concrete strategy 1: %d + %d = %d\n", num1, num2, num1 + num2);
}


i_strategy__vtable i_strategy__vtable__concrete_strategy_1 = {
    .execute = execute__concrete_strategy_1
};


concrete_strategy_1 *new__concrete_strategy_1() {
    concrete_strategy_1 *s1 = malloc(sizeof(concrete_strategy_1));

    s1->i_strategy__iface.vtable = &i_strategy__vtable__concrete_strategy_1;

    return s1;
}
