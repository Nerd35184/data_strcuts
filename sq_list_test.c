

#include"life_cycle.h"
#include"sq_list.h"
#include<stdio.h>
int print_int_sq_list(SqList* sq_list_p){
    int ret=0;
    printf("{\n");
    for(int i=0;i<sq_list_p->length;++i){
        int *result=NULL;
        ret=get_sq_list_elem(sq_list_p,i,(void*)&result);
        if(ret!=0){
            return -1;
        }
        printf("print_sq_list %d %d \n",i,*result);
    }
    printf("}\n");
}


void default_constructor(void* elem){
    printf("default_constructor\n");
};

void destructor(void* elem){
    printf("destructor\n");
}

void copy_constructor(void* dst,const void* src){
    printf("copy_constructor\n");
}


int main(){
    LifeCycle life_cycle = new_life_cycle(default_constructor,copy_constructor,destructor);
    SqList* sq_list_ptr=alloc_sq_list(sizeof(int),0,life_cycle);
    if(sq_list_ptr==NULL){
        printf("main alloc_sq_list err");
        goto clean;
    }
    int ret;
    int a=5;
    int b=4;
    int c=3;
    int d=2;
    int e=1;
    ret=push_back_sq_list(sq_list_ptr,(void*)&a);
    if(ret!=0){
        goto clean;
    }
    ret=push_back_sq_list(sq_list_ptr,(void*)&b);
    if(ret!=0){
        goto clean;
    }
    ret=push_back_sq_list(sq_list_ptr,(void*)&c);
    if(ret!=0){
        goto clean;
    }    
    ret=push_back_sq_list(sq_list_ptr,(void*)&d);
    if(ret!=0){
        goto clean;
    }
    ret=push_back_sq_list(sq_list_ptr,(void*)&e);
    if(ret!=0){
        goto clean;
    }
    ret=insert_sq_list(sq_list_ptr,(void*)&e,2);
    if(ret!=0){
        goto clean;
    }
    print_int_sq_list(sq_list_ptr);
    ret=remove_sq_list(sq_list_ptr,2);
    if(ret!=0){
        goto clean;
    }
    ret=remove_sq_list(sq_list_ptr,2);
    if(ret!=0){
        goto clean;
    }
    ret=remove_sq_list(sq_list_ptr,2);
    if(ret!=0){
        goto clean;
    }
    ret=remove_sq_list(sq_list_ptr,2);
    if(ret!=0){
        goto clean;
    }
    ret=remove_sq_list(sq_list_ptr,0);
    if(ret!=0){
        goto clean;
    }
    ret=remove_sq_list(sq_list_ptr,0);
    if(ret!=0){
        goto clean;
    }
    print_int_sq_list(sq_list_ptr);
clean:
    if(sq_list_ptr!=NULL){
        free_sq_list(&sq_list_ptr);
    }
    return ret;
}