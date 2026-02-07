#ifndef GROUND_HOUSE_H
#define GROUND_HOUSE_H

#include <stdbool.h>
#include "base_house.h"
#include "../defines.h"

class_(ground_house) {
    extends_(base_house);

    bool has_fantana;
};

ground_house *new__ground_house0(void);

ground_house *new__ground_house1_bool(bool has_fantana);

ground_house *new__ground_house2_int_bool(int number_of_rooms, bool has_fantana);

ground_house *new__ground_house1_ground_house(ground_house *gh);

#define new__ground_house1(x) \
    _Generic((x), \
    bool:           new__ground_house1_bool, \
    ground_house*: new__ground_house1_ground_house \
)(x)

#define dispatch_ground_house_2_2(type, second_type) \
    _Generic((second_type), \
    bool:    new__ground_house2_##type##_bool   \
)

#define new__ground_house2(x, y) \
    _Generic((x), \
    int:     dispatch_ground_house_2_2(int, y) \
)(x, y)

#define new__ground_house(...) \
    CAT(new__ground_house, PP_NARG(__VA_ARGS__))(__VA_ARGS__)

#endif //GROUND_HOUSE_H
