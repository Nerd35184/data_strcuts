#include<shared_ptr.h>
#include<pthread.h>
#include<stdlib.h>



SharedPtr* alloc_shared_ptr(void* elem){
    malloc(sizeof(SharedPtr));
}