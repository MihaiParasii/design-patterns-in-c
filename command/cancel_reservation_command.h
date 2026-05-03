#ifndef CANCEL_RESERVATION_COMMAND_H
#define CANCEL_RESERVATION_COMMAND_H
#include "../defines.h"
#include "i_apartment_command.h"
#include "apartment_booking_receiver.h"

class_(cancel_reservation_command) {
    implements_(i_apartment_command);
    apartment_booking_receiver *__receiver;
    char *__prev_tenant_name;
};

constructor(cancel_reservation_command, apartment_booking_receiver *receiver);

#endif //CANCEL_RESERVATION_COMMAND_H
