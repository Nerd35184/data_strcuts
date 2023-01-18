#include "sqlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


SqList* alloc_sq_list(size_t elem_size,size_t list_size){
    if(elem_size<=0 || list_size<0){
        return NULL;
    }
    //1.初始化结构体
    SqList* sq_list_p=malloc(sizeof(SqList));
    if(sq_list_p==NULL){
        exit(-1);
        return NULL;
    }
    memset(sq_list_p,0,sizeof(SqList));
    sq_list_p->elem_size=elem_size;
    sq_list_p->capacity=list_size;

    //2.初始化buff
    if(list_size<=0){
        return sq_list_p;
    }
    size_t elem_buf_size=sq_list_p->elem_size*sq_list_p->capacity;
    sq_list_p->elem=malloc(elem_buf_size);    
    if(sq_list_p->elem==NULL){
        free(sq_list_p);
        exit(-1);
        return NULL;
    }
    return sq_list_p;
}


int init_sq_list(SqList** sq_list_pp,size_t elem_size,size_t list_size){
    *sq_list_pp=alloc_sq_list(elem_size,list_size);
    if(*sq_list_pp==NULL){
        return -1;
    }
    return 0;
}


int free_sq_list(SqList** sq_list_pp){
    if(sq_list_pp==NULL){
        return -1;
    }
    SqList* sq_list_p= *sq_list_pp;
    if(sq_list_p==NULL){
        return -1;
    }
    free(sq_list_p->elem);
    sq_list_p->elem=NULL;

    free(*sq_list_pp);
    *sq_list_pp=NULL;
    return 0;
}


int get_sq_list_elem(SqList* sq_list_p,int postion,void* result){
    if(sq_list_p==NULL){
        return -1;
    }
    if(postion<0 ||postion>=sq_list_p->length){
        return -1;
    }
    memcpy(result,sq_list_p->elem+sq_list_p->elem_size*postion,sq_list_p->elem_size);
    return 0;
}

int set_sq_list_elem(SqList* sq_list_p,void* elem,int postion){
    if(sq_list_p==NULL){
        return -1;
    }
    if(postion>=sq_list_p->length){
        return -1;
    }
    memcpy(sq_list_p->elem+sq_list_p->elem_size*postion,
        elem,
        sq_list_p->elem_size);
    return 0;
}

int insert_sq_list(SqList* sq_list_p,void* elem,size_t position){
    if(sq_list_p==NULL){
        return -1;
    }

    if(elem==NULL){
        return -1;
    }

    if(position<0 || position>sq_list_p->length){
        return -1;
    }

    int move_elem_count=sq_list_p->length - position;

    if(sq_list_p->length >= sq_list_p->capacity){
        //已经满了，需要重新申请大小
        int new_capacity=sq_list_p->capacity*2;
        if(new_capacity==0){
            new_capacity=2;
        }
        void* new_elem=realloc(sq_list_p->elem,new_capacity*sq_list_p->elem_size);
        if(new_elem==NULL){
            return -1;
        }
        sq_list_p->elem=new_elem; 
        sq_list_p->capacity=new_capacity;
    }

    void* src=sq_list_p->elem+position*sq_list_p->elem_size;
    void* dst=src+sq_list_p->elem_size;
    size_t move_byte_count=move_elem_count*sq_list_p->elem_size;
    memcpy(dst,src,move_byte_count);
    ++sq_list_p->length;
    return set_sq_list_elem(sq_list_p,elem,position);
}

int push_back_sq_list(SqList* sq_list_p,void* elem){
    if(sq_list_p==NULL){
        return -1;
    }
    return insert_sq_list(sq_list_p,elem,sq_list_p->length);
}


int remove_sq_list(SqList* sq_list_p,size_t position){
    if(sq_list_p==NULL){
        return -1;
    }

    if(position < 0 || position >= sq_list_p->length){
        return -1;
    }

    size_t move_elem_count=sq_list_p->length - position - 1;
    printf("remove_sq_list move_elem_count:%d\n",move_elem_count);
    void* dst=sq_list_p->elem+position*sq_list_p->elem_size;
    void* src=dst+sq_list_p->elem_size;
    size_t move_byte_count=move_elem_count*sq_list_p->elem_size;
    printf("remove_sq_list move_byte_count:%d\n",move_byte_count);
    memcpy(dst,src,move_byte_count);
    --sq_list_p->length;
    return 0;
}