#ifndef SQ_LIST_H
#define SQ_LIST_H

#include <stdint.h>
#include "life_cycle.h"



struct SqList
{
    size_t elem_size;
    size_t length;
    size_t capacity;
    void* buf;
    LifeCycle elem_life_cycle;
};

typedef struct SqList  SqList;

SqList* alloc_sq_list(size_t elem_size,size_t capacity,LifeCycle elem_life_cycle);
int free_sq_list(SqList** sq_list_pp);
int get_sq_list_elem(SqList* sq_list_p,int postion,void** result);
int set_sq_list_elem(SqList* sq_list_p,const void* elem,int postion);
int insert_sq_list(SqList* sq_list_p,void* elem,size_t position);
int push_back_sq_list(SqList* sq_list_p,void* elem);
int remove_sq_list(SqList* sq_list_p,size_t position);
int print_sq_list(SqList* sq_list_ptr);
#endif