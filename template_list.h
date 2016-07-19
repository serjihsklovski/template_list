#ifndef TEMPLATE_LIST_H
#define TEMPLATE_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lib/cclasses/cclasses.h"
#include "lib/cexception/CException.h"
#include "error_codes.h"
#include <stdlib.h>


/* Specific typename */
#define List(T) List_##T


/* This macros generates definition of a specific type of List(T) */
#define TemplateList(T)                                                         \
                                                                                \
typedef struct Node_##T {                                                       \
    T                   _data;                                                  \
    struct Node_##T*    _next;                                                  \
    struct Node_##T*    _prev;                                                  \
} Node_##T;                                                                     \
                                                                                \
                                                                                \
cclass_(List_##T) {                                                             \
    /* fields */                                                                \
    size_t      _size;                                                          \
    Node_##T*   _head;                                                          \
    Node_##T*   _tail;                                                          \
    Node_##T*   _cache;                                                         \
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


#define TemplateListImplementation(T)                                           \
                                                                                \
static int _get_abs_index(int relative_index, size_t size) {                    \
    return relative_index >= 0 ? relative_index : (int) size + relative_index;  \
}                                                                               \
                                                                                \
                                                                                \
method_body_(_Bool, is_empty, List(T)) without_args {                           \
    return self->_size == 0;                                                    \
}                                                                               \
                                                                                \
                                                                                \
method_body_(void, push_back, List(T)) with_(T value) {                         \
    Node_##T* node = malloc(sizeof(Node_##T));                                  \
                                                                                \
    node->_data = value;                                                        \
    node->_next = NULL;                                                         \
                                                                                \
    if (self->is_empty(self)) {                                                 \
        self->_head = node;                                                     \
        self->_tail = node;                                                     \
        node->_prev = NULL;                                                     \
    } else {                                                                    \
        self->_tail->_next = node;                                              \
        node->_prev = self->_tail;                                              \
        self->_tail = node;                                                     \
    }                                                                           \
                                                                                \
    ++self->_size;                                                              \
}                                                                               \
                                                                                \
                                                                                \
method_body_(void, push_front, List(T)) with_(T value) {                        \
    Node_##T* node = malloc(sizeof(Node_##T));                                  \
                                                                                \
    node->_data = value;                                                        \
    node->_prev = NULL;                                                         \
                                                                                \
    if (self->is_empty(self)) {                                                 \
        self->_head = node;                                                     \
        self->_tail = node;                                                     \
        node->_next = NULL;                                                     \
    } else {                                                                    \
        self->_head->_prev = node;                                              \
        node->_next = self->_head;                                              \
        self->_head = node;                                                     \
    }                                                                           \
                                                                                \
    ++self->_size;                                                              \
}                                                                               \
                                                                                \
                                                                                \
method_body_(T, pop_back, List(T)) without_args {                               \
    if (self->is_empty(self)) {                                                 \
        Throw(EMPTY_LIST);                                                      \
    }                                                                           \
                                                                                \
    T value = self->_tail->_data;                                               \
                                                                                \
    if (self->_size > 1) {                                                      \
        self->_tail->_prev->_next = NULL;                                       \
        Node_##T* temp = self->_tail;                                           \
        self->_tail = temp->_prev;                                              \
        free(temp);                                                             \
    } else {    /* 1 element in the list */                                     \
        self->_head = NULL;                                                     \
        free(self->_tail);                                                      \
        self->_tail = NULL;                                                     \
    }                                                                           \
                                                                                \
    --self->_size;                                                              \
                                                                                \
    return value;                                                               \
} throws_(EMPTY_LIST)                                                           \
                                                                                \
                                                                                \
method_body_(T, pop_front, List(T)) without_args {                              \
    if (self->is_empty(self)) {                                                 \
        Throw(EMPTY_LIST);                                                      \
    }                                                                           \
                                                                                \
    T value = self->_head->_data;                                               \
                                                                                \
    if (self->_size > 1) {                                                      \
        self->_head->_next->_prev = NULL;                                       \
        Node_##T* temp = self->_head;                                           \
        self->_head = temp->_next;                                              \
        free(temp);                                                             \
    } else {    /* 1 element in the list */                                     \
        self->_tail = NULL;                                                     \
        free(self->_head);                                                      \
        self->_head = NULL;                                                     \
    }                                                                           \
                                                                                \
    --self->_size;                                                              \
                                                                                \
    return value;                                                               \
} throws_(EMPTY_LIST)                                                           \
                                                                                \
                                                                                \
method_body_(_Bool, has_index, List(T)) with_(int index) {                      \
    index = _get_abs_index(index, self->_size);                                 \
                                                                                \
    if (index >= 0 && index < (int) self->_size) {                              \
        return 1;                                                               \
    }                                                                           \
                                                                                \
    return 0;                                                                   \
}                                                                               \
                                                                                \
                                                                                \
constructor_(List(T))() {                                                       \
    new_self_(List_##T);                                                        \
                                                                                \
    self->_size = 0;                                                            \
    self->_head = NULL;                                                         \
    self->_tail = NULL;                                                         \
    self->_cache = NULL;                                                        \
                                                                                \
    init_method_(is_empty);                                                     \
    init_method_(push_back);                                                    \
    init_method_(push_front);                                                   \
    init_method_(pop_back);                                                     \
    init_method_(pop_front);                                                    \
    init_method_(has_index);                                                    \
                                                                                \
    return self;                                                                \
}                                                                               \
                                                                                \
                                                                                \
destructor_(List(T)) {                                                          \
    while (!self->is_empty(self)) {                                             \
        if (self->_size > 1) {                                                  \
            self->_head->_next->_prev = NULL;                                   \
            Node_##T* temp = self->_head;                                       \
            self->_head = temp->_next;                                          \
            free(temp);                                                         \
            temp->_next = NULL;                                                 \
            temp->_prev = NULL;                                                 \
        } else {    /* only 1 element in the list */                            \
            free(self->_head);                                                  \
            self->_head = NULL;                                                 \
            self->_head = NULL;                                                 \
        }                                                                       \
                                                                                \
        --self->_size;                                                          \
    }                                                                           \
                                                                                \
    free(self);                                                                 \
    self = NULL;                                                                \
}


#ifdef __cplusplus
}
#endif

#endif // TEMPLATE_LIST_H
