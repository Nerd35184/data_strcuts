#include"life_cycle.h"
#include<stdlib.h>



void empty_default_constructor(void* elem){

}

void empty_copy_constructor(void* dst,const void* src){

}

void empty_destructor(void* elem){

}






LifeCycle new_life_cycle(void (*constructor)(void* elem),void (*copy_constructor)(void* dst,const void* src),void (*destructor)(void* elem)){
    LifeCycle live_cycle;
    live_cycle.default_constructor=constructor;
    live_cycle.copy_constructor=copy_constructor;
    live_cycle.destructor=destructor;
    if(live_cycle.default_constructor == NULL){
        live_cycle.default_constructor=empty_default_constructor;
    }

    if(live_cycle.destructor == NULL){
        live_cycle.destructor=empty_destructor;
    }

    if(live_cycle.copy_constructor == NULL){
        live_cycle.copy_constructor=empty_copy_constructor;
    }
    return live_cycle;
}

int check_life_cycle(LifeCycle life_cycle){
    if(life_cycle.default_constructor==NULL || life_cycle.copy_constructor==NULL || life_cycle.destructor==NULL){
        return -1;
    }
    return 0;
}
