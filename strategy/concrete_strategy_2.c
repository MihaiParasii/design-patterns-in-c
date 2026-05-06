#include "concrete_strategy_2.h"

#include <stdio.h>
#include <stdlib.h>


static void execute__concrete_strategy_2(void *self, int num1, int num2) {
    printf("Executing concrete strategy 2: %d * %d = %d\n", num1, num2, num1 * num2);
}


static i_strategy__vtable vtable = {
    .execute = execute__concrete_strategy_2
};


constructor(concrete_strategy_2) {
    concrete_strategy_2 *cs2 = malloc(sizeof(concrete_strategy_2));

    cs2->i_strategy__iface.vtable = &vtable;

    return cs2;
}
