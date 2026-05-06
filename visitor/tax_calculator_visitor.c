#include "tax_calculator_visitor.h"
#include <stdlib.h>
#include <stdio.h>

static void visit_apartment(void *self, apartment *apt) {
    tax_calculator_visitor *v =
            container_of(self, tax_calculator_visitor, i_property_visitor__iface);
    double tax = apt->floor * 30.0 + apt->base_house__base.number_of_rooms * 120.0;
    v->__total_tax += tax;
    printf("[Tax] Apartment (floor %d, %d rooms): $%.0f\n",
           apt->floor, apt->base_house__base.number_of_rooms, tax);
}

static void visit_ground_house(void *self, ground_house *gh) {
    tax_calculator_visitor *v =
            container_of(self, tax_calculator_visitor, i_property_visitor__iface);
    double tax = gh->base_house__base.number_of_rooms * 200.0
                 + (gh->has_fantana ? 150.0 : 0.0);
    v->__total_tax += tax;
    printf("[Tax] Ground house (%d rooms, well: %s): $%.0f\n",
           gh->base_house__base.number_of_rooms,
           gh->has_fantana ? "yes" : "no", tax);
}

static i_property_visitor__vtable tax_calculator_visitor_vtable = {
    .visit_apartment = visit_apartment,
    .visit_ground_house = visit_ground_house,
};

constructor(tax_calculator_visitor) {
    tax_calculator_visitor *v = malloc(sizeof(tax_calculator_visitor));
    v->i_property_visitor__iface.vtable = &tax_calculator_visitor_vtable;
    v->__total_tax = 0.0;
    return v;
}
