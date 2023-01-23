#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include"life_cycle.h"
#include<stdint.h>

struct TreeElem
{
    void* elem;
    size_t elem_size;
};

typedef struct TreeElem TreeElem;

struct BinaryTree
{
    TreeElem* left;
    TreeElem* right;
    LifeCycle tree_elem_life_cycle;
};

typedef struct BinaryTree BinaryTree;


#endif