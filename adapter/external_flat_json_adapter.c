#include "external_flat_json_adapter.h"

#include <stdio.h>
#include <stdlib.h>

char *to_json_external_flat(void *self) {
    external_flat_json_adapter *s = self;
    char *json = malloc(150);
    sprintf(json, "{ \"number_of_rooms\": %d, \"address\": %s, \"area\": %d }",
            s->_flat->number_of_rooms,
            s->_flat->address,
            s->_flat->area);

    return json;
};


i_as_json__vtable external_flat_as_json_v_table = {
    .to_json = to_json_external_flat
};

external_flat_json_adapter *new__external_flat_json_adapter1_external_flat(external_flat *ef) {
    external_flat_json_adapter *adapter = malloc(sizeof(external_flat_json_adapter));

    adapter->i_as_json__iface.vtable = &external_flat_as_json_v_table;
    adapter->_flat = ef;

    return adapter;
};
