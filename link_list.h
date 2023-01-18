#ifndef LINK_LIST_H
#define LINK_LIST_H
#include<stdint.h>

/*
其实应该注入一个elem的析构函数，todo，在删除的时候使用
*/

struct LinkListElem;

typedef struct LinkListElem LinkListElem;

struct LinkListElem
{
    LinkListElem* prew;
    LinkListElem* next;
    void* elem;
    LinkList* link_list;
};





struct LinkList;
typedef struct LinkList LinkList;





struct LinkList
{
    LinkListElem root;
    size_t elem_size;
    size_t length;
};



LinkList* alloc_link_list(size_t elem_size);

// int insert_link_list_after_elem(LinkList* link_list,void* elem,LinkListElem* mark);

#endif