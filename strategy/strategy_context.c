#include "strategy_context.h"

#include <stdlib.h>

void set_strategy__strategy_context(void *self, i_strategy *strategy) {
    strategy_context *s = self;
    s->__strategy = strategy;
}

void execute_strategy__strategy_context(void *self, int num1, int num2) {
    const strategy_context *s = self;
    call(s->__strategy, execute, num1, num2);
}

strategy_context__vtable strategy_context_vtable__strategy_context = {
    .set_strategy = set_strategy__strategy_context,
    .execute_strategy = execute_strategy__strategy_context
};


strategy_context *new__strategy_context(i_strategy *strategy) {
    strategy_context *sc = malloc(sizeof(strategy_context));
    if (sc == NULL) {
        return NULL;
    }
    sc->vtable = &strategy_context_vtable__strategy_context;
    sc->__strategy = strategy;
    return sc;
}
