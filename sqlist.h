#ifndef SQLIST_H
#define SQLIST_H


#include<stdint.h>

typedef struct SqList
{
    void* elem;
    size_t elem_size;
    size_t length;//当前长度
    size_t list_size;//当前分配的存储容量
}SqList;


SqList* alloc_sq_list(size_t elem_size,size_t list_size);
int init_sq_list(SqList** sq_list_ptr2,size_t elem_size,size_t list_size);
int free_sq_list(SqList** sq_list_ptr2);
int get_sq_list_elem(SqList* sq_list_p,int postion,void* result);
int set_sq_list_elem(SqList* sq_list_p,void* elem,int postion);
int push_back_sq_list(SqList* sq_list_p,void* elem);
int insert_sq_list(SqList* sq_list_p,void* elem,size_t position);
int remove_sq_list(SqList* sq_list_p,size_t position);

#endif