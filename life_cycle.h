#ifndef LIFE_CYCLE_H
#define LIFE_CYCLE_H
struct LifeCycle;

typedef struct LifeCycle LifeCycle;

struct LifeCycle{
    void (*default_constructor)(void* elem);
    void (*destructor)(void* elem);
    void (*copy_constructor)(void* dst,const void* src);
};



LifeCycle new_life_cycle(void (*default_constructor)(void* elem),void (*copy_constructor)(void* dst,const void* src),void (*destructor)(void* elem));

int check_life_cycle(LifeCycle life_cycle);



#endif