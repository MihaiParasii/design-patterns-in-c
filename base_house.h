#ifndef BASE_HOUSE_H
#define BASE_HOUSE_H


typedef struct House_VTable {
    void (*print_myself)(void *self);
} house_v_table;

typedef struct House {
    house_v_table *vtable;
    int number_of_rooms;
} base_house;


#endif //BASE_HOUSE_H
