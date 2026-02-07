#ifndef APARTMENT_H
#define APARTMENT_H
#include "base_house.h"
#include "../defines.h"

class_(apartment) {
    extends_(base_house);

    int floor;
};

apartment *new__apartment0(void);

apartment *new__apartment1_int(int floor);

apartment *new__apartment2_int_int(int number_of_rooms, int floor);

apartment *new__apartment1_apartment(apartment *a);


#define new__apartment1(x) \
    _Generic((x), \
    int:       new__apartment1_int, \
    apartment*: new__apartment1_apartment \
)(x)

#define dispatch_apartment_2_2(type, second_type) \
    _Generic((second_type), \
    int:    new__apartment2_##type##_int   \
)

#define new__apartment2(x, y) \
    _Generic((x), \
    int:       dispatch_apartment_2_2(int, y) \
)(x, y)

#define new__apartment(...) \
        CAT(new__apartment, PP_NARG(__VA_ARGS__))(__VA_ARGS__)

#endif //APARTMENT_H
