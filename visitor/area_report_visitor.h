#ifndef AREA_REPORT_VISITOR_H
#define AREA_REPORT_VISITOR_H
#include "../defines.h"
#include "i_property_visitor.h"

class_(area_report_visitor) {
    implements_(i_property_visitor);
    double __total_area;
};

constructor(area_report_visitor);

#endif //AREA_REPORT_VISITOR_H
