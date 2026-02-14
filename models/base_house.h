#ifndef BASE_HOUSE_H
#define BASE_HOUSE_H
#include "../defines.h"
#include "../common/i_prototype.h"
#include "../common/i_as_json.h"
#include "../common/i_house_component.h"


vtable_for(base_house) {
    method_(void, print_myself);
};

class_(base_house) {
    implements_(i_prototype);
    implements_(i_as_json);
    implements_(i_house_component);
    base_house__vtable *vtable;
    int number_of_rooms;
};

base_house *_new__base_house0(void);

base_house *_new__base_house1_int(int number_of_rooms);

base_house *_new__base_house1_base_house(base_house *bh);


#define _new__base_house1(x) \
    _Generic((x), \
    int:        _new__base_house1_int, \
    base_house*: _new__base_house1_base_house \
)(x)

#define _new__base_house(...) \
    CAT(_new__base_house, PP_NARG(__VA_ARGS__))(__VA_ARGS__)


#endif //BASE_HOUSE_H
