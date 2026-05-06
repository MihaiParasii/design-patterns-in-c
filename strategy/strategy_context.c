#include "strategy_context.h"

#include <stdlib.h>

static void set_strategy(void *self, i_strategy *strategy) {
    strategy_context *s = self;
    s->__strategy = strategy;
}

static void execute_strategy(void *self, int num1, int num2) {
    const strategy_context *s = self;
    call(s->__strategy, execute, num1, num2);
}

static strategy_context__vtable vtable = {
    .set_strategy = set_strategy,
    .execute_strategy = execute_strategy
};


constructor(strategy_context, i_strategy *strategy) {
    strategy_context *sc = malloc(sizeof(strategy_context));
    if (sc == NULL) {
        return NULL;
    }
    sc->vtable = &vtable;
    sc->__strategy = strategy;
    return sc;
}
