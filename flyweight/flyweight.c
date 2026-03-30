#include "flyweight.h"

#include <stdio.h>
#include <stdlib.h>

void print_color(void *self) {
    flyweight *s = self;
    printf("Color: #%06X\n", s->__color_hex);
    printf("---DEBUG--- ->Memory address: || color-hex: %p ||\n\n", &s->__color_hex);
}

int get_color_hex(void *self) {
    flyweight *s = self;
    return s->__color_hex;
}

flyweight__vtable flyweight_vtable = {
    .print_color = print_color,
    .get_color = get_color_hex
};

flyweight *new__flyweight(int color_hex) {
    flyweight *f = malloc(sizeof(flyweight));
    
    f->vtable = &flyweight_vtable;

    f->__color_hex = color_hex;
    return f;
}
