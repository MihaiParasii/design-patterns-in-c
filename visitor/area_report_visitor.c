#include "area_report_visitor.h"
#include <stdlib.h>
#include <stdio.h>

static void visit_apartment__area_report_visitor(void *self, apartment *apt) {
    area_report_visitor *v =
        container_of(self, area_report_visitor, i_property_visitor__iface);
    double area = apt->base_house__base.number_of_rooms * 18.0;
    v->__total_area += area;
    printf("[Area] Apartment (floor %d, %d rooms): %.0f m2\n",
           apt->floor, apt->base_house__base.number_of_rooms, area);
}

static void visit_ground_house__area_report_visitor(void *self, ground_house *gh) {
    area_report_visitor *v =
        container_of(self, area_report_visitor, i_property_visitor__iface);
    double area = gh->base_house__base.number_of_rooms * 28.0;
    v->__total_area += area;
    printf("[Area] Ground house (%d rooms): %.0f m2\n",
           gh->base_house__base.number_of_rooms, area);
}

static i_property_visitor__vtable area_report_visitor_vtable = {
    .visit_apartment    = visit_apartment__area_report_visitor,
    .visit_ground_house = visit_ground_house__area_report_visitor,
};

constructor(area_report_visitor) {
    area_report_visitor *v = malloc(sizeof(area_report_visitor));
    v->i_property_visitor__iface.vtable = &area_report_visitor_vtable;
    v->__total_area = 0.0;
    return v;
}
