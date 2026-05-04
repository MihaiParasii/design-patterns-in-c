#ifndef TAX_CALCULATOR_VISITOR_H
#define TAX_CALCULATOR_VISITOR_H
#include "../defines.h"
#include "i_property_visitor.h"

class_(tax_calculator_visitor) {
    implements_(i_property_visitor);
    double __total_tax;
};

constructor(tax_calculator_visitor);

#endif //TAX_CALCULATOR_VISITOR_H
