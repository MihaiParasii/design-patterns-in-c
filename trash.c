#define new__apartment2(x, y) \
_Generic((x), \
int:    dispatch_2_2(int, y),     \
double: dispatch_2_2(double, y)   \
)(x, y)

#define dispatch_2_2(type, second_type) \
_Generic((second_type), \
int:    new__apartment2_##type##_int,   \
double: new__apartment2_##type##_double, \
char:   new__apartment2_##type##_char \
)
// #include <stdio.h>
//
// #include "models/apartment.h"
//
//
// apartment *new__apartment2_int_int(int floor, int test);
//
// apartment *new__apartment2_double_int(double floor, int test);
//
// apartment *new__apartment2_int_double(int floor, double test);
//
// apartment *new__apartment2_double_double(double floor, double test);
//
// apartment *new__apartment2_double_char(double floor, char test);
//
// apartment *new__apartment2_int_char(double floor, char test);
//
//
//
//
// apartment *new__apartment1_double(const double test_double) {
//     apartment *a = new__apartment0();
//
//     printf("i'm test double %f", test_double);
//     // a->floor = floor;
//
//     return a;
// }
//
// apartment *new__apartment2_int_int(const int floor, const int test) {
//     apartment *a = new__apartment0();
//
//     printf("i'm test int_int: %d %d\n", floor, test);
//
//     a->floor = floor;
//
//     return a;
// }
//
// apartment *new__apartment2_double_int(const double floor, const int test) {
//     apartment *a = new__apartment0();
//
//     printf("i'm test double_int: %lf %d\n", floor, test);
//
//     a->floor = floor;
//
//     return a;
// }
//
// apartment *new__apartment2_int_double(const int floor, const double test) {
//     apartment *a = new__apartment0();
//
//     printf("i'm test int_double: %d %lf\n", floor, test);
//
//     a->floor = floor;
//
//     return a;
// }
//
// apartment *new__apartment2_double_double(const double floor, const double test) {
//     apartment *a = new__apartment0();
//
//     printf("i'm test double_double: %lf %lf\n", floor, test);
//
//     a->floor = floor;
//
//     return a;
// }
//
// apartment *new__apartment2_double_char(const double floor, const char test) {
//     apartment *a = new__apartment0();
//
//     printf("i'm test double_char: %lf %c\n", floor, test);
//
//     a->floor = floor;
//
//     return a;
// }
