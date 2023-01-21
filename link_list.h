#ifndef LIKN_LIST_H
#define LIKN_LIST_H

#include<stdint.h>
#include"life_cycle.h"


struct LinkListElem;
typedef struct LinkListElem LinkListElem;

struct LinkList;
typedef struct LinkList LinkList;

struct LinkListElem
{
    LinkListElem* prew;
    LinkListElem* next;
    void* elem;
    LinkList* link_list;
};


struct LinkList
{
    LinkListElem root;
    size_t elem_size;
    size_t length;
    LifeCycle elem_life_cycle;
};


#endif 