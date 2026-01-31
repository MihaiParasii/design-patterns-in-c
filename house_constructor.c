#include "house_constructor.h"

void print_a_new_house(void *self) {
    base_house *house = ((house_constructor*)self)->vtable->construct_house();
    house->vtable->print_myself(house);
}
