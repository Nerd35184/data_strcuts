#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include<pthread.h>
#include"life_cycle.h"



struct  SharedPtr;
typedef struct  SharedPtr SharedPtr;




struct  SharedPtr{
    void* elem;
    LifeCycle elem_life_cycle;
};

#endif


