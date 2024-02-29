#include"sq_list.h"

void print_sq_list_int(SqList(int)* sq_list_p){
    printf("length:%I64d %I64d {\n",sq_list_p->length,sq_list_p->capacity);
    for(int i=0;i<sq_list_p->length;++i){
        printf("    %d\n",sq_list_p->buf[i]);
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

void operator_assignment(void* dst,const void* src){
    printf("operator_equal\n");
}

int main(){
    LifeCycle life_cycle = new_life_cycle(default_constructor,copy_constructor,operator_assignment,destructor);
    SqList(int)* sq_list_p = alloc_sq_list(int)(0,life_cycle);
    int ret=0;
    ret=push_back_sq_list(int)(sq_list_p,5);
    if(ret!=0){
        goto end;
    }
    ret=push_back_sq_list(int)(sq_list_p,3);
    if(ret!=0){
        goto end;
    }
    ret=push_back_sq_list(int)(sq_list_p,1);
    if(ret!=0){
        goto end;
    }
    ret=insert_sq_list(int)(sq_list_p,4,1);
    if(ret!=0){
        goto end;
    }

    ret=insert_sq_list(int)(sq_list_p,2,3);
    if(ret!=0){
        goto end;
    }
    ret = remove_sq_list(int)(sq_list_p,2);
    if(ret!=0){
        goto end;
    }
    print_sq_list_int(sq_list_p);
    printf("success\n");
end:
    free_sq_list(int)(&sq_list_p);
    printf("done\n");
    return 0;
}