#include "sqlist.h"
#include <stdio.h>
#include <string.h>



int print_sq_list(SqList* sq_list_ptr){
    int ret=0;
    printf("{\n");
    for(int i=0;i<sq_list_ptr->length;++i){
        int result;
        ret=get_sq_list_elem(sq_list_ptr,i,(void*)&result);
        if(ret!=0){
            return -1;
        }
        printf("print_sq_list %d %d \n",i,result);
    }
    printf("}\n");
}

int test(){
    int ret;
    SqList* sq_list_ptr;
    ret=init_sq_list(&sq_list_ptr,sizeof(int),0);
    if(ret!=0){
        goto clean;
    }
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
    print_sq_list(sq_list_ptr);
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
    print_sq_list(sq_list_ptr);
clean:
    if(sq_list_ptr!=NULL){
        free_sq_list(&sq_list_ptr);
    }
    return ret;
}

int main()
{
    test();
}