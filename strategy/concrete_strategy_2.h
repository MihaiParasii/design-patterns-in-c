#ifndef LAB2_CONCRETE_STRATEGY_2_H
#define LAB2_CONCRETE_STRATEGY_2_H
#include "../defines.h"
#include "i_strategy.h"

class_(concrete_strategy_2) {
    implements_(i_strategy);
};


concrete_strategy_2 *new__concrete_strategy_2();

#endif //LAB2_CONCRETE_STRATEGY_2_H