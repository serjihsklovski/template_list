#ifndef TEMPLATE_LIST_H
#define TEMPLATE_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lib/cclasses/cclasses.h"
#include "lib/cexception/CException.h"
#include <stdlib.h>


/* Specific typename */
#define List(T) List_##T


/* This macros generates definition of a specific type of List(T) */
#define TemplateList(T)                                                         \
                                                                                \
cclass_(List_##T) {                                                             \
    struct Node_##T {                                                           \
        T                   _data;                                              \
        struct Node_##T*    _next;                                              \
        struct Node_##T*    _prev;                                              \
    };                                                                          \
                                                                                \
    /* fields */                                                                \
    size_t              _size;                                                  \
    struct Node_##T*    _head;                                                  \
    struct Node_##T*    _tail;                                                  \
    struct Node_##T*    _cache;                                                 \
                                                                                \
    /* methods */                                                               \
    method_def_(void,   push_back,  List(T)) with_(T value);                    \
    method_def_(void,   push_front, List(T)) with_(T value);                    \
    method_def_(T,      pop_back,   List(T)) without_args;                      \
    method_def_(T,      pop_front,  List(T)) without_args;                      \
    method_def_(_Bool,  is_empty,   List(T)) without_args;                      \
    method_def_(_Bool,  has_index,  List(T)) with_(int index);                  \
    method_def_(T,      at,         List(T)) with_(int index);                  \
    method_def_(void,   set,        List(T)) with_(int index, T value);         \
    method_def_(void,   insert,     List(T)) with_(int index, T value);         \
    method_def_(void,   embed,      List(T)) with_(int index, List(T) lst);     \
    method_def_(T,      pop,        List(T)) with_(int index);                  \
    method_def_(void,   clear,      List(T)) without_args;                      \
    method_def_(void,   swap,       List(T)) with_(int index_1, int index_2);   \
    method_def_(List(T), copy,      List(T)) without_args;                      \
    method_def_(List(T), slice,     List(T)) with_(int beg, int end, int step); \
};                                                                              \
                                                                                \
constructor_(List(T))();                                                        \
destructor_(List(T));


#ifdef __cplusplus
}
#endif

#endif // TEMPLATE_LIST_H
