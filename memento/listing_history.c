#include "listing_history.h"
#include <stdlib.h>
#include <stdio.h>

static void push(void *self, listing_memento *m) {
    listing_history *h = self;
    if (h->__top < LISTING_HISTORY_MAX) {
        h->__stack[h->__top++] = m;
    }
}

static listing_memento *pop(void *self) {
    listing_history *h = self;
    if (h->__top == 0) {
        printf("[History] Nothing to undo.\n");
        return NULL;
    }
    return h->__stack[--h->__top];
}

static listing_history__vtable listing_history_vtable = {
    .push = push,
    .pop  = pop,
};

constructor(listing_history) {
    listing_history *h = malloc(sizeof(listing_history));
    h->vtable = &listing_history_vtable;
    h->__top  = 0;
    return h;
}
