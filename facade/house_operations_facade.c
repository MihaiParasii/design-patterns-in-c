#include "house_operations_facade.h"

#include <stdlib.h>


void buy_apartment__house_operation_facade(void *self, int user_id, int apartment_id) {
    // Simulate some busingess logic.

    // Get the user id from the database
    
    // Get the apartment id from the database
    // Check apartment price
    
    // Check if the user has enought money to buy the apartment
    // Call the external service to make payment
}


i_house_operations_facade__vtable house_operations_facade__vtable = {
    .buy_apartment = buy_apartment__house_operation_facade
};

house_operations_facade *new__house_operations_facade() {
    house_operations_facade *facade = malloc(sizeof(house_operations_facade));
    facade->i_house_operations_facade.vtable = &house_operations_facade__vtable;
    return facade;
}
