#include"binary_tree.h"
#include"life_cycle.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

TreeElem* alloc_tree_elem(const void* elem, size_t elem_size,LifeCycle life_cycle){
    if(elem==NULL || elem_size==0 || check_life_cycle(life_cycle)!=0){
        return NULL;
    }
    TreeElem* tree_elem_p = malloc(sizeof(TreeElem));
    if(tree_elem_p == NULL){
        printf("alloc_tree_elem malloc 1");
        exit(-1);
    }


    memset(tree_elem_p,0,sizeof(TreeElem)); 
    tree_elem_p->elem_size=elem_size;

    tree_elem_p->elem = malloc(tree_elem_p->elem_size);
    if(tree_elem_p->elem == NULL){
        printf("alloc_tree_elem malloc 2");
        exit(-1);
    }

    memcpy(tree_elem_p->elem,elem,elem_size);

    life_cycle.copy_constructor(tree_elem_p->elem,elem);
    return tree_elem_p;
}

void free_tree_elem(TreeElem** tree_elem_pp,LifeCycle life_cycle){
    assert(tree_elem_pp!=NULL);
    TreeElem* tree_elem_p=*tree_elem_pp;
    if(tree_elem_p==NULL){
        return ;
    }
    life_cycle.destructor(tree_elem_p->elem);
    free(tree_elem_p->elem);
    free(tree_elem_p);
    *tree_elem_pp=NULL;
}


BinaryTree* alloc_binary_tree(LifeCycle life_cycle){
    BinaryTree* binary_tree_p= malloc(sizeof(BinaryTree));
    memset(binary_tree_p,0,sizeof(BinaryTree));
    binary_tree_p->tree_elem_life_cycle=life_cycle;
    return binary_tree_p;
}







