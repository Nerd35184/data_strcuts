#ifndef SQ_LIST_H
#define SQ_LIST_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "life_cycle.h"
#include <string.h>

#define SqList(T) SqList##T
#define SqListDefinition(T)             \
    typedef struct SqList(T) SqList(T); \
    struct SqList(T)                    \
    {                                   \
        T *buf;                         \
        size_t length;                  \
        size_t capacity;                \
        LifeCycle elem_life_cycle;      \
    }
#define alloc_sq_list(T) alloc_sq_list_##T
#define alloc_sq_list_prototype(T) SqList(int) * alloc_sq_list(T)(size_t capacity, LifeCycle elem_life_cycle)

#define free_sq_list(T) free_sq_list_##T
#define free_sq_list_prototype(T) void free_sq_list(T)(SqList(T) * *sq_list_pp)

#define get_sq_list_elem(T) get_sq_list_elem_##T
#define get_sq_list_elem_prototype(T) int get_sq_list_elem(T)(SqList(T) * sq_list_p, int postion, T **result)

#define set_sq_list_elem(T) set_sq_list_elem_##T
#define set_sq_list_elem_prototype(T) int set_sq_list_elem(T)(SqList(T) * sq_list_p, const T elem, size_t postion)

#define insert_sq_list(T) insert_sq_list_##T
#define insert_sq_list_prototype(T) int insert_sq_list(T)(SqList(T) * sq_list_p, const T elem, size_t position)

// int push_back_sq_list(SqListPlaceholder* sq_list_p,Placeholder elem)
#define push_back_sq_list(T) push_back_sq_list_##T
#define push_back_sq_list_prototype(T) int push_back_sq_list(T)(SqList(T) * sq_list_p, T elem)

#define remove_sq_list(T) remove_sq_list_##T
#define remove_sq_list_prototype(T) int remove_sq_list(T)(SqList(T) * sq_list_p, size_t position)

SqListDefinition(int);
alloc_sq_list_prototype(int);
free_sq_list_prototype(int);
get_sq_list_elem_prototype(int);
set_sq_list_elem_prototype(int);
insert_sq_list_prototype(int);
push_back_sq_list_prototype(int);
remove_sq_list_prototype(int);

#endif