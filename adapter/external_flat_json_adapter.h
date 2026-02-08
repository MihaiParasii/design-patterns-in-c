#ifndef EXTERNAL_FLAT_JSON_ADAPTER_H
#define EXTERNAL_FLAT_JSON_ADAPTER_H
#include "../defines.h"
#include "external_flat.h"
#include "../common/i_as_json.h"

class_(external_flat_json_adapter) {
    implements_(i_as_json);
    external_flat *_flat;
};

external_flat_json_adapter *new__external_flat_json_adapter1_external_flat(external_flat *ef);

#define new__external_flat_json_adapter1(x) \
    _Generic((x), \
    external_flat*:       new__external_flat_json_adapter1_external_flat \
)(x)

#define new__external_flat_json_adapter(...) \
    CAT(new__external_flat_json_adapter, PP_NARG(__VA_ARGS__))(__VA_ARGS__)


#endif //EXTERNAL_FLAT_JSON_ADAPTER_H
