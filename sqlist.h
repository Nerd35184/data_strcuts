#ifndef SQLIST_H
#define SQLIST_H


#include<stdint.h>
#include"life_cycle.h"

/*
其实应该注入一个elem的析构函数，todo
*/


struct SqList;

typedef struct SqList SqList;

struct SqList
{
    void* buf;
    size_t elem_size;
    size_t length;//当前长度
    size_t capacity;//当前分配的存储容量
    void (*elem_destructor)(void* elem,size_t elem_size);
    LifeCycle elem_life_cycle;
};


SqList* alloc_sq_list(size_t elem_size,size_t capacity,void (*elem_destructor)(void* elem,size_t elem_size));
int init_sq_list(SqList** sq_list_ptr2,size_t elem_size,size_t capacity,void (*elem_destructor)(void* elem,size_t elem_size));
int free_sq_list(SqList** sq_list_ptr2);
int get_sq_list_elem(SqList* sq_list_p,int postion,void* result);
int set_sq_list_elem(SqList* sq_list_p,void* elem,int postion);
int push_back_sq_list(SqList* sq_list_p,void* elem);
int insert_sq_list(SqList* sq_list_p,void* elem,size_t position);
int remove_sq_list(SqList* sq_list_p,size_t position);

#endif