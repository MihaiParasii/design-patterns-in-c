#ifndef LAB2_I_STRATEGY_H
#define LAB2_I_STRATEGY_H
#include "../defines.h"

vtable_for(i_strategy) {
    method_(void, execute, int num1, int num2);  
};


class_(i_strategy) {
    i_strategy__vtable *vtable;
};


#endif //LAB2_I_STRATEGY_H