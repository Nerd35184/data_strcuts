#include"link_list.h"
#include<stdio.h>

void print_int_link_list(LinkList* link_list_p){
    printf("length:%I64u {\n",link_list_p->length);

    LinkListElem* cur=get_link_list_front(link_list_p);
    for(int i=0;cur!=NULL;++i){
        LinkListElem* next = get_link_list_elem_next(cur);
        printf("print_sq_list %d %d \n",i,*(int*)cur->elem);
        cur=next;
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
    int ret=0;
    LifeCycle life_cycle = new_life_cycle(default_constructor,copy_constructor,destructor);
    LinkList* link_list_p = alloc_link_list(sizeof(int),life_cycle);
    if(link_list_p==NULL){
        ret=-1;
        goto clean;
    }
    int a=5;
    int b=4;
    int c=3;
    int d=2;
    int e=1;
    ret=push_back_link_list(link_list_p,&b);
    if(ret!=0){
        printf("main push_back_link_list 1");
        goto clean;
    }
    ret=push_back_link_list(link_list_p,&a);
    if(ret!=0){
        printf("main push_back_link_list 1");
        goto clean;
    }
    ret=push_front_link_list(link_list_p,&c);
    if(ret!=0){
        printf("main push_front_link_list 1");
        goto clean;
    }
    ret=push_front_link_list(link_list_p,&d);
    if(ret!=0){
        printf("main push_front_link_list 1");
        goto clean;
    }
    ret=push_front_link_list(link_list_p,&e);
    if(ret!=0){
        printf("main push_front_link_list 1");
        goto clean;
    }
    LinkListElem* front=get_link_list_front(link_list_p);

    ret=remove_link_list_elem(link_list_p,front);
    if(ret!=0){
        printf("main push_front_link_list 1");
        goto clean;
    }

    print_int_link_list(link_list_p);
clean:
    if(link_list_p!=NULL){
        free_link_list(&link_list_p);
    }
    return ret;
}