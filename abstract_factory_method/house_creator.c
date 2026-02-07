#include "house_creator.h"

void print_a_new_house(void *self) {
    base_house *house = call((house_creator *) self, construct_house);
    call(house, print_myself);
}
