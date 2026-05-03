#ifndef EXTERNAL_FLAT_JSON_ADAPTER_H
#define EXTERNAL_FLAT_JSON_ADAPTER_H
#include "../defines.h"
#include "external_flat.h"
#include "../common/i_as_json.h"

class_(external_flat_json_adapter) {
    implements_(i_as_json);
    external_flat *_flat;
};

constructor(external_flat_json_adapter, external_flat *ef);


#endif //EXTERNAL_FLAT_JSON_ADAPTER_H
