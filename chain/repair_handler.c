#include "repair_handler.h"
#include <stdlib.h>
#include <stdio.h>

static void set_next__repair_handler(void *self, i_repair_handler *next) {
    repair_handler *h = container_of(self, repair_handler, i_repair_handler__iface);
    h->__next = next;
}

static void handle__repair_handler(void *self, int cost, const char *description) {
    repair_handler *h = container_of(self, repair_handler, i_repair_handler__iface);
    if (cost <= h->__budget_limit) {
        printf("[%s] Approving repair \"%s\" (cost: $%d, budget: $%d)\n",
               h->__role, description, cost, h->__budget_limit);
    } else if (h->__next) {
        printf("[%s] Cost $%d exceeds my budget ($%d). Escalating \"%s\"...\n",
               h->__role, cost, h->__budget_limit, description);
        call(h->__next, handle, cost, description);
    } else {
        printf("[%s] No one can approve repair \"%s\" (cost: $%d).\n",
               h->__role, description, cost);
    }
}

static i_repair_handler__vtable repair_handler_vtable = {
    .set_next = set_next__repair_handler,
    .handle   = handle__repair_handler,
};

constructor(repair_handler, const char *role, int budget_limit) {
    repair_handler *h = malloc(sizeof(repair_handler));
    h->i_repair_handler__iface.vtable = &repair_handler_vtable;
    h->__next         = NULL;
    h->__budget_limit = budget_limit;
    h->__role         = role;
    return h;
}
