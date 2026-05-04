#include "house_inspection.h"
#include <stdio.h>

void run_inspection(house_inspection *inspection) {
    printf("========== Inspection Report ==========\n");
    call(inspection, gather_info);
    call(inspection, inspect_structure);
    call(inspection, inspect_utilities);
    call(inspection, write_conclusion);
    printf("=======================================\n");
}
