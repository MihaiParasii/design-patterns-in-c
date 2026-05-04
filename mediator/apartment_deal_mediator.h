#ifndef APARTMENT_DEAL_MEDIATOR_H
#define APARTMENT_DEAL_MEDIATOR_H
#include "../defines.h"
#include "i_negotiation_mediator.h"
#include "seller.h"
#include "buyer.h"

class_(apartment_deal_mediator) {
    implements_(i_negotiation_mediator);
    seller *__seller;
    buyer  *__buyer;
};

constructor(apartment_deal_mediator, seller *s, buyer *b);

#endif //APARTMENT_DEAL_MEDIATOR_H
