#ifndef LAB2_CONCRETE_STRATEGY_1_H
#define LAB2_CONCRETE_STRATEGY_1_H
#include "../defines.h"
#include "i_strategy.h"

class_(concrete_strategy_1) {
    implements_(i_strategy);
};

concrete_strategy_1 *new__concrete_strategy_1();


#endif //LAB2_CONCRETE_STRATEGY_1_H