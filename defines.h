#ifndef DEFINES_H
#define DEFINES_H

#define TRUE (bool)true
#define FALSE (bool)false


#define PP_NARG(...) PP_NARG_(_, ##__VA_ARGS__, 2, 1, 0)
#define PP_NARG_(_0, _1, _2, N, ...) N

#define CAT(a,b) CAT_I(a,b)
#define CAT_I(a,b) a##b


#define new(type, ...) new__##type(__VA_ARGS__)
#define _new(type, ...) _new__##type(__VA_ARGS__)
#define s_new(type, ...) s_new__##type(__VA_ARGS__)

#define class_(typedef_name) typedef struct typedef_name typedef_name; struct typedef_name
#define vtable_(class_name) typedef struct class_name##__vtable class_name##__vtable; struct class_name##__vtable
#define s_vtable_(class_name) typedef struct class_name##__s_vtable class_name##__s_vtable; struct class_name##__s_vtable
#define extends_(base_type) base_type base_type##__base
#define implements_(interface) interface interface
#define method_(return_type, method_name, ...) return_type (*method_name)(void *self, ##__VA_ARGS__)

#define call(obj, method, ...) ((obj)->vtable->method((obj), ##__VA_ARGS__))
#define s_call(obj, method, ...) ((obj)->s_vtable->method((obj), ##__VA_ARGS__))


#endif //DEFINES_H
