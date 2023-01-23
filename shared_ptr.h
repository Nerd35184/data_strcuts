#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include<pthread.h>
#include"life_cycle.h"
#include<stdint.h>



struct  SharedPtr;
typedef struct  SharedPtr SharedPtr;




struct  SharedPtr{
    void* elem;
    LifeCycle elem_life_cycle;
    size_t count;
};

#endif


