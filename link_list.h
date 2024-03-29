#ifndef LIKN_LIST_H
#define LIKN_LIST_H

#include <stdint.h>
#include <string.h>
#include "life_cycle.h"

#define LinkList(T) LinkList##T
#define LinkListElem(T) LinkListElem##T
#define LinkListElemDefinition(T)                   \
    typedef struct LinkListElem(T) LinkListElem(T); \
    struct LinkListElem(T)                          \
    {                                               \
        LinkListElem *prew;                         \
        LinkListElem *next;                         \
        T elem;                                     \
        LinkList(T) * link_list;                    \
    };

#define LinkListDefinition(T)                                 \
    typedef struct LinkList(T) LinkList(T) struct LinkList(T) \
    {                                                         \
        LinkListElem(T) root;                                 \
        size_t length;                                        \
        LifeCycle elem_life_cycle;                            \
    };

#define alloc_link_list(T) alloc_link_list_##T
#define alloc_link_list_prototype(T) LinkList(T) * alloc_link_list(T)(LifeCycle elem_life_cycle)

struct LinkListElem;
typedef struct LinkListElem LinkListElem;

struct LinkList;
typedef struct LinkList LinkList;

struct LinkListElem
{
    LinkListElem *prew;
    LinkListElem *next;
    void *elem;
    LinkList *link_list;
};

struct LinkList
{
    LinkListElem root;
    size_t elem_size;
    size_t length;
    LifeCycle elem_life_cycle;
};

LinkList *alloc_link_list(size_t elem_size, LifeCycle elem_life_cycle);

int push_back_link_list(LinkList *link_list_p, void *data);
int push_front_link_list(LinkList *link_list_p, void *data);
int remove_link_list_elem(LinkList *link_list_p, LinkListElem *link_list_elem_p);
LinkListElem *get_link_list_front(LinkList *link_list_p);
LinkListElem *get_link_list_elem_next(LinkListElem *link_list_elem_p);
void free_link_list_elem(LinkListElem **link_list_elem_pp, LifeCycle elem_life_cycle);
void free_link_list(LinkList **link_list_pp);
#endif