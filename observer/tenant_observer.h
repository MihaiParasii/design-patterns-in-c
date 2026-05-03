#ifndef TENANT_OBSERVER_H
#define TENANT_OBSERVER_H
#include "../defines.h"
#include "i_apartment_observer.h"

class_(tenant_observer) {
    implements_(i_apartment_observer);
    char *__name;
    int __max_floor;
};

constructor(tenant_observer, char *name, int max_floor);

#endif //TENANT_OBSERVER_H
