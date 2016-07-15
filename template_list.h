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


/* This macros generates defenition of a specific type of List(T) */
#define TemplateList(T)                                                         \
                                                                                \
cclass_(List_##T) {                                                             \
    typedef struct Node_##T* {                                                  \
        T                   _data;                                              \
        struct Node_##T*    _next;                                              \
        struct Node_##T*    _prev;                                              \
    } Node_##T;                                                                 \
                                                                                \
    /* fields */                                                                \
    size_t      _size;                                                          \
    Node_##T*   _head;                                                          \
    Node_##T*   _tail;                                                          \
    Node_##T*   _cach;                                                          \
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
};                                                                              \
                                                                                \
constructor_(List(T))();                                                        \
destructor_(List(T));


#ifdef __cplusplus
}
#endif

#endif // TEMPLATE_LIST_H
