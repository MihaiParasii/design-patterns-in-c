#ifndef RESERVE_APARTMENT_COMMAND_H
#define RESERVE_APARTMENT_COMMAND_H
#include "../defines.h"
#include "i_apartment_command.h"
#include "apartment_booking_receiver.h"

class_(reserve_apartment_command) {
    implements_(i_apartment_command);
    apartment_booking_receiver *__receiver;
    char *__tenant_name;
};

constructor(reserve_apartment_command, apartment_booking_receiver *receiver, char *tenant_name);

#endif //RESERVE_APARTMENT_COMMAND_H
