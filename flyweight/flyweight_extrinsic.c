#include "flyweight_extrinsic.h"

#include <stdio.h>
#include <stdlib.h>

void print_info__flyweight(void *self) {
    flyweight_extrinsic *s = self;
    
    printf("Not shared info: %d\n", s->not_shared_info);
    call(s->__flyweight, print_color);
}

flyweight_extrinsic__vtable flyweight_extrinsic_vtable = {
    .print_info = print_info__flyweight
};


flyweight_extrinsic *new__flyweight_extrinsic(int not_shared_info, flyweight *flyweight) {
    flyweight_extrinsic *s = malloc(sizeof(flyweight_extrinsic));
    
    s->vtable = &flyweight_extrinsic_vtable;
    s->not_shared_info = not_shared_info;
    s->__flyweight = flyweight;
    
    return s;   
}