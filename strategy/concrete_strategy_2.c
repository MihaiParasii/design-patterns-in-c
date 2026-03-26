#include "concrete_strategy_2.h"

#include <stdio.h>
#include <stdlib.h>


void execute__concrete_strategy_2(void *self, int num1, int num2) {
    printf("Executing concrete strategy 2: %d * %d = %d\n", num1, num2, num1 * num2);
}


i_strategy__vtable i_strategy__vtable__concrete_strategy_2 = {
    .execute = execute__concrete_strategy_2
};


concrete_strategy_2 *new__concrete_strategy_2() {
    concrete_strategy_2 *cs2 = malloc(sizeof(concrete_strategy_2));

    cs2->i_strategy__iface.vtable = &i_strategy__vtable__concrete_strategy_2;

    return cs2;
}
