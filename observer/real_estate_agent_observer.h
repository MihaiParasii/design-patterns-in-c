#ifndef REAL_ESTATE_AGENT_OBSERVER_H
#define REAL_ESTATE_AGENT_OBSERVER_H
#include "../defines.h"
#include "i_apartment_observer.h"

class_(real_estate_agent_observer) {
    implements_(i_apartment_observer);
    char *__agency_name;
};

constructor(real_estate_agent_observer, char *agency_name);

#endif //REAL_ESTATE_AGENT_OBSERVER_H
