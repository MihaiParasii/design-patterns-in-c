#ifndef LAB2_STRATEGY_CONTEXT_H
#define LAB2_STRATEGY_CONTEXT_H

#include "i_strategy.h"
#include "../defines.h"

vtable_for(strategy_context) {
    method_(void, execute_strategy, int num1, int num2);

    method_(void, set_strategy, i_strategy *strategy);
};

class_(strategy_context) {
    strategy_context__vtable *vtable;
    i_strategy *__strategy;
};


strategy_context *new__strategy_context(i_strategy *strategy);


#endif //LAB2_STRATEGY_CONTEXT_H
